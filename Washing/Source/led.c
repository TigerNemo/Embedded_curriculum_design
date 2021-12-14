#include "led.h"

void ledInit(void){					// 4��LED�ĳ�ʼ��
	PINSEL1 &= 0xFFFFFC03;  // 4��LED(P[17:20])���ӵ�GPIO
	IO0DIR |= LEDS;	  // P0[17:20]����Ϊ���	
	ledOff();		 // ��ʼ�����ʱ4��LEDȫ��
	return;
}

void ledOn(void){						//4��LED������P[17:20]����͵�ƽ
	IO0CLR = LEDS;
	return;
}
void ledOff(void){						//4��LED�𣬼�P[17:20]����ߵ�ƽ
	IO0SET = LEDS;
	return;
}

void led0On(void) {  // LED0 ��
	IO0CLR = LED0;
	return;
}
void led0Off(void) {  // LED0 ��
	IO0SET = LED0;
	return;
}

void led1On(void) {  // LED1 ��
	IO0CLR = LED1;
	return;
}
void led1Off(void) {  // LED1 ��
	IO0SET = LED1;
	return;
}

void led2On(void) {  // LED2 ��
	IO0CLR = LED2;
	return;
}
void led2Off(void) {  // LED2 ��
	IO0SET = LED2;
	return;
}

void led3On(void) {  // LED3 ��
	IO0CLR = LED3;
	return;
}
void led3Off(void) {  // LED3 ��
	IO0SET = LED3;
	return;
}

