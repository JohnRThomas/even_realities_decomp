/*
 * Function: FUN_01011190
 * Entry:    01011190
 * Prototype: int __stdcall FUN_01011190(int param_1, int param_2)
 */


int FUN_01011190(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (param_1 + -1) * 0x80;
  uVar3 = (*(ushort *)(&DAT_0103c17c + param_2 * 2) + 999) / 1000;
  if (param_2 == 8) {
    return param_1 * 0x690 + uVar3 + iVar2;
  }
  if (param_2 == 4) {
    return param_1 * 0x2be + uVar3 + iVar2;
  }
  if (param_2 == 2) {
    iVar1 = 0x60;
  }
  else {
    iVar1 = 0xf0;
  }
  return iVar1 * param_1 + uVar3 + iVar2;
}


