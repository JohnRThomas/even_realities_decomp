/*
 * Function: __aeabi_cdrcmple
 * Entry:    0000dda8
 * Prototype: undefined __stdcall __aeabi_cdrcmple(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

void __aeabi_cdrcmple(uint param_1,uint param_2,uint param_3,uint param_4)

{
  __aeabi_cdcmpeq(param_3,param_4,param_1,param_2);
  return;
}


