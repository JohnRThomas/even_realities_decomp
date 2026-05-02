/*
 * Function: FUN_0008b012
 * Entry:    0008b012
 * Prototype: undefined4 __stdcall FUN_0008b012(undefined4 * param_1, undefined4 * param_2)
 */


undefined4 FUN_0008b012(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_2[0xd];
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1 != param_2 + 0x11) {
      _free_r(param_1,(int)puVar1);
    }
    param_2[0xd] = 0;
    param_2[1] = param_2[0x10];
    if (param_2[0x10] != 0) {
      *param_2 = param_2[0xf];
      return 0;
    }
  }
  *param_2 = param_2[4];
  param_2[1] = 0;
  *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x20;
  return 0xffffffff;
}


