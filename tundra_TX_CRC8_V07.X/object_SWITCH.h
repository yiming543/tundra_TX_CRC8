#ifndef OBJECT_SWITCH_H
#define OBJECT_SWITCH_H

#include <stdint.h>

// LED物件型態定義
// typedef void (*output_func)(void);
// typedef uint8_t (*input_func)(void);

typedef struct {
  uint8_t (*get)(void);
  uint8_t (*is_on)(void);
  uint8_t state;
} SWITCH_t;

typedef struct {
  SWITCH_t pos;
  SWITCH_t drl;
  SWITCH_t loBeam;
  SWITCH_t hiBeam;
  SWITCH_t turnLeft;
  SWITCH_t turnRight;
} SWITCH_GROUP_t;


// 初始化函數
extern SWITCH_GROUP_t obj_sw;
extern void SWITCH_init(SWITCH_GROUP_t *obj);
extern void swState_update(SWITCH_GROUP_t *obj);



#endif // OBJECT_SWITCH_H
