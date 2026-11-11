/*
 * File:   DATA_define.c
 * Author: T00904
 *
 * Created on November 5, 2026, 10:51 AM
 */
#include "tundra_data.h"
#include "mcc_generated_files/epwm3.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr2.h"
#include "tundra_PWM.h"

void tundra_init(FRAME_t *data) {
  data->buf[0] = 0xC8; // 車燈信號
  data->buf[1] = 0x8B; // 8 byte
  data->buf[2] = 0;
  data->buf[3] = 0;
  data->buf[4] = 0;
  data->buf[5] = 0;
  data->buf[6] = 0;
  data->buf[7] = 0;
  data->buf[8] = 0;
  data->buf[9] = 0;
  data->buf[10] = 0x04C; // check sum
}

void Transmit_data(FRAME_t *data) {
  for (uint8_t i = 0U; i < buf_length; i++) {
    PWM(data->buf[i]);
  }
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
  } else{
      
  }
}