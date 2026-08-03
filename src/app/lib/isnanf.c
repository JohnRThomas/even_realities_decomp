/*
 * Function: isnanf
 * Entry:    0000e938
 * Prototype: int __stdcall isnanf(float param_1)
 */


/* exclude_from_export_ai */

int isnanf(float param_1)

{
  int iVar1;
  undefined4 in_r1;
  uint uVar2;
  undefined4 in_r2;
  uint in_r3;
  ulonglong uVar3;
  
  uVar3 = __aeabi_f2d((uint)param_1,in_r1,in_r2,in_r3);
  uVar2 = (uint)(uVar3 >> 0x20);
  iVar1 = __unorddf2((int)uVar3,uVar2,(int)uVar3,uVar2);
  return (uint)(iVar1 != 0);
}


