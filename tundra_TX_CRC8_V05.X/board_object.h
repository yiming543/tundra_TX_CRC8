#ifndef BOARD_OBJECT_H
#define BOARD_OBJECT_H

#include "tundra_data.h"
// #include <stdint.h>

#define ON 1
#define OFF 0

// LED物件型態定義
// typedef void (*output_func)(void);
// typedef uint8_t (*input_func)(void);

typedef struct {
  void (*on)(void);
  void (*off)(void);
  bool (*is_on)(void);
} LED_t;

typedef struct {
  bool (*get)(void);
  bool (*is_on)(void);
} SWITCH_t;

typedef struct {
  LED_t pos;
  LED_t drl;
  LED_t loBeam;
  LED_t hiBeam;
  LED_t turnLeft;
  LED_t turnRight;
} LED_GROUP_t;

typedef struct {
  SWITCH_t pos;
  SWITCH_t drl;
  SWITCH_t loBeam;
  SWITCH_t hiBeam;
  SWITCH_t turnLeft;
  SWITCH_t turnRight;
} SWITCH_GROUP_t;

typedef struct {
  LED_GROUP_t led;
  SWITCH_GROUP_t sw;
} BOARD_t;

typedef struct {
  unsigned pos : 1;
  unsigned drl : 1;
  unsigned loBeam : 1;
  unsigned hiBeam : 1;
  unsigned turnLeft : 1;
  unsigned turnRight : 1;
} FLAG_t;

typedef struct {
  FLAG_t sw;
  FLAG_t led;
} STATE_t;

// 初始化函數
extern void board_init(BOARD_t *obj);
extern void swState_update(BOARD_t *obj);
extern void Check_Input(BOARD_t *board, FRAME_t *data);

extern BOARD_t board;

#endif // BOARD_OBJECT_H
