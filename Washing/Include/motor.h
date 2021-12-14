#ifndef MOTOR_H
#define MOTOR_H

#include "lpc213x.h"
#include "TypeDef.h"

#define SPEED_MAX 10000  // ת�����ֵ
#define SPEED_MID 6000  // ת���м�ֵ
#define SPEED_MIN 3500  // ת����Сֵ

#define DIRECTION ((uint32)(1 << 8))  // P0.8���Ƶ���ķ���

void motorInit(void);  // �����ʼ��

void motorSpeed(int);  // �����ٶȼ�ת��speedΪ����ʱ��ת��Ϊ����ʱ��ת


#endif
