#ifndef _DIGITALTUBE_H
#define _DIGITALTUBE_H

#include "lpc213x.h"
#include "TypeDef.h"

#define DIGITALTUBE_A ((uint32)(1 << 27))  // P0.27 -- a
#define DIGITALTUBE_B ((uint32)(1 << 25))  // P0.25 -- b
#define DIGITALTUBE_C ((uint32)(1 << 30))  // P0.30 -- c
#define DIGITALTUBE_D ((uint32)(1 << 28))  // P0.28 -- d
#define DIGITALTUBE_E ((uint32)(1 << 26))  // P0.26 -- e
#define DIGITALTUBE_F ((uint32)(1 << 29))  // P0.29 -- f
#define DIGITALTUBE_G ((uint32)(1 << 31))  // P0.31 -- g

#define DIGITALTUBE_GPIO ((uint32)(0xFE000000))  // P[31:25]  数码管端口与GPIO的映射
#define DIGITALTUBE_0 ((uint32)(0x7E000000))  // 数码管显示数字 0
#define DIGITALTUBE_1 ((uint32)(0x42000000))  // 数码管显示数字 1
#define DIGITALTUBE_2 ((uint32)(0x9E000000))  // 数码管显示数字 2
#define DIGITALTUBE_3 ((uint32)(0xDA000000))  // 数码管显示数字 3
#define DIGITALTUBE_4 ((uint32)(0xE2000000))  // 数码管显示数字 4
#define DIGITALTUBE_5 ((uint32)(0xF8000000))  // 数码管显示数字 5
#define DIGITALTUBE_6 ((uint32)(0xFC000000))  // 数码管显示数字 6
#define DIGITALTUBE_7 ((uint32)(0x4A000000))  // 数码管显示数字 7
#define DIGITALTUBE_8 ((uint32)(0xFE000000))  // 数码管显示数字 8
#define DIGITALTUBE_9 ((uint32)(0xFA000000))  // 数码管显示数字 9

// 数码管显示数字0
#define digitalTubeShow0() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_0;\
}
// 数码管显示数字1
#define digitalTubeShow1() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_1;\
}
// 数码管显示数字2
#define digitalTubeShow2() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_2;\
}
// 数码管显示数字3
#define digitalTubeShow3() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_3;\
}
// 数码管显示数字4
#define digitalTubeShow4() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_4;\
}
// 数码管显示数字5
#define digitalTubeShow5() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_5;\
}
// 数码管显示数字6
#define digitalTubeShow6() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_6;\
}
// 数码管显示数字7
#define digitalTubeShow7() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_7;\
}
// 数码管显示数字8
#define digitalTubeShow8() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_8;\
}
// 数码管显示数字9
#define digitalTubeShow9() {\
	IO0CLR = DIGITALTUBE_GPIO;\
	IO0SET = DIGITALTUBE_9;\
}

void digitalTubeInit(void);  // 数码管初始化
void digitalTubeShow(unsigned char);  // 数码管显示数字

#endif
