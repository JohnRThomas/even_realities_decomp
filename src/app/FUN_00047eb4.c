/*
 * Function: FUN_00047eb4
 * Entry:    00047eb4
 * Prototype: undefined * __stdcall FUN_00047eb4(uint param_1, int * param_2, undefined4 * param_3)
 */


undefined * FUN_00047eb4(uint param_1,int *param_2,undefined4 *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = 0;
  puVar5 = &DAT_0009cbe0;
  iVar3 = 0;
  while( true ) {
    if (0x60 < iVar4) {
      return (undefined *)0x0;
    }
    uVar2 = *puVar5;
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    if (uVar2 == param_1) break;
    iVar3 = (short)(ushort)(byte)*puVar1 * 0x1a + iVar3;
    iVar4 = iVar4 + 1;
  }
  *param_2 = (uint)(byte)*puVar1 << 1;
  *param_3 = 0x1a;
  return &DAT_000dc124 + iVar3;
}


