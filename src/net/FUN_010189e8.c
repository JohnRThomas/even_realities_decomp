/*
 * Function: FUN_010189e8
 * Entry:    010189e8
 * Prototype: undefined4 __stdcall FUN_010189e8(byte * param_1)
 */


/* WARNING: Possible PIC construction at 0x01018f24: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x01018f28) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010189e8(byte *param_1)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  ushort *puVar10;
  undefined *puVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 *extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 *extraout_r2_01;
  undefined4 *extraout_r2_02;
  undefined4 *puVar12;
  undefined4 *extraout_r2_03;
  undefined4 *extraout_r2_04;
  undefined4 *extraout_r2_05;
  undefined4 *extraout_r2_06;
  undefined4 *extraout_r2_07;
  int extraout_r2_08;
  uint extraout_r2_09;
  uint *extraout_r2_10;
  uint *puVar13;
  uint extraout_r2_11;
  undefined4 extraout_r3;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint *unaff_r6;
  int unaff_r7;
  uint unaff_r8;
  undefined8 uVar17;
  undefined1 auStack_50 [7];
  byte local_49;
  uint auStack_48 [2];
  undefined1 uStack_40;
  byte local_3f;
  uint *local_3c;
  int local_38;
  byte local_2f;
  
  iVar7 = FUN_0100df60();
  puVar15 = (undefined1 *)(*param_1 & 0xf);
  DAT_2100001c = (char)iVar7;
  FUN_0101a734(param_1,(int)&uStack_40,puVar15);
  puVar12 = extraout_r2;
  if (puVar15 == &LAB_00000006_1) {
    if (local_3c == (uint *)0x0) {
      _DAT_21001012 = CONCAT11(DAT_21001013,1);
      if ((DAT_2100103b != '\0') &&
         (bVar5 = FUN_0102a324(DAT_2100103c + 0x50), puVar12 = extraout_r2_05, !bVar5)) {
        _DAT_21001012 = CONCAT11(1,DAT_21001012);
      }
      goto LAB_01018aa0;
    }
    if (((local_2f == 1) && ((*(byte *)((int)local_3c + 5) & 0xc0) == 0x40)) &&
       ((DAT_2100100c != '\0' &&
        ((DAT_21001049 != 1 || (DAT_2100100c = FUN_0100d2d4((int)local_3c,1), DAT_2100100c != '\0'))
        )))) goto LAB_01018ada;
LAB_01018a20:
    uVar8 = (uint)DAT_21001008;
joined_r0x01018a26:
    if (uVar8 == 0xff) {
      cVar2 = FUN_01011090((uint)local_2f,local_3c);
      bVar4 = FUN_0100c45c((uint)local_2f,(byte *)local_3c,&DAT_21001008);
      puVar12 = extraout_r2_04;
      if (bVar4 == 0) {
        _DAT_21001012 = 0;
        goto LAB_01018aa0;
      }
    }
    else {
      iVar7 = FUN_0100d298(uVar8,&local_49,auStack_48);
      if (iVar7 == 0) {
        uVar9 = 0x1018bcd;
        FUN_01009500(0x32,0xd21,extraout_r2_00,extraout_r3);
        puVar16 = (undefined1 *)(extraout_r2_08 << 8);
        puVar10 = (ushort *)0x0;
        puVar15 = auStack_50;
        while( true ) {
          *(undefined4 *)(puVar15 + -4) = uVar9;
          *(uint *)(puVar15 + -8) = unaff_r8;
          *(int *)(puVar15 + -0xc) = unaff_r7;
          *(uint **)(puVar15 + -0x10) = unaff_r6;
          *(undefined **)(puVar15 + -0x14) = &DAT_21000f90;
          *(undefined1 **)(puVar15 + -0x18) = puVar16;
          if (DAT_21000fe7 == '\0') break;
          if (DAT_21001012 == '\0') {
            if (DAT_21001013 == '\0') break;
            cVar2 = (char)*puVar10;
            if (cVar2 != '\x01') goto LAB_01018bfc;
LAB_01018c20:
            uVar17 = FUN_01020d00();
            if (DAT_21001049 == 2) {
              if ((*puVar10 & 0x1900) != 0x1900) {
                return 5;
              }
            }
            else if ((*puVar10 & 0x1800) != 0x1800) {
              return 5;
            }
            if (DAT_21000fe4 == '\x03') {
              if (*(int *)(puVar10 + 2) != 0) {
                bVar5 = FUN_0100b23c((uint)DAT_21001020,(byte *)&DAT_21001019,(uint)DAT_21000feb,
                                     (byte *)&DAT_21000fec);
                uVar8 = (uint)bVar5;
                uVar17 = CONCAT44(extraout_r1_00,uVar8);
                if (DAT_21000fe6 != '\x01') {
                  if (DAT_21000fe6 != '\0') {
                    return 5;
                  }
                  uVar17 = CONCAT44(extraout_r1_00,uVar8);
                  if ((uVar8 == 0) &&
                     (uVar17 = CONCAT44(extraout_r1_00,uVar8), DAT_21001008 != DAT_2100100b)) {
                    return 5;
                  }
                }
              }
              if (*(int *)(puVar10 + 4) != 0) {
                return 5;
              }
              cVar2 = DAT_2100100e;
              if ((((*(byte *)(*(int *)(puVar10 + 0xc) + 2) & 0xe0) == 0) ||
                  (cVar2 = DAT_2100100f, (*(byte *)(*(int *)(puVar10 + 0xc) + 2) & 0xe0) == 0x40))
                 && (cVar2 == '\0')) {
                return 5;
              }
            }
            puVar14 = &DAT_2100001c;
            puVar16 = (undefined1 *)(int)DAT_2100001c;
            if (puVar16 != (undefined1 *)0x7f) {
              *(undefined1 **)(puVar15 + -0x28) = puVar16;
              DAT_2100001c = 0x7f;
              *(uint *)(puVar15 + -0x2c) = (uint)DAT_21001009;
              *(undefined4 *)(puVar15 + -0x24) = 0;
              *(uint *)(puVar15 + -0x30) = (uint)DAT_2100101f;
              uVar8 = FUN_0101a2a0(puVar10,0xff,&DAT_21000fd6,(uint)DAT_21001049,puVar15[-0x30],
                                   puVar15[-0x2c],puVar15[-0x28],puVar15[-0x24]);
              if (uVar8 == 0) {
                return 5;
              }
              puVar11 = FUN_01017818(1,*(byte **)(puVar10 + 0xc));
              if (puVar11 == (undefined *)0x0) {
                return 5;
              }
              DAT_21001018 = 1;
              return 3;
            }
          }
          else {
            cVar2 = (char)*puVar10;
            if (cVar2 == '\x01') goto LAB_01018c20;
LAB_01018bfc:
            if (cVar2 == '\x02') {
              uVar17 = FUN_01020d00();
              if (DAT_21000fe4 == '\x03') {
                return 5;
              }
              if ((*puVar10 & 0x1800) != 0x1800) {
                return 5;
              }
              puVar16 = &DAT_2100001c;
              puVar14 = (undefined1 *)(int)DAT_2100001c;
              if (puVar14 != (undefined1 *)0x7f) {
                *(undefined1 **)(puVar15 + -0x28) = puVar14;
                *(undefined4 *)(puVar15 + -0x24) = 0;
                *(uint *)(puVar15 + -0x2c) = (uint)DAT_21001009;
                *(uint *)(puVar15 + -0x30) = (uint)DAT_2100101f;
                DAT_2100001c = 0x7f;
                uVar8 = FUN_0101a2a0(puVar10,0xff,&DAT_21000fd6,(uint)DAT_21001049,puVar15[-0x30],
                                     puVar15[-0x2c],puVar15[-0x28],puVar15[-0x24]);
                if (uVar8 == 0) {
                  return 5;
                }
                uVar3 = 2;
LAB_01018d4a:
                puVar11 = FUN_01017818(1,*(byte **)(puVar10 + 0xc));
                if (puVar11 == (undefined *)0x0) {
                  return 5;
                }
                DAT_21001018 = uVar3;
                return 3;
              }
            }
            else {
              if (cVar2 != '\0') break;
              uVar17 = FUN_01020d00();
              if (DAT_21000fe4 == '\x03') {
                return 5;
              }
              bVar4 = *(byte *)((int)puVar10 + 1);
              unaff_r7 = -((int)((uint)bVar4 << 0x1b) >> 0x1f);
              if ((bVar4 & 0x10) == 0) {
                uVar8 = 1;
              }
              else {
                uVar8 = 8;
              }
              if ((uVar8 & ~(uint)bVar4) != 0) {
                return 5;
              }
              iVar7 = *(int *)(puVar10 + 4);
              puVar15[-0x1b] = 0;
              puVar15[-0x1a] = 0;
              puVar15[-0x19] = 0;
              if (iVar7 == 0) {
                unaff_r8 = 0xff;
              }
              else {
                uVar17 = FUN_01017e58((int)puVar10,puVar15 + -0x1a,puVar15 + -0x1b,puVar15 + -0x19);
                unaff_r8 = (uint)DAT_21000fd5;
                if (puVar15[-0x1b] == '\0') {
                  bVar5 = FUN_0100b23c(unaff_r8,(byte *)&DAT_21000fd6,(uint)(byte)puVar10[9],
                                       *(byte **)(puVar10 + 4));
                  uVar8 = (uint)bVar5;
                  uVar17 = CONCAT44(extraout_r1,uVar8);
                  if (uVar8 == 0) {
                    if (1 < DAT_21000fe5 - 2) {
                      return 5;
                    }
                    if (puVar15[-0x1a] == '\0') {
                      return 5;
                    }
                    if (puVar15[-0x1b] != '\0') {
                      return 5;
                    }
                    unaff_r8 = 0xfe;
                    uVar17 = CONCAT44(extraout_r1,uVar8);
                  }
                }
                else {
                  unaff_r8 = unaff_r8 | 2;
                }
              }
              puVar16 = &DAT_2100001c;
              puVar14 = (undefined1 *)(int)DAT_2100001c;
              if (unaff_r7 == 0) {
                if (puVar14 != (undefined1 *)0x7f) {
                  DAT_2100001c = 0x7f;
                  uVar9 = 0;
                  if (DAT_21001000 != '\x05') {
                    if (DAT_21001000 == '\b') {
                      uVar9 = 3;
                    }
                    else {
                      uVar9 = 1;
                    }
                  }
                  *(undefined4 *)(puVar15 + -0x24) = uVar9;
                  *(uint *)(puVar15 + -0x30) = (uint)DAT_2100101f;
                  *(uint *)(puVar15 + -0x2c) = (uint)DAT_21001009;
                  *(undefined1 **)(puVar15 + -0x28) = puVar14;
                  uVar8 = FUN_0101a2a0(puVar10,unaff_r8,&DAT_21000fd6,(uint)DAT_21001049,
                                       puVar15[-0x30],puVar15[-0x2c],puVar15[-0x28],puVar15[-0x24]);
                  if (uVar8 == 0) {
                    return 5;
                  }
                  FUN_01019e60();
                  return 5;
                }
              }
              else if (puVar14 != (undefined1 *)0x7f) {
                *(undefined1 **)(puVar15 + -0x28) = puVar14;
                uVar3 = 0;
                *(uint *)(puVar15 + -0x2c) = (uint)DAT_21001009;
                *(undefined4 *)(puVar15 + -0x24) = 0;
                *(uint *)(puVar15 + -0x30) = (uint)DAT_2100101f;
                DAT_2100001c = 0x7f;
                uVar8 = FUN_0101a2a0(puVar10,unaff_r8,&DAT_21000fd6,(uint)DAT_21001049,
                                     puVar15[-0x30],puVar15[-0x2c],puVar15[-0x28],puVar15[-0x24]);
                if (uVar8 == 0) {
                  return 5;
                }
                goto LAB_01018d4a;
              }
            }
          }
          FUN_01017028((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),puVar16,puVar14);
          unaff_r6 = (uint *)(extraout_r2_09 >> 0x1f);
          *(undefined4 *)(puVar15 + -0x34) = 0x1018e7f;
          *(ushort **)(puVar15 + -0x38) = puVar10;
          *(uint *)(puVar15 + -0x3c) = (uint)puVar10 >> 0x1f;
          puVar10 = (ushort *)(puVar15 + -0x68);
          iVar7 = FUN_0100df60();
          puVar16 = (undefined1 *)(*(byte *)(extraout_r2_09 >> 0x1e) & 0xf);
          DAT_2100001c = (char)iVar7;
          FUN_0101a870((byte *)(extraout_r2_09 >> 0x1e),puVar15 + -0x68);
          if (puVar16 == &LAB_00000006_1) {
            cVar2 = puVar15[-0x68];
            if (cVar2 == '\x02') {
              *(undefined4 *)(puVar15 + -100) = 0;
              *(undefined4 *)(puVar15 + -0x60) = 0;
              puVar15[-0x67] = puVar15[-0x67] & 0xfc;
              goto LAB_01018f70;
            }
            uVar8 = (uint)DAT_21001049;
            if (cVar2 == '\x01') goto LAB_01018fb6;
            if (cVar2 != '\0') goto LAB_01018f70;
            if ((DAT_21001049 & 0xc) == 0) goto LAB_01018f70;
            if (-1 < (int)((uint)(byte)puVar15[-0x67] << 0x1b)) goto LAB_01018f70;
            *(undefined4 *)(puVar15 + -100) = 0;
            *(undefined4 *)(puVar15 + -0x60) = 0;
            puVar15[-0x67] = puVar15[-0x67] & 0xfc;
            goto LAB_01018f70;
          }
          FUN_01017c6c((int)(puVar15 + -0x68),(uint)puVar16,0);
          iVar7 = DAT_21001049 - 1;
          puVar13 = extraout_r2_10;
          switch(DAT_21001049) {
          case 1:
            if ((puVar16 == &LAB_00000006) ||
               ((puVar16 < &LAB_00000006_1 && (puVar16 < &LAB_00000002_1)))) {
              uVar9 = FUN_010170e4((uint)(puVar15 + -0x68),puVar16,extraout_r2_10);
              goto joined_r0x01018f04;
            }
          case 2:
switchD_01018ec8_caseD_2:
            uVar9 = 5;
            FUN_01020d00();
joined_r0x01018f04:
            if (DAT_2100100c == '\0') {
                    /* WARNING: Could not recover jumptable at 0x01018ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar9 = (**(code **)(puVar15 + -0x34))(uVar9);
              return uVar9;
            }
            FUN_010210b0();
            FUN_010204a8();
            DAT_2100100c = 0;
                    /* WARNING: Could not recover jumptable at 0x01018f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar9 = (**(code **)(puVar15 + -0x34))(uVar9);
            return uVar9;
          default:
            do {
              FUN_01009500(0x32,&DAT_000013b3,puVar13,iVar7);
              uVar8 = extraout_r2_11;
LAB_01018fb6:
              bVar4 = puVar15[-0x67];
              *(undefined4 *)(puVar15 + -0x60) = 0;
              puVar15[-0x67] = bVar4 & 0xfd;
              if (uVar8 != 2) {
                *(undefined4 *)(puVar15 + -100) = 0;
                puVar15[-0x67] = bVar4 & 0xfc;
              }
LAB_01018f70:
              FUN_01017c6c((int)(puVar15 + -0x68),7,0);
              iVar7 = DAT_21001049 - 1;
              puVar13 = &switchD_01018f86::switchdataD_01018f8c;
              switch(iVar7) {
              case 0:
              case 3:
              case 7:
                goto switchD_01018f86_caseD_1;
              case 1:
                if (puVar15[-0x68] != '\x01') goto switchD_01018ec8_caseD_2;
                goto switchD_01018f86_caseD_1;
              }
            } while( true );
          case 4:
          case 8:
            if (puVar16 != &LAB_00000006_1) goto switchD_01018ec8_caseD_2;
switchD_01018f86_caseD_1:
            uVar9 = 0x1018f29;
            puVar15 = puVar15 + -0x68;
          }
        }
        FUN_01020d00();
        return 5;
      }
      cVar2 = FUN_01011090((uint)local_49,auStack_48);
      puVar12 = extraout_r2_01;
    }
  }
  else {
    if (local_3c != (uint *)0x0) {
      unaff_r6 = local_3c;
      if (((local_2f != 1) || ((*(byte *)((int)local_3c + 5) & 0xc0) != 0x40)) ||
         (DAT_2100100c == '\0')) goto LAB_01018a20;
LAB_01018ada:
      uVar8 = FUN_0100d310();
      _DAT_21001008 = (ushort)uVar8 & 0xff | (ushort)((uVar8 & 0xff) << 8);
      DAT_21001010 = 1;
      goto joined_r0x01018a26;
    }
    cVar2 = '\0';
  }
  cVar1 = DAT_21000fdd;
  if (&LAB_00000006 < puVar15) {
    if (&NMI < puVar15) {
      cVar6 = '\0';
    }
    else {
      if (local_3c != (uint *)0x0) goto LAB_01018a4e;
      if ((int)((uint)local_3f << 0x1b) < 0) {
        cVar6 = '\x01';
      }
      else {
        bVar5 = FUN_0101a1cc();
        puVar12 = extraout_r2_06;
        if (((!bVar5) || (cVar6 = DAT_21001012, DAT_21001012 == '\0')) &&
           (cVar6 = cVar1, cVar1 == '\0')) {
          cVar6 = FUN_0100c450();
          puVar12 = extraout_r2_07;
        }
      }
    }
  }
  else {
LAB_01018a4e:
    cVar6 = cVar1;
    if (DAT_21000fdd == '\0') {
      cVar6 = cVar2;
    }
  }
  _DAT_21001012 = CONCAT11(DAT_21001013,cVar6);
  if (DAT_21000214 != (code *)0x0) {
    uVar3 = (*DAT_21000214)(&uStack_40,0);
    _DAT_21001012 = CONCAT11(uVar3,DAT_21001012);
    puVar12 = extraout_r2_02;
  }
  if (local_3c != (uint *)0x0) {
    DAT_21001020 = local_2f;
    DAT_21001019 = *local_3c;
    puVar12 = &DAT_21001019;
    DAT_2100101d = (undefined2)local_3c[1];
  }
  if ((puVar15 == &LAB_00000006_1) && (local_38 != 0)) {
    if ((DAT_21001008 != 0xff) && (_DAT_21001012 != 0)) {
      FUN_0100d328(local_38,(uint)DAT_21001008);
      DAT_21001011 = 1;
      puVar12 = extraout_r2_03;
    }
  }
LAB_01018aa0:
  uVar9 = FUN_010170e4((uint)&uStack_40,puVar15,puVar12);
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    FUN_010204a8();
    DAT_2100100c = 0;
    return uVar9;
  }
  return uVar9;
}


