/*
 * Function: log
 * Entry:    00012c78
 * Prototype: double __stdcall log(double __x)
 */


/* exclude_from_export */

double log(double __x)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  double dVar7;
  
  uVar4 = SUB84(__x,0);
  uVar6 = (uint)((ulonglong)__x >> 0x20);
  uVar5 = log_outline();
  dVar7 = (double)CONCAT44(extraout_s1,uVar5);
  if (((DAT_20003751 != -1) && (iVar2 = __unorddf2(uVar4,uVar6,uVar4,uVar6), iVar2 == 0)) &&
     (bVar1 = __ltdf2(uVar4,uVar6,0,0), !bVar1)) {
    bVar1 = __aeabi_dcmpeq(uVar4,uVar6,0,0);
    if (!bVar1) {
      piVar3 = __errno();
      *piVar3 = 0x21;
      uVar5 = log_outline_float_math();
      return (double)CONCAT44(extraout_s1_00,uVar5);
    }
    piVar3 = __errno();
    dVar7 = -INFINITY;
    *piVar3 = 0x22;
  }
  return dVar7;
}


