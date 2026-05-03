/*
 * Function: FUN_010299aa
 * Entry:    010299aa
 * Prototype: undefined __stdcall FUN_010299aa(undefined1 * param_1, undefined4 param_2)
 */


void FUN_010299aa(undefined1 *param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  undefined4 local_10;
  undefined1 *local_c;
  
  local_10 = param_1;
  local_c = (undefined1 *)param_2;
  FUN_0101ee2c();
  local_c = param_1 + 1;
  local_10 = (undefined1 *)CONCAT13(*param_1,0x300);
  FUN_010298d0((byte *)&local_10,extraout_r1);
  return;
}


