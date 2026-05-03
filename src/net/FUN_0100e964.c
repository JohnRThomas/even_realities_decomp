/*
 * Function: FUN_0100e964
 * Entry:    0100e964
 * Prototype: uint __stdcall FUN_0100e964(int param_1, int param_2, int param_3, uint param_4)
 */


uint FUN_0100e964(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar4;
  byte bVar5;
  undefined8 uVar6;
  
  uVar6 = CONCAT44(param_2,param_1);
  if (param_2 == 0) {
    FUN_01009500(0x2a,0x324,param_3,param_4);
    param_4 = extraout_r2_00;
    uVar3 = extraout_r3_00;
  }
  else {
    uVar3 = *(byte *)(param_1 + 3) & 0x3f;
    if ((*(byte *)(param_1 + 3) & 0x3f) == 0) goto LAB_0100e9f2;
    bVar5 = *(byte *)(param_1 + 4);
    if ((bVar5 & 1) == 0) goto LAB_0100e9fc;
    if (param_3 == 0) {
      param_3 = 1;
      uVar4 = 5;
    }
    else {
      if ((bVar5 & 2) == 0) {
        uVar4 = 0xb;
        goto LAB_0100e990;
      }
      if (param_3 != 1) {
        uVar4 = 0x11;
        do {
          if ((bVar5 & 4) == 0) {
            if (param_3 != 2) {
              if ((bVar5 & 8) == 0) goto LAB_0100ea28;
LAB_0100e9ac:
              if (param_3 == 3) goto LAB_0100ea3e;
              uVar4 = uVar4 + 2;
joined_r0x0100ea30:
              if ((bVar5 & 0x10) == 0) {
                if (param_3 == 4) goto LAB_0100e9f2;
              }
              else {
                if (param_3 == 4) goto LAB_0100ea3e;
                uVar4 = uVar4 + 3;
              }
              if ((bVar5 & 0x20) == 0) {
                if (param_3 == 5) goto LAB_0100e9f2;
              }
              else {
                if (param_3 == 5) goto LAB_0100ea3e;
                uVar4 = uVar4 + 0x12 & 0xff;
              }
              if ((bVar5 & 0x40) == 0) {
                if (param_3 == 6) goto LAB_0100e9f2;
              }
              else {
                if (param_3 == 6) goto LAB_0100ea3e;
                uVar4 = uVar4 + 1 & 0xff;
              }
              if ((param_3 == 7) && (param_3 = uVar4 - 4, param_3 <= (int)uVar3)) goto LAB_0100ea42;
            }
          }
          else {
            if (param_3 == 2) {
LAB_0100ea3e:
              param_3 = uVar4 - 4;
              goto LAB_0100ea42;
            }
            uVar4 = uVar4 + 1;
            if ((bVar5 & 8) != 0) goto LAB_0100e9ac;
LAB_0100ea28:
            if (param_3 != 3) goto joined_r0x0100ea30;
          }
LAB_0100e9f2:
          do {
            do {
              bVar5 = 0xfd;
              uVar6 = FUN_01009500(0x2a,0x325,param_4,uVar3);
              param_4 = extraout_r2;
              uVar3 = extraout_r3;
LAB_0100e9fc:
            } while (param_3 == 0);
            if ((bVar5 & 2) != 0) {
              if (param_3 == 1) {
                uVar4 = 5;
                param_3 = 1;
                goto LAB_0100ea42;
              }
              uVar4 = 0xb;
              break;
            }
            uVar4 = 5;
LAB_0100e990:
          } while (param_3 == 1);
        } while( true );
      }
      param_3 = 7;
      uVar4 = 0xb;
    }
LAB_0100ea42:
    if ((int)(param_3 + param_4) < 0x40) {
      uVar3 = FUN_01026198((undefined4 *)((int)uVar6 + uVar4),
                           (undefined4 *)((ulonglong)uVar6 >> 0x20),param_4);
      return uVar3;
    }
  }
  uVar6 = FUN_01009500(0x2a,0x326,param_4,uVar3);
  iVar2 = (int)((ulonglong)uVar6 >> 0x20);
  iVar1 = (int)uVar6;
  uVar3 = *(byte *)(iVar1 + 3) & 0x3f;
  if ((*(byte *)(iVar1 + 3) & 0x3f) == 0) {
    return uVar3;
  }
  bVar5 = *(byte *)(iVar1 + 4);
  uVar4 = (uint)bVar5;
  if ((int)(uVar4 << 0x1f) < 0) {
    if (iVar2 == 0) {
LAB_0100eb52:
      iVar2 = 5;
LAB_0100eb54:
      return iVar1 + iVar2;
    }
    if (-1 < (int)(uVar4 << 0x1e)) {
      uVar4 = 0xb;
      goto LAB_0100eab0;
    }
    if (iVar2 == 1) {
      iVar2 = 0xb;
      goto LAB_0100eb54;
    }
    uVar4 = 0x11;
    if ((bVar5 & 4) == 0) goto LAB_0100eb22;
LAB_0100eabc:
    if (iVar2 == 2) goto LAB_0100eb46;
    uVar4 = uVar4 + 1;
    if ((bVar5 & 8) != 0) goto LAB_0100eaca;
LAB_0100eb2c:
    if (iVar2 == 3) {
      return 0;
    }
    if ((bVar5 & 0x10) == 0) goto LAB_0100eb36;
LAB_0100ead8:
    if (iVar2 == 4) goto LAB_0100eb46;
    uVar4 = uVar4 + 3;
  }
  else {
    if (iVar2 == 0) {
      return 0;
    }
    if ((int)(uVar4 << 0x1e) < 0) {
      if (iVar2 == 1) goto LAB_0100eb52;
      uVar4 = 0xb;
    }
    else {
      uVar4 = 5;
LAB_0100eab0:
      if (iVar2 == 1) {
        return 0;
      }
    }
    if ((bVar5 & 4) != 0) goto LAB_0100eabc;
LAB_0100eb22:
    if (iVar2 == 2) {
      return 0;
    }
    if ((bVar5 & 8) == 0) goto LAB_0100eb2c;
LAB_0100eaca:
    if (iVar2 == 3) goto LAB_0100eb46;
    uVar4 = uVar4 + 2;
    if ((bVar5 & 0x10) != 0) goto LAB_0100ead8;
LAB_0100eb36:
    if (iVar2 == 4) {
      return 0;
    }
  }
  if ((bVar5 & 0x20) == 0) {
    if (iVar2 == 5) {
      return 0;
    }
  }
  else {
    if (iVar2 == 5) goto LAB_0100eb46;
    uVar4 = uVar4 + 0x12 & 0xff;
  }
  if ((bVar5 & 0x40) == 0) {
    if (iVar2 == 6) {
      return 0;
    }
  }
  else {
    if (iVar2 == 6) goto LAB_0100eb46;
    uVar4 = uVar4 + 1 & 0xff;
  }
  if ((iVar2 != 7) || ((int)uVar3 < (int)(uVar4 - 4))) {
    return 0;
  }
LAB_0100eb46:
  return iVar1 + uVar4;
}


