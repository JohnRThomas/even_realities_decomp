/*
 * Function: CC_HalWaitInterrupt
 * Entry:    0007d56c
 * Prototype: CCError_t __stdcall CC_HalWaitInterrupt(uint32_t data)
 */


/* exclude_from_export_ai */

CCError_t CC_HalWaitInterrupt(uint32_t data)

{
  CCError_t CVar1;
  undefined4 *in_r1;
  
  if (data != 0) {
    CVar1 = CC_HalReadIrq(data,in_r1);
    return CVar1;
  }
  return 0xf50000;
}


