/*
 * Function: FUN_0101963c
 * Entry:    0101963c
 * Prototype: undefined4 __stdcall FUN_0101963c(undefined4 param_1, undefined4 param_2, uint param_3)
 */


/* WARNING: Removing unreachable block (ram,0x01019694) */
/* WARNING: Removing unreachable block (ram,0x0101966a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101963c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3 >> 0x1e;
  if ((uVar1 & 1) != 0) {
    *(undefined1 *)(_FUN_010196a4 + 0xbd) = 1;
    if ((int)(uVar1 << 0x1e) < 0) {
      *(undefined1 *)(_FUN_010196a4 + 0xbe) = 2;
    }
    return 0;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    *(undefined1 *)(_FUN_010196a4 + 0xbd) = 2;
  }
  return 0;
}


