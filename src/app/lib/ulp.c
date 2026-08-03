/*
 * Function: ulp
 * Entry:    0007bea0
 * Prototype: double __stdcall ulp(double x)
 */


/* exclude_from_export_ai */

double ulp(double x)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_4;
  
  uStack_4 = (uint)((ulonglong)x >> 0x20);
  iVar2 = (uStack_4 & 0x7ff00000) + 0xfcc00000;
  if (iVar2 < 1) {
    uVar1 = -iVar2 >> 0x14;
    if (0x13fffff < -iVar2) {
      uVar1 = uVar1 - 0x14;
      if ((int)uVar1 < 0x1f) {
        uVar1 = 0x80000000 >> (uVar1 & 0xff);
      }
      else {
        uVar1 = 1;
      }
      iVar2 = 0;
      goto LAB_0007bedc;
    }
    iVar2 = 0x80000 >> (uVar1 & 0xff);
  }
  uVar1 = 0;
LAB_0007bedc:
  return (double)CONCAT44(iVar2,uVar1);
}


