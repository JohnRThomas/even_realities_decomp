/*
 * Function: __aeabi_dcmpeq
 * Entry:    0000ddc8
 * Prototype: bool __stdcall __aeabi_dcmpeq(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

bool __aeabi_dcmpeq(uint param_1,uint param_2,uint param_3,uint param_4)

{
  char in_ZR;
  
  __aeabi_cdcmpeq(param_1,param_2,param_3,param_4);
  return in_ZR != '\0';
}


