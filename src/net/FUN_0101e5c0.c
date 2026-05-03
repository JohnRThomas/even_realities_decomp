/*
 * Function: FUN_0101e5c0
 * Entry:    0101e5c0
 * Prototype: int __stdcall FUN_0101e5c0(uint param_1, int param_2)
 */


int FUN_0101e5c0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (DAT_2100113c != 0) {
    uVar5 = 0xffffffff;
    iVar2 = 0;
    iVar1 = DAT_2100113c;
    do {
      iVar4 = iVar1;
      uVar3 = *(uint *)(iVar4 + 0xc);
      if ((param_1 <= uVar3) && (uVar3 < uVar5)) {
        iVar2 = iVar4;
        uVar5 = uVar3;
      }
      iVar1 = *(int *)(iVar4 + 0x18);
    } while (*(int *)(iVar4 + 0x18) != 0);
    if ((param_2 == 0) && (iVar2 == 0)) {
      iVar2 = iVar4;
    }
    return iVar2;
  }
  if (param_2 == 0) {
    return 0;
  }
  return 0;
}


