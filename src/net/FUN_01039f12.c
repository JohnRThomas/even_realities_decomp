/*
 * Function: FUN_01039f12
 * Entry:    01039f12
 * Prototype: undefined __stdcall FUN_01039f12(int param_1, int param_2, int param_3, undefined4 param_4)
 */


void FUN_01039f12(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_1 + param_2 * 8;
  if (*(uint *)(param_1 + 8) < 0x8000) {
    *(short *)(iVar1 + param_3 * 2) = (short)param_4;
  }
  else {
    *(undefined4 *)(iVar1 + param_3 * 4) = param_4;
  }
  return;
}


