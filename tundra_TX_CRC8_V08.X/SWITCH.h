#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>
#include "LED.h"

// 範例
// sw[POS].get();

typedef struct {
  uint8_t (*const get)(void);
  uint8_t (*const is_on)(void);
} SWITCH_t;

// 初始化函數
// extern const SWITCH_GROUP_t sw;
extern SWITCH_t const sw[LED_COUNT];
extern void swState_update(void);



#endif // SWITCH_H
