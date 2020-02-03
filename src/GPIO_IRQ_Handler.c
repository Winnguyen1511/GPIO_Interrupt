#include "GPIO_IRQ_Handler.h"

int split_arg(void *arg)
{
    return SUCCESS;
}
#define BUF_LEN 10 * (sizeof(struct inotify_event) + 1024 + 1)

void* IRQ_Handler_GPIO17(void* arg)
{
    //printf("IRQ_start\n");
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 17 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 18 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO27(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 27 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO22(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 22 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO23(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 23 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO24(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 24 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO25(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 25 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO05(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 5 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO06(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 06 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO12(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 12 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO13(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 13 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO19(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 19 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO16(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 16 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO26(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 26 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO20(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 20 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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

void* IRQ_Handler_GPIO21(void* arg)
{
    int inotifyFd, wd;
    
    ssize_t numReadEvent;
    GPIO_t gpio = *(GPIO_t*)arg;
    direction_t tmpDir;
    GPIO_get_direction(&gpio, &tmpDir);
    char buf[BUF_LEN];
    if(gpio.gpio_num == 21 && tmpDir == INPUT)
    {
        //printf("IRQ process\n");
        //if()
        inotifyFd = inotify_init();
        if (inotifyFd == -1)
        {
            printf("Error: IRQ_Handler_GPIO17 inotify_init\n");
            return (void*)ERROR;
        }
        printf("%s\n", gpio.path);
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
            //printf("IRQ rising handler\n");
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
                previous = now;
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
    if(pin_index == INVALID_IRQ)
    {
        printf("Non-Interrupt-supported GPIO\n");
        return ERROR;
    }
    pin_index = IRQ_Handler_Array_Index(pin_index);
    if(IRQ_Handler_Array[pin_index] == NULL)
    {
        printf("Error: Trying to use Non-Interrupt-supported GPIO\n");
        return ERROR;
    }
    pthread_t exti_thread;
    s = pthread_create(&exti_thread, NULL, IRQ_Handler_Array[pin_index],instance);
    if(s != 0)
    {
        printf("Error: create exti thread failed\n");
        return ERROR;
    }
    return SUCCESS;
}