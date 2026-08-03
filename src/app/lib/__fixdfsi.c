/*
 * Function: __fixdfsi
 * Entry:    0000ec34
 * Prototype: int __stdcall __fixdfsi(uint param_1, uint param_2)
 */


/* exclude_from_export_ai */

int __fixdfsi(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = __gedf2(param_1,param_2,0,0);
  if (!bVar1) {
    iVar2 = __aeabi_d2ulz(param_1,param_2);
    return iVar2;
  }
  iVar2 = __aeabi_d2ulz(param_1,param_2 + 0x80000000);
  return -iVar2;
}


