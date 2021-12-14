#include "beep.h"
#include "delay.h"

void beepInit(void) {
	PINSEL1 &= 0xFFFF3FFF;  // P0.23����GPIO
	IO0DIR |= BEEP;  // P0.23��������Ϊ���
}

void beepTimes(unsigned char num) {   // numΪ��Ĵ���
	while (num-- != 0) {
		IO0SET = BEEP;
		delay(10);
		IO0CLR = BEEP;
		delay(10);
	}
	return;
}
