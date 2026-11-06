#include "board_object.h"
#include "mcc_generated_files/pin_manager.h"
#include "tundra_crc8.h"

static STATE_t state = {0};

// 每種燈綁定現有 SetHigh/SetLow
static void POS_ON(void) {
  if (state.led.pos == 0) {
    LED1_SetHigh();
    state.led.pos = 1;
  }
}
static void POS_OFF(void) {
  if (state.led.pos != 0) {
    LED1_SetLow();
    state.led.pos = 0;
  }
}
static void DRL_ON(void) {
  if (state.led.drl == 0) {
    LED2_SetHigh();
    state.led.drl = 1;
  }
}
static void DRL_OFF(void) {
  if (state.led.drl != 0) {
    LED2_SetLow();
    state.led.drl = 0;
  }
}

static void LOBEAM_ON(void) {
  if (state.led.loBeam == 0) {
    LED3_SetHigh();
    state.led.loBeam = 1;
  }
}

static void LOBEAM_OFF(void) {
  if (state.led.loBeam != 0) {
    LED3_SetLow();
    state.led.loBeam = 1;
  }
}

static void HIBEAM_ON(void) {
  if (state.led.hiBeam == 0) {
    LED4_SetHigh();
    state.led.hiBeam = 1;
  }
}

static void HIBEAM_OFF(void) {
  if (state.led.hiBeam != 0) {
    LED4_SetLow();
    state.led.hiBeam = 1;
  }
}

static void TURN_LEFT_ON(void) {
  if (state.led.turnLeft == 0) {
    LED5_SetHigh();
    state.led.turnLeft = 1;
  }
}

static void TURN_LEFT_OFF(void) {
  if (state.led.turnLeft != 0) {
    LED5_SetLow();
    state.led.turnLeft = 0;
  }
}

static void TURN_RIGHT_ON(void) {
  if (state.led.turnRight == 0) {
    LED6_SetHigh();
    state.led.turnRight = 1;
  }
}

static void TURN_RIGHT_OFF(void) {
  if (state.led.turnRight != 0) {
    LED6_SetLow();
    state.led.turnRight = 0;
  }
}

static bool SW1_pressed(void) {
  state.sw.pos = SW1_GetValue() == LOW ? 1 : 0;
  return state.sw.pos;
}

static bool SW2_pressed(void) {
  state.sw.drl = SW2_GetValue() == LOW ? 1 : 0;
  return state.sw.drl;
}

static bool SW3_pressed(void) {
  state.sw.loBeam = SW3_GetValue() == LOW ? 1 : 0;
  return state.sw.loBeam;
}

static bool SW4_pressed(void) {
  state.sw.hiBeam = SW4_GetValue() == LOW ? 1 : 0;
  return state.sw.hiBeam;
}

static bool SW5_pressed(void) {
  state.sw.turnLeft = SW5_GetValue() == LOW ? 1 : 0;
  return state.sw.turnLeft;
}

static bool SW6_pressed(void) {
  state.sw.turnRight = SW6_GetValue() == LOW ? 1 : 0;
  return state.sw.turnRight;
}

static bool LED_POS_IS_ON(void) { return state.led.pos; }
static bool LED_DRL_IS_ON(void) { return state.led.drl; }
static bool LED_LOBEAM_IS_ON(void) { return state.led.loBeam; }
static bool LED_HIBEAM_IS_ON(void) { return state.led.hiBeam; }
static bool LED_TURN_LEFT_IS_ON(void) { return state.led.turnLeft; }
static bool LED_TURN_RIGHT_IS_ON(void) { return state.led.turnRight; }
static bool SW_POS_IS_ON(void) { return state.sw.pos; }
static bool SW_DRL_IS_ON(void) { return state.sw.drl; }
static bool SW_LOBEAM_IS_ON(void) { return state.sw.loBeam; };
static bool SW_HIBEAM_IS_ON(void) { return state.sw.hiBeam; };
static bool SW_TURN_LEFT_IS_ON(void) { return state.sw.turnLeft; }
static bool SW_TURN_RIGHT_IS_ON(void) { return state.sw.turnRight; }

