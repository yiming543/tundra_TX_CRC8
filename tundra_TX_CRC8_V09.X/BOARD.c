
#include "BOARD.h"
#include "LED.h"
#include "SWITCH.h"
#include "tundra_crc8.h"
#include "Warning_ignored.h"

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

void board_init(void) {
  LED_Init();
  Clear_No_Call_Warning();
  swState_update();
}

void swSetLED(void) {
  // 用switch控制LED
  if (sw.pos.is_on() == ON) {
    led.pos.on();
  } else {
    led.pos.off();
  }

  if (sw.drl.is_on() == ON) {
    led.drl.on();
  } else {
    led.drl.off();
  }
  if (sw.loBeam.is_on() == ON) {
    led.loBeam.on();
  } else {
    led.loBeam.off();
  }
  if (sw.hiBeam.is_on() == ON) {
    led.hiBeam.on();
  } else {
    led.hiBeam.off();
  }
  if (sw.turnLeft.is_on() == ON) {
    led.turnLeft.on();
  } else {
    led.turnLeft.off();
  }
  if (sw.turnRight.is_on() == ON) {
    led.turnRight.on();
  } else {
    led.turnRight.off();
  }
}

void swSetDATA(FRAME_t const *data) {
  // 用switch控制資料
  //  行車
  uint8_t D2 = 0;
  uint8_t D3 = 0;

  if (sw.pos.is_on() == ON) {
    BIT_SET(D2, D2_POS_MASK);
  } else {
    BIT_CLR(D2, D2_POS_MASK);
  }

  // 晝行
  if (sw.drl.is_on() == ON) {
    BIT_SET(D2, D2_DRL_MASK);
  } else {
    BIT_CLR(D2, D2_DRL_MASK);
  }

  // 近燈
  if (sw.loBeam.is_on() == ON) {
    BIT_SET(D2, D2_LOBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_LOBEAM_MASK);
  }

  // 遠燈
  if (sw.hiBeam.is_on() == ON) {
    BIT_SET(D2, D2_HIBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_HIBEAM_MASK);
  }

  // 左方向燈
  if (sw.turnLeft.is_on() == ON) {
    BIT_SET(D3, D3_TURN_LEFT_MASK);
  } else {
    BIT_CLR(D3, D3_TURN_LEFT_MASK);
  }

  // 右方向燈
  if (sw.turnRight.is_on() == ON) {
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
