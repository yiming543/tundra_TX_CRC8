
/*
 * File:   tundra.h
 * Author: T00904
 * Comments: Main header file for the Tundra project
 * Revision history: V1.0 May 11, 2026
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef TUNDRA_DATA_H
#define TUNDRA_DATA_H

#include <stdbool.h>
#include <stdint.h>

#define D2_POS_MASK 2
#define D2_DRL_MASK 3
#define D2_LOBEAM_MASK 4
#define D2_HIBEAM_MASK 5

#define D3_TURN_LEFT_MASK 5
#define D3_TURN_RIGHT_MASK 6

// struct {
//   unsigned : 2;
//   unsigned pos : 1;
//   unsigned drl : 1;
//   unsigned loBeam : 1;
//   unsigned hiBeam : 1;
//   unsigned : 2;
// } D2_t;

// struct {
//   unsigned : 5;
//   unsigned turnLeft : 1;
//   unsigned turnRight : 1;
//   unsigned : 1;
// } D3_t;

typedef struct {
  uint8_t buf[11];
  //     uint8_t ID;
  //     uint8_t LENGTH;
  //     D2_t D2;    // data[0]
  //     D3_t D3;    // data[1]
  //     uint8_t D4; // data[2]
  //     uint8_t D5; // data[3]
  //     uint8_t D6; // data[4]
  //     uint8_t D7; // data[5]
  //     uint8_t D8; // data[6]
  //     uint8_t D9; // data[7]
  //     uint8_t CRC;
} FRAME_t;

#define data_length 8U
#define buf_length 11U

extern FRAME_t tundra_data;
extern void tundra_init(FRAME_t *data);
extern void Transmit_data(FRAME_t *data);
extern void Clear_No_Call_Warning(void);

#endif /* TUNDRA_DATA_H */
