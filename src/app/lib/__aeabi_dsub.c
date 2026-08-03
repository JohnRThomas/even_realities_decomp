/*
 * Function: __aeabi_dsub
 * Entry:    0000d580
 * Prototype: ulonglong __stdcall __aeabi_dsub(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

ulonglong __aeabi_dsub(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = __aeabi_dadd(param_1,param_2 ^ 0x80000000,param_3,param_4);
  return uVar1;
}


