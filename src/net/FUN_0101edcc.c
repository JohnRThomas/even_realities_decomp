/*
 * Function: FUN_0101edcc
 * Entry:    0101edcc
 * Prototype: undefined4 __stdcall FUN_0101edcc(undefined4 param_1, int param_2, uint param_3, int param_4)
 */


undefined4 FUN_0101edcc(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (1 < (uint)(param_2 >> 8)) {
    return 0x12;
  }
  if (param_4 == 2) {
    uVar2 = 0x270f9a7;
    if (0x270f9a7 < param_3 - 1000) {
      return 0x30;
    }
    uVar3 = 0xfffffc18;
    goto LAB_0101ede6;
  }
  if (0x270fd8f < param_3) {
    return 0x30;
  }
  if (param_4 == 1) {
    uVar3 = 0x752;
LAB_0101ee02:
    if (param_3 <= uVar3) {
      return 0x30;
    }
  }
  else if (param_4 == 4) {
    uVar3 = 0x9c3;
    goto LAB_0101ee02;
  }
  uVar3 = 0xfffff63c;
  uVar2 = 0x270f3cb;
LAB_0101ede6:
  if (uVar2 < uVar3) {
    return 0x30;
  }
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x12;
  }
  return uVar1;
}


