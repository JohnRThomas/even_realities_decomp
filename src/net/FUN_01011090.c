/*
 * Function: FUN_01011090
 * Entry:    01011090
 * Prototype: undefined __stdcall FUN_01011090(int param_1, uint * param_2)
 */


void FUN_01011090(int param_1,uint *param_2)

{
  uint uVar1;
  undefined1 auStack_9 [5];
  
  uVar1 = (uint)(ushort)param_2[1];
  if (param_1 == 1) {
    uVar1 = uVar1 | 0x10000;
  }
  FUN_01010edc(*param_2,uVar1,auStack_9);
  return;
}


