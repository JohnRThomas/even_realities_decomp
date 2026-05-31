/*
 * Function: FUN_00047e70
 * Entry:    00047e70
 * Prototype: undefined * __stdcall FUN_00047e70(uint param_1, int * param_2, undefined4 * param_3)
 */


undefined * FUN_00047e70(uint param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  iVar2 = 0;
  uVar1 = 0;
  ppuVar3 = &PTR_DAT_0009cd64;
  while( true ) {
    if (10 < iVar2) {
      return (undefined *)0x0;
    }
    if (*(ushort *)ppuVar3 == param_1) break;
    uVar1 = uVar1 + (uint)*(byte *)((int)ppuVar3 + 2) * 0x20 & 0xffff;
    iVar2 = iVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  *param_2 = (uint)*(byte *)((int)ppuVar3 + 2) << 1;
  *param_3 = 0x20;
  return &DAT_000dedd4 + uVar1;
}


