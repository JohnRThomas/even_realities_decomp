/*
 * Function: $_newlib_FUN_0007acd0
 * Entry:    0007acd0
 * Prototype: uint __stdcall $_newlib_FUN_0007acd0(undefined4 * param_1, byte * param_2, undefined4 * param_3, uint param_4)
 */


uint __newlib_FUN_0007acd0(undefined4 *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if ((0x24 < param_4) || (pbVar6 = param_2, param_4 == 1)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    return 0;
  }
  do {
    pbVar5 = pbVar6;
    pbVar6 = pbVar5 + 1;
    uVar4 = (uint)*pbVar5;
    uVar7 = (byte)(&DAT_000f6aa2)[uVar4] & 8;
  } while (((&DAT_000f6aa2)[uVar4] & 8) != 0);
  if (uVar4 == 0x2d) {
    uVar4 = (uint)*pbVar6;
    uVar7 = 1;
    pbVar6 = pbVar5 + 2;
  }
  else if (uVar4 == 0x2b) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = pbVar5 + 2;
  }
  if (param_4 == 0) {
    if (uVar4 != 0x30) {
      param_4 = 10;
      goto LAB_0007ad12;
    }
    if ((*pbVar6 & 0xdf) != 0x58) {
      param_4 = 8;
      goto LAB_0007ad12;
    }
  }
  else if (((param_4 != 0x10) || (uVar4 != 0x30)) || ((*pbVar6 & 0xdf) != 0x58)) goto LAB_0007ad12;
  uVar4 = (uint)pbVar6[1];
  param_4 = 0x10;
  pbVar6 = pbVar6 + 2;
LAB_0007ad12:
  iVar3 = 0;
  uVar10 = uVar7 + 0x7fffffff;
  uVar2 = 0;
  uVar9 = uVar10 / param_4;
  do {
    uVar8 = uVar4 - 0x30;
    if (9 < uVar8) {
      if (uVar4 - 0x41 < 0x1a) {
        uVar8 = uVar4 - 0x37;
      }
      else {
        if (0x19 < uVar4 - 0x61) break;
        uVar8 = uVar4 - 0x57;
      }
    }
    if ((int)param_4 <= (int)uVar8) break;
    if (iVar3 != -1) {
      if ((uVar9 < uVar2) || ((uVar9 == uVar2 && ((int)(uVar10 - param_4 * uVar9) < (int)uVar8)))) {
        iVar3 = -1;
      }
      else {
        uVar2 = uVar2 * param_4 + uVar8;
        iVar3 = 1;
      }
    }
    uVar4 = (uint)*pbVar6;
    pbVar6 = pbVar6 + 1;
  } while( true );
  if (iVar3 == -1) {
    *param_1 = 0x22;
    uVar2 = uVar10;
    if (param_3 == (undefined4 *)0x0) {
      return uVar10;
    }
  }
  else {
    if (uVar7 != 0) {
      uVar2 = -uVar2;
    }
    if (param_3 == (undefined4 *)0x0) {
      return uVar2;
    }
    if (iVar3 == 0) goto LAB_0007adc2;
  }
  param_2 = pbVar6 + -1;
LAB_0007adc2:
  *param_3 = param_2;
  return uVar2;
}


