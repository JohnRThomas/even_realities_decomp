/*
 * Function: FUN_00082dce
 * Entry:    00082dce
 * Prototype: undefined4 __stdcall FUN_00082dce(undefined4 param_1, int param_2, uint * param_3, int param_4)
 */


undefined4 FUN_00082dce(undefined4 param_1,int param_2,uint *param_3,int param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  uint local_18;
  uint local_14;
  uint *puStack_10;
  
  local_18 = 0;
  local_14 = 0;
  pcVar2 = *(code **)(param_2 + 0x1c);
  if (param_4 == 8) {
    local_18 = param_3[1];
    local_14 = *param_3 & 0xffff1fff;
    if ((byte)*param_3 < 3) {
      if (*(byte *)((int)param_3 + 2) < 0xc) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffea;
      }
    }
    else {
      uVar1 = 0xffffffea;
    }
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
  }
  else {
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    uVar1 = 0xffffffea;
  }
  puStack_10 = param_3;
  (*pcVar2)(param_2 + -0x1028,uVar1,&local_18);
  return 1;
}


