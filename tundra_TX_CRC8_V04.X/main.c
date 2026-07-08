/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules
  selected in the GUI. Generation Information : Product Revision  :  PIC10 /
  PIC12 / PIC16 / PIC18 MCUs - 1.81.8 Device            :  PIC16F1936 Driver
  Version    :  2.00
 */

// 20260511 TUNDRA_TX_CRC8_V01 CS:7F19
// 使用CRC8校驗(table)
// D4=D2
// D5=D2
// D6=D3
// D7=D3
//SW1:行車燈
//SW2:晝行燈
//SW3:近燈
//SW4:遠燈
//SW5:左方向燈
//SW6:右方向燈

//20260512 TUNDRA_TX_CRC8_V02
//使用CRC8校驗(逐位計算) CS:7023
//使用CRC8校驗(table) CS:5CC3

//20260513 TUNDRA_TX_CRC8_V03 CS:F43E
//1.修正PWM週期為52µs (19200 baud)
//2.修正PWM bit=1 duty為14µs，bit=0 duty為28µs
//3.新增tundra_PWM.c 與tundra_PWM.h，將PWM相關程式碼獨立出來
//4.重構 (Refactoring)main.c，將程式碼切分為Check_Input、prepare_tx_data、Transmit_data等函式，提升程式結構與可讀性


//20260708 TUNDRA_TX_CRC8_V04 CS:018B
//修正編譯失敗

#include "mcc_generated_files/mcc.h"
#include "DATA_define.h"
#include "tundra_crc8.h"
#include "tundra_PWM.h"


// Variable declaration
flag_D2 D2 = {.Byte = 0};
flag_D3 D3 = {.Byte = 0};
DATA_FRAME tx_buf = {
    .id = 0xC8,     // 車燈信號
    .length = 0x8B, // 8 byte
    .data = {0},
    .crc = 0x04C // check sum
};

void Check_Input(void) {
  // initionzation flag
  D2.Byte = 0;
  D3.Byte = 0;

  // 行車
  if (SW1 == SW_ON) {
    LED1 = LED_ON;
    D2.RunLight = 1;
  } else {
    LED1 = LED_OFF;
    D2.RunLight = 0;
  }

  // 晝行
  if (SW2 == SW_ON) {
    LED2 = LED_ON;
    D2.DRL = 1;
  } else {
    LED2 = LED_OFF;
    D2.DRL = 0;
  }

  // 近燈
  if (SW3 == SW_ON) {
    LED3 = LED_ON;
    D2.LoBeam = 1;
  } else {
    LED3 = LED_OFF;
    D2.LoBeam = 0;
  }

  // 遠燈
  if (SW4 == SW_ON) {
    LED4 = LED_ON;
    D2.HiBeam = 1;
  } else {
    LED4 = LED_OFF;
    D2.HiBeam = 0;
  }

  // 左方向燈
  if (SW5 == SW_ON) {
    LED5 = LED_ON;
    D3.turnLight_L = 1;
  } else {
    LED5 = LED_OFF;
    D3.turnLight_L = 0;
  }

  // 右方向燈
  if (SW6 == SW_ON) {
    LED6 = LED_ON;
    D3.trunLight_R = 1;
  } else {
    LED6 = LED_OFF;
    D3.trunLight_R = 0;
  }
}

void prepare_tx_data(void) {
    // Prepare data for transmission
    tx_buf.data[0] = D2.Byte; // D0
    tx_buf.data[1] = D3.Byte; // D1
    // D4~D7 are 0 by D2
//    tx_data.data[4] = D2.Byte; // D4
//    tx_data.data[5] = D2.Byte; // D5
//    tx_data.data[6] = D3.Byte; // D6
//    tx_data.data[7] = D3.Byte; // D7
    tx_buf.crc = calculate_crc8(tx_buf.data, data_length);
}

void Transmit_data(void){
   // Transmit data via PWM
    // PWM(tx_data.id); // ID
    // PWM(tx_data.length); // Length

    // for (unsigned char i = 0; i < data_length; i++) {
    //   PWM(tx_data.data[i]); // D1~D8
    // }
    // PWM(tx_data.crc); // CRC
    for (uint8_t i = 0; i < buf_length; i++) {
      PWM(tx_buf.buf[i]);
    }
}

/*
                         Main application
 */
int main(void) {
  // initialize the device
  SYSTEM_Initialize();

  while (1) {
    // Add your application code
    Check_Input();
    prepare_tx_data();
    Transmit_data();
    __delay_ms(20); // Optional delay between transmissions
  }
  return 0;
}
/**
 End of File
 */