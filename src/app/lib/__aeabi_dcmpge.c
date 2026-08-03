/*
 * Function: __aeabi_dcmpge
 * Entry:    0000de04
 * Prototype: bool __stdcall __aeabi_dcmpge(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

bool __aeabi_dcmpge(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  __aeabi_cdrcmple(param_1,param_2,param_3,param_4);
  return !(bool)in_CY || (bool)in_ZR;
}


