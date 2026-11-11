/*
 * File:   tundra_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 10:54 AM
 */

#include "tundra_PWM.h"
#include "tundra_crc8.h"
#include <xc.h>


#define PWM_HIGH_PULSE 112U
#define PWM_LOW_PULSE 225U
#define PWM_BITS 8U
#define buf_length 11U

// 全域變數
FRAME_t tundra_data;

void tundra_init(FRAME_t *data) {
  data->cal_crc8 = &calculate_crc8;
  data->ID = 0xC8;     // 車燈信號
  data->LENGTH = 0x8B; // 8 byte
  for (uint8_t i = 0U; i < 8U; i++) {
    data->data[i] = 0U;
  }

  data->CRC = 0x04C; // check sum
}

void wait_for_pwm_cycle_complete(void) {
  while (!TMR2IF) {
  }

  TMR2IF = 0;
}

void pwm_set_bit(unsigned char bit_value) {
  unsigned int duty;
  if (bit_value == 1U) {
    //   CCPR3L = 30;
    duty = PWM_HIGH_PULSE; // bit=1 duty ≈ 27% → 14 µs
  } else {
    duty = PWM_LOW_PULSE; // bit=0 duty ≈ 54% → 28 µs
    // CCPR3L = 55;
  }
  CCPR3L = (duty >> 2U) & 0xFFU;
  CCP3CONbits.DC3B = duty & 3U;
}

void PWM(unsigned char buf) {
  wait_for_pwm_cycle_complete();
  // start  bit
  pwm_set_bit(0);

  // data bit
  for (uint8_t i = 0U; i < PWM_BITS; i++) {
    wait_for_pwm_cycle_complete(); // 每位元時間
    pwm_set_bit((buf >> i) & 1U);
  }

  // stop bit
  wait_for_pwm_cycle_complete();
  pwm_set_bit(1U);

  // byte 間隔：送出 8 個 bit=1
  for (uint8_t j = 0U; j < 8U; j++) {
    wait_for_pwm_cycle_complete();
    pwm_set_bit(1);
  }
}

void Transmit_data(FRAME_t *data) {
  uint8_t buf[11];

  buf[0] = data->ID;
  buf[1] = data->LENGTH;
  for(uint8_t i=0U;i<8U;i++){
    buf[i+2U] = data->data[i];
  }
  buf[10] = data->CRC;
  
  for (uint8_t i = 0U; i < buf_length; i++) {
    PWM(buf[i]);
  }
}