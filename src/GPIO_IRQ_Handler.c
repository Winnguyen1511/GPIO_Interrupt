#include "GPIO_IRQ_Handler.h"

int split_arg(void *arg)
{
    return SUCCESS;
}
#define BUF_LEN 10 * (sizeof(struct inotify_event) + 1024 + 1)

void* IRQ_Handler_GPIO17(void* arg)
{
    int inotifyFd, wd;
    struct inotify_event *event;
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 17 && tmpDir == INPUT)
    {
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        wd = inotify_add_watch(inotifyFd, gpio.path, IN_MODIFY | IN_OPEN);
        if (wd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_add_watch\n");
            return (void*)ERROR;
        }
        gpio_value_t previous, now;
        GPIO_get_value(&gpio, &previous);
        now = previous;
        edge_t tmpEdge;
        GPIO_get_edge(&gpio, &tmpEdge);
        if(tmpEdge == RISING)
        {
            for(;;)
            {
                numReadEvent = read(inotifyFd, buf, BUF_LEN);
                if (numReadEvent == 0)
                {
                    printf("read() from inotify fd returned 0!\n");
                    return (void*)ERROR;
                }
                
                if (numReadEvent == -1)
                {
                    printf("Error: read\n");
                    return (void*)ERROR;
                }
                GPIO_get_value(&gpio, &now);
                if(now == HIGH && previous == LOW)
                {
                    GPIO_EXTI_Callback(gpio.gpio_num);
                }
            }
        }
        else if(tmpEdge == FALLING)
        {
            for(;;)
            {
                numReadEvent = read(inotifyFd, buf, BUF_LEN);
                if (numReadEvent == 0)
                {
                    printf("read() from inotify fd returned 0!\n");
                    return (void*)ERROR;
                }
                
                if (numReadEvent == -1)
                {
                    printf("Error: read\n");
                    return (void*)ERROR;
                }
                GPIO_get_value(&gpio, &now);
                if(now == LOW && previous == HIGH)
                {
                    GPIO_EXTI_Callback(gpio.gpio_num);
                }
            }
        }
        else
        {       
            //do nothing   
        }
        

    }
    else 
    {
        printf("Internal error\n");
        return (void*)-1;
    }
    return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO18(void* arg)
{
    return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO27(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO22(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO23(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO24(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO25(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO05(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO06(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO12(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO13(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO19(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO16(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO26(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO20(void* arg)
{
return (void*)SUCCESS;
}

void* IRQ_Handler_GPIO21(void* arg)
{
return (void*)SUCCESS;
}

void  GPIO_EXTI_Callback(int gpio_num)
{
    //User code define here
    //User can define this function anywhere in user code
    printf("Interrupted\n");
}

int GPIO_EXTI_Init(GPIO_t* instance)
{
    edge_t ed = -1;
    if(!GPIO_get_edge(instance, &ed))
    {
        printf("Error: Cannot get edge gpio%d\n", instance->gpio_num);
        return ERROR;
    }
    if(ed == NONE)
    {
        printf("Error: Please set edge gpio%d\n", instance->gpio_num);
        return ERROR;
    }
    int pin_index, s;
    // arg = instance->gpio_num;
    // arg += (ed << 16);
    pin_index = GPIO_Map[GPIO_MAP_INDEX(instance->gpio_num)];
    pin_index = IRQ_Handler_Array_Index(pin_index);
    pthread_t exti_thread;
    s = pthread_create(&exti_thread, NULL, IRQ_Handler_Array[pin_index],instance);
    if(s != 0)
    {
        printf("Error: create exti thread failed\n");
        return ERROR;
    }
    return SUCCESS;
}