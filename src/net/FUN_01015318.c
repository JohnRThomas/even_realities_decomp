/*
 * Function: FUN_01015318
 * Entry:    01015318
 * Prototype: undefined __stdcall FUN_01015318(int param_1, undefined1 * param_2, undefined4 param_3)
 */


void FUN_01015318(int param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined *puVar1;
  byte *pbVar2;
  ushort uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  char cVar6;
  bool bVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  ushort *puVar14;
  uint uVar15;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  int iVar16;
  uint extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 uVar17;
  undefined4 extraout_r1_08;
  uint extraout_r1_09;
  undefined4 extraout_r1_10;
  ushort *extraout_r1_11;
  ushort *extraout_r1_12;
  undefined4 extraout_r2;
  uint uVar18;
  ushort *extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  ushort *extraout_r2_03;
  ushort *extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  ushort *extraout_r2_07;
  ushort *extraout_r2_08;
  ushort *puVar19;
  ushort *extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  ushort *extraout_r2_12;
  ushort *extraout_r2_13;
  int extraout_r2_14;
  ushort *extraout_r2_15;
  ushort *extraout_r2_16;
  ushort *extraout_r2_17;
  byte bVar20;
  undefined4 extraout_r3;
  uint uVar21;
  ushort *extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  ushort *extraout_r3_03;
  ushort *puVar22;
  int extraout_r3_04;
  uint extraout_r3_05;
  ushort *unaff_r4;
  uint unaff_r8;
  undefined1 *unaff_r9;
  undefined8 uVar23;
  ulonglong uVar24;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  uint local_24;
  
  uVar9 = FUN_0100a97c(*DAT_21000f6c,param_2,param_3);
  puVar19 = DAT_21000f6c;
  if (uVar9 != 0) {
    uVar21 = (uint)DAT_21000f74;
    if ((int)(uVar21 << 0x17) < 0) {
      DAT_21000f6c[0x7b] = 0;
      *(undefined1 *)(puVar19 + 0x17a) = 0;
      if (*(char *)((int)puVar19 + 0xcb) != '\0') goto LAB_01015352;
LAB_01015610:
      uVar15 = FUN_0100dbc0((int)(puVar19 + 0x54),6,(uint)(byte)puVar19[99],1);
      uVar21 = (uint)DAT_21000f74;
      puVar19 = DAT_21000f6c;
      if (uVar15 != 0) {
        if ((-1 < (int)(uVar21 << 0x14)) || (*(char *)((int)DAT_21000f6c + 0xcb) == '\0'))
        goto LAB_01015358;
LAB_0101563a:
        puVar19[0x74] = 0;
        puVar19[0x75] = 0;
      }
    }
    else {
      DAT_21000f6c[0x7b] = DAT_21000f6c[0x7b] + 1;
      if (*(char *)((int)puVar19 + 0xcb) == '\0') goto LAB_01015610;
LAB_01015352:
      if ((int)(uVar21 << 0x14) < 0) goto LAB_0101563a;
LAB_01015358:
      uVar15 = *(uint *)(puVar19 + 0x76);
      uVar18 = *(int *)(puVar19 + 0x74) + 1;
      *(uint *)(puVar19 + 0x74) = uVar18;
      if ((uVar15 < uVar18) || (uVar15 - uVar18 <= DAT_21000f82 + 5)) {
        *(undefined1 *)(puVar19 + 0x7a) = 1;
      }
      if (uVar15 <= uVar18) {
        puVar19[0x74] = 0;
        puVar19[0x75] = 0;
        FUN_0100f7c8((undefined4 *)((int)puVar19 + 0x1c5),0x10109cd,2);
        uVar21 = (uint)DAT_21000f74;
        puVar19 = DAT_21000f6c;
      }
    }
    cVar6 = *(char *)((int)puVar19 + 0xc9);
    if ((uVar21 & 0x300) != 0) {
      if (cVar6 == '\0') {
        *(undefined1 *)((int)puVar19 + 0xc9) = 1;
        FUN_01014698((undefined4 *)puVar19,1,0,uVar21);
        uVar21 = (uint)DAT_21000f74;
        cVar6 = *(char *)((int)DAT_21000f6c + 0xc9);
        puVar19 = DAT_21000f6c;
      }
      else if (cVar6 == '\x03') {
        *(undefined1 *)((int)puVar19 + 0xc9) = 2;
        FUN_01014698((undefined4 *)puVar19,1,3,2);
        uVar21 = (uint)DAT_21000f74;
        cVar6 = *(char *)((int)DAT_21000f6c + 0xc9);
        puVar19 = DAT_21000f6c;
      }
    }
    if ((cVar6 == '\x01') && ((int)(uVar21 << 0x15) < 0)) {
      *(undefined1 *)((int)puVar19 + 0xc9) = 2;
    }
    if (param_1 != 0) goto joined_r0x010156b0;
    if ((int)(uVar21 << 0x19) < 0) {
      puVar19[0x184] = 0;
    }
    else {
      puVar19[0x184] = puVar19[0x184] + 1;
    }
    puVar13 = param_2;
    if (param_2 == (undefined1 *)0x0) {
      iVar10 = uVar21 << 0x1c;
      unaff_r4 = puVar19;
      if (iVar10 < 0) {
        uVar21 = (uint)(byte)puVar19[0xa7];
        if (uVar21 == 0x22) {
          *(undefined1 *)(puVar19 + 0xd5) = 0;
          if (DAT_210001dc != (code *)0x0) {
            (*DAT_210001dc)(DAT_21000f6c + 0xac,DAT_21000f6c + 0xd5);
          }
          FUN_0100ff84(0x21000f68);
          uVar21 = (uint)(byte)DAT_21000f6c[0xa7];
          iVar10 = extraout_r2_01;
          unaff_r4 = DAT_21000f6c;
        }
        else if ((uVar21 == 0x2a) || (uVar21 == 0x1c)) {
          *(undefined1 *)(puVar19 + 0xba) = 0;
          FUN_0100ff84(0x21000f68);
          uVar21 = (uint)(byte)DAT_21000f6c[0xa7];
          iVar10 = extraout_r2_02;
          unaff_r4 = DAT_21000f6c;
        }
        if (uVar21 == 0xfe) goto LAB_0101641c;
        uVar21 = (uint)(byte)unaff_r4[99];
        *(undefined1 *)(unaff_r4 + 0xa7) = 0xfe;
        if (uVar21 == 0x1b) {
          uVar21 = 0;
          *(undefined1 *)((int)unaff_r4 + 0x105) = 0;
          FUN_0100ffb0(0x21000f68);
          unaff_r4 = DAT_21000f6c;
          *(undefined1 *)(DAT_21000f6c + 99) = 0;
        }
        if (*(char *)((int)unaff_r4 + 0xc5) == '!') {
          uVar21 = FUN_0100dbc0((int)(unaff_r4 + 0x54),0xb,uVar21,1);
          unaff_r4 = DAT_21000f6c;
          if (uVar21 == 0) {
            *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0x22;
          }
          else {
            *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0x2f;
          }
        }
        else if (*(char *)((int)unaff_r4 + 0xc5) == '2') {
          *(undefined1 *)((int)unaff_r4 + 0xc5) = 0;
          *(undefined1 *)(unaff_r4 + 0x80) = 0;
          *(undefined1 *)((int)unaff_r4 + 0x3b5) = 1;
        }
        if (*(char *)((int)unaff_r4 + 199) == '\b') goto LAB_01015b20;
        goto LAB_01015a8c;
      }
      do {
        iVar10 = DAT_21000f7c;
        if ((int)(uVar21 << 0x1f) < 0) {
          puVar22 = unaff_r4 + 0x54;
          puVar19 = unaff_r4 + 99;
          unaff_r4 = (ushort *)(uint)*(byte *)(DAT_21000f7c + 3);
          uVar21 = FUN_0100dbc0((int)puVar22,5,(uint)(byte)*puVar19,1);
          if ((uVar21 != 0) &&
             ((9 < ((uint)(unaff_r4 + -1) & 0xff) ||
              (unaff_r4 = (ushort *)(1 << ((uint)(unaff_r4 + -1) & 0xff)),
              ((uint)unaff_r4 & 0x333) == 0)))) {
            puVar19 = DAT_21000f6c;
            puVar13 = &NMI;
            break;
          }
          bVar7 = FUN_0100ee10(iVar10);
          if (bVar7) {
            uVar21 = (uint)*(byte *)(iVar10 + 3);
            if ((uVar21 < 2) || (uVar21 == 0x16)) {
              uVar15 = FUN_0100ffe0((uint)*(byte *)((int)DAT_21000f6c + 0xc5));
              puVar19 = DAT_21000f6c;
              if ((uVar15 != 0) && (unaff_r4 = puVar19, *(char *)((int)DAT_21000f6c + 0xc5) != '!'))
              {
                if (*(char *)((int)DAT_21000f6c + 0xc5) != '\"') {
                  if (uVar21 == 0x16) {
                    puVar13 = &Reserved2;
                  }
                  else {
                    puVar13 = &LAB_00000002;
                  }
                  break;
                }
                *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0x2f;
              }
            }
            else if (0x2a < uVar21) {
              if ((uVar21 == 0xff) && (DAT_21000f70 != (code *)0x0)) {
                *(undefined1 *)(DAT_21000f6c + 0x1db) = 1;
                uVar21 = (uint)DAT_21000f74;
                goto LAB_0101573c;
              }
              goto LAB_01015bde;
            }
            if ((code *)(&DAT_21000078)[uVar21] == (code *)0x0) goto LAB_01015bde;
            puVar13 = (undefined1 *)(*(code *)(&DAT_21000078)[uVar21])(&DAT_21000f68,DAT_21000f7c);
          }
          else {
LAB_01015bde:
            puVar13 = (undefined1 *)FUN_01010034(0x21000f68,iVar10);
          }
          puVar19 = DAT_21000f6c;
          if (puVar13 != (undefined1 *)0x0) break;
          uVar21 = (uint)DAT_21000f74;
        }
LAB_0101573c:
        puVar19 = DAT_21000f6c;
        if (((int)(uVar21 << 0x1d) < 0) && (*(char *)((int)DAT_21000f6c + 199) == '\a')) {
          DAT_21000f84 = '\x01';
        }
        if (-1 < (int)(uVar21 << 0x1e)) goto LAB_0101592e;
        uVar15 = (uint)*(byte *)(DAT_21000f78 + 3);
        if (uVar15 < 0x2b) {
          uVar21 = 0;
          if (*(code **)(&DAT_21000124 + uVar15 * 4) != (code *)0x0) goto code_r0x0101576a;
        }
        else if (uVar15 == 0xff) {
          *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0x32;
          *(undefined1 *)(puVar19 + 0x1da) = 0;
          goto LAB_0101592e;
        }
        FUN_01009500(0x31,0x57c,uVar15,uVar21);
LAB_01015b20:
        DAT_21000f84 = '\x02';
        *(undefined1 *)(unaff_r4 + 0xa7) = 2;
LAB_01015a8c:
        uVar21 = (uint)DAT_21000f74;
      } while( true );
    }
    goto LAB_010153dc;
  }
  uVar24 = FUN_01009500(0x31,0xbc3,extraout_r2,extraout_r3);
  uVar21 = extraout_r3_01;
  uVar9 = unaff_r8;
  goto LAB_01015e98;
code_r0x0101576a:
  (**(code **)(&DAT_21000124 + uVar15 * 4))(&DAT_21000f68);
  uVar21 = (uint)DAT_21000f74;
  puVar19 = DAT_21000f6c;
LAB_0101592e:
  puVar13 = (undefined1 *)0x0;
  if ((uVar21 & 0x10) != 0) {
    if ((char)puVar19[99] == '\v') {
      *(undefined1 *)(puVar19 + 99) = 0xc;
      puVar13 = (undefined1 *)0x0;
    }
    else {
      puVar13 = (undefined1 *)0x0;
    }
  }
LAB_010153dc:
  unaff_r9 = puVar13;
  if ((int)((uint)DAT_21000f80 << 0x1c) < 0) {
    puVar12 = (undefined4 *)FUN_0100dbc0((int)(puVar19 + 0x54),5,(uint)(byte)puVar19[99],1);
    if (puVar12 == (undefined4 *)0x0) {
      local_34 = puVar12;
      FUN_0100be30(3,&local_34);
      puVar19 = DAT_21000f6c;
      if (local_34 != (undefined4 *)0x0) {
                    /* WARNING (jumptable): Read-only address (ram,0x00000008) is written */
        *(undefined1 *)(local_34 + 2) = 0;
        FUN_0100f788(local_34,DAT_21000f6c,0x10);
        puVar19 = DAT_21000f6c;
      }
    }
    else {
      puVar19 = DAT_21000f6c;
      unaff_r9 = &NMI;
    }
  }
  param_2 = (undefined1 *)(((uint)param_2 | (uint)unaff_r9) & 0xff);
  if (DAT_21000f70 != (code *)0x0) {
    local_34 = (undefined4 *)0x0;
    local_30 = 0;
    local_2c = 0;
    local_28 = (char *)0x0;
    local_24 = 0;
    iVar10 = FUN_010211f0((uint)*(byte *)((int)puVar19 + 0x6f));
    uVar11 = FUN_010211e0((uint)*(byte *)((int)DAT_21000f6c + 0x6f));
    local_34 = (undefined4 *)CONCAT22(local_34._2_2_,*DAT_21000f6c);
    local_30 = CONCAT22((short)uVar11 + (short)((iVar10 + 500U) / 1000),DAT_21000f6c[0x5e]);
    uVar21 = FUN_0100ddd0(*(uint *)(DAT_21000f6c + 10));
    local_34 = (undefined4 *)CONCAT22((short)uVar21,(undefined2)local_34);
    if ((char)DAT_21000f6c[0x1db] != '\0') {
      local_28 = (char *)(DAT_21000f7c + 3);
      uVar8 = FUN_0100edd8(DAT_21000f7c);
      local_24 = CONCAT31(local_24._1_3_,uVar8);
    }
    local_2c = CONCAT31(local_2c._1_3_,
                        (byte)local_2c & 0xfe | *(byte *)((int)DAT_21000f6c + 0x3b5) & 1);
    (*DAT_21000f70)(&local_34);
    puVar19 = DAT_21000f6c;
    *(undefined2 *)((int)DAT_21000f6c + 0x3b5) = 0;
    if (((local_28 != (char *)0x0) && ((char)puVar19[0x1da] == '\0')) &&
       (*(char *)((int)puVar19 + 0xc5) != '2')) {
      uVar21 = local_24 & 0xff;
      if (uVar21 != 0) {
        if (*local_28 == -1) {
          if (uVar21 < 0x1c) goto LAB_01015494;
        }
        else if (((*local_28 == '\a') && (uVar21 == 2)) && (local_28[1] == -1)) {
LAB_01015494:
          *(char **)(puVar19 + 0x1dc) = local_28;
          *(undefined1 *)((int)puVar19 + 0x3b7) = (undefined1)local_24;
          *(undefined1 *)(puVar19 + 0x1da) = 1;
        }
      }
    }
  }
  unaff_r4 = puVar19;
  if ((((char)puVar19[0xa7] != -2) || (param_2 != (undefined1 *)0x0)) ||
     (uVar21 = FUN_0100dbc0((int)(puVar19 + 0x54),1,(uint)*(byte *)((int)puVar19 + 199),1),
     unaff_r4 = DAT_21000f6c, uVar21 != 0)) goto LAB_010154b0;
  if ((char)DAT_21000f6c[0xb0] != '\0') {
    puVar1 = (undefined *)((int)DAT_21000f6c + 0x161);
    DAT_21000f6c[0x7d] = 0;
    *(undefined *)(unaff_r4 + 0xa8) = *puVar1;
    puVar19 = extraout_r2_00;
    puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
    uVar24 = (ulonglong)extraout_r1 << 0x20;
    if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    unaff_r4[0x7e] = 0;
    *(undefined1 *)(unaff_r4 + 0xa7) = 2;
    *(undefined1 *)(unaff_r4 + 0x80) = 1;
    goto LAB_010154b0;
  }
  unaff_r9 = (undefined1 *)FUN_0100dbc0((int)(DAT_21000f6c + 0x54),4,(uint)(byte)DAT_21000f6c[99],1)
  ;
  unaff_r4 = DAT_21000f6c;
  uVar24 = CONCAT44(extraout_r1_00,unaff_r9);
  uVar4 = CONCAT44(extraout_r1_00,unaff_r9);
  if (unaff_r9 != (undefined1 *)0x0) {
    puVar19 = extraout_r2_03;
    switch((char)DAT_21000f6c[99]) {
    case '\x12':
      puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
      if (puVar22 != (ushort *)&UNK_000000fe) goto LAB_01016418;
      *(undefined1 *)(DAT_21000f6c + 0xa7) = 0xb;
      unaff_r4[0x81] = 0;
      break;
    default:
      goto switchD_01015ca4_caseD_13;
    case '\x16':
      uVar11 = extraout_r1_00;
      if ((byte)DAT_21000f6c[0xaa] < 8) {
        cVar6 = FUN_010099f8();
        *(char *)(DAT_21000f6c + 0xaa) = (char)DAT_21000f6c[0xaa] + cVar6;
        uVar11 = extraout_r1_07;
      }
      uVar24 = CONCAT44(uVar11,DAT_21000f6c);
      puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xaa];
      if (((uint)(puVar19 + -4) & 0xff) < 4) {
        uVar24 = FUN_010099f8();
        puVar19 = DAT_21000f6c;
        *(char *)(DAT_21000f6c + 0xaa) = (char)DAT_21000f6c[0xaa] + (char)uVar24;
      }
      unaff_r4 = DAT_21000f6c;
      uVar21 = (uint)(byte)DAT_21000f6c[0xaa];
      if (0xb < uVar21) {
        if (uVar21 != 0xc) {
          FUN_01009500(0x31,0x5f6,puVar19,uVar21);
          puVar19 = extraout_r2_13;
          iVar10 = extraout_r3_04;
          goto switchD_0101622c_caseD_3;
        }
        puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
        puVar22 = (ushort *)0x0;
        *(undefined1 *)(DAT_21000f6c + 0xaa) = 0;
        if (puVar19 != (ushort *)&UNK_000000fe) goto LAB_01016418;
        unaff_r4[0x81] = 0;
        *(undefined1 *)(unaff_r4 + 0xa7) = 4;
      }
      break;
    case '\x17':
      if ((char)DAT_21000f6c[0x1d0] == '\x01') {
        bVar20 = (byte)DAT_21000f6c[0x160];
        unaff_r9 = (undefined1 *)(uint)bVar20;
        if (unaff_r9 == (undefined1 *)0x0) {
          uVar24 = FUN_010110b8((int)((int)DAT_21000f6c + 0x3a1),(int)(DAT_21000f6c + 0x17c),0,
                                (undefined4 *)(DAT_21000f6c + 0x98));
          unaff_r4 = DAT_21000f6c;
          puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
          puVar19 = extraout_r2_08;
          if (puVar22 != (ushort *)&UNK_000000fe) goto LAB_01016418;
          DAT_21000f6c[0x81] = (ushort)bVar20;
          *(byte *)(unaff_r4 + 0x1d0) = bVar20;
          *(undefined1 *)(unaff_r4 + 0xa7) = 5;
        }
      }
      else if ((char)DAT_21000f6c[0x1d0] == '\x02') {
        uVar3 = DAT_21000f6c[0x83];
        unaff_r9 = (undefined1 *)(uint)(byte)uVar3;
        if (unaff_r9 == (undefined1 *)0x0) {
          uVar11 = FUN_0100ffd0(0x21000f68,3,6);
          puVar22 = DAT_21000f6c;
          uVar24 = (ulonglong)CONCAT14((char)DAT_21000f6c[0xa7],uVar11);
          if ((DAT_21000f6c[0x8b] & 4) == 0) {
            puVar19 = (ushort *)0xd;
          }
          else {
            puVar19 = (ushort *)0x11;
          }
          if ((char)DAT_21000f6c[0xa7] != -2) goto LAB_01016418;
          *(char *)(DAT_21000f6c + 0xa7) = (char)puVar19;
          puVar22[0x81] = (ushort)(byte)uVar3;
        }
        else {
          *(undefined1 *)(DAT_21000f6c + 0xa8) = 6;
          puVar19 = (ushort *)(uint)(byte)unaff_r4[0xa7];
          puVar22 = (ushort *)&LAB_00000002;
          uVar24 = uVar4;
          if (puVar19 != (ushort *)&UNK_000000fe) goto LAB_01016418;
          *(undefined1 *)(unaff_r4 + 0xa7) = 2;
          unaff_r4[0x81] = 0;
        }
        unaff_r4 = DAT_21000f6c;
        *(undefined1 *)(DAT_21000f6c + 0x1d0) = 0;
      }
      break;
    case '\x1d':
      puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
      uVar24 = CONCAT44(extraout_r1_00,unaff_r9);
      if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
      *(undefined1 *)(DAT_21000f6c + 0xa7) = 6;
      unaff_r4[0x81] = 0;
    }
    goto LAB_010154b0;
  }
  uVar21 = *(uint *)(DAT_21000f6c + 0x5a);
  puVar19 = (ushort *)(uVar21 & 1);
  if (puVar19 != (ushort *)0x0) {
    puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
    uVar24 = CONCAT44(extraout_r1_00,unaff_r9);
    if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    DAT_21000f6c[0x81] = 0;
    *(undefined1 *)(unaff_r4 + 0xa7) = 9;
    goto LAB_010154b0;
  }
  if ((uVar21 & 2) != 0) {
    puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
    uVar24 = ((ulonglong)uVar21 & 2) << 0x20;
    if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    pbVar2 = (byte *)((int)DAT_21000f6c + 0x107);
    DAT_21000f6c[0x81] = 0;
    *(byte *)((int)unaff_r4 + 0x107) = *pbVar2 | 1;
    *(undefined1 *)(unaff_r4 + 0xa7) = 0xc;
    goto LAB_010154b0;
  }
  iVar10 = uVar21 << 0x1d;
  if (iVar10 < 0) {
    puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
    uVar24 = CONCAT44(uVar21,iVar10) & 0x2ffffffff;
    if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    DAT_21000f6c[0x81] = 0;
    *(undefined1 *)(unaff_r4 + 0xa7) = 0x13;
    goto LAB_010154b0;
  }
  iVar16 = uVar21 << 0x1c;
  uVar24 = CONCAT44(iVar16,iVar10);
  if (iVar16 < 0) {
    *(char *)(DAT_21000f6c + 0xa8) = (char)DAT_21000f6c[0xa4];
    puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
    uVar24 = CONCAT44(iVar16,iVar10);
    if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    *(undefined1 *)(unaff_r4 + 0xa7) = 7;
    unaff_r4[0x81] = 0;
    goto LAB_010154b0;
  }
