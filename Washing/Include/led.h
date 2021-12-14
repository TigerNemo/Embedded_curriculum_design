#ifndef _LED_H
#define _LED_H

#include "lpc213x.h"
#include "TypeDef.h"

#define LEDS ((uint32)(0xF << 17))			// 4个LED对应P0[17:20]，低有效
#define LED0 ((uint32)(1 << 17))
#define LED1 ((uint32)(1 << 18))
#define LED2 ((uint32)(1 << 19))
#define LED3 ((uint32)(1 << 20))

void ledInit(void);						// 4各LED的初始化
void ledOn(void);							// 4个LED亮，即P0[17:20]输出低电平
void ledOff(void);							// 4个LED灭，即P0[17:20]输出高电平

// LED0亮灭
void led0On(void);
void led0Off(void);

// LED1亮灭
void led1On(void);
void led1Off(void);

// LED2亮灭
void led2On(void);
void led2Off(void);

// LED3亮灭
void led3On(void);
void led3Off(void);


#endif
