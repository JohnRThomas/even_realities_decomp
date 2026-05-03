/*
 * Function: FUN_00087840
 * Entry:    00087840
 * Prototype: undefined4 __stdcall FUN_00087840(int param_1, uint param_2)
 */


undefined4 FUN_00087840(int param_1,uint param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  byte *pbVar4;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 8) + 0x20);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar1 = 0xffffffa8;
  }
  else {
    uVar5 = (uint)*(byte *)(*(int *)(param_1 + 4) + 0x18);
    if (uVar5 == 0) {
LAB_00087852:
                    /* WARNING: Could not recover jumptable at 0x00087856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
      return uVar1;
    }
    pbVar2 = *(byte **)(*(int *)(param_1 + 4) + 0x14);
    pbVar4 = pbVar2;
    do {
      pbVar3 = pbVar4 + 1;
      if (*pbVar4 == param_2) goto LAB_00087852;
      pbVar4 = pbVar3;
    } while (pbVar3 != pbVar2 + uVar5);
    uVar1 = 0xffffff7a;
  }
  return uVar1;
}