LAB_01015e98:
  puVar14 = (ushort *)uVar24;
  puVar19 = (ushort *)(uVar21 << 0x18);
  if ((int)puVar19 < 0) {
    puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
    if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
    *(undefined1 *)(unaff_r4 + 0xa7) = 0x1b;
    unaff_r4[0x81] = 0;
  }
  else {
    uVar15 = uVar21 & 0x30;
    if (uVar15 != 0) {
      if (*(char *)((int)unaff_r4 + 0x163) != '\0') goto LAB_01015f4c;
      if ((char)unaff_r4[0xb1] == '\0') goto LAB_01015f40;
      puVar19 = unaff_r4 + 0xb1;
      puVar22 = unaff_r4 + 0x1df;
      if ((char)unaff_r4[99] == '&') goto LAB_01016450;
      uVar21 = (uint)(*(char *)((int)unaff_r4 + 0xc5) == '&');
      goto LAB_01015f22;
    }
    puVar19 = (ushort *)(uVar21 & 0x40);
    if (puVar19 == (ushort *)0x0) {
      uVar15 = uVar21 << 0x17;
      if (-1 < (int)uVar15) goto LAB_01015f4c;
      puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
      uVar24 = CONCAT44(uVar15,puVar14);
      if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
      unaff_r4[0x81] = 0;
      *(undefined1 *)(unaff_r4 + 0xa7) = 0x1e;
    }
    else {
      puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
      uVar24 = CONCAT44(uVar21,puVar14) & 0x30ffffffff;
      if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
      unaff_r4[0x81] = 0;
      *(undefined1 *)(unaff_r4 + 0xa7) = 0x24;
    }
  }
LAB_010154b0:
  unaff_r4[0x174] = unaff_r4[0x174] + 1;
  if ((char)unaff_r4[0x176] == '\0') {
    cVar6 = FUN_0100be08();
    if ((cVar6 != '\0') && ((char)DAT_21000f6c[0x177] == '\0')) {
      unaff_r4[0x174] = 0;
    }
    cVar6 = FUN_0100be24();
    if ((cVar6 != '\0') &&
       (bVar20 = (char)unaff_r4[0x17a] + 1, *(byte *)(unaff_r4 + 0x17a) = bVar20, 2 < bVar20)) {
      unaff_r4[0x174] = 0;
      *(undefined1 *)(unaff_r4 + 0x17a) = 0;
    }
  }
  else {
    uVar21 = FUN_0100be14();
    if (uVar21 != 0) {
      unaff_r4[0x174] = 0;
    }
  }
  uVar21 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)(byte)DAT_21000f6c[99],1);
  if ((uVar21 == 0) && ((char)DAT_21000f6c[99] != '\f')) {
LAB_010154f0:
    uVar21 = (uint)*(byte *)((int)DAT_21000f6c + 0xc9);
LAB_010154f4:
    puVar19 = DAT_21000f6c;
    *(undefined1 *)(DAT_21000f6c + 0x175) = 0;
    uVar15 = 1;
LAB_010154fc:
    *(undefined1 *)(puVar19 + 0x177) = 0;
  }
  else {
    uVar21 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)*(byte *)((int)DAT_21000f6c + 0xc5),1);
    if (uVar21 == 0) {
      uVar21 = (uint)*(byte *)((int)DAT_21000f6c + 0xc9);
      goto LAB_010154f4;
    }
    uVar15 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)*(byte *)((int)DAT_21000f6c + 199),1);
    uVar21 = (uint)*(byte *)((int)DAT_21000f6c + 0xc9);
    if (((uVar15 == 0) || (uVar21 != 2)) || ((char)DAT_21000f6c[0x17a] != '\0')) goto LAB_010154f4;
    bVar7 = FUN_01027516(uVar9);
    puVar19 = DAT_21000f6c;
    if (((!bVar7) || ((char)DAT_21000f6c[0xa7] != -2)) || (DAT_21000f6c[0x171] < 2))
    goto LAB_010154f0;
    puVar22 = DAT_21000f6c + 0x7c;
    puVar14 = DAT_21000f6c + 0x7b;
    *(undefined1 *)(DAT_21000f6c + 0x175) = 1;
    if ((int)(*puVar22 - 2) <= (int)(uint)*puVar14) {
      uVar3 = puVar19[0x174];
      if (uVar3 < DAT_21000f82) {
        uVar21 = 1;
        goto LAB_01015ec2;
      }
LAB_01015eca:
      *(undefined1 *)(puVar19 + 0x175) = 0;
      if (*(char *)((int)puVar19 + 0x7b) == '\0') {
        uVar15 = 1;
        if (*(int *)(puVar19 + 0x3a) != 0) goto LAB_01015854;
        goto LAB_01015ee4;
      }
      uVar21 = (uint)*(byte *)((int)puVar19 + 0xc9);
      uVar15 = 1;
      goto LAB_010154fc;
    }
    uVar3 = puVar19[0x174];
    uVar21 = (*puVar22 - 1) - (uint)*puVar14 & 0xffff;
    if (uVar3 < DAT_21000f82) {
LAB_01015ec2:
      uVar15 = (uint)(ushort)((DAT_21000f82 + 1) - uVar3);
    }
    else {
      uVar15 = 1;
    }
    if (uVar21 <= uVar15) {
      uVar15 = uVar21;
    }
    if (uVar15 == 1) goto LAB_01015eca;
    if ((*(char *)((int)puVar19 + 0x7b) == '\0') && (*(int *)(puVar19 + 0x3a) != 0)) {
LAB_01015854:
      uVar3 = puVar19[0x79] - puVar19[0x5e];
      if ((0 < (short)uVar3) && ((int)(short)uVar3 <= (int)uVar15)) {
        uVar15 = (uint)uVar3;
      }
    }
    if ((DAT_21000f85 == '\0') || (uVar15 < 2)) {
LAB_01015ee4:
      uVar21 = (uint)*(byte *)((int)puVar19 + 0xc9);
      goto LAB_010154fc;
    }
    uVar15 = 1;
    uVar21 = (uint)*(byte *)((int)puVar19 + 0xc9);
    *(undefined1 *)(puVar19 + 0x177) = 1;
  }
  uVar15 = uVar15 + puVar19[0x5e];
  uVar3 = (ushort)uVar15;
  puVar19[0x172] = uVar3;
  if (uVar21 < 2) {
LAB_01015514:
    uVar21 = (uint)DAT_21000f74;
    puVar19[0x170] = uVar3;
joined_r0x010156b0:
    if ((int)(uVar21 << 0x19) < 0) {
      puVar19[0x17b] = 0;
      if ((char)puVar19[0xb0] != '\0') goto LAB_01015530;
LAB_010156cc:
      uVar21 = FUN_0100dbc0((int)(puVar19 + 0x54),1,(uint)*(byte *)((int)puVar19 + 199),1);
      puVar19 = DAT_21000f6c;
      unaff_r4 = DAT_21000f6c;
      if (uVar21 != 0) goto LAB_01015530;
    }
    else {
      puVar19[0x17b] = puVar19[0x17b] + puVar19[0x173];
      if ((char)puVar19[0xb0] == '\0') goto LAB_010156cc;
LAB_01015530:
      puVar19[0x7d] = puVar19[0x7d] + puVar19[0x173];
      unaff_r4 = puVar19;
    }
    uVar21 = (uint)(byte)unaff_r4[0x80];
    if (uVar21 != 0) {
      unaff_r4[0x7e] = unaff_r4[0x7e] + unaff_r4[0x173];
    }
    if ('\0' < (char)unaff_r4[0x82]) {
      unaff_r4[0x81] = unaff_r4[0x81] + unaff_r4[0x173];
    }
    cVar6 = *(char *)((int)unaff_r4 + 0xe5);
    if (cVar6 != '\0') {
LAB_010155a2:
      if ((char)unaff_r4[0x72] == '\0') {
        *(char *)((int)unaff_r4 + 0xe5) = cVar6;
        FUN_0100f788((undefined4 *)(unaff_r4 + 0x6e),&BYTE_010100a1,2);
        unaff_r4 = DAT_21000f6c;
      }
      *(undefined2 *)((int)unaff_r4 + 0xc5) = 0;
      *(undefined1 *)((int)unaff_r4 + 0xc9) = 0;
      if (*(byte *)((int)unaff_r4 + 0x2eb) == 0) {
        FUN_01014698((undefined4 *)unaff_r4,3,0,0);
      }
      else {
        FUN_01014698((undefined4 *)unaff_r4,2,(uint)*(byte *)((int)unaff_r4 + 0x2eb),0);
      }
LAB_010155c8:
      if (DAT_210001d0 != (code *)0x0) {
        (*DAT_210001d0)(DAT_21000f6c,DAT_21000018);
      }
      *(undefined1 *)((int)DAT_21000f6c + 0x2eb) = 0;
      FUN_0100b184();
      return;
    }
    if (param_1 != 0) {
LAB_01015720:
      cVar6 = '=';
      goto LAB_010155a2;
    }
    if (DAT_21000f84 == '\x02') {
      cVar6 = (char)unaff_r4[0xa8];
      if (cVar6 != '\x06') {
        cVar6 = '\x16';
      }
      goto LAB_010155a2;
    }
    if (DAT_21000f84 == '\x01') {
      cVar6 = (char)unaff_r4[100];
      uVar9 = 0;
      if (cVar6 == '\0') goto LAB_010158ea;
      goto LAB_010155a2;
    }
    if (param_2 == (undefined1 *)0x0) {
      if ((((uVar21 == 0) || (unaff_r4[0x7e] < unaff_r4[0x7f])) &&
          (((char)unaff_r4[0x82] < '\x01' || (unaff_r4[0x81] < unaff_r4[0x7f])))) &&
         ((uVar9 = (uint)unaff_r4[0x7c], unaff_r4[0x7d] < uVar9 || ((char)unaff_r4[0xb0] == '\0'))))
      {
        if (*(char *)((int)unaff_r4 + 0xc9) == '\0') {
          uVar9 = (uint)unaff_r4[0x7b];
          uVar21 = 0;
          if (uVar9 < 6) goto LAB_010158ea;
          cVar6 = '>';
        }
        else {
          uVar21 = (uint)unaff_r4[0x7b];
          if (uVar21 < uVar9) {
LAB_010158ea:
            FUN_01014698((undefined4 *)unaff_r4,0,uVar21,uVar9);
            goto LAB_010155c8;
          }
          cVar6 = '\b';
        }
      }
      else {
        cVar6 = '\"';
      }
      goto LAB_010155a2;
    }
    if ((int)param_2 << 0x1b < 0) {
      cVar6 = '\x1e';
      goto LAB_010155a2;
    }
    if ((int)param_2 << 0x1c < 0) goto LAB_01015720;
    param_1 = (int)param_2 << 0x1a;
    if (param_1 < 0) {
      cVar6 = '#';
      goto LAB_010155a2;
    }
    if (((uint)param_2 & 3) != 0) {
      cVar6 = '*';
      goto LAB_010155a2;
    }
    FUN_01009500(0x31,0xadd,(int)param_2 << 0x1b,(int)param_2 << 0x1c);
    puVar19 = extraout_r1_12;
    puVar22 = extraout_r2_16;
LAB_01016450:
    uVar21 = 1;
LAB_01015f22:
    FUN_0100f910((int)unaff_r4,(int)puVar19,(byte *)puVar22,uVar21);
    puVar19 = DAT_21000f6c;
    *(uint *)(DAT_21000f6c + 0x5a) = *(uint *)(DAT_21000f6c + 0x5a) & 0xffffffdf | 0x10;
    *(undefined1 *)(puVar19 + 0xb1) = 0;
    uVar15 = extraout_r1_04;
LAB_01015f40:
    puVar14 = DAT_21000f6c;
    if (*(int *)(DAT_21000f6c + 0x5a) << 0x1b < 0) {
      FUN_0100f9f8((int)DAT_21000f6c);
      uVar24 = FUN_010102e4(0x21000f68);
      unaff_r4 = DAT_21000f6c;
      DAT_21000f6c[0xa8] = DAT_21000f6c[0x27];
      unaff_r4[0xa9] = unaff_r4[0x29];
      puVar19 = extraout_r2_17;
      puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
      if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
      *(undefined1 *)(unaff_r4 + 0xa7) = 0x15;
      unaff_r4[0x81] = 0;
      goto LAB_010154b0;
    }
LAB_01015f4c:
    unaff_r4 = DAT_21000f6c;
    cVar6 = (char)DAT_21000f6c[99];
    if (cVar6 == '+') {
      puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
      uVar24 = CONCAT44(uVar15,puVar14);
      if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
        *(undefined1 *)(DAT_21000f6c + 0xa7) = 0x20;
        unaff_r4[0x81] = 0;
        goto LAB_010154b0;
      }
    }
    else if (cVar6 == '0') {
      puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
      uVar24 = CONCAT44(uVar15,puVar14);
      if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
        *(undefined1 *)(DAT_21000f6c + 0xa7) = 0x11;
        unaff_r4[0x81] = 0;
        goto LAB_010154b0;
      }
    }
    else if ((cVar6 == '#') &&
            (((char)DAT_21000f6c[0xb6] == '\x02' ||
             (((char)DAT_21000f6c[0xb6] == '\x01' && (*(char *)((int)DAT_21000f6c + 0x16d) == '\0'))
             )))) {
      puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
      uVar24 = CONCAT44(uVar15,puVar14);
      if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
        *(undefined1 *)(DAT_21000f6c + 0xa7) = 0x17;
        unaff_r4[0x81] = 0;
        goto LAB_010154b0;
      }
    }
    else {
switchD_01015ca4_caseD_13:
      uVar15 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)*(byte *)((int)DAT_21000f6c + 0xc5),1
                           );
      uVar21 = 0;
      uVar11 = extraout_r1_01;
      if (uVar15 != 0) {
        uVar21 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),4,(uint)(byte)DAT_21000f6c[99],1);
        unaff_r4 = DAT_21000f6c;
        uVar11 = extraout_r1_02;
        if ((uVar21 == 0) && ((char)DAT_21000f6c[0x7a] != '\0')) {
          puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
          puVar22 = extraout_r3_00;
          uVar24 = CONCAT44(extraout_r1_02,uVar21);
          if (puVar19 != (ushort *)&UNK_000000fe) goto LAB_01016418;
          DAT_21000f6c[0x7e] = 0;
          *(undefined1 *)(unaff_r4 + 0xa7) = 0x12;
          *(undefined1 *)(unaff_r4 + 0x80) = 1;
          goto LAB_010154b0;
        }
      }
      unaff_r4 = DAT_21000f6c;
      if (*(byte *)((int)DAT_21000f6c + 0xc5) == 10) {
        *(undefined *)(DAT_21000f6c + 0xa8) = *(undefined *)((int)DAT_21000f6c + 0x149);
        puVar19 = (ushort *)&LAB_0000000a;
        puVar22 = (ushort *)(uint)(byte)unaff_r4[0xa7];
        uVar24 = CONCAT44(uVar11,uVar21);
        if ((ushort *)(uint)(byte)unaff_r4[0xa7] != (ushort *)&UNK_000000fe) goto LAB_01016418;
        uVar8 = 7;
LAB_01015e7a:
        *(undefined1 *)(unaff_r4 + 0xa7) = uVar8;
        unaff_r4[0x7e] = 0;
        *(undefined1 *)(unaff_r4 + 0x80) = 1;
        goto LAB_010154b0;
      }
      if (unaff_r9 != (undefined1 *)0x0) goto LAB_010154b0;
      uVar15 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)*(byte *)((int)DAT_21000f6c + 0xc5),1
                           );
      unaff_r4 = DAT_21000f6c;
      if (uVar15 == 0) {
LAB_0101600c:
        uVar21 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0,(uint)*(byte *)((int)DAT_21000f6c + 0xc5)
                              ,1);
        unaff_r4 = DAT_21000f6c;
        if ((uVar21 == 0) || ((char)DAT_21000f6c[0x1da] == '\0')) goto LAB_010154b0;
        puVar19 = extraout_r2_07;
        puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
        uVar24 = CONCAT44(extraout_r1_06,uVar21);
        if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
          uVar8 = 0xff;
          goto LAB_01015e7a;
        }
      }
      else if (*(char *)((int)DAT_21000f6c + 0x173) == '\0') {
        if ((char)DAT_21000f6c[0xb9] != '\0') {
          bVar20 = *(byte *)((int)DAT_21000f6c + 0x107);
          if ((bVar20 & 3) == 0) {
            puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
            puVar22 = (ushort *)(uint)bVar20;
            uVar24 = CONCAT44(extraout_r1_03,uVar15);
            if (puVar19 != (ushort *)&UNK_000000fe) goto LAB_01016418;
            DAT_21000f6c[0x7e] = 0;
            *(undefined1 *)(unaff_r4 + 0xb9) = 0;
            *(byte *)((int)unaff_r4 + 0x107) = bVar20 | 1;
            *(undefined1 *)(unaff_r4 + 0xa7) = 0xc;
            *(undefined1 *)(unaff_r4 + 0x80) = 1;
            goto LAB_010154b0;
          }
        }
        if (((char)DAT_21000f6c[0xb1] != '\0') && (*(char *)((int)DAT_21000f6c + 0x163) == '\0')) {
          puVar19 = DAT_21000f6c + 0xb1;
          puVar22 = DAT_21000f6c + 0x1df;
          if ((char)DAT_21000f6c[99] == '&') goto LAB_01016426;
          uVar21 = (uint)(*(char *)((int)DAT_21000f6c + 0xc5) == '&');
          goto LAB_01016120;
        }
        puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xb6];
        uVar17 = extraout_r1_03;
        if (((puVar19 == (ushort *)&DAT_00000001) &&
            (puVar19 = (ushort *)(uint)*(byte *)((int)DAT_21000f6c + 0x16d),
            puVar19 == (ushort *)0x0)) &&
           (uVar15 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),0xb,(uint)(byte)DAT_21000f6c[99],
                                  (uint)(byte)DAT_21000f6c[0xb6]), uVar17 = extraout_r1_08,
           puVar19 = extraout_r2_09, uVar15 == 0)) {
          bVar20 = (byte)DAT_21000f6c[0x37];
          uVar5 = (ulonglong)CONCAT14(bVar20,DAT_21000f6c);
          uVar4 = (ulonglong)CONCAT14(bVar20,DAT_21000f6c);
          uVar24 = (ulonglong)CONCAT14(bVar20,DAT_21000f6c);
          iVar10 = bVar20 - 1;
          puVar22 = DAT_21000f6c;
          switch((uint)bVar20) {
          case 1:
            iVar10 = *(byte *)((int)DAT_21000f6c + 0x6f) - 1;
            switch(*(byte *)((int)DAT_21000f6c + 0x6f)) {
            case 1:
              if ((char)DAT_21000f6c[0xb7] != '\x01') goto LAB_010162ea;
LAB_0101633a:
              uVar5 = (ulonglong)CONCAT14(bVar20,DAT_21000f6c);
              if (*(char *)((int)DAT_21000f6c + 0x16f) != '\x01') goto LAB_010162ea;
              break;
            case 2:
              if ((char)DAT_21000f6c[0xb7] == '\x01') {
LAB_0101636a:
                if (*(char *)((int)DAT_21000f6c + 0x16f) == '\x02') break;
              }
              goto LAB_010162ea;
            default:
              goto switchD_0101622c_caseD_3;
            case 4:
            case 8:
              if ((char)DAT_21000f6c[0xb7] != '\x01') goto LAB_010162ea;
              goto LAB_010163dc;
            }
LAB_01016342:
            iVar10 = (int)uVar5;
            iVar10 = FUN_0102a082((uint)*(ushort *)(iVar10 + 0x170),(int)(uVar5 >> 0x20),
                                  (undefined2 *)(iVar10 + 0x3bc),*(undefined2 *)(iVar10 + 0xbc));
            unaff_r4 = DAT_21000f6c;
            if (iVar10 == 0) {
              FUN_01020134(0x21000f68,0,extraout_r2_10);
              goto LAB_0101600c;
            }
            *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0x28;
            goto LAB_010154b0;
          case 2:
            iVar10 = *(byte *)((int)DAT_21000f6c + 0x6f) - 1;
            switch(*(byte *)((int)DAT_21000f6c + 0x6f)) {
            case 1:
              if ((char)DAT_21000f6c[0xb7] == '\x02') goto LAB_0101633a;
              break;
            case 2:
              if ((char)DAT_21000f6c[0xb7] == '\x02') goto LAB_0101636a;
              break;
            default:
              goto switchD_0101622c_caseD_3;
            case 4:
            case 8:
              uVar4 = (ulonglong)CONCAT14(bVar20,DAT_21000f6c);
              if ((char)DAT_21000f6c[0xb7] == '\x02') goto LAB_010163dc;
            }
            break;
          default:
switchD_0101622c_caseD_3:
            uVar24 = FUN_01009500(6,0x294,puVar19,iVar10);
switchD_0101626a_caseD_4:
            puVar22 = (ushort *)uVar24;
            uVar4 = uVar24;
            if ((char)((ushort *)uVar24)[0xb7] == '\x04') {
LAB_010163dc:
              puVar22 = (ushort *)uVar4;
              uVar5 = uVar4;
              if (*(char *)((int)(ushort *)uVar4 + 0x16f) == '\x04') goto LAB_01016342;
            }
            break;
          case 4:
          case 8:
            iVar10 = *(byte *)((int)DAT_21000f6c + 0x6f) - 1;
            switch(*(byte *)((int)DAT_21000f6c + 0x6f)) {
            case 1:
              if ((char)DAT_21000f6c[0xb7] == '\x04') goto LAB_0101633a;
              break;
            case 2:
              if ((char)DAT_21000f6c[0xb7] == '\x04') goto LAB_0101636a;
              break;
            default:
              goto switchD_0101622c_caseD_3;
            case 4:
            case 8:
              goto switchD_0101626a_caseD_4;
            }
          }
LAB_010162ea:
          uVar21 = FUN_0100dbc0((int)(puVar22 + 0x54),3,(uint)(byte)puVar22[99],1);
          if ((uVar21 != 0) ||
             (uVar21 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),2,(uint)(byte)DAT_21000f6c[99],1),
             unaff_r4 = DAT_21000f6c, uVar21 != 0)) goto LAB_0101600c;
          puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
          puVar22 = extraout_r3_03;
          uVar24 = (ulonglong)extraout_r1_09 << 0x20;
          if (puVar19 == (ushort *)&UNK_000000fe) {
            DAT_21000f6c[0x7e] = 0;
            *(undefined1 *)(unaff_r4 + 0xa7) = 0x16;
            *(undefined1 *)(unaff_r4 + 0x80) = 1;
            goto LAB_010154b0;
          }
        }
        else {
          unaff_r4 = DAT_21000f6c;
          if (*(char *)((int)DAT_21000f6c + 0x1a9) == '\0') {
            if ((char)DAT_21000f6c[0xd3] == '\0') {
              if ((char)DAT_21000f6c[0xd5] == '\0') {
                uVar21 = (uint)(byte)DAT_21000f6c[0xba];
                uVar11 = 0;
                puVar19 = DAT_21000f6c;
                if (uVar21 != 0) goto LAB_01015fd4;
                if ((char)DAT_21000f6c[0xd9] == '\0') goto LAB_0101600c;
                puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
                puVar22 = (ushort *)0x0;
                uVar24 = CONCAT44(uVar17,uVar15);
                if (puVar19 == (ushort *)&UNK_000000fe) {
                  DAT_21000f6c[0x7e] = (ushort)(byte)DAT_21000f6c[0xba];
                  *(undefined1 *)(unaff_r4 + 0xa7) = 0x1d;
                  *(undefined1 *)(unaff_r4 + 0x80) = 1;
                  goto LAB_010154b0;
                }
              }
              else {
                puVar19 = (ushort *)0x0;
                puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
                uVar24 = CONCAT44(uVar17,uVar15);
                if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
                  DAT_21000f6c[0x7e] = 0;
                  *(undefined1 *)(unaff_r4 + 0xa7) = 0x22;
                  *(undefined1 *)(unaff_r4 + 0x80) = 1;
                  goto LAB_010154b0;
                }
              }
            }
            else {
              puVar19 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
              puVar22 = (ushort *)0x0;
              uVar24 = CONCAT44(uVar17,uVar15);
              if (puVar19 == (ushort *)&UNK_000000fe) {
                DAT_21000f6c[0x7e] = 0;
                *(undefined1 *)(unaff_r4 + 0xa7) = 0x25;
                *(undefined1 *)(unaff_r4 + 0x80) = 1;
                *(undefined1 *)(unaff_r4 + 0xd3) = 0;
                unaff_r4 = DAT_21000f6c;
                goto LAB_010154b0;
              }
            }
          }
          else {
            puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
            uVar24 = CONCAT44(uVar17,uVar15);
            if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
              uVar8 = 0x23;
              goto LAB_01015e7a;
            }
          }
        }
      }
      else {
        puVar19 = extraout_r2_04;
        puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
        uVar24 = CONCAT44(extraout_r1_03,uVar15);
        if ((ushort *)(uint)(byte)DAT_21000f6c[0xa7] == (ushort *)&UNK_000000fe) {
          DAT_21000f6c[0x7e] = 0;
          *(undefined1 *)((int)unaff_r4 + 0x173) = 0;
          *(undefined1 *)(unaff_r4 + 0xa7) = 0xe;
          *(undefined1 *)(unaff_r4 + 0x80) = 1;
          goto LAB_010154b0;
        }
      }
    }
  }
  else {
    if (uVar21 - 2 < 2) {
      if (*(char *)((int)puVar19 + 199) == '\b') {
        if (puVar19[0x7b] < 3) goto LAB_01015514;
        uVar21 = (uint)DAT_21000f74;
        puVar19[0x170] = puVar19[0x5e] + puVar19[0x7c] + 1;
      }
      else {
        if ((puVar19[0x7b] + 1 < (uint)puVar19[0x7c]) &&
           (uVar9 = (uint)puVar19[0x7c] - (uint)puVar19[0x7b] & 0xffff, uVar9 != 2)) {
          uVar21 = uVar9 - 3 & 0xffff;
        }
        else {
          uVar21 = 0;
        }
        if (((char)puVar19[0x7a] == '\0') ||
           (uVar9 = FUN_0100dbc0((int)(puVar19 + 0x54),9,(uint)*(byte *)((int)puVar19 + 0xc5),1),
           puVar19 = DAT_21000f6c, uVar9 != 0)) {
          if ((*(char *)((int)puVar19 + 0xcb) != '\0') ||
             (uVar9 = FUN_0100dbc0((int)(puVar19 + 0x54),6,(uint)(byte)puVar19[99],1),
             puVar19 = DAT_21000f6c, uVar9 != 0)) {
            if ((*(uint *)(puVar19 + 0x76) < *(int *)(puVar19 + 0x74) + 2U) ||
               (iVar10 = *(uint *)(puVar19 + 0x76) - *(int *)(puVar19 + 0x74), iVar10 == 2)) {
              uVar9 = 0;
            }
            else {
              uVar9 = iVar10 - 3;
            }
            if (uVar9 < uVar21) {
              uVar21 = uVar9 & 0xffff;
            }
          }
          uVar9 = 0;
          if (uVar21 != 0) {
            uVar9 = uVar21 - 1 & 0xffff;
          }
        }
        else {
          uVar9 = 0;
        }
        puVar19[0x170] = puVar19[0x172] + (short)uVar9;
        uVar21 = (uint)DAT_21000f74;
      }
      goto joined_r0x010156b0;
    }
    FUN_01009500(0x31,0x952,uVar15 & 0xffff,uVar21 - 2);
    uVar17 = extraout_r1_05;
    uVar11 = extraout_r2_05;
    uVar21 = extraout_r3_02;
LAB_01015fd4:
    iVar10 = FUN_01016a50((uint)(byte)puVar19[0xbc],uVar17,uVar11,uVar21);
    if (iVar10 == 0) {
      uVar23 = (*DAT_2100020c)(&DAT_21000f68,(undefined *)((int)DAT_21000f6c + 0x179),
                               (undefined *)((int)DAT_21000f6c + 0x19b),(char)DAT_21000f6c[0xbc]);
      uVar11 = extraout_r2_11;
    }
    else {
      uVar23 = (*DAT_21000204)(&DAT_21000f68,(undefined *)((int)DAT_21000f6c + 0x179),
                               (char)DAT_21000f6c[0xbc]);
      uVar11 = extraout_r2_06;
    }
    unaff_r9 = (undefined1 *)uVar23;
    if (unaff_r9 != (undefined1 *)0x0) {
      if (unaff_r9 == &LAB_00000002) {
        *(undefined1 *)(DAT_21000f6c + 0xba) = 0;
      }
      goto LAB_0101600c;
    }
    iVar10 = FUN_01016a50((uint)(byte)DAT_21000f6c[0xbc],(int)((ulonglong)uVar23 >> 0x20),uVar11,
                          DAT_21000f6c);
    unaff_r4 = DAT_21000f6c;
    puVar22 = (ushort *)(uint)(byte)DAT_21000f6c[0xa7];
    puVar19 = extraout_r2_12;
    if (iVar10 == 0) {
      uVar24 = CONCAT44(extraout_r1_10,iVar10);
      if (puVar22 != (ushort *)&UNK_000000fe) goto LAB_01016418;
      DAT_21000f6c[0x7e] = 0;
      *(undefined1 *)(unaff_r4 + 0xa7) = 0x2a;
      *(undefined1 *)(unaff_r4 + 0x80) = 1;
      goto LAB_010154b0;
    }
    uVar24 = CONCAT44(extraout_r1_10,iVar10);
    if (puVar22 == (ushort *)&UNK_000000fe) {
      DAT_21000f6c[0x7e] = 0;
      *(undefined1 *)(unaff_r4 + 0xa7) = 0x1c;
      *(undefined1 *)(unaff_r4 + 0x80) = 1;
      goto LAB_010154b0;
    }
  }
