#ifndef __PERIPHERAL_H__
#define __PERIPHERAL_H__

#include "motor.h"

enum PP_IO_TYPE
{
  PP_TYPE_GPIO = 0, 
  PP_TYPE_I2C,
  PP_TYPE_MAX
};

enum PP_SENSOR_TYPE
{
  PP_SENSOR_TYPE_GAMEPAD_KONDO, // 10
  PP_SENSOR_TYPE_MAX
};

enum PP_SENSOR_GET
{
  PP_SENSOR_GET_BTKEY,          // 10
  PP_SENSOR_GET_MAX
};
    
typedef struct{
  uint8_t isEnable;
  PP_SENSOR_TYPE sensorType;
  PP_IO_TYPE ioType;
} pp_type;

extern pp_type pp_sensor[PP_SENSOR_TYPE_MAX];

#endif // __PERIPHERAL_H__
