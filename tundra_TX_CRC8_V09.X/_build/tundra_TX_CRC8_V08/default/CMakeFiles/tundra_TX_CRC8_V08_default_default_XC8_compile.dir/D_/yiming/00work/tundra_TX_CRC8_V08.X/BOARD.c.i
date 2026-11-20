# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2

# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/BOARD.h" 1


# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/tundra_PWM.h" 1
# 13 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/tundra_PWM.h"
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 1 3



# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/musl_xc8.h" 1 3
# 5 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 26 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 1 3
# 133 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef short intptr_t;
# 164 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "c:\\PROGRA~1\\MICROC~1\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 14 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/tundra_PWM.h" 2

typedef struct {
  void (*const get)(uint8_t *);
  void (*const set)(uint8_t *);
} array_t;

typedef struct {
  uint8_t (*const get)(void);
  void (*const set)(uint8_t);
} byte_t;


typedef struct {
  array_t data;
  byte_t crc;
} FRAME_t;

extern FRAME_t const tundra;
extern void Transmit_data(void);
# 4 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/BOARD.h" 2


extern void swSetLED(void);
extern void swSetDATA(FRAME_t const *tundra);
extern void board_init(void);
extern void swState_update(void);
# 3 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/LED.h" 1
# 12 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/LED.h"
typedef struct {
  void (*const on)(void);
  void (*const off)(void);
  uint8_t (*const is_on)(void);
} LED_t;

typedef struct {
  LED_t pos;
  LED_t drl;
  LED_t loBeam;
  LED_t hiBeam;
  LED_t turnLeft;
  LED_t turnRight;
} LEDs_t;

typedef enum {
  POS = 0,
  DRL,
  LO_BEAM,
  HI_BEAM,
  TURN_LEFT,
  TURN_RIGHT,
  LED_COUNT,
} Led_t;



extern const LEDs_t led;


void LED_Init(void);
# 4 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/SWITCH.h" 1








typedef struct {
  uint8_t (*const get)(void);
  uint8_t (*const is_on)(void);
} SWITCH_t;

typedef struct {
  SWITCH_t pos;
  SWITCH_t drl;
  SWITCH_t loBeam;
  SWITCH_t hiBeam;
  SWITCH_t turnLeft;
  SWITCH_t turnRight;
} SWITCHs_t;



extern const SWITCHs_t sw;
extern void swState_update(void);
# 5 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/tundra_crc8.h" 1
# 16 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/tundra_crc8.h"
extern uint8_t calculate_crc8(const uint8_t *data, uint8_t length);
# 6 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2
# 1 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/Warning_ignored.h" 1
# 15 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X/Warning_ignored.h"
extern void Clear_No_Call_Warning(void) ;
# 7 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c" 2
# 26 "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\BOARD.c"
void board_init(void) {
  LED_Init();
  Clear_No_Call_Warning();
  swState_update();
}

void swSetLED(void) {

  if (sw.pos.is_on() == (1U)) {
    led.pos.on();
  } else {
    led.pos.off();
  }

  if (sw.drl.is_on() == (1U)) {
    led.drl.on();
  } else {
    led.drl.off();
  }
  if (sw.loBeam.is_on() == (1U)) {
    led.loBeam.on();
  } else {
    led.loBeam.off();
  }
  if (sw.loBeam.is_on() == (1U)) {
    led.hiBeam.on();
  } else {
    led.hiBeam.off();
  }
  if (sw.turnLeft.is_on() == (1U)) {
    led.turnLeft.on();
  } else {
    led.turnLeft.off();
  }
  if (sw.turnRight.is_on() == (1U)) {
    led.turnRight.on();
  } else {
    led.turnRight.off();
  }
}

void swSetDATA(FRAME_t const *data) {


  uint8_t D2 = 0;
  uint8_t D3 = 0;

  if (sw.pos.is_on() == (1U)) {
    ((D2) |= (1U << ((2))));
  } else {
    ((D2) &= ~(1U << ((2))));
  }


  if (sw.drl.is_on() == (1U)) {
    ((D2) |= (1U << ((3))));
  } else {
    ((D2) &= ~(1U << ((3))));
  }


  if (sw.loBeam.is_on() == (1U)) {
    ((D2) |= (1U << ((4))));
  } else {
    ((D2) &= ~(1U << ((4))));
  }


  if (sw.hiBeam.is_on() == (1U)) {
    ((D2) |= (1U << ((5))));
  } else {
    ((D2) &= ~(1U << ((5))));
  }


  if (sw.turnLeft.is_on() == (1U)) {
    ((D3) |= (1U << ((5))));
  } else {
    ((D3) &= ~(1U << ((5))));
  }


  if (sw.turnRight.is_on() == (1U)) {
    ((D3) |= (1U << ((6))));
  } else {
    ((D3) &= ~(1U << ((6))));
  }

  uint8_t tmp[8]={0};
   tmp[0] = D2;
   tmp[1] = D3;
   data->data.set(tmp);
   data->crc.set(calculate_crc8(tmp,(8U)));
}
