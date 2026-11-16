/*
 * File:   tundra_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 10:54 AM
 */

#include "tundra_PWM.h"
#include <xc.h>

#define PWM_HIGH_PULSE 112U
#define PWM_LOW_PULSE 225U
#define PWM_BITS 8U
#define buf_length 11U

typedef struct {
  // uint8_t buf[11];
  uint8_t ID;
  uint8_t LENGTH;
  uint8_t DATA[8];
  uint8_t CRC;
} Frame_t;

// 全域變數
static Frame_t frame = {
    .ID = 0xC8U,
    .LENGTH = 0x8BU,
    .DATA = {0},
    .CRC = 0};

void DATA_GET(uint8_t *data) {
  for (uint8_t i = 0U; i < 8U; i++) {
    data[i] = frame.DATA[i];
  }
}

void DATA_SET(uint8_t *data) {
  for (uint8_t i = 0U; i < 8U; i++) {
    frame.DATA[i] = data[i];
  }
}

uint8_t CRC_GET(void) {
  return frame.CRC;
}

void CRC_SET(uint8_t data) {
  frame.CRC = data;
}

FRAME_t const tundra = {
    .data = {.get = DATA_GET, .set = DATA_SET},
    .crc = {.get = CRC_GET, .set = CRC_SET},
};

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

void Transmit_data(void) {
  uint8_t buf[11];

  buf[0] = frame.ID;
  buf[1] = frame.LENGTH;
  for (uint8_t i = 0U; i < 8U; i++) {
    buf[i + 2U] = frame.DATA[i];
  }
  buf[10] = frame.CRC;

  for (uint8_t i = 0U; i < buf_length; i++) {
    PWM(buf[i]);
  }
}