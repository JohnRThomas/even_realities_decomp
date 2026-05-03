/*
 * Function: FUN_0101f568
 * Entry:    0101f568
 * Prototype: uint __stdcall FUN_0101f568(byte * param_1)
 */


uint FUN_0101f568(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  undefined4 extraout_r1;
  undefined4 *extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  ushort local_46;
  byte local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  
  if (((int)((uint)param_1[9] << 0x1e) < 0) && ((char)DAT_2100120c == '\0')) {
    param_1[9] = param_1[9] | 1;
  }
  bVar1 = param_1[9];
  uVar7 = (uint)bVar1;
  if (((bVar1 & 7) == 0) || ((bVar1 & 0xf8) != 0)) {
LAB_0101f588:
    uVar7 = 0x12;
  }
  else {
    uVar4 = FUN_010200d8();
    if ((uVar7 & ~uVar4) != 0) {
      return 0x11;
    }
    if (param_1[0x48] == 0) {
      if (uVar7 != 1) goto LAB_0101f588;
    }
    else {
      uVar4 = uVar7 & 1;
      if ((bVar1 & 1) == 0) goto LAB_0101f5c6;
    }
    if (*(int *)(param_1 + 0x18) - 0x753U < 0x270f63d) {
      while( true ) {
        uVar4 = 1;
LAB_0101f5c6:
        if ((int)(uVar7 << 0x1e) < 0) {
          uVar9 = (uint)(byte)((char)uVar4 + 1);
        }
        else {
          uVar9 = uVar4;
          uVar4 = 0xff;
        }
        if ((int)(uVar7 << 0x1d) < 0) {
          if (0x270f3cb < *(int *)(param_1 + (uVar9 + 6) * 4) - 0x9c4U) goto LAB_0101f5bc;
          uVar9 = uVar9 + 1;
        }
        pbVar8 = param_1 + 0x22;
        puVar10 = (uint *)(param_1 + 0xc);
        uVar7 = 0;
        for (uVar11 = 0; uVar12 = uVar11 & 0xff, uVar12 < uVar9; uVar11 = uVar11 + 1) {
          if (uVar4 == uVar12) {
            if (uVar9 == 1) {
              uVar12 = puVar10[3];
              if ((0x270f9a7 < uVar12 - 1000) || (0x270f9a7 < *puVar10 - 1000)) goto LAB_0101f5bc;
              if (*puVar10 < uVar12) goto LAB_0101f588;
              uVar7 = uVar7 + uVar12;
            }
          }
          else {
            if (*puVar10 < puVar10[3]) goto LAB_0101f588;
            uVar7 = uVar7 + puVar10[3];
            bVar2 = FUN_0101ed30(0,(uint)*(ushort *)(pbVar8 + 2),(uint)*(ushort *)(pbVar8 + 8),
                                 (uint)*(ushort *)(pbVar8 + 0xe),*(ushort *)(pbVar8 + 0x14),
                                 *(ushort *)(pbVar8 + 0x1a),*(ushort *)(pbVar8 + 0x20));
            if (!bVar2) goto LAB_0101f5bc;
            if ((uVar12 != 0) &&
               ((((*(short *)(pbVar8 + 2) != *(short *)pbVar8 ||
                  (*(short *)(pbVar8 + 8) != *(short *)(pbVar8 + 6))) ||
                 (*(short *)(pbVar8 + 0xe) != *(short *)(pbVar8 + 0xc))) ||
                (*(short *)(pbVar8 + 0x14) != *(short *)(pbVar8 + 0x12))))) goto LAB_0101f588;
          }
          pbVar8 = pbVar8 + 2;
          puVar10 = puVar10 + 1;
        }
        if ((((*(uint *)(param_1 + 0xc) < uVar7) || (1 < *param_1)) ||
            ((*param_1 == 0 && (1 < param_1[2])))) || ((3 < param_1[1] || (6 < param_1[0x4c] - 1))))
        goto LAB_0101f588;
        bVar2 = FUN_01028ba4();
        if (bVar2) break;
        iVar5 = func_0x0101946c();
        if ((iVar5 != 0) || (bVar2 = FUN_01019458(), bVar2)) {
          return 0x3a;
        }
        if (*(uint *)(param_1 + 0x18) < 0xf42401) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18);
        }
        else {
          param_1[0x18] = 0;
          param_1[0x19] = 0x24;
          param_1[0x1a] = 0xf4;
          param_1[0x1b] = 0;
        }
        if (*(uint *)(param_1 + 0x1c) < 0xf42401) {
          *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c);
        }
        else {
          param_1[0x1c] = 0;
          param_1[0x1d] = 0x24;
          param_1[0x1e] = 0xf4;
          param_1[0x1f] = 0;
        }
        if (*(uint *)(param_1 + 0x20) < 0xf42401) {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20);
        }
        else {
          param_1[0x20] = 0;
          param_1[0x21] = 0x24;
          param_1[0x22] = 0xf4;
          param_1[0x23] = 0;
        }
        puVar6 = (ushort *)FUN_0100a3c4(&local_46,0);
        if (puVar6 == (ushort *)0x0) {
          return 0xd;
        }
        uVar7 = FUN_0101eeac(puVar6,local_46,(int)param_1,1);
        if ((uVar7 == 0) &&
           (uVar7 = FUN_0101c3ec((uint)puVar6,extraout_r1,extraout_r2,extraout_r3), uVar7 == 0)) {
          pbVar8 = param_1 + 3;
          FUN_0101971c(param_1[1]);
          cVar3 = FUN_010196b4((uint)*param_1,(uint)param_1[2],pbVar8);
          if (cVar3 == '\0') {
            uVar7 = 0x12;
          }
          else {
            FUN_01019728();
            uVar7 = func_0x010197d4(*param_1,param_1[2],pbVar8);
            if (uVar7 == 0) {
              uVar7 = (uint)param_1[9];
              if (uVar7 != 2) {
                uVar4 = FUN_010200d8();
                uVar7 = FUN_01028aac(uVar4 & uVar7 & 5);
              }
              uVar7 = FUN_01019640(uVar7);
              if (uVar7 == 0) {
                uVar7 = FUN_01019850(3,puVar6);
                bVar2 = FUN_01028a96((uint)param_1[2]);
                FUN_01019814(bVar2,extraout_r1_00,extraout_r2_00,extraout_r3_00);
                if (uVar7 == 0) {
                  if ((*param_1 == 0) &&
                     (bVar2 = FUN_01028c12((int)puVar6,(uint)param_1[2],pbVar8), bVar2)) {
                    uVar7 = 0xb;
                  }
                  else {
                    uVar7 = func_0x01019868(1);
                    if ((uVar7 == 0) && (uVar7 = func_0x01019878(1), uVar7 == 0)) {
                      uVar7 = (uint)param_1[9];
                      uVar4 = uVar7 & 1;
                      local_44[0] = (param_1[9] & 1) != 0;
                      if ((bool)local_44[0]) {
                        local_40 = *(undefined4 *)(param_1 + 0xc);
                        local_3c = *(undefined4 *)(param_1 + 0x18);
                      }
                      uVar9 = uVar7 << 0x1e;
                      if ((int)uVar9 < 0) {
                        if (uVar7 == 2) {
                          local_38 = *(undefined4 *)(param_1 + 0xc);
                          local_34 = *(undefined4 *)(param_1 + 0x18);
                          uVar9 = local_44[0] | 2;
                          local_44[0] = (byte)uVar9;
                        }
                        uVar4 = uVar4 + 1;
                      }
                      iVar5 = uVar7 << 0x1d;
                      if (iVar5 < 0) {
                        iVar5 = *(int *)(param_1 + uVar4 * 4 + 0xc);
                        local_2c = *(undefined4 *)(param_1 + uVar4 * 4 + 0x18);
                        uVar4 = local_44[0] | 4;
                        local_44[0] = (byte)uVar4;
                        local_30 = iVar5;
                      }
                      uVar7 = FUN_0101b7a8(local_44,uVar9,iVar5,uVar4);
                      FUN_010196a8(param_1[0x48] != 0);
                      FUN_01019634(param_1[0x4c]);
                      if (((uVar7 == 0) && (uVar7 = func_0x01019918(), uVar7 == 0)) &&
                         (uVar7 = FUN_0101b6e0((int)puVar6,(uint *)(uint)*(ushort *)(param_1 + 0x4a)
                                              ), uVar7 == 0)) {
                        return 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        FUN_0100b0dc((uint)*puVar6);
        iVar5 = FUN_0100a564(*puVar6,0);
        if (iVar5 == 0) {
          return uVar7;
        }
        FUN_01009500(0x39,&DAT_00001255,extraout_r2_01,extraout_r3_01);
      }
      uVar7 = 0xc;
    }
    else {
LAB_0101f5bc:
      uVar7 = 0x30;
    }
  }
  return uVar7;
}


