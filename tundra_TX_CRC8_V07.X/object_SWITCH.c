#include "object_SWITCH.h"
#include "mcc_generated_files/pin_manager.h"

// 全域變數
SWITCH_GROUP_t obj_sw;

// 每種燈綁定現有 SetHigh/SetLow
static uint8_t SW_POS_IS_ON(void) { return obj_sw.pos.state; }
static uint8_t SW_DRL_IS_ON(void) { return obj_sw.drl.state; }
static uint8_t SW_LOBEAM_IS_ON(void) { return obj_sw.loBeam.state; }
static uint8_t SW_HIBEAM_IS_ON(void) { return obj_sw.hiBeam.state; }
static uint8_t SW_TURN_LEFT_IS_ON(void) { return obj_sw.turnLeft.state; }
static uint8_t SW_TURN_RIGHT_IS_ON(void) { return obj_sw.turnRight.state; }

void SWITCH_init(SWITCH_GROUP_t *obj) {
  obj->pos.is_on = SW_POS_IS_ON;
  obj->drl.is_on = SW_DRL_IS_ON;
  obj->loBeam.is_on = SW_LOBEAM_IS_ON;
  obj->hiBeam.is_on = SW_HIBEAM_IS_ON;
  obj->turnLeft.is_on = SW_TURN_LEFT_IS_ON;
  obj->turnRight.is_on = SW_TURN_RIGHT_IS_ON;
}

void swState_update(SWITCH_GROUP_t *obj) {
  obj->pos.state = (SW1_GetValue() == LOW) ? 1 : 0;
  obj->drl.state = (SW2_GetValue() == LOW) ? 1 : 0;
  obj->loBeam.state = (SW3_GetValue() == LOW) ? 1 : 0;
  obj->hiBeam.state = (SW4_GetValue() == LOW) ? 1 : 0;
  obj->turnLeft.state = (SW5_GetValue() == LOW) ? 1 : 0;
  obj->turnRight.state = (SW6_GetValue() == LOW) ? 1 : 0;
}