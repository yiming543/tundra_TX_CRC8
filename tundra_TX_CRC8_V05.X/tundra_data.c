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
  data->id = 0xC8;     // 車燈信號
  data->length = 0x8B; // 8 byte
  data->data[0] = 0;
  data->data[1] = 0;
  data->data[2] = 0;
  data->data[3] = 0;
  data->data[4] = 0;
  data->data[5] = 0;
  data->data[6] = 0;
  data->data[7] = 0;
  data->crc = 0x04C; // check sum
}

void Transmit_data(FRAME_t *data) {
  for (uint8_t i = 0; i < buf_length; i++) {
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
    TMR2_ReadTimer();
    TMR2_WriteTimer(0);
    TMR2_LoadPeriodRegister(0);
    TMR2_HasOverflowOccured();
  } else if (i == 4U) {
  }
}