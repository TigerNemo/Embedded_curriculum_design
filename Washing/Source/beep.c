#include "beep.h"
#include "delay.h"

void beepInit(void) {
	PINSEL1 &= 0xFFFF3FFF;  // P0.23配置GPIO
	IO0DIR |= BEEP;  // P0.23方向设置为输出
}

void beepTimes(unsigned char num) {   // num为响的次数
	while (num-- != 0) {
		IO0SET = BEEP;
		delay(10);
		IO0CLR = BEEP;
		delay(10);
	}
	return;
}
