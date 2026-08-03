/*
 * Function: CC_HalWaitOnIrq
 * Entry:    0007d64c
 * Prototype: undefined4 __stdcall CC_HalWaitOnIrq(uint param_1)
 */


/* exclude_from_export_ai */

undefined4 CC_HalWaitOnIrq(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  do {
    uVar1 = DAT_50845a00;
    if ((uVar1 & 0x100) != 0) {
      uVar2 = 1;
      param_1 = param_1 | 0x100;
      break;
    }
    uVar2 = 0;
  } while ((param_1 & uVar1) == 0);
  DAT_50845a08 = param_1;
  return uVar2;
}


