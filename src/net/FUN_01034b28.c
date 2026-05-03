/*
 * Function: FUN_01034b28
 * Entry:    01034b28
 * Prototype: undefined1 * __stdcall FUN_01034b28(uint * param_1, uint param_2)
 */


undefined1 * FUN_01034b28(uint *param_1,uint param_2)

{
  undefined1 *puVar1;
  
  if ((int)((*param_1 >> (param_2 & 0xff)) << 0x1f) < 0) {
    puVar1 = &DAT_0bad0004;
  }
  else {
    do {
    } while (*param_1 != *param_1);
    *param_1 = 1 << (param_2 & 0xff) | *param_1;
    puVar1 = &DAT_0bad0000;
  }
  return puVar1;
}


