#include "SWITCH.h"

#include "mcc_generated_files/pin_manager.h"

// 1. 定義私有開關索引，方便統一管理狀態陣列
// typedef enum {
//   POS = 0U,
//   DRL,
//   LO_BEAM,
//   HI_BEAM,
//   TURN_LEFT,
//   TURN_RIGHT,
//   LED_COUNT,
// } Led_t;

#define ON (1U)
#define OFF (0U)

// 2. 【真正的 Private 狀態變數】僅佔用 6 Bytes RAM，外部完全無法直接修改
static uint8_t sw_states[LED_COUNT] = {
    OFF, OFF, OFF, OFF, OFF, OFF};

// 3. 內部硬體操作函式（加上 static 隱藏於此檔案內部）
static uint8_t SW_POS_GET(void) {
  // return (uint8_t)(!!(SW1_GetValue() == OFF));
  return (uint8_t)(!!(SW1_GetValue() == OFF));
}

static uint8_t SW_DRL_GET(void) {
  return (uint8_t)(!!(SW2_GetValue() == OFF));
}

static uint8_t SW_LO_BEAM_GET(void) {
  return (uint8_t)(!!(SW3_GetValue() == OFF));
}

static uint8_t SW_HI_BEAM_GET(void) {
  return (uint8_t)(!!(SW4_GetValue() == OFF));
}

static uint8_t SW_TURN_LEFT_GET(void) {
  return (uint8_t)(!!(SW5_GetValue() == OFF));
}

static uint8_t SW_TURN_RIGHT_GET(void) {
  return (uint8_t)(!!(SW6_GetValue() == OFF));
}

static uint8_t SW_POS_IS_ON(void) {
  return sw_states[POS];
}

static uint8_t SW_DRL_IS_ON(void) {
  return sw_states[DRL];
}

static uint8_t SW_LO_BEAM_IS_ON(void) {
  return sw_states[LO_BEAM];
}

static uint8_t SW_HI_BEAM_IS_ON(void) {
  return sw_states[HI_BEAM];
}

static uint8_t SW_TURN_LEFT_IS_ON(void) {
  return sw_states[TURN_LEFT];
}

static uint8_t SW_TURN_RIGHT_IS_ON(void) {
  return sw_states[TURN_RIGHT];
}

// 4. 編譯期靜態初始化物件（存放於 Flash 唯讀區）
SWITCH_t const sw[LED_COUNT] = {
    [POS] = {.get = SW_POS_GET, .is_on = SW_POS_IS_ON},
    [DRL] = {.get = SW_DRL_GET, .is_on = SW_DRL_IS_ON},
    [LO_BEAM] = {.get = SW_LO_BEAM_GET, .is_on = SW_LO_BEAM_IS_ON},
    [HI_BEAM] = {.get = SW_HI_BEAM_GET, .is_on = SW_HI_BEAM_IS_ON},
    [TURN_LEFT] = {.get = SW_TURN_LEFT_GET, .is_on = SW_TURN_LEFT_IS_ON},
    [TURN_RIGHT] = {.get = SW_TURN_RIGHT_GET, .is_on = SW_TURN_RIGHT_IS_ON}};

// 5. 開機硬體狀態同步函式
// void SW_Init(void) {
//   sw.pos.get();
//   sw.drl.get();
//   sw.loBeam.get();
//   sw.hiBeam.get();
//   sw.turnLeft.get();
//   sw.turnRight.get();
// }

void swState_update(void) {
  sw_states[POS] = sw[POS].get();
  sw_states[DRL] = sw[DRL].get();
  sw_states[LO_BEAM] = sw[LO_BEAM].get();
  sw_states[HI_BEAM] = sw[HI_BEAM].get();
  sw_states[TURN_LEFT] = sw[TURN_LEFT].get();
  sw_states[TURN_RIGHT] = sw[TURN_RIGHT].get();
}