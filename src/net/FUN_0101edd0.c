/*
 * Function: FUN_0101edd0
 * Entry:    0101edd0
 * Prototype: undefined4 __stdcall FUN_0101edd0(uint param_1, uint param_2, uint param_3, int param_4)
 */


undefined4 FUN_0101edd0(uint param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (1 < param_1) {
    return 0x12;
  }
  if (param_4 == 2) {
    uVar3 = 0x270f9a7;
    if (0x270f9a7 < param_3 - 1000) {
      return 0x30;
    }
    iVar1 = -1000;
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
  iVar1 = -0x9c4;
  uVar3 = 0x270f3cb;
LAB_0101ede6:
  if (uVar3 < param_2 + iVar1) {
    return 0x30;
  }
  if (param_2 < param_3) {
    uVar2 = 0x12;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


