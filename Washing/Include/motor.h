#ifndef MOTOR_H
#define MOTOR_H

#include "lpc213x.h"
#include "TypeDef.h"

#define SPEED_MAX 10000  // 转速最大值
#define SPEED_MID 6000  // 转速中间值
#define SPEED_MIN 3500  // 转速最小值

#define DIRECTION ((uint32)(1 << 8))  // P0.8控制电机的方向

void motorInit(void);  // 电机初始化

void motorSpeed(int);  // 控制速度及转向。speed为负数时反转，为正数时正转


#endif
