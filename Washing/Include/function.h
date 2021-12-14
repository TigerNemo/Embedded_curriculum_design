#ifndef FUNCTION_H
#define FUNCTION_H

#include "TypeDef.h"
#include "digitaltube.h"
#include "CountDown.h"

volatile extern unsigned char flag;


/* 慢洗功能函数 */
void functionModel1(void);
/* 快洗功能函数 */
void functionModel2(void);
/* 脱水功能函数 */
void functionModel3(void);

void menu(void);

#endif
