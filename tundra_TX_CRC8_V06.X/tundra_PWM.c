/*
 * File:   tundra_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 10:54 AM
 */

#include <xc.h>
//#define _XTAL_FREQ 32000000U // 系統時鐘 32 MHz

#define PWM_HIGH_PULSE 112U
#define PWM_LOW_PULSE 225U
#define PWM_BITS 8U

// void pwm_init(void) {
//     TRISCbits.TRISC6 = 0;    // ECCP3 輸出 RC6
//     CCP3CON = 0b00001100;    // ECCP3 PWM 模式
//     PR2 = 103;               // 19200 baud -> 52 µs 週期
//     T2CON = 0b00000101;      // Timer2 ON, Prescaler=4
// }

void wait_for_pwm_cycle_complete(void) {
  while (!TMR2IF){}
  
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
  CCPR3L = (duty >> 2U) & 0xffU;
  CCP3CONbits.DC3B = duty & 0x03U;
}

void PWM(unsigned char buf) {
  wait_for_pwm_cycle_complete();
  // start  bit
  pwm_set_bit(0);

  // data bit
  for (uint8_t i = 0U; i < PWM_BITS; i++) {
    wait_for_pwm_cycle_complete(); // 每位元時間
    pwm_set_bit((buf >> i) & 0x01U);
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
