/*
 * Function: __ledf2
 * Entry:    0000ddf0
 * Prototype: bool __stdcall __ledf2(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export_ai */

bool __ledf2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  __aeabi_cdcmpeq(param_1,param_2,param_3,param_4);
  return !(bool)in_CY || (bool)in_ZR;
}


