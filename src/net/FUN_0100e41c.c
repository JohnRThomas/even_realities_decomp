/*
 * Function: FUN_0100e41c
 * Entry:    0100e41c
 * Prototype: undefined4 __stdcall FUN_0100e41c(int param_1, int param_2, int param_3)
 */


undefined4 FUN_0100e41c(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(byte *)(param_1 + 0x30);
  if (0x24 < uVar5 - 1) {
    return 0x12;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x25) != '\0') {
    if (*(char *)(param_1 + 0x25) != '\x01') {
      return 0x1f;
    }
    uVar5 = FUN_0100e078(param_1 + 0x25,*(uint *)(param_2 + 0x18),(uint)*(ushort *)(param_1 + 0x14))
    ;
    *(char *)(param_1 + 0x33) = (char)uVar5;
    return 0;
  }
  iVar2 = param_3 * (uint)*(byte *)(param_1 + 0x31) + (uint)*(byte *)(param_1 + 0x32);
  uVar3 = iVar2 + (iVar2 / 0x25 + (iVar2 >> 0x1f)) * -0x25;
  uVar4 = uVar3 & 0xff;
  *(char *)(param_1 + 0x32) = (char)uVar3;
  if (((uint)*(byte *)(param_1 + (uVar4 >> 3) + 0x26) & 1 << (uVar3 & 7)) != 0) {
    *(char *)(param_1 + 0x33) = (char)uVar3;
    return 0;
  }
  uVar3 = uVar4 - uVar5 * (uVar4 / uVar5) & 0xff;
  uVar5 = uVar3 + 1 & 0xff;
  if (*(byte *)(param_1 + 0x2b) < uVar5) {
    uVar5 = uVar5 - *(byte *)(param_1 + 0x2b) & 0xff;
LAB_0100e4ae:
    if (*(byte *)(param_1 + 0x2c) < uVar5) {
      uVar5 = uVar5 - *(byte *)(param_1 + 0x2c) & 0xff;
    }
    else {
      uVar4 = (uint)*(byte *)(param_1 + 0x27);
      uVar3 = uVar4 & 1;
      if (((*(byte *)(param_1 + 0x27) & 1) != 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0))
      goto LAB_0100e75e;
      if (((int)(uVar4 << 0x1e) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e73a;
      }
      if (((int)(uVar4 << 0x1d) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e740;
      }
      if (((int)(uVar4 << 0x1c) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e746;
      }
      if (((int)(uVar4 << 0x1b) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e74c;
      }
      if (((int)(uVar4 << 0x1a) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e752;
      }
      if (((int)(uVar4 << 0x19) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e758;
      }
      if (((int)(uVar4 << 0x18) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 1;
        goto LAB_0100e554;
      }
    }
    if (*(byte *)(param_1 + 0x2d) < uVar5) {
      uVar5 = uVar5 - *(byte *)(param_1 + 0x2d) & 0xff;
    }
    else {
      uVar3 = (uint)*(byte *)(param_1 + 0x28);
      if (((int)(uVar3 << 0x1f) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e75e;
      }
      if (((int)(uVar3 << 0x1e) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e73a;
      }
      if (((int)(uVar3 << 0x1d) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e740;
      }
      if (((int)(uVar3 << 0x1c) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e746;
      }
      if (((int)(uVar3 << 0x1b) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e74c;
      }
      if (((int)(uVar3 << 0x1a) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e752;
      }
      if (((int)(uVar3 << 0x19) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e758;
      }
      if (((int)(uVar3 << 0x18) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 2;
        goto LAB_0100e554;
      }
    }
    if (*(byte *)(param_1 + 0x2e) < uVar5) {
      uVar5 = uVar5 - *(byte *)(param_1 + 0x2e) & 0xff;
    }
    else {
      uVar3 = (uint)*(byte *)(param_1 + 0x29);
      if (((int)(uVar3 << 0x1f) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e75e;
      }
      if (((int)(uVar3 << 0x1e) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e73a;
      }
      if (((int)(uVar3 << 0x1d) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e740;
      }
      if (((int)(uVar3 << 0x1c) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e746;
      }
      if (((int)(uVar3 << 0x1b) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e74c;
      }
      if (((int)(uVar3 << 0x1a) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e752;
      }
      if (((int)(uVar3 << 0x19) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e758;
      }
      if (((int)(uVar3 << 0x18) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
        uVar3 = 3;
        goto LAB_0100e554;
      }
    }
    if (*(byte *)(param_1 + 0x2f) < uVar5) {
      return 0x1f;
    }
    uVar3 = (uint)*(byte *)(param_1 + 0x2a);
    if (((int)(uVar3 << 0x1f) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e75e:
      cVar1 = '\0';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x1e) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e73a:
      cVar1 = '\x01';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x1d) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e740:
      cVar1 = '\x02';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x1c) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e746:
      cVar1 = '\x03';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x1b) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e74c:
      cVar1 = '\x04';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x1a) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e752:
      cVar1 = '\x05';
      goto LAB_0100e556;
    }
    if (((int)(uVar3 << 0x19) < 0) && (uVar5 = uVar5 - 1 & 0xff, uVar5 == 0)) {
      uVar3 = 4;
LAB_0100e758:
      cVar1 = '\x06';
      goto LAB_0100e556;
    }
    if (-1 < (int)(uVar3 << 0x18)) {
      return 0x1f;
    }
    if (uVar5 != 1) {
      return 0x1f;
    }
    uVar3 = 4;
  }
  else {
    uVar4 = (uint)*(byte *)(param_1 + 0x26);
    if (((*(byte *)(param_1 + 0x26) & 1) != 0) && (uVar5 = uVar3, uVar3 == 0)) {
      uVar3 = 0;
      goto LAB_0100e75e;
    }
    if ((int)(uVar4 << 0x1e) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e586;
      goto LAB_0100e73a;
    }
LAB_0100e586:
    if ((int)(uVar4 << 0x1d) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e594;
      goto LAB_0100e740;
    }
LAB_0100e594:
    if ((int)(uVar4 << 0x1c) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e5a2;
      goto LAB_0100e746;
    }
LAB_0100e5a2:
    if ((int)(uVar4 << 0x1b) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e5b0;
      goto LAB_0100e74c;
    }
LAB_0100e5b0:
    if ((int)(uVar4 << 0x1a) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e5be;
      goto LAB_0100e752;
    }
LAB_0100e5be:
    if ((int)(uVar4 << 0x19) < 0) {
      uVar5 = uVar5 - 1 & 0xff;
      uVar3 = 0;
      if (uVar5 != 0) goto LAB_0100e5cc;
      goto LAB_0100e758;
    }
LAB_0100e5cc:
    if ((-1 < (int)(uVar4 << 0x18)) || (uVar5 = uVar5 - 1 & 0xff, uVar5 != 0)) goto LAB_0100e4ae;
    uVar3 = 0;
  }
LAB_0100e554:
  cVar1 = '\a';
LAB_0100e556:
  *(char *)(param_1 + 0x33) = cVar1 + (char)(uVar3 << 3);
  return 0;
}


