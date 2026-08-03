/*
 * Function: sulp
 * Entry:    0008a89a
 * Prototype: uint __stdcall sulp(undefined4 param_1, uint param_2, int param_3)
 */


/* exclude_from_export_ai */

uint sulp(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  double dVar3;
  ulonglong uVar4;
  
  dVar3 = ulp((double)CONCAT44(param_2,param_1));
  uVar1 = SUB84(dVar3,0);
  if ((param_3 != 0) && (iVar2 = 0x6b - ((param_2 & 0x7fffffff) >> 0x14), 0 < iVar2)) {
    uVar4 = __muldf3(uVar1,(uint)((ulonglong)dVar3 >> 0x20),0,iVar2 * 0x100000 + 0x3ff00000);
    uVar1 = (uint)uVar4;
  }
  return uVar1;
}


