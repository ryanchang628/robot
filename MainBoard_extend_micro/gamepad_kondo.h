#ifndef __GAMEPAD_KONDO_H__
#define __GAMEPAD_KONDO_H__

#include <IcsSoftSerialClass.h>

#define GAMEPAD_KONDO_TX_PIN  9
#define GAMEPAD_KONDO_RX_PIN  8
#define GAMEPAD_KONDO_ENABLE_PIN  4
#define GAMEPAD_KONDO_BAUDRATE  115200
#define GAMEPAD_KONDO_TIMEOUT 100


int16_t gpKondo_init(uint8_t id);
int16_t gpKondo_enable(uint8_t id);
int16_t gpKondo_disable(uint8_t id);


enum KONDO_BUTTON : unsigned short{
  KONDO_BUTTON_NONE       = 0x0000,  //
  KONDO_BUTTON_UP        =  0x0001,  //
  KONDO_BUTTON_DOWN      =  0x0002,  //   
  KONDO_BUTTON_RIGHT     =  0x0004,  //   
  KONDO_BUTTON_LEFT      =  0x0008,  //  
  KONDO_BUTTON_TRIANGLE  =  0x0010,  //   
  KONDO_BUTTON_CROSS     =  0x0020,  //   
  KONDO_BUTTON_CIRCLE    =  0x0040,  //   
  KONDO_BUTTON_SQUARE    =  0x0100,  //     
  KONDO_BUTTON_L1        =  0x0200,  // LEFT 1   
  KONDO_BUTTON_L2        =  0x0400,  // LEFT 2  
  KONDO_BUTTON_R1        =  0x0800,  // RIGHT 1 
  KONDO_BUTTON_R2        =  0x1000,  // RIGHT 2
  KONDO_BUTTON_START     =  0x0170,
  KONDO_BUTTON_STOP      =  0x000F,
  
  KONDO_BUTTON_FALSE = 0xFFFF ///
};


#endif
