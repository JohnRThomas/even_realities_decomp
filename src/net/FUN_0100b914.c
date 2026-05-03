/*
 * Function: FUN_0100b914
 * Entry:    0100b914
 * Prototype: undefined4 __stdcall FUN_0100b914(undefined4 param_1, undefined4 param_2)
 */


undefined4 FUN_0100b914(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int extraout_r2;
  undefined4 extraout_r3;
  
  DAT_21000050 = &PTR_FUN_0100b710_1_0100c21c;
  if (DAT_21000c8c == 0) {
    DAT_21000c60 = DAT_21000c8c;
    uVar1 = FUN_0100eddc(&DAT_21000c90,1);
    DAT_21000d00 = param_1;
    DAT_21000ccc = param_2;
    return uVar1;
  }
  FUN_01009500(0x27,0xde,&PTR_FUN_0100b710_1_0100c21c,(uint)DAT_21000c8c);
  *(int *)extraout_r2 = extraout_r2;
  *(undefined4 *)(extraout_r2 + 4) = extraout_r3;
  *(undefined4 **)(extraout_r2 + 8) = &DAT_21000c48;
  if (DAT_21000c8c == 0) {
    DAT_21000c60 = DAT_21000c8c;
    return 0;
  }
  return 0xc;
}


