/*
 * Function: read_sensors
 * Entry:    0002fe10
 * Prototype: int __stdcall read_sensors(device * device, float * voltage, float * current, float * temp)
 */


int read_sensors(device *device,float *voltage,float *current,float *temp)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  sensor_value local_28;
  
  iVar1 = (**(code **)(device->api + 0xc))(device,0x3a);
  if (-1 < iVar1) {
    sensor_channel_get(device,SENSOR_CHAN_GAUGE_VOLTAGE,&local_28);
    fVar2 = (float)VectorSignedToFloat(local_28.val2,(byte)(in_fpscr >> 0x16) & 3);
    fVar3 = (float)VectorSignedToFloat(local_28.val1,(byte)(in_fpscr >> 0x16) & 3);
    *voltage = fVar2 / 1e+06 + fVar3;
    sensor_channel_get(device,SENSOR_CHAN_GAUGE_TEMP,&local_28);
    fVar2 = (float)VectorSignedToFloat(local_28.val2,(byte)(in_fpscr >> 0x16) & 3);
    fVar3 = (float)VectorSignedToFloat(local_28.val1,(byte)(in_fpscr >> 0x16) & 3);
    *temp = fVar2 / 1e+06 + fVar3;
    sensor_channel_get(device,SENSOR_CHAN_GAUGE_AVG_CURRENT,&local_28);
    fVar2 = (float)VectorSignedToFloat(local_28.val2,(byte)(in_fpscr >> 0x16) & 3);
    fVar3 = (float)VectorSignedToFloat(local_28.val1,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = 0;
    *current = fVar2 / 1e+06 + fVar3;
  }
  return iVar1;
}


