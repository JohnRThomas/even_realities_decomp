/*
 * Function: FUN_01024e0c
 * Entry:    01024e0c
 * Prototype: undefined __stdcall FUN_01024e0c(void)
 */


void FUN_01024e0c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_21001bca;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + ((uVar1 >> 5) + 0x40) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


