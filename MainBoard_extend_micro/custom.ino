#include "motor.h"
#include "custom.h"
#include "gamepad_kondo.h"

volatile uint8_t btn_mode = BTN_MODE_NONE;

uint8_t auto_edge_cnt = 0;
uint8_t auto_turn_cnt = 0;
uint8_t auto_fight_cnt = 0;
int16_t auto_time_cnt = 0;
uint32_t auto_millis_cnt = 0;
uint8_t xy=0;


void custom_setup()
{
  //krs.begin();
  gpKondo_init(PP_SENSOR_TYPE_GAMEPAD_KONDO);

}

void custom_loop()
{

  uint16_t btn_key = 0; 

  uart_disableMotor();

  // wait the key to start machine
  while((btn_key = gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO)) != KONDO_BUTTON_START) {  
    //Serial.println(btn_key);
    if(uart_isConnectToPC() != 0){
      return;
    }
  }
  
  while(uart_isUartMode == 0){  
    custom_gamepadKeyFun_kondo();
    
    if(uart_isConnectToPC() != 0){
      return;
    }    
  } 
 
}

int16_t custom_gamepadKeyFun_kondo()
{  
  unsigned short buttonData = KONDO_BUTTON_FALSE;
  unsigned short tempButton = KONDO_BUTTON_FALSE;
  buttonData = gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO);
  if(buttonData != KONDO_BUTTON_FALSE) 
  {
    switch(buttonData){
      case KONDO_BUTTON_RIGHT:
        if (xy == 2){
          do {
            SetFrameRun(14, 40);
            SetFrameRun(38, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(38, 10);
        }else{
          do {
            SetFrameRun(14, 70);
            SetFrameRun(12, 95);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);   
              }
      break;
      
      case KONDO_BUTTON_DOWN:  
        if (xy == 0){
       do {
          SetFrameRun(7, 35);
          SetFrameRun(8, 95);
          SetFrameRun(9, 35);
          SetFrameRun(10, 95);  
          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);    
          SetFrameRun(1, 50);
        }else if (xy == 1){
       do {
          SetFrameRun(3, 35);
          SetFrameRun(4, 75);
          SetFrameRun(5, 35);
          SetFrameRun(6, 75);  
          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);    
          SetFrameRun(1, 50);  
              }
      break;
      
      case KONDO_BUTTON_LEFT:
        if (xy == 2){
          do {
            SetFrameRun(13, 40);
            SetFrameRun(38, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(38, 10);
        }else{
          do {
            SetFrameRun(13, 70);
            SetFrameRun(12, 95);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);   
              }
      break;
      
      case KONDO_BUTTON_UP:
        if (xy == 0){
       do {
          SetFrameRun(3, 35);
          SetFrameRun(4, 75);
          SetFrameRun(5, 35);
          SetFrameRun(6, 75);  
          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);    
          SetFrameRun(1, 50);  
        }else if (xy == 1){
       do {
          SetFrameRun(7, 35);
          SetFrameRun(8, 95);
          SetFrameRun(9, 35);
          SetFrameRun(10, 95);  
          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);    
          SetFrameRun(1, 50);  
              }else if (xy == 2){
       
          SetFrameRun(18, 70);
          SetFrameRun(38, 100);  
              }
      break;
      
      case KONDO_BUTTON_TRIANGLE://三角
      
      break;

                        case KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_UP:
            
                            SetFrameRun(77, 400);
                            SetFrameRun(78, 320);
                           do {
                            SetFrameRun(79, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_UP);        
                        break;

                         case KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_LEFT:
            
                            SetFrameRun(80, 250);
                           do {
                            SetFrameRun(81, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_LEFT);    
                        break;

                         case KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_RIGHT:
                            SetFrameRun(77, 400);
                            SetFrameRun(78, 320);
                            SetFrameRun(82, 500); 
                           do {
                            SetFrameRun(83, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_RIGHT);    
                        break;
                        
                         case KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_DOWN:
                            SetFrameRun(38, 400);
                            SetFrameRun(84, 150);
                           do {
                            SetFrameRun(85, 50);
                           } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_DOWN);    
                        break;

      case KONDO_BUTTON_CIRCLE:

      break;

                       case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_L1:

                        break; 
                       
                       case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R1:
                               if (xy == 0){
                            SetFrameRun(57, 150);
                        do {
                            SetFrameRun(58, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R1);
                            SetFrameRun(25, 50); 
                        }else if (xy == 1){
                            SetFrameRun(73, 150);
                        do {
                            SetFrameRun(74, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R1);
                            SetFrameRun(25, 50); 
                            }
                       break; 
                    
                       case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_L2:

                       break; 
                       
                       case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R2:
                              if (xy == 0){
                            SetFrameRun(34, 150);
                        do {
                            SetFrameRun(35, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R2);
                            SetFrameRun(25, 50); 
                        }else if (xy == 1){
                            SetFrameRun(63, 150);
                        do {
                            SetFrameRun(64, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R2);
                            SetFrameRun(25, 50); 
                            }
                       break; 

      case KONDO_BUTTON_CROSS:
         tempButton=KONDO_BUTTON_CROSS;
         while(tempButton != 0&&tempButton != KONDO_BUTTON_CROSS + KONDO_BUTTON_DOWN){
            SetFrameRun(38, 20);  
            tempButton=gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO);
          };
          if(tempButton == KONDO_BUTTON_CROSS + KONDO_BUTTON_DOWN){
               SetFrameRun(84, 150);
               SetFrameRun(85, 1000);
          }
          SetFrameRun(25, 50);
//           do {  
//                SetFrameRun(38, 20);
//                delay(30);
//                if(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_CROSS + KONDO_BUTTON_DOWN){
//                     SetFrameRun(84, 150);
//                     SetFrameRun(85, 1000);
//                delay(10);
//                     break;
//                     }      
//                 if(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == 0){
//                delay(10);
//                     break;         
//                }
//           } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) != 0);
//                    SetFrameRun(25, 50);
//                    SetFrameRun(1, 50);       
//        break;

      case KONDO_BUTTON_SQUARE:
      
      break;
    
                       case KONDO_BUTTON_SQUARE + KONDO_BUTTON_L1:
                               if (xy == 0){
                            SetFrameRun(53, 150);
                        do {
                            SetFrameRun(54, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_SQUARE + KONDO_BUTTON_L1);
                            SetFrameRun(25, 50); 
                        }else if (xy == 1){
                            SetFrameRun(71, 150);
                        do {
                            SetFrameRun(72, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_SQUARE + KONDO_BUTTON_L1);
                            SetFrameRun(25, 50); 
                            }
                        break; 
                       
                       case KONDO_BUTTON_SQUARE + KONDO_BUTTON_R1:

                       break; 
                    
                       case KONDO_BUTTON_SQUARE + KONDO_BUTTON_L2:
                              if (xy == 0){
                            SetFrameRun(30, 150);
                        do {
                            SetFrameRun(31, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_SQUARE + KONDO_BUTTON_L2);
                            SetFrameRun(25, 50); 
                        }else if (xy == 1){
                            SetFrameRun(75, 150);
                        do {
                            SetFrameRun(76, 50); 
                          } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_SQUARE + KONDO_BUTTON_L2);
                            SetFrameRun(25, 50); 
                            }
                       break; 
                       
                       case KONDO_BUTTON_SQUARE + KONDO_BUTTON_R2:

                       break; 


      case KONDO_BUTTON_L1:
            if (xy == 0){
            SetFrameRun(36, 50);
          do {
            SetFrameRun(37, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);
      }else if (xy == 1){
            SetFrameRun(61, 50);
          do {
            SetFrameRun(62, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);
      }
      break;

      case KONDO_BUTTON_R1:
            if (xy == 0){
            SetFrameRun(32, 50);
          do {
            SetFrameRun(33, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_R1);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);
      }else if (xy == 1){
            SetFrameRun(65, 50);
          do {
            SetFrameRun(66, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == KONDO_BUTTON_R1);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);
      }
      break;

      case KONDO_BUTTON_L2:
           if (xy == 0){
          do {
            SetFrameRun(15, 90);
            SetFrameRun(17, 90);     
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50); 
      }else if (xy == 1){
          do {
            SetFrameRun(16, 90);
            SetFrameRun(11, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50); 
      }else if (xy == 2){
          do {
            SetFrameRun(29, 80);
            SetFrameRun(38, 100);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(38, 10);
          }
      break;

      case KONDO_BUTTON_R2:
           if (xy == 0){
          do {
            SetFrameRun(16, 90);
            SetFrameRun(11, 90);     
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50); 
      }else if (xy == 1){
          do {
            SetFrameRun(15, 90);
            SetFrameRun(17, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50); 
      }else if (xy == 2){
          do {
            SetFrameRun(28, 80);
            SetFrameRun(38, 100);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(38, 10);
      }
      break;

      case KONDO_BUTTON_STOP:
        uart_disableMotor();
      break;
      
      case KONDO_BUTTON_START:

          SetFrameRun(19, 700);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50);
      break;
      
      case KONDO_BUTTON_LEFT + KONDO_BUTTON_DOWN:
        // L left down
          SetFrameRun(20, 250);
          SetFrameRun(26, 400);           
         do {
          SetFrameRun(27, 50); 
     } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
         SetFrameRun(23, 350); 
         SetFrameRun(61, 100);
         SetFrameRun(1, 50);
      break;

      case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_CROSS:
        // R right down
         SetFrameRun(20, 300);
         SetFrameRun(21, 250);
         do {
         SetFrameRun(22, 50);
     } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
         SetFrameRun(23, 350); 
         SetFrameRun(61, 100);
         SetFrameRun(1, 50);
      break;  
      
      case KONDO_BUTTON_SQUARE | KONDO_BUTTON_TRIANGLE:
            if (xy == 0){
            SetFrameRun(39, 50);
          do {
            SetFrameRun(40, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50);
      }else if (xy == 1){
            SetFrameRun(67, 50);
          do {
            SetFrameRun(68, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50);
      }
      break;

       case KONDO_BUTTON_LEFT | KONDO_BUTTON_UP:
           if (xy == 0){
        do {
             SetFrameRun(47, 90);
             SetFrameRun(48, 80);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) != 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50); 
           }else if (xy == 1){
        do {
             SetFrameRun(43, 70);
             SetFrameRun(44, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) != 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50); 
          }
      break;

       case KONDO_BUTTON_RIGHT | KONDO_BUTTON_UP:
           if (xy == 0){
        do {
             SetFrameRun(49, 90);
             SetFrameRun(50, 80);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) != 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50); 
           }else if (xy == 1){
        do {
             SetFrameRun(45, 70);
             SetFrameRun(46, 90);
        } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) != 0);
          SetFrameRun(25, 50);
          SetFrameRun(1, 50); 
          }
      break;

       case KONDO_BUTTON_RIGHT + KONDO_BUTTON_DOWN:
          SetFrameRun(59, 250);
          SetFrameRun(60, 250);            
      break;

      case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS:

      break; 

        case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_L1:
          xy = 0;
             SetFrameRun(25, 10);
        break; 
  
        case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_R1:
          xy = 1;
            SetFrameRun(25, 10);
        break; 
        
        case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_R2:
          xy = 2;
            SetFrameRun(38, 10); 
        break; 
      
      case KONDO_BUTTON_CIRCLE + KONDO_BUTTON_TRIANGLE:
            if (xy == 0){
            SetFrameRun(41, 50);
          do {
            SetFrameRun(42, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50);
      }else if (xy == 1){
            SetFrameRun(69, 50);
          do {
            SetFrameRun(70, 50);
         } while(gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) > 0);
          SetFrameRun(25, 100);
          SetFrameRun(1, 50);
      }
      break;
    }
  }
  else
  {

  }
  delay(10); //KRR5 10ms

  return 0;
}
