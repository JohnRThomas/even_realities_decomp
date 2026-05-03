/*
 * Function: FUN_000807aa
 * Entry:    000807aa
 * Prototype: int __stdcall FUN_000807aa(int param_1, int param_2, int param_3)
 */


int FUN_000807aa(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 - 1;
  if (uVar2 < 2) {
    param_2 = param_2 + 0xc;
  }
  if (uVar2 < 2) {
    param_1 = param_1 + -1;
  }
  iVar1 = param_1;
  if (param_1 < 0) {
    iVar1 = param_1 + 3;
  }
  return (((param_2 + 1) * 3) / 5 + param_3 + param_2 * 2 + param_1 + (iVar1 >> 2) + param_1 / -100
          + param_1 / 400 + 1) % 7;
}


