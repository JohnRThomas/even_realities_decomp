/*
 * Function: FUN_010091f8
 * Entry:    010091f8
 * Prototype: undefined __stdcall FUN_010091f8(undefined8 * param_1, uint * param_2, uint * param_3)
 */


void FUN_010091f8(undefined8 *param_1,uint *param_2,uint *param_3)

{
  uint extraout_r2;
  uint extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r3;
  uint extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined8 uVar1;
  
  uVar1 = FUN_01008bdc(param_1,param_2,param_3);
  uVar1 = FUN_01009140((uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),extraout_r2,extraout_r3);
  uVar1 = FUN_01009140((uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),extraout_r2_00,extraout_r3_00);
  *param_1 = uVar1;
  *(undefined4 *)(param_1 + 1) = extraout_r2_01;
  *(undefined4 *)((int)param_1 + 0xc) = extraout_r3_01;
  *(undefined4 *)(param_1 + 2) = unaff_r4;
  *(undefined4 *)((int)param_1 + 0x14) = unaff_r5;
  *(undefined4 *)(param_1 + 3) = unaff_r6;
  *(undefined4 *)((int)param_1 + 0x1c) = unaff_r7;
  return;
}


