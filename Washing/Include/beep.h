#ifndef _BEEP_H
#define _BEEP_H

#include "lpc213x.h"
#include "TypeDef.h"

#define BEEP ((uint32)(1 << 23))			// P0.23 ���� BEEP

void beepInit(void);  // ��������ʼ��

void beepTimes(unsigned char);   // ���Ʒ������Ķ���

#endif
