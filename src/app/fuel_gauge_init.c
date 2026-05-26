/*
 * Function: fuel_gauge_init
 * Entry:    0002feb0
 * Prototype: int __stdcall fuel_gauge_init(device * charger)
 */


int fuel_gauge_init(device *charger)

{
  int iVar1;
  int64_t iVar2;
  sensor_value sStack_28;
  float local_20;
  float fStack_1c;
  float local_18;
  undefined *local_14;
  
  local_14 = &DAT_0008c200;
  local_20 = 0.0;
  fStack_1c = 0.0;
  local_18 = 0.0;
  iVar1 = read_sensors(charger,&local_20,&fStack_1c,&local_18);
  iVar2 = CONCAT44(fuel_guage_ref_time._4_4_,(undefined4)fuel_guage_ref_time);
  if (-1 < iVar1) {
    sensor_channel_get(charger,SENSOR_CHAN_GAUGE_DESIRED_CHARGING_CURRENT,&sStack_28);
    iVar1 = nrf_fuel_gauge_init(&local_20,(undefined4 *)0x0);
    iVar2 = CONCAT44(fuel_guage_ref_time._4_4_,(undefined4)fuel_guage_ref_time);
    if (-1 < iVar1) {
      iVar2 = k_uptime_get();
      iVar1 = 0;
    }
  }
  fuel_guage_ref_time._4_4_ = (undefined4)((ulonglong)iVar2 >> 32);
  fuel_guage_ref_time._0_4_ = (undefined4)iVar2;
  return iVar1;
}


