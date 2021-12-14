#ifndef _LED_H
#define _LED_H

#include "lpc213x.h"
#include "TypeDef.h"

#define LEDS ((uint32)(0xF << 17))			// 4��LED��ӦP0[17:20]������Ч
#define LED0 ((uint32)(1 << 17))
#define LED1 ((uint32)(1 << 18))
#define LED2 ((uint32)(1 << 19))
#define LED3 ((uint32)(1 << 20))

void ledInit(void);						// 4��LED�ĳ�ʼ��
void ledOn(void);							// 4��LED������P0[17:20]����͵�ƽ
void ledOff(void);							// 4��LED�𣬼�P0[17:20]����ߵ�ƽ

// LED0����
void led0On(void);
void led0Off(void);

// LED1����
void led1On(void);
void led1Off(void);

// LED2����
void led2On(void);
void led2Off(void);

// LED3����
void led3On(void);
void led3Off(void);


#endif
