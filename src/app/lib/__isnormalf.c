/*
 * Function: __isnormalf
 * Entry:    00078c28
 * Prototype: bool __stdcall __isnormalf(uint param_1)
 */


/* exclude_from_export_ai */

bool __isnormalf(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0x7fffffff;
  if (uVar1 == 0) {
    return true;
  }
  if (0x7effffff < uVar1 - 0x800000) {
    if (0x7ffffe < uVar1 - 1) {
      return uVar1 == 0x7f800000;
    }
    return true;
  }
  return true;
}


