/*
 * Function: __aeabi_ldivmod
 * Entry:    0000e1a4
 * Prototype: undefined8 __stdcall __aeabi_ldivmod(uint param_1, uint param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

undefined8 __aeabi_ldivmod(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint local_8 [2];
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if ((int)param_2 < 0) {
      param_1 = 0;
      param_2 = 0x80000000;
    }
    else if (param_2 != 0 || param_1 != 0) {
      param_2 = 0x7fffffff;
      param_1 = 0xffffffff;
    }
    return CONCAT44(param_2,param_1);
  }
  if ((int)param_2 < 0) {
    uVar1 = -param_2 - (uint)(param_1 != 0);
    if ((int)param_4 < 0) {
      uVar2 = __udivmoddi4(-param_1,uVar1,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
      return uVar2;
    }
    uVar2 = __udivmoddi4(-param_1,uVar1,param_3,param_4,local_8);
    return CONCAT44(-(int)((ulonglong)uVar2 >> 0x20) - (uint)((int)uVar2 != 0),-(int)uVar2);
  }
  if ((int)param_4 < 0) {
    uVar2 = __udivmoddi4(param_1,param_2,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
    return CONCAT44(-(int)((ulonglong)uVar2 >> 0x20) - (uint)((int)uVar2 != 0),-(int)uVar2);
  }
  uVar2 = __udivmoddi4(param_1,param_2,param_3,param_4,local_8);
  return uVar2;
}


