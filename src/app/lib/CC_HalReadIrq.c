/*
 * Function: CC_HalReadIrq
 * Entry:    0007d610
 * Prototype: undefined4 __stdcall CC_HalReadIrq(uint param_1, undefined4 * param_2)
 */


/* exclude_from_export_ai */

undefined4 CC_HalReadIrq(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  do {
    uVar2 = DAT_50845a00;
    if ((uVar2 & 0x100) != 0) {
      uVar3 = 1;
      param_1 = param_1 | 0x100;
      break;
    }
    uVar3 = 0;
  } while ((uVar2 & param_1) == 0);
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = Peripherals::CC_AES_S._260_4_;
    *param_2 = uVar1;
    Peripherals::CC_AES_S._264_4_ = uVar1;
  }
  DAT_50845a08 = param_1;
  return uVar3;
}


