/*
 * Function: __aeabi_uldivmod
 * Entry:    0000e244
 * Prototype: void __stdcall __aeabi_uldivmod(int param_1, int param_2, int param_3, int param_4)
 */


/* exclude_from_export */

void __aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  uint local_8 [2];
  
  if ((param_4 == 0) && (param_3 == 0)) {
    return;
  }
  __udivmoddi4(param_1,param_2,param_3,param_4,local_8);
  return;
}


