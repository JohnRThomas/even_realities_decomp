/*
 * Function: b2d
 * Entry:    0007beec
 * Prototype: uint __stdcall b2d(int param_1)
 */


/* exclude_from_export_ai */

uint b2d(int param_1)

{
  int iVar1;
  uint uVar2;
  int *extraout_r1;
  int extraout_r2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0x14;
  iVar4 = uVar6 + *(int *)(param_1 + 0x10) * 4;
  uVar5 = iVar4 - 4;
  iVar1 = hi0bits(*(uint *)(iVar4 + -4));
  *extraout_r1 = 0x20 - iVar1;
  if (iVar1 < 0xb) {
    if (uVar6 < uVar5) {
      uVar5 = *(uint *)(iVar4 + -8);
    }
    else {
      uVar5 = 0;
    }
    uVar3 = uVar5 >> (0xbU - iVar1 & 0xff) | extraout_r2 << (iVar1 + 0x15U & 0xff);
  }
  else {
    if (uVar6 < uVar5) {
      uVar5 = iVar4 - 8;
      uVar3 = *(uint *)(iVar4 + -8);
    }
    else {
      uVar3 = 0;
    }
    uVar2 = iVar1 - 0xb;
    if (uVar2 != 0) {
      if (uVar6 < uVar5) {
        uVar5 = *(uint *)(uVar5 - 4);
      }
      else {
        uVar5 = 0;
      }
      uVar3 = uVar3 << (uVar2 & 0xff) | uVar5 >> (0x20 - uVar2 & 0xff);
    }
  }
  return uVar3;
}


