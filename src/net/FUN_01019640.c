/*
 * Function: FUN_01019640
 * Entry:    01019640
 * Prototype: undefined4 __stdcall FUN_01019640(uint param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01019640(uint param_1)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 & 1) != 0) {
    iVar1 = 1;
    *(undefined1 *)(_FUN_010196a4 + 0xbd) = 1;
    if ((int)(param_1 << 0x1e) < 0) {
      iVar1 = 2;
      *(undefined1 *)(_FUN_010196a4 + 0xbe) = 2;
    }
    if ((int)(param_1 << 0x1c) < 0) {
      *(undefined1 *)(iVar1 + _FUN_010196a4 + 0xbd) = 8;
    }
    return 0;
  }
  bVar2 = (int)(param_1 << 0x1e) < 0;
  if (bVar2) {
    *(undefined1 *)(_FUN_010196a4 + 0xbd) = 2;
  }
  if ((int)(param_1 << 0x1c) < 0) {
    *(undefined1 *)((uint)bVar2 + _FUN_010196a4 + 0xbd) = 8;
  }
  return 0;
}


