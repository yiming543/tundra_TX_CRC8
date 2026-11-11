/* 
 * File: tundra_PWM.h  
 * Author: yiming
 * Comments:
 * Revision history: V1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_H
#define	PWM_H
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  // uint8_t buf[11];
  uint8_t ID;
  uint8_t LENGTH;
  uint8_t data[8];
  uint8_t CRC;
  uint8_t (*cal_crc8)(const uint8_t *data, uint8_t length);
} FRAME_t;

// #define data_length 8U
// #define buf_length 11U

extern FRAME_t tundra_data;
extern void tundra_init(FRAME_t *data);
extern void Transmit_data(FRAME_t *data);
#endif	/* PWM_H */

