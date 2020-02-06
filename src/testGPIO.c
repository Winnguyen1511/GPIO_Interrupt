#include <stdio.h>
#include <stdlib.h>
#include "GPIORpi.h"
#include "GPIO_IRQ_Handler.h"
#include <unistd.h>


int main(int argc, char** argv)
{
    gpio_value_t tmpVal;
    edge_t  tmpEd;
    direction_t tmpDir;

    printf("Welcome to test GPIO program:\n");

    GPIO_t gpio17;
    GPIO_Init_Custom(&gpio17, 17, INPUT, HIGH_ACTIVE,RISING, LOW);

    sleep(2);
    GPIO_get_value(&gpio17, &tmpVal);
    GPIO_get_edge(&gpio17, &tmpEd);
    GPIO_get_direction(&gpio17, &tmpDir);
    printf("Num=%d, Value=%d, Edge=%d, Dir=%d\n",gpio17.gpio_num, tmpVal, tmpEd, tmpDir);
    
    sleep(2);
    GPIO_get_value(&gpio17, &tmpVal);
    GPIO_get_edge(&gpio17, &tmpEd);
    GPIO_get_direction(&gpio17, &tmpDir);
    printf("Num=%d, Value=%d, Edge=%d, Dir=%d\n",gpio17.gpio_num, tmpVal, tmpEd, tmpDir);
    sleep(2);
    
    GPIO_EXTI_Init(&gpio17);
    //hello
    while(1)
    {
        printf("Hello from main\n");
        sleep(2);
    }
    GPIO_Denit(&gpio17);
    return SUCCESS;
}
