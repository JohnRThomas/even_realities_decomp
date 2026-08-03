/*
 * Function: __gedf2
 * Entry:    0000dddc
 * Prototype: bool __stdcall __gedf2(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export_ai */

bool __gedf2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  char in_CY;
  
  __aeabi_cdcmpeq(param_1,param_2,param_3,param_4);
  return in_CY == '\0';
}


