/*
 * Function: FUN_0100ea94
 * Entry:    0100ea94
 * Prototype: uint __stdcall FUN_0100ea94(int param_1, int param_2)
 */


uint FUN_0100ea94(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = *(byte *)(param_1 + 3) & 0x3f;
  if ((*(byte *)(param_1 + 3) & 0x3f) == 0) {
    return uVar2;
  }
  bVar1 = *(byte *)(param_1 + 4);
  uVar4 = (uint)bVar1;
  if ((int)(uVar4 << 0x1f) < 0) {
    if (param_2 == 0) {
LAB_0100eb52:
      iVar3 = 5;
LAB_0100eb54:
      return param_1 + iVar3;
    }
    if (-1 < (int)(uVar4 << 0x1e)) {
      uVar4 = 0xb;
      goto LAB_0100eab0;
    }
    if (param_2 == 1) {
      iVar3 = 0xb;
      goto LAB_0100eb54;
    }
    uVar4 = 0x11;
    if ((bVar1 & 4) == 0) goto LAB_0100eb22;
LAB_0100eabc:
    if (param_2 == 2) goto LAB_0100eb46;
    uVar4 = uVar4 + 1;
    if ((bVar1 & 8) != 0) goto LAB_0100eaca;
LAB_0100eb2c:
    if (param_2 == 3) {
      return 0;
    }
    if ((bVar1 & 0x10) == 0) goto LAB_0100eb36;
LAB_0100ead8:
    if (param_2 == 4) goto LAB_0100eb46;
    uVar4 = uVar4 + 3;
  }
  else {
    if (param_2 == 0) {
      return 0;
    }
    if ((int)(uVar4 << 0x1e) < 0) {
      if (param_2 == 1) goto LAB_0100eb52;
      uVar4 = 0xb;
    }
    else {
      uVar4 = 5;
LAB_0100eab0:
      if (param_2 == 1) {
        return 0;
      }
    }
    if ((bVar1 & 4) != 0) goto LAB_0100eabc;
LAB_0100eb22:
    if (param_2 == 2) {
      return 0;
    }
    if ((bVar1 & 8) == 0) goto LAB_0100eb2c;
LAB_0100eaca:
    if (param_2 == 3) goto LAB_0100eb46;
    uVar4 = uVar4 + 2;
    if ((bVar1 & 0x10) != 0) goto LAB_0100ead8;
LAB_0100eb36:
    if (param_2 == 4) {
      return 0;
    }
  }
  if ((bVar1 & 0x20) == 0) {
    if (param_2 == 5) {
      return 0;
    }
  }
  else {
    if (param_2 == 5) goto LAB_0100eb46;
    uVar4 = uVar4 + 0x12 & 0xff;
  }
  if ((bVar1 & 0x40) == 0) {
    if (param_2 == 6) {
      return 0;
    }
  }
  else {
    if (param_2 == 6) goto LAB_0100eb46;
    uVar4 = uVar4 + 1 & 0xff;
  }
  if ((param_2 != 7) || ((int)uVar2 < (int)(uVar4 - 4))) {
    return 0;
  }
LAB_0100eb46:
  return param_1 + uVar4;
}


