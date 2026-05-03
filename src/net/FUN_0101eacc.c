/*
 * Function: FUN_0101eacc
 * Entry:    0101eacc
 * Prototype: undefined4 __stdcall FUN_0101eacc(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0101eacc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 extraout_r2;
  uint uVar2;
  int iVar3;
  undefined1 extraout_r3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  switch(param_1) {
  case 1:
    return 0;
  case 2:
    return 1;
  case 4:
    return 3;
  case 8:
    return 2;
  }
  uVar5 = FUN_01009500(0x78,0x2a8,param_3,param_4);
  uVar6 = FUN_010200cc();
  iVar4 = (int)uVar6;
  uVar1 = (int)((ulonglong)uVar5 >> 0x20) - 1U & 0xff;
  if (3 < uVar1) {
    return 0x11;
  }
  if (iVar4 << 0x17 < 0) {
    if (-1 < iVar4 << 0x14) {
      uVar2 = 3;
      goto LAB_0101eb26;
    }
  }
  else {
    if (iVar4 << 0x17 < 0 || iVar4 << 0x14 < 0) {
      uVar2 = 0xd;
    }
    else {
      uVar2 = 1;
    }
LAB_0101eb26:
    if ((1 << uVar1 & uVar2) == 0) {
      return 0x11;
    }
  }
  iVar4 = *(int *)((int)uVar5 + 4);
  uVar2 = ((uint)*(byte *)(iVar4 + 0x11a) << 0x1e) >> 0x1f;
  if ((int)((uint)*(byte *)(iVar4 + 0x11a) << 0x1e) < 0) {
    iVar3 = *(int *)(iVar4 + 0x116);
    if (iVar3 << 0x17 < 0) {
      if (iVar3 << 0x14 < 0) goto LAB_0101eb5a;
      uVar2 = 3;
    }
    else if (iVar3 << 0x14 < 0 || iVar3 << 0x17 < 0) {
      uVar2 = 0xd;
    }
    if ((1 << uVar1 & 0xffU & uVar2) != 0) {
LAB_0101eb5a:
      if (*(char *)(iVar4 + 0x1a9) == '\0') {
        *(undefined1 *)(iVar4 + 0x1a9) = extraout_r3;
        *(char *)(iVar4 + 0x1a7) = (char)(1 << uVar1);
        *(undefined1 *)(iVar4 + 0x1a8) = extraout_r2;
        return 0;
      }
      return 0x3a;
    }
  }
  return 0x1a;
}


