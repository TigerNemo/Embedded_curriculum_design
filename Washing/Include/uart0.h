#ifndef UART0_H
#define UART0_H

#include "TypeDef.h"
#include "lpc213x.h"

volatile extern uint8 rcv_new;  // 接收数据标记
volatile extern char rcv_buf[8];  // 接收缓冲数据
volatile extern uint8 uart0Flag;

void uart0Init(void);  // 串口初始化
void __irq IRQ_Uart0(void);  // 中断服务程序
void UART0_SendBuf (void);  // 发送数据
void UART0_SendByte (uint8);

#endif

