/*
 * File:   Warning_ignored.c
 * Author: T00904
 *
 * Created on November 13, 2026, 10:30 AM
 */

#include <stdint.h>
//for Clear_No_Call_Warning
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/epwm3.h"
#include "mcc_generated_files/tmr2.h"
#include "LED.h"
#include "tundra_PWM.h"

// 消除未呼叫警告 假裝有使用這些函數

void Clear_No_Call_Warning(void) {
    uint8_t i = 0U;
    if (i == 1U) {
        PIN_MANAGER_IOC();
    } else if (i == 2U) {
        // uint8_t tmp = TMR0_ReadTimer();
        // TMR0_WriteTimer(0U);
        // TMR0_Reload();
    } else if (i == 3U) {
        TMR2_StartTimer();
        TMR2_StopTimer();
        uint16_t tmp1 = TMR2_ReadTimer();
        TMR2_WriteTimer(0U);
        TMR2_LoadPeriodRegister(0);
        bool tmp_bit1 = TMR2_HasOverflowOccured();
    } else if(i==4U){
        EPWM3_LoadDutyValue(0);
    } else if(i==5U){
        tundra.crc.get();
        uint8_t tmp[8];
        tundra.data.get(tmp);
        led[POS].is_on();
        led[DRL].is_on();
        led[LO_BEAM].is_on();
        led[HI_BEAM].is_on();
        led[TURN_LEFT].is_on();
        led[TURN_RIGHT].is_on();

    }else{

    }
}