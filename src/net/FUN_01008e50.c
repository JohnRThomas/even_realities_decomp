/*
 * Function: FUN_01008e50
 * Entry:    01008e50
 * Prototype: undefined __stdcall FUN_01008e50(undefined4 * param_1, uint * param_2, uint * param_3)
 */


void FUN_01008e50(undefined4 *param_1,uint *param_2,uint *param_3)

{
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r11;
  undefined8 uVar1;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar1 = FUN_01008bdc(param_1,param_2,param_3);
  *(undefined8 *)(param_1 + 8) = uVar1;
  param_1[10] = extraout_r2;
  param_1[0xb] = extraout_r3;
  param_1[0xc] = unaff_r4;
  param_1[0xd] = unaff_r5;
  param_1[0xe] = unaff_r6;
  param_1[0xf] = unaff_r7;
  *param_1 = uStack_44;
  param_1[1] = uStack_40;
  param_1[2] = uStack_3c;
  param_1[3] = uStack_38;
  param_1[4] = uStack_34;
  param_1[5] = uStack_30;
  param_1[6] = uStack_2c;
  param_1[7] = unaff_r11;
  return;
}


