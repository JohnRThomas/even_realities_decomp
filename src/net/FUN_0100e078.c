/*
 * Function: FUN_0100e078
 * Entry:    0100e078
 * Prototype: uint __stdcall FUN_0100e078(int param_1, uint param_2, uint param_3)
 */


uint FUN_0100e078(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r2;
  int iVar5;
  uint uVar6;
  int extraout_r12;
  uint uVar7;
  
  uVar3 = (param_2 ^ param_2 >> 0x10) & 0xffff;
  bVar1 = (byte)(param_3 ^ uVar3);
  bVar2 = (byte)((param_3 ^ uVar3) >> 8);
  iVar5 = (uint)CONCAT11((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                            bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                         bVar2 >> 6 & 1) << 1 | bVar2 >> 7,
                         (((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                            bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                         bVar1 >> 6 & 1) << 1 | bVar1 >> 7) * 0x11 + uVar3;
  bVar2 = (byte)((uint)iVar5 >> 8);
  bVar1 = (byte)iVar5;
  iVar5 = (uint)CONCAT11((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                            bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                         bVar2 >> 6 & 1) << 1 | bVar2 >> 7,
                         (((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                            bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                         bVar1 >> 6 & 1) << 1 | bVar1 >> 7) * 0x11 + uVar3;
  bVar2 = (byte)((uint)iVar5 >> 8);
  bVar1 = (byte)iVar5;
  uVar6 = ((uint)CONCAT11((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                             bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                          bVar2 >> 6 & 1) << 1 | bVar2 >> 7,
                          (((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                             bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                          bVar1 >> 6 & 1) << 1 | bVar1 >> 7) * 0x11 + uVar3 ^ uVar3) & 0xffff;
  uVar3 = uVar6 % 0x25;
  if (((uint)*(byte *)(((uVar3 << 0x18) >> 0x1b) + param_1 + 1) & 1 << (uVar3 & 7)) != 0) {
    return uVar3;
  }
  uVar6 = *(byte *)(param_1 + 0xb) * uVar6;
  uVar7 = uVar6 >> 0x10;
  uVar3 = uVar7 + 1 & 0xff;
  if (*(byte *)(param_1 + 6) < uVar3) {
    uVar3 = uVar3 - *(byte *)(param_1 + 6) & 0xff;
    goto LAB_0100e12c;
  }
  uVar4 = (uint)*(byte *)(param_1 + 1);
  if (((int)(uVar4 << 0x1f) < 0) && (uVar3 = uVar7, (int)uVar6 >> 0x10 == 0)) {
    uVar6 = 0;
LAB_0100e27e:
    iVar5 = 0;
  }
  else {
    if ((int)(uVar4 << 0x1e) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e206;
LAB_0100e1fc:
      iVar5 = 1;
      goto LAB_0100e1fe;
    }
LAB_0100e206:
    if ((int)(uVar4 << 0x1d) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e216;
LAB_0100e212:
      iVar5 = 2;
      goto LAB_0100e1fe;
    }
LAB_0100e216:
    if ((int)(uVar4 << 0x1c) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e226;
LAB_0100e222:
      iVar5 = 3;
      goto LAB_0100e1fe;
    }
LAB_0100e226:
    if ((int)(uVar4 << 0x1b) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e236;
LAB_0100e232:
      iVar5 = 4;
      goto LAB_0100e1fe;
    }
LAB_0100e236:
    if ((int)(uVar4 << 0x1a) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e246;
LAB_0100e242:
      iVar5 = 5;
      goto LAB_0100e1fe;
    }
LAB_0100e246:
    if ((int)(uVar4 << 0x19) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e256;
LAB_0100e252:
      iVar5 = 6;
      goto LAB_0100e1fe;
    }
LAB_0100e256:
    if ((int)(uVar4 << 0x18) < 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar6 = 0;
      if (uVar3 != 0) goto LAB_0100e12c;
    }
    else {
LAB_0100e12c:
      if (*(byte *)(param_1 + 7) < uVar3) {
        uVar3 = uVar3 - *(byte *)(param_1 + 7) & 0xff;
      }
      else {
        uVar7 = (uint)*(byte *)(param_1 + 2);
        uVar6 = uVar7 & 1;
        if (((*(byte *)(param_1 + 2) & 1) != 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0))
        goto LAB_0100e27e;
        if (((int)(uVar7 << 0x1e) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e1fc;
        }
        if (((int)(uVar7 << 0x1d) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e212;
        }
        if (((int)(uVar7 << 0x1c) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e222;
        }
        if (((int)(uVar7 << 0x1b) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e232;
        }
        if (((int)(uVar7 << 0x1a) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e242;
        }
        if (((int)(uVar7 << 0x19) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e252;
        }
        if (((int)(uVar7 << 0x18) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 1;
          goto LAB_0100e266;
        }
      }
      if (*(byte *)(param_1 + 8) < uVar3) {
        uVar3 = uVar3 - *(byte *)(param_1 + 8) & 0xff;
      }
      else {
        uVar6 = (uint)*(byte *)(param_1 + 3);
        if (((int)(uVar6 << 0x1f) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e27e;
        }
        if (((int)(uVar6 << 0x1e) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e1fc;
        }
        if (((int)(uVar6 << 0x1d) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e212;
        }
        if (((int)(uVar6 << 0x1c) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e222;
        }
        if (((int)(uVar6 << 0x1b) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e232;
        }
        if (((int)(uVar6 << 0x1a) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e242;
        }
        if (((int)(uVar6 << 0x19) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e252;
        }
        if (((int)(uVar6 << 0x18) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 2;
          goto LAB_0100e266;
        }
      }
      if (uVar3 <= *(byte *)(param_1 + 9)) goto LAB_0100e166;
      uVar3 = uVar3 - *(byte *)(param_1 + 9) & 0xff;
      do {
        uVar6 = (uint)*(byte *)(param_1 + 10);
        if (uVar3 <= uVar6) {
          uVar6 = (uint)*(byte *)(param_1 + 5);
          if (((int)(uVar6 << 0x1f) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e27e;
          }
          if (((int)(uVar6 << 0x1e) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e1fc;
          }
          if (((int)(uVar6 << 0x1d) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e212;
          }
          if (((int)(uVar6 << 0x1c) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e222;
          }
          if (((int)(uVar6 << 0x1b) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e232;
          }
          if (((int)(uVar6 << 0x1a) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e242;
          }
          if (((int)(uVar6 << 0x19) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
            uVar6 = 4;
            goto LAB_0100e252;
          }
          uVar6 = uVar6 << 0x18;
          if (((int)uVar6 < 0) && (uVar3 == 1)) {
            uVar6 = 4;
            goto LAB_0100e266;
          }
        }
        FUN_01009500(0x46,0x9d,uVar3,uVar6);
        uVar3 = extraout_r2;
        param_1 = extraout_r12;
LAB_0100e166:
        uVar6 = (uint)*(byte *)(param_1 + 4);
        if (((int)(uVar6 << 0x1f) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e27e;
        }
        if (((int)(uVar6 << 0x1e) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e1fc;
        }
        if (((int)(uVar6 << 0x1d) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e212;
        }
        if (((int)(uVar6 << 0x1c) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e222;
        }
        if (((int)(uVar6 << 0x1b) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e232;
        }
        if (((int)(uVar6 << 0x1a) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e242;
        }
        if (((int)(uVar6 << 0x19) < 0) && (uVar3 = uVar3 - 1 & 0xff, uVar3 == 0)) {
          uVar6 = 3;
          goto LAB_0100e252;
        }
      } while ((-1 < (int)(uVar6 << 0x18)) || (uVar3 = uVar3 - 1 & 0xff, uVar3 != 0));
      uVar6 = 3;
    }
LAB_0100e266:
    iVar5 = 7;
  }
LAB_0100e1fe:
  return iVar5 + uVar6 * 8;
}


