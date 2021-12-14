#ifndef UART0_H
#define UART0_H

#include "TypeDef.h"
#include "lpc213x.h"

volatile extern uint8 rcv_new;  // �������ݱ��
volatile extern char rcv_buf[8];  // ���ջ�������
volatile extern uint8 uart0Flag;

void uart0Init(void);  // ���ڳ�ʼ��
void __irq IRQ_Uart0(void);  // �жϷ������
void UART0_SendBuf (void);  // ��������
void UART0_SendByte (uint8);

#endif

