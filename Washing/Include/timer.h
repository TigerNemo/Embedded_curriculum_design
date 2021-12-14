#ifndef _TIMER_H
#define _TIMER_H

#include "TypeDef.h"
#include "led.h"

//#define Fpclk 11059200		 // 外设时钟频率  11.0592Mhz晶振
#define Fpclk 13000000  // 大约1s

void timer0Init(void);						// 定时器初始化
void __irq IRQ_Timer0(void);				// TC的中断服务程序，MR0和MR1与TC匹配时触发
extern	void IRQEnable(void);				// 设置CPSR的I位开启IRQ中断

#endif
