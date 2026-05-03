/*
 * Function: FUN_0007fc00
 * Entry:    0007fc00
 * Prototype: void __stdcall FUN_0007fc00(device * param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0007fc00(device *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  __st25dv_read((device *)param_1->name,*(ushort *)&param_1->api | 4,param_2,param_3,param_4);
  return;
}


