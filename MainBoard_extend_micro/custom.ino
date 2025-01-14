#include <vector>
#include "motor.h"
#include "custom.h"
#include "action.h"
#include "gamepad_kondo.h"

volatile uint8_t btn_mode = BTN_MODE_NONE;

std::vector<Action>* state = forward;

bool IsKeyPressed(unsigned short key) {
  return gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO) == key;
}

void custom_setup() {
  //krs.begin();
  gpKondo_init(PP_SENSOR_TYPE_GAMEPAD_KONDO);
}

void custom_loop()
{
  uint16_t btn_key = KONDO_BUTTON_FALSE; 
  uart_disableMotor();

  // 等待連接
  while(IsKeyPressed(KONDO_BUTTON_START)) {
    if(uart_isConnectToPC() != 0){return;}
    delay(10); // less load
  }
  
  // 主操作
  while(uart_isUartMode == 0){

    // 判斷退出
    if(uart_isConnectToPC() != 0){return;}

    // 取得輸入
    unsigned short buttonData = KONDO_BUTTON_FALSE;
    buttonData = gpKondo_getKey(PP_SENSOR_TYPE_GAMEPAD_KONDO);
    if(buttonData == KONDO_BUTTON_FALSE) {return;}

    // 操作
    custom_gamepadKeyFun_kondo(buttonData);

    // 等待
    delay(10);
  }
}

const Action* findActionByKey(
  const std::vector<Action>& actions, 
  const char*& key
) {

  // 尋找單獨指令
  for (const auto& action : actions) {
    if (key == action.key) {return &action;}
  }

  // 尋找共同指令
  for (const auto& action : common) {
    if (key == action.key) {return &action;}
  }

  return nullptr; // 找不到時返回 nullptr
}

void custom_gamepadKeyFun_kondo(unsigned short buttonData) {

  unsigned short tempButton = KONDO_BUTTON_FALSE;

  switch(buttonData){
    
    // 開機
    case KONDO_BUTTON_START:
      SetFrameRun(19, 700);
      SetFrameRun(25, 50);
      SetFrameRun(1, 50);
    break;

    // 罰站
    case KONDO_BUTTON_RIGHT + KONDO_BUTTON_DOWN:
      SetFrameRun(59, 250);
      SetFrameRun(60, 250);
    break;

    // 關機
    case KONDO_BUTTON_STOP:
      uart_disableMotor();
    break;

    // 模式切換
    // ==================================
    case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_L1:
      state = 0;
      SetFrameRun(25, 10);
    break; 

    case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_R1:
      state = 1;
      SetFrameRun(25, 10);
    break; 
    
    case KONDO_BUTTON_SQUARE + KONDO_BUTTON_CROSS + KONDO_BUTTON_R2:
      state = 2;
      SetFrameRun(38, 10); 
    break; 

    // 叉 : 看起來像必殺技
    // ==================================

    case KONDO_BUTTON_CROSS:
      do {
        SetFrameRun(38, 20);
        if (IsKeyPressed(KONDO_BUTTON_CROSS + KONDO_BUTTON_DOWN)) {
          SetFrameRun(84, 150);
          SetFrameRun(85, 1000);
          break;
        }
      } while (IsKeyPressed(KONDO_BUTTON_CROSS))
      SetFrameRun(25, 50);
    break;

    default:
      const Action* action = findActionByKey(buttonData);

      for (const auto& step : action->readyAction) 
      {SetFrameRun(step.act_number, step.spend_time)}
      
      do {
        for (const auto& step : action->doAction) 
        {SetFrameRun(step.act_number, step.spend_time)}
      } while (IsKeyPressed(buttonData));

      for (const auto& step : action->endAction) 
      {SetFrameRun(step.act_number, step.spend_time)}

    break;
  }
  return;
}
