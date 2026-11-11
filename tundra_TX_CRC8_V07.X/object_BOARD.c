
#include "object_BOARD.h"

//for Clear_No_Call_Warning
#include "mcc_generated_files/epwm3.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr2.h"

#define ON 1U
#define OFF 0U

#define data_length 8U

#define D2_POS_MASK 2
#define D2_DRL_MASK 3
#define D2_LOBEAM_MASK 4
#define D2_HIBEAM_MASK 5

#define D3_TURN_LEFT_MASK 5
#define D3_TURN_RIGHT_MASK 6

#define BIT_SET(number, n) ((number) |= (1U << (n)))
#define BIT_CLR(number, n) ((number) &= ~(1U << (n)))

//全域變數
BOARD_t board;

void board_init(BOARD_t *obj) {
  obj->led = &obj_led;
  obj->sw = &obj_sw;
  obj->tundraData = &tundra_data;
}

void swSetLED(BOARD_t *board) {
  // 行車
  if (board->sw->pos.is_on() == ON) {
    board->led->pos.on();
  } else {
    board->led->pos.off();
  }

  // 晝行
  if (board->sw->drl.is_on() == ON) {
    board->led->drl.on();
  } else {
    board->led->drl.off();
  }

  // 近燈
  if (board->sw->loBeam.is_on() == ON) {
    board->led->loBeam.on();
  } else {
    board->led->loBeam.off();
  }

  // 遠燈
  if (board->sw->hiBeam.is_on() == ON) {
    board->led->hiBeam.on();
  } else {
    board->led->hiBeam.off();
  }

  // 左方向燈
  if (board->sw->turnLeft.is_on() == ON) {
    board->led->turnLeft.on();
  } else {
    board->led->turnLeft.off();
  }

  // 右方向燈
  if (board->sw->turnRight.is_on() == ON) {
    board->led->turnRight.on();
  } else {
    board->led->turnRight.off();
  }

}

void swSetDATA(BOARD_t *board) {
  // 行車
  uint8_t D2 = 0;
  uint8_t D3 = 0;

  if (board->sw->pos.is_on() == ON) {
    BIT_SET(D2, D2_POS_MASK);
  } else {
    BIT_CLR(D2, D2_POS_MASK);
  }

  // 晝行
  if (board->sw->drl.is_on() == ON) {
    BIT_SET(D2, D2_DRL_MASK);
  } else {
    BIT_CLR(D2, D2_DRL_MASK);
  }

  // 近燈
  if (board->sw->loBeam.is_on() == ON) {
    BIT_SET(D2, D2_LOBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_LOBEAM_MASK);
  }

  // 遠燈
  if (board->sw->hiBeam.is_on() == ON) {
    BIT_SET(D2, D2_HIBEAM_MASK);
  } else {
    BIT_CLR(D2, D2_HIBEAM_MASK);
  }

  // 左方向燈
  if (board->sw->turnLeft.is_on() == ON) {
    BIT_SET(D3, D3_TURN_LEFT_MASK);
  } else {
    BIT_CLR(D3, D3_TURN_LEFT_MASK);
  }

  // 右方向燈
  if (board->sw->turnRight.is_on() == ON) {
    BIT_SET(D3, D3_TURN_RIGHT_MASK);
  } else {
    BIT_CLR(D3, D3_TURN_RIGHT_MASK);
  }

  board->tundraData->data[0] = D2;
  board->tundraData->data[1] = D3;
  board->tundraData->CRC = board->tundraData->cal_crc8(&board->tundraData->data[0], data_length);
}

// 消除未呼叫警告 假裝有使用這些函數
void Clear_No_Call_Warning(void) {
  uint8_t i = 0U;
  if (i == 1U) {
    PIN_MANAGER_IOC();
  } else if (i == 2U) {
    EPWM3_LoadDutyValue(0);
  } else if (i == 3U) {
    TMR2_StartTimer();
    TMR2_StopTimer();
    uint8_t tmp = TMR2_ReadTimer();
    TMR2_WriteTimer(0);
    TMR2_LoadPeriodRegister(0);
    bool bit = TMR2_HasOverflowOccured();
  } else {
  }
}

void obj_init(void) {
  SWITCH_init(&obj_sw);
  LED_init(&obj_led);
  swState_update(&obj_sw);
  tundra_init(&tundra_data);
  board_init(&board);
  Clear_No_Call_Warning();
}