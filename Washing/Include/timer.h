#ifndef _TIMER_H
#define _TIMER_H

#include "TypeDef.h"
#include "led.h"

//#define Fpclk 11059200		 // ����ʱ��Ƶ��  11.0592Mhz����
#define Fpclk 13000000  // ��Լ1s

void timer0Init(void);						// ��ʱ����ʼ��
void __irq IRQ_Timer0(void);				// TC���жϷ������MR0��MR1��TCƥ��ʱ����
extern	void IRQEnable(void);				// ����CPSR��Iλ����IRQ�ж�

#endif
