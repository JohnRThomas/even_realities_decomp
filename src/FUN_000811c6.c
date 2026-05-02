/*
 * Function: FUN_000811c6
 * Entry:    000811c6
 * Prototype: int __stdcall FUN_000811c6(byte * param_1, uint param_2, int param_3)
 */


int FUN_000811c6(byte *param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  pbVar2 = param_1;
  while ((uint)((int)pbVar2 - (int)param_1) < param_2) {
    bVar1 = *pbVar2;
    memset((void *)(param_3 + iVar3),(uint)pbVar2[1],(uint)bVar1);
    iVar3 = iVar3 + (uint)bVar1;
    pbVar2 = pbVar2 + 2;
  }
  return iVar3;
}


