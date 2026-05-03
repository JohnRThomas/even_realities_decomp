/*
 * Function: FUN_01034ae8
 * Entry:    01034ae8
 * Prototype: undefined1 * __stdcall FUN_01034ae8(uint * param_1, undefined1 * param_2)
 */


undefined1 * FUN_01034ae8(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
    if (uVar1 == 0) {
      return &DAT_0bad0002;
    }
  } while (*param_1 != uVar1);
  *param_1 = uVar1 & ~(1 << (0x1fU - LZCOUNT(uVar1) & 0xff));
  *param_2 = (char)(0x1fU - LZCOUNT(uVar1));
  return &DAT_0bad0000;
}