LAB_01016418:
  do {
    FUN_01015084((int)uVar24,(int)(uVar24 >> 0x20),puVar19,puVar22);
    iVar10 = extraout_r2_14;
    uVar21 = extraout_r3_05;
LAB_0101641c:
    FUN_01009500(0x31,0x588,iVar10,uVar21);
    puVar19 = extraout_r1_11;
    puVar22 = extraout_r2_15;
LAB_01016426:
    uVar21 = 1;
LAB_01016120:
    uVar24 = FUN_0100f910((int)unaff_r4,(int)puVar19,(byte *)puVar22,uVar21);
    unaff_r4 = DAT_21000f6c;
    *(undefined1 *)(DAT_21000f6c + 0xb1) = 0;
    puVar19 = (ushort *)(uint)(byte)unaff_r4[0xa7];
    puVar22 = (ushort *)0x0;
  } while (puVar19 != (ushort *)&UNK_000000fe);
  unaff_r4[0x7e] = 0;
  *(undefined1 *)(unaff_r4 + 0xa7) = 0x14;
  *(undefined1 *)(unaff_r4 + 0x80) = 1;
  unaff_r4[0xa8] = unaff_r4[0x27];
  unaff_r4[0xa9] = unaff_r4[0x29];
  goto LAB_010154b0;
}


