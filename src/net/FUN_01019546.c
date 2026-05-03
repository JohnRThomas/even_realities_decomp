/*
 * Function: FUN_01019546
 * Entry:    01019546
 * Prototype: uint __stdcall FUN_01019546(undefined4 param_1, undefined1 param_2, int param_3, int param_4)
 */


uint FUN_01019546(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  uint extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  
  *(undefined4 *)(param_4 + 0xc0) = param_1;
  if (param_3 == 0) {
    FUN_01009500(0x32,0x9a9,0,param_4);
    uVar2 = extraout_r2_00;
    uVar3 = extraout_r3_00;
  }
  else {
    *(undefined2 *)(param_4 + 0xba) = 0;
    *(undefined1 *)(param_4 + 0xbc) = 0;
    *(undefined1 *)(param_4 + 0x70) = 0;
    FUN_01019d88();
    iVar1 = FUN_010194ac(param_2);
    uVar2 = extraout_r2;
    uVar3 = extraout_r3;
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_01009500(0x32,0x9af,uVar2,uVar3);
  DAT_21001054 = &DAT_21000328;
  return extraout_r2_01 >> 0x1e;
}


