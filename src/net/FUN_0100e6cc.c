/*
 * Function: FUN_0100e6cc
 * Entry:    0100e6cc
 * Prototype: undefined4 __stdcall FUN_0100e6cc(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint param_4)
 */


undefined4 FUN_0100e6cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  int unaff_r4;
  
  uVar2 = (uint)*(byte *)(unaff_r4 + 0x29);
  if (((int)(uVar2 << 0x1f) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
    cVar3 = '\x03';
LAB_0100e75e:
    cVar1 = '\0';
  }
  else {
    if (((int)(uVar2 << 0x1e) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e73a:
      cVar1 = '\x01';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x1d) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e740:
      cVar1 = '\x02';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x1c) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e746:
      cVar1 = '\x03';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x1b) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e74c:
      cVar1 = '\x04';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x1a) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e752:
      cVar1 = '\x05';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x19) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
LAB_0100e758:
      cVar1 = '\x06';
      goto LAB_0100e556;
    }
    if (((int)(uVar2 << 0x18) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
      cVar3 = '\x03';
    }
    else {
      if (*(byte *)(unaff_r4 + 0x2f) < param_4) {
        return 0x1f;
      }
      uVar2 = (uint)*(byte *)(unaff_r4 + 0x2a);
      if (((int)(uVar2 << 0x1f) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e75e;
      }
      if (((int)(uVar2 << 0x1e) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e73a;
      }
      if (((int)(uVar2 << 0x1d) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e740;
      }
      if (((int)(uVar2 << 0x1c) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e746;
      }
      if (((int)(uVar2 << 0x1b) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e74c;
      }
      if (((int)(uVar2 << 0x1a) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e752;
      }
      if (((int)(uVar2 << 0x19) < 0) && (param_4 = param_4 - 1 & 0xff, param_4 == 0)) {
        cVar3 = '\x04';
        goto LAB_0100e758;
      }
      if (-1 < (int)(uVar2 << 0x18)) {
        return 0x1f;
      }
      if (param_4 != 1) {
        return 0x1f;
      }
      cVar3 = '\x04';
    }
    cVar1 = '\a';
  }
LAB_0100e556:
  *(char *)(unaff_r4 + 0x33) = cVar1 + cVar3 * '\b';
  return param_1;
}


