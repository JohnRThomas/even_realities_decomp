/*
 * Function: read_sensors
 * Entry:    0002fe10
 * Prototype: int __stdcall read_sensors(device * device, float * voltage, float * current, float * temp)
 */


int read_sensors(device *device,float *voltage,float *current,float *temp)

{
  int iVar1;
  int local_28;
  int local_24;
  
  iVar1 = (**(code **)(device->api + 0xc))(device,0x3a);
  if (-1 < iVar1) {
    sensor_channel_get(device,0x28,&local_28);
    *voltage = (float)(longlong)local_24 / 1e+06 + (float)(longlong)local_28;
    sensor_channel_get(device,0x2c,&local_28);
    *temp = (float)(longlong)local_24 / 1e+06 + (float)(longlong)local_28;
    sensor_channel_get(device,0x29,&local_28);
    iVar1 = 0;
    *current = (float)(longlong)local_24 / 1e+06 + (float)(longlong)local_28;
  }
  return iVar1;
}


