/*
 * Function: FUN_0103a5ac
 * Entry:    0103a5ac
 * Prototype: undefined __stdcall FUN_0103a5ac(int param_1, uint param_2, int param_3, uint * param_4)
 */


void FUN_0103a5ac(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = *(uint *)(param_1 + 0x304);
  bVar5 = (uVar4 & 2) != 0;
  uVar1 = 0;
  if (bVar5) {
    uVar1 = 0x1000000 - param_3;
    *param_4 = uVar1;
  }
  uVar3 = 0;
  if (bVar5) {
    uVar1 = 1;
  }
  do {
    if (((1 << (uVar3 & 0xff) & param_2) != 0) && ((0x10000 << (uVar3 & 0xff) & uVar4) != 0)) {
      uVar2 = *(int *)(param_1 + (uVar3 + 0x150) * 4) - param_3 & 0xffffff;
      if (uVar2 == 0) {
        uVar2 = 0x1000000;
      }
      if ((uVar1 == 0) || (uVar2 < *param_4)) {
        *param_4 = uVar2;
      }
      uVar1 = 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 4);
  return;
}