void swState_update(BOARD_t *obj) {
  state.sw.pos = obj->sw.pos.get();
  state.sw.drl = obj->sw.drl.get();
  state.sw.loBeam = obj->sw.loBeam.get();
  state.sw.hiBeam = obj->sw.hiBeam.get();
  state.sw.turnLeft = obj->sw.turnLeft.get();
  state.sw.turnRight = obj->sw.turnRight.get();
}

void board_init(BOARD_t *obj) {
  obj->led.pos.on = POS_ON;
  obj->led.pos.off = POS_OFF;
  obj->led.drl.on = DRL_ON;
  obj->led.drl.off = DRL_OFF;
  obj->led.loBeam.on = LOBEAM_ON;
  obj->led.loBeam.off = LOBEAM_OFF;
  obj->led.hiBeam.on = HIBEAM_ON;
  obj->led.hiBeam.off = HIBEAM_OFF;
  obj->led.turnLeft.on = TURN_LEFT_ON;
  obj->led.turnLeft.off = TURN_LEFT_OFF;
  obj->led.turnRight.on = TURN_RIGHT_ON;
  obj->led.turnRight.off = TURN_RIGHT_OFF;

  obj->sw.pos.get = SW1_pressed;
  obj->sw.drl.get = SW2_pressed;
  obj->sw.loBeam.get = SW3_pressed;
  obj->sw.hiBeam.get = SW4_pressed;
  obj->sw.turnLeft.get = SW5_pressed;
  obj->sw.turnRight.get = SW6_pressed;

  obj->led.pos.is_on = LED_POS_IS_ON;
  obj->led.drl.is_on = LED_DRL_IS_ON;
  obj->led.loBeam.is_on = LED_LOBEAM_IS_ON;
  obj->led.hiBeam.is_on = LED_HIBEAM_IS_ON;
  obj->led.turnLeft.is_on = LED_TURN_LEFT_IS_ON;
  obj->led.turnRight.is_on = LED_TURN_RIGHT_IS_ON;

  obj->sw.pos.is_on = SW_POS_IS_ON;
  obj->sw.drl.is_on = SW_DRL_IS_ON;
  obj->sw.loBeam.is_on = SW_LOBEAM_IS_ON;
  obj->sw.hiBeam.is_on = SW_HIBEAM_IS_ON;
  obj->sw.turnLeft.is_on = SW_TURN_LEFT_IS_ON;
  obj->sw.turnRight.is_on = SW_TURN_RIGHT_IS_ON;

  swState_update(obj);
}

void Check_Input(BOARD_t *board, FRAME_t *data) {

  // 行車
  if (board->sw.pos.is_on() == ON) {
    board->led.pos.on();
    data->D2.pos = 1;
  } else {
    board->led.pos.off();
    data->D2.pos = 0;
  }

  // 晝行
  if (board->sw.drl.is_on() == ON) {
    board->led.drl.on();
    data->D2.drl = 1;
  } else {
    board->led.drl.off();
    data->D2.drl = 0;
  }

  // 近燈
  if (board->sw.loBeam.is_on() == ON) {
    board->led.loBeam.on();
    data->D2.loBeam = 1;
  } else {
    board->led.loBeam.off();
    data->D2.loBeam = 0;
  }

  // 遠燈
  if (board->sw.hiBeam.is_on() == ON) {
    board->led.hiBeam.on();
    data->D2.hiBeam = 1;
  } else {
    board->led.hiBeam.off();
    data->D2.hiBeam = 0;
  }

  // 左方向燈
  if (board->sw.turnLeft.is_on() == ON) {
    board->led.turnLeft.on();
    data->D3.turnLeft = 1;
  } else {
    board->led.turnLeft.off();
    data->D3.turnLeft = 0;
  }

  // 右方向燈
  if (board->sw.turnRight.is_on() == ON) {
    board->led.turnRight.on();
    data->D3.turnRight = 1;
  } else {
    board->led.turnRight.off();
    data->D3.turnRight = 0;
  }

  data->crc = calculate_crc8(data->data, data_length);
}
