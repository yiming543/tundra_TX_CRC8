
#include "object_BOARD.h"

#include "LED.h"
#include "SWITCH.h"
#include "tundra_PWM.h"
#include "tundra_crc8.h"

#define ON (1U)
#define OFF (0U)

#define data_length (8U)

#define D2_POS_MASK (2)
#define D2_DRL_MASK (3)
#define D2_LOBEAM_MASK (4)
#define D2_HIBEAM_MASK (5)

#define D3_TURN_LEFT_MASK (5)
#define D3_TURN_RIGHT_MASK (6)

#define BIT_SET(number, n) ((number) |= (1U << (n)))
#define BIT_CLR(number, n) ((number) &= ~(1U << (n)))

// 全域變數

void swSetLED(void) {
  // 用switch控制LED
  if (sw[POS].is_on() == ON) {
    led[POS].on();
  } else {
    led[POS].off();
  }

  if (sw[DRL].is_on() == ON) {
    led[DRL].on();
  } else {
    led[DRL].off();
  }
  if (sw[LO_BEAM].is_on() == ON) {
    led[LO_BEAM].on();
  } else {
    led[LO_BEAM].off();
  }
  if (sw[HI_BEAM].is_on() == ON) {
    led[HI_BEAM].on();
  } else {
    led[HI_BEAM].off();
  }
  if (sw[TURN_LEFT].is_on() == ON) {
    led[TURN_LEFT].on();
  } else {
    led[TURN_LEFT].off();
  }
  if (sw[TURN_RIGHT].is_on() == ON) {
    led[TURN_RIGHT].on();
  } else {
    led[TURN_RIGHT].off();
  }
}

void swSetDATA(FRAME_t const *data) {
  // 用switch控制資料
  //  行車
  uint8_t D2 = 0;
  uint8_t D3 = 0;

  if (sw[POS].is_on() == ON) {
    BIT_SET(D2, D2_POS_MASK);
  } else {
    BIT_CLR(D2, D2_POS_MASK);
  }

  // 晝行
  if (sw[DRL].is_on() == ON) {
    BIT_SET(D2, D2_DRL_MASK);
  } else {
    BIT_CLR(D2, D2_DRL_MASK);
  }

  // 近燈
  if (sw[LO_BEAM].is_on() == ON) {
    BIT_SET(D2, D2_LOBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_LOBEAM_MASK);
  }

  // 遠燈
  if (sw[HI_BEAM].is_on() == ON) {
    BIT_SET(D2, D2_HIBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_HIBEAM_MASK);
  }

  // 左方向燈
  if (sw[TURN_LEFT].is_on() == ON) {
    BIT_SET(D3, D3_TURN_LEFT_MASK);
  } else {
    BIT_CLR(D3, D3_TURN_LEFT_MASK);
  }

  // 右方向燈
  if (sw[TURN_RIGHT].is_on() == ON) {
    BIT_SET(D3, D3_TURN_RIGHT_MASK);
  } else {
    BIT_CLR(D3, D3_TURN_RIGHT_MASK);
  }

  uint8_t tmp[8]={0};
   tmp[0] = D2;
   tmp[1] = D3;
   data->data.set(tmp);
   data->crc.set(calculate_crc8(tmp,data_length));
}
