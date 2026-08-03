/*
 * Function: CC_PalWaitInterrupt
 * Entry:    0007d560
 * Prototype: CCError_t __stdcall CC_PalWaitInterrupt(uint32_t data)
 */


/* exclude_from_export_ai */

CCError_t CC_PalWaitInterrupt(uint32_t data)

{
  CCError_t CVar1;
  
  if (data != 0) {
    CVar1 = CC_HalWaitOnIrq(data);
    return CVar1;
  }
  return 0xf50000;
}


