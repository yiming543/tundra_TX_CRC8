#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H

#include "object_LED.h"
#include "object_SWITCH.h"
#include "tundra_PWM.h"

#define ON 1U
#define OFF 0U

// LED物件型態定義
// typedef void (*output_func)(void);
// typedef uint8_t (*input_func)(void);

typedef struct {
  LED_GROUP_t *led;
  SWITCH_GROUP_t *sw;
  FRAME_t *tundraData;
} BOARD_t;

// 初始化函數
extern void board_init(BOARD_t *obj);
extern void swSetLED(BOARD_t *board);
extern void swSetDATA(BOARD_t *board);
extern void obj_init(void);
// extern void Clear_No_Call_Warning(void);

extern BOARD_t board;

#endif // OBJECT_BOARD_H
