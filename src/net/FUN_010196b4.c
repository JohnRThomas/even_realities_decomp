/*
 * Function: FUN_010196b4
 * Entry:    010196b4
 * Prototype: undefined1 __stdcall FUN_010196b4(int param_1, uint param_2, byte * param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_010196b4(int param_1,uint param_2,byte *param_3)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = _FUN_01019700;
  uVar4 = (uint)*(byte *)(_FUN_01019700 + 0x44);
  bVar5 = uVar4 - 2 == 1;
  if (uVar4 - 2 < 2) {
    bVar5 = param_1 == 0;
  }
  if (bVar5) {
    iVar3 = FUN_0100cf44((uint)((param_2 & 0xfd) != 0),param_3);
    if (iVar3 != 8) {
      return 1;
    }
    uVar4 = (uint)*(byte *)(iVar1 + 0x44);
  }
  uVar2 = FUN_0100b290((uint)((uVar4 & 0xfd) != 0));
  return uVar2;
}


