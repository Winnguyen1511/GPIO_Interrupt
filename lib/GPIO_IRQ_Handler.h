#ifndef GPIO_IRQ_HANDLER_H
#define GPIO_IRQ_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include "GPIORpi.h" 

void* IRQ_Handler_GPIO17(void* arg);

void* IRQ_Handler_GPIO18(void* arg);

void* IRQ_Handler_GPIO27(void* arg);

void* IRQ_Handler_GPIO22(void* arg);

void* IRQ_Handler_GPIO23(void* arg);

void* IRQ_Handler_GPIO24(void* arg);

void* IRQ_Handler_GPIO25(void* arg);

void* IRQ_Handler_GPIO05(void* arg);

void* IRQ_Handler_GPIO06(void* arg);

void* IRQ_Handler_GPIO12(void* arg);

void* IRQ_Handler_GPIO13(void* arg);

void* IRQ_Handler_GPIO19(void* arg);

void* IRQ_Handler_GPIO16(void* arg);

void* IRQ_Handler_GPIO26(void* arg);

void* IRQ_Handler_GPIO20(void* arg);

void* IRQ_Handler_GPIO21(void* arg);

static int GPIO_Map[GPIO_NUM] = {
                                    INVALID_IRQ, INVALID_IRQ, INVALID_IRQ, 29, 31, INVALID_IRQ, INVALID_IRQ, INVALID_IRQ, INVALID_IRQ,//GPIO02->10
                                    INVALID_IRQ, 32, 33, INVALID_IRQ, INVALID_IRQ, 36, 11, 12, 35,//GPIO11->19
                                    38, 40, 15, 16, 18, 22, 37, 13//GPIO20->26
                                    };

static void *IRQ_Handler_Array[PIN_NUM] = {
                                            NULL, NULL, NULL, NULL, //Pin 01->04
                                            NULL, NULL, NULL, NULL, //Pin 05->08
                                            NULL, NULL, IRQ_Handler_GPIO17, IRQ_Handler_GPIO18,//Pin 09->12
                                            IRQ_Handler_GPIO27, NULL, IRQ_Handler_GPIO22, IRQ_Handler_GPIO23,//Pin 13->16
                                            NULL, IRQ_Handler_GPIO24, NULL, NULL,//Pin 17->20
                                            NULL, IRQ_Handler_GPIO25, NULL, NULL,//Pin 21->24
                                            NULL, NULL, NULL, NULL,//Pin 25->28
                                            IRQ_Handler_GPIO05, NULL, IRQ_Handler_GPIO06, IRQ_Handler_GPIO12,//Pin 29 -> 32
                                            IRQ_Handler_GPIO13, NULL, IRQ_Handler_GPIO19, IRQ_Handler_GPIO16,//Pin 33->36
                                            IRQ_Handler_GPIO26, IRQ_Handler_GPIO20, NULL, IRQ_Handler_GPIO21//Pin 37->40
                                            };

int split_arg(void *arg);
//static 



int GPIO_EXTI_Init(GPIO_t* instance);

extern void GPIO_EXTI_Callback(int gpio_num) __attribute__((weak));

#endif