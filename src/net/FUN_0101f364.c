/*
 * Function: FUN_0101f364
 * Entry:    0101f364
 * Prototype: uint __stdcall FUN_0101f364(byte * param_1)
 */


uint FUN_0101f364(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r1;
  int extraout_r2;
  uint uVar5;
  uint uVar6;
  byte local_34;
  undefined1 local_33;
  byte local_32;
  undefined1 local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  undefined1 local_2d;
  byte local_2c [4];
  undefined4 local_28;
  uint uStack_24;
  uint local_20;
  uint uStack_1c;
  uint local_18;
  uint uStack_14;
  
  if ((*param_1 < 4) && (param_1[1] < 4)) {
    bVar1 = param_1[2];
    uVar6 = (uint)bVar1;
    if (((param_1[0x19] != 0) || (uVar6 == 1)) && ((bVar1 & 0xf8) == 0)) {
      if ((int)(uVar6 << 0x1e) < 0) {
        bVar1 = DAT_2100120c._1_1_;
        if (uVar6 != 2) {
          return 0x12;
        }
      }
      else {
        bVar1 = bVar1 & 7;
      }
      if (bVar1 != 0) {
        uVar3 = FUN_010200d8();
        if ((uVar6 & ~uVar3) != 0) {
          return 0x11;
        }
        uVar3 = (uint)param_1[2];
        uVar6 = uVar3 & 1;
        if ((param_1[2] & 1) != 0) {
          uVar6 = FUN_0101edd0((uint)param_1[3],*(uint *)(param_1 + 8),*(uint *)(param_1 + 0x10),1);
        }
        if ((int)(uVar3 << 0x1e) < 0) {
          uVar4 = FUN_0101edd0((uint)param_1[3],*(uint *)(param_1 + 8),*(uint *)(param_1 + 0x10),2);
          uVar6 = (uVar4 | uVar6) & 0xff;
        }
        if ((int)(uVar3 << 0x1d) < 0) {
          uVar4 = FUN_0101edd0((uint)param_1[3],*(uint *)(param_1 + 8),*(uint *)(param_1 + 0x10),4);
          uVar6 = (uVar4 | uVar6) & 0xff;
        }
        if (uVar6 != 0) {
          return uVar6;
        }
        if (uVar3 == 5) {
          bVar1 = param_1[4];
          uVar6 = FUN_0101edd0((uint)bVar1,*(uint *)(param_1 + 0xc),*(uint *)(param_1 + 0x14),4);
          if (uVar6 != 0) {
            return uVar6;
          }
          if ((uint)param_1[3] != (uint)bVar1) {
            return 0x12;
          }
          if (extraout_r1 != *(uint *)(param_1 + 8)) {
            return 0x12;
          }
          if (extraout_r1 < (uint)(*(int *)(param_1 + 0x10) + extraout_r2)) {
            return 0x12;
          }
        }
        if (param_1[0x18] - 1 < 7) {
          bVar2 = FUN_01028ba4();
          if (bVar2) {
            return 0xc;
          }
          local_2f = param_1[1];
          uVar3 = *(uint *)(param_1 + 0x10);
          local_30 = *param_1;
          uVar6 = *(uint *)(param_1 + 0x14);
          if (15999999 < uVar3) {
            uVar3 = 16000000;
          }
          local_2e = param_1[0x18];
          *(uint *)(param_1 + 0x10) = uVar3;
          if (15999999 < uVar6) {
            uVar6 = 16000000;
          }
          local_34 = param_1[2];
          uVar5 = (uint)local_34;
          local_2d = param_1[0x19] != 0;
          *(uint *)(param_1 + 0x14) = uVar6;
          uVar4 = (uint)(byte)local_2d;
          if ((int)(uVar5 << 0x1f) < 0) {
            if (param_1[3] == 1) {
              local_33 = 2;
            }
            else {
              local_33 = param_1[3] == 0;
            }
            local_28 = *(undefined4 *)(param_1 + 8);
            uVar4 = uVar5 << 0x1d;
            uStack_24 = uVar3;
            if ((int)uVar4 < 0) {
              if (param_1[4] == 1) {
                local_31 = 2;
              }
              else {
                local_31 = param_1[4] == 0;
              }
              uVar5 = *(uint *)(param_1 + 0xc);
              local_18 = uVar5;
              uStack_14 = uVar6;
            }
          }
          else if (uVar5 == 2) {
            uVar4 = (uint)param_1[3];
            local_32 = local_34;
            if (uVar4 != 1) {
              local_32 = uVar4 == 0;
            }
            uVar5 = *(uint *)(param_1 + 8);
            local_20 = uVar5;
            uStack_1c = uVar3;
          }
          else {
            uVar5 = uVar5 << 0x1d;
            if ((int)uVar5 < 0) {
              if (param_1[3] == 1) {
                local_31 = 2;
              }
              else {
                local_31 = param_1[3] == 0;
              }
              uVar5 = *(uint *)(param_1 + 8);
              local_18 = uVar5;
              uStack_14 = uVar3;
            }
          }
          local_2c[0] = local_34;
          uVar6 = FUN_0101b7a8(local_2c,uVar3,uVar4,uVar5);
          if (uVar6 == 0) {
            uVar6 = FUN_01019960(&local_34);
            return uVar6;
          }
          return uVar6;
        }
      }
    }
  }
  return 0x12;
}


