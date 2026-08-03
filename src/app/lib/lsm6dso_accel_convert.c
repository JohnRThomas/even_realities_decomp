/*
 * Function: lsm6dso_accel_convert
 * Entry:    000124d8
 * Prototype: void __stdcall lsm6dso_accel_convert(sensor_value * val, int raw_val, uint32_t sensitivity)
 */


/* exclude_from_export_ai */

void lsm6dso_accel_convert(sensor_value *val,int raw_val,uint32_t sensitivity)

{
  uint uVar1;
  uint extraout_r1;
  int32_t extraout_r2;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = __aeabi_l2d((uint)((ulonglong)(uint)raw_val * (ulonglong)sensitivity),
                      sensitivity * (raw_val >> 0x1f) +
                      (int)((ulonglong)(uint)raw_val * (ulonglong)sensitivity >> 0x20));
  uVar2 = __muldf3((uint)uVar2,(uint)(uVar2 >> 0x20),0x3a92a305,0x40239d01);
  uVar1 = __fixdfsi((uint)uVar2,(uint)(uVar2 >> 0x20));
  uVar3 = __aeabi_ldivmod(uVar1,extraout_r1,1000000,0);
  val->val1 = (int32_t)uVar3;
  val->val2 = extraout_r2;
  return;
}


