/*
 * Function: FUN_0100b314
 * Entry:    0100b314
 * Prototype: undefined __stdcall FUN_0100b314(undefined4 * param_1, undefined1 * param_2, int param_3)
 */


void FUN_0100b314(undefined4 *param_1,undefined1 *param_2,int param_3)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined1 local_24;
  byte local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  if (param_3 == 0) {
    FUN_01009a04();
  }
  else {
    FUN_010099f8();
  }
  local_23 = param_2[5] & 0x3f | 0x40;
  param_2[5] = local_23;
  local_40 = *param_1;
  local_28 = 0;
  local_24 = 0;
  uStack_3c = param_1[1];
  uStack_38 = param_1[2];
  local_30 = 0;
  uStack_2c = 0;
  local_21 = param_2[3];
  local_22 = param_2[4];
  uStack_34 = param_1[3];
  FUN_0100afe8((uint)&local_40);
  *param_2 = local_11;
  param_2[1] = local_12;
  param_2[2] = local_13;
  return;
}


