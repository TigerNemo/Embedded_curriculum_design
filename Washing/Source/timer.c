#include "timer.h"
#include "CountDown.h"

void timer0Init(void){						// 定时器0初始化
	IRQEnable();							// 允许IRQ中断
	T0TCR = 0x3;							// 定时器0的TC和PC保持复位  11
	T0PR = 0;								// 预分频PR为0，不分频
	T0MCR = 0x003;       // 设置MRO匹配时中断并复位TC
	T0MR0 = Fpclk;					// 设置TC计数上限，当TC达到计数上限，则复位
	
	VICIntSelect &= 0xFFFFFFEF;					// 通道4（Timer0中断）设置为IRQ中断（对应位为0）
	VICVectCntl0 = 0x20 | 0x04;				// bit[5]使能，bit[4:0]通道号设置为Timer0的中断通道号4
	VICVectAddr0 = (uint32)IRQ_Timer0;		// 设置中断服务程序地址
	VICIntEnable = 1 << 4;				// 使能Timer0中断
	T0TCR = 0x1;							// 使能定时器0，并清除复位
	return;
}


void __irq IRQ_Timer0(void){				//Timer0中断服务程序
	countDownNum -= 1;
	
	T0IR = 0x01;					// 清除Timer0中断标志寄存器IR的bit[0]MR0
	VICVectAddr = 0x00;		// 通知VIC中断处理结束

}


