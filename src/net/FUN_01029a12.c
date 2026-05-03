/*
 * Function: FUN_01029a12
 * Entry:    01029a12
 * Prototype: undefined __stdcall FUN_01029a12(undefined1 * param_1, undefined4 param_2)
 */


void FUN_01029a12(undefined1 *param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  undefined4 local_10;
  undefined1 *local_c;
  
  local_10 = param_1;
  local_c = (undefined1 *)param_2;
  FUN_0101ee2c();
  local_c = param_1 + 1;
  local_10 = (undefined1 *)CONCAT13(*param_1,0x300);
  FUN_010297a4((byte *)&local_10,extraout_r1);
  return;
}


