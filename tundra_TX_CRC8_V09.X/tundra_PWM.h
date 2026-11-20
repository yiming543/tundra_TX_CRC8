/*
 * File: tundra_PWM.h
 * Author: yiming
 * Comments:
 * Revision history: V1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef PWM_H
#define PWM_H
// #include <stdbool.h>
#include <stdint.h>

typedef struct {
  void (*const get)(uint8_t *);
  void (*const set)(uint8_t *);
} array_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} byte_t;

// 1. 定義單一 LED 公開介面（全部使用 const 指標，不佔用 RAM，也無 state 暴露風險）
typedef struct {
  array_t data;
  byte_t crc;
} FRAME_t;

extern FRAME_t const tundra;
extern void Transmit_data(void);
#endif /* PWM_H */
