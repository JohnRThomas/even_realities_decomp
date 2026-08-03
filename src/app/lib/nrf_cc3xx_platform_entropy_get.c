/*
 * Function: nrf_cc3xx_platform_entropy_get
 * Entry:    0007dc70
 * Prototype: int __stdcall nrf_cc3xx_platform_entropy_get(uint8_t * buffer, size_t length, size_t * olen)
 */


/* exclude_from_export_ai */

int nrf_cc3xx_platform_entropy_get(uint8_t *buffer,size_t length,size_t *olen)

{
  CCError_t CVar1;
  uint32_t **in_stack_00000000;
  uint32_t *in_stack_00000004;
  uint32_t *in_stack_00000008;
  
  CVar1 = getTrngSource((CCRndState_t *)buffer,(CCRndParams_t *)length,(CCBool_t)olen,
                        in_stack_00000000,in_stack_00000004,in_stack_00000008,0);
  return CVar1;
}


