#ifndef _BEEP_H
#define _BEEP_H

#include "lpc213x.h"
#include "TypeDef.h"

#define BEEP ((uint32)(1 << 23))			// P0.23 控制 BEEP

void beepInit(void);  // 蜂鸣器初始化

void beepTimes(unsigned char);   // 控制蜂鸣器的动作

#endif
