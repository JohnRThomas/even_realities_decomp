/*
 * Function: __aeabi_d2ulz
 * Entry:    0000e274
 * Prototype: undefined __stdcall __aeabi_d2ulz(uint param_1, uint param_2)
 */


/* exclude_from_export_ai */

void __aeabi_d2ulz(uint param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = __muldf3(param_1,param_2,0,0x3df00000);
  uVar1 = __fixunsdfsi((uint)uVar2,(uint)(uVar2 >> 0x20));
  uVar2 = __floatunsidf(uVar1);
  uVar2 = __muldf3((uint)uVar2,(uint)(uVar2 >> 0x20),0,0x41f00000);
  uVar2 = __subdf(param_1,param_2,(uint)uVar2,(uint)(uVar2 >> 0x20));
  __fixunsdfsi((uint)uVar2,(uint)(uVar2 >> 0x20));
  return;
}


