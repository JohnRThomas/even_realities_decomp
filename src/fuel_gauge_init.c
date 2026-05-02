/*
 * Function: fuel_gauge_init
 * Entry:    0002feb0
 * Prototype: int __stdcall fuel_gauge_init(device * param_1)
 */


int fuel_gauge_init(device *param_1)

{
  int iVar1;
  int64_t iVar2;
  sensor_value asStack_28 [2];
  float local_20;
  float fStack_1c;
  float local_18;
  undefined *local_14;
  
  local_14 = &DAT_0008c200;
  local_20 = 0.0;
  fStack_1c = 0.0;
  local_18 = 0.0;
  iVar1 = read_sensors(param_1,&local_20,&fStack_1c,&local_18);
  iVar2 = CONCAT44(DAT_20004934,DAT_20004930);
  if (-1 < iVar1) {
    sensor_channel_get(param_1,0x39,asStack_28);
    iVar1 = nrf_fuel_gauge_init(&local_20,(undefined4 *)0x0);
    iVar2 = CONCAT44(DAT_20004934,DAT_20004930);
    if (-1 < iVar1) {
      iVar2 = k_uptime_get();
      iVar1 = 0;
    }
  }
  DAT_20004934 = (undefined4)((ulonglong)iVar2 >> 0x20);
  DAT_20004930 = (undefined4)iVar2;
  return iVar1;
}


