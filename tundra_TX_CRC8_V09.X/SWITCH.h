#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>

// 範例
// sw[POS].get();

typedef struct {
  uint8_t (*const get)(void);
  uint8_t (*const is_on)(void);
} SWITCH_t;

typedef struct {
  SWITCH_t pos;
  SWITCH_t drl;
  SWITCH_t loBeam;
  SWITCH_t hiBeam;
  SWITCH_t turnLeft;
  SWITCH_t turnRight;
} SWITCHs_t;

// 初始化函數
// extern const SWITCH_GROUP_t sw;
extern const SWITCHs_t sw;
extern void swState_update(void);



#endif // SWITCH_H
