#include "TypeDef.h"
#include "lpc213x.h"

// 按键与GPIO的对应关系
#define KEY1 ((uint32)(1 << 16))
#define KEY2 ((uint32)(1 << 14))
#define KEY3 ((uint32)(1 << 15))
#define KEYS ((uint32)(7 << 14))

// 按键信号
#define KEY1_F ((unsigned char)(0x01))
#define KEY2_F ((unsigned char)(0x02))
#define KEY3_F ((unsigned char)(0x03))

void keyInit(void);  // 按键初始化
unsigned char keyScan(void);  // 检测按键用扫描的方式
