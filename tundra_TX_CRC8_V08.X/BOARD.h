#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H
#include "tundra_PWM.h"

// 初始化函數
extern void swSetLED(void);
extern void swSetDATA(FRAME_t const *tundra);
extern void board_init(void);
extern void swState_update(void);
#endif // OBJECT_BOARD_H
