/*
 * Function: FUN_0008a1b6
 * Entry:    0008a1b6
 * Prototype: uint __stdcall FUN_0008a1b6(byte * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0007ad0c) */
/* WARNING: Removing unreachable block (ram,0x0007ad10) */
/* WARNING: Removing unreachable block (ram,0x0007ad72) */
/* WARNING: Removing unreachable block (ram,0x0007ad7c) */
/* WARNING: Removing unreachable block (ram,0x0007ad5c) */
/* WARNING: Removing unreachable block (ram,0x0007ad60) */
/* WARNING: Removing unreachable block (ram,0x0007ad6a) */
/* WARNING: Removing unreachable block (ram,0x0007adbe) */
/* WARNING: Removing unreachable block (ram,0x0007adb0) */
/* WARNING: Removing unreachable block (ram,0x0007adc2) */
/* WARNING: Removing unreachable block (ram,0x0007ace0) */

uint FUN_0008a1b6(byte *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  do {
    pbVar4 = param_1;
    param_1 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
    uVar5 = (byte)(&DAT_000f6aa2)[uVar3] & 8;
  } while (((&DAT_000f6aa2)[uVar3] & 8) != 0);
  if (uVar3 == 0x2d) {
    uVar3 = (uint)*param_1;
    uVar5 = 1;
    param_1 = pbVar4 + 2;
  }
  else if (uVar3 == 0x2b) {
    uVar3 = (uint)*param_1;
    param_1 = pbVar4 + 2;
  }
  iVar2 = 0;
  uVar7 = uVar5 + 0x7fffffff;
  uVar1 = 0;
  do {
    uVar6 = uVar3 - 0x30;
    if (9 < uVar6) {
      if (uVar3 - 0x41 < 0x1a) {
        uVar6 = uVar3 - 0x37;
      }
      else {
        if (0x19 < uVar3 - 0x61) {
LAB_0007ad9e:
          if (iVar2 == -1) {
            *DAT_20002d40 = 0x22;
            uVar1 = uVar7;
          }
          else if (uVar5 != 0) {
            uVar1 = -uVar1;
          }
          return uVar1;
        }
        uVar6 = uVar3 - 0x57;
      }
    }
    if (9 < (int)uVar6) goto LAB_0007ad9e;
    if (iVar2 != -1) {
      if ((uVar7 / 10 < uVar1) || ((uVar7 / 10 == uVar1 && ((int)(uVar7 % 10) < (int)uVar6)))) {
        iVar2 = -1;
      }
      else {
        uVar1 = uVar1 * 10 + uVar6;
        iVar2 = 1;
      }
    }
    uVar3 = (uint)*param_1;
    param_1 = param_1 + 1;
  } while( true );
}


