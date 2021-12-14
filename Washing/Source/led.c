#include "led.h"

void ledInit(void){					// 4个LED的初始化
	PINSEL1 &= 0xFFFFFC03;  // 4个LED(P[17:20])连接到GPIO
	IO0DIR |= LEDS;	  // P0[17:20]设置为输出	
	ledOff();		 // 初始化完成时4个LED全灭
	return;
}

void ledOn(void){						//4个LED亮，即P[17:20]输出低电平
	IO0CLR = LEDS;
	return;
}
void ledOff(void){						//4个LED灭，即P[17:20]输出高电平
	IO0SET = LEDS;
	return;
}

void led0On(void) {  // LED0 亮
	IO0CLR = LED0;
	return;
}
void led0Off(void) {  // LED0 灭
	IO0SET = LED0;
	return;
}

void led1On(void) {  // LED1 亮
	IO0CLR = LED1;
	return;
}
void led1Off(void) {  // LED1 灭
	IO0SET = LED1;
	return;
}

void led2On(void) {  // LED2 亮
	IO0CLR = LED2;
	return;
}
void led2Off(void) {  // LED2 灭
	IO0SET = LED2;
	return;
}

void led3On(void) {  // LED3 亮
	IO0CLR = LED3;
	return;
}
void led3Off(void) {  // LED3 灭
	IO0SET = LED3;
	return;
}

