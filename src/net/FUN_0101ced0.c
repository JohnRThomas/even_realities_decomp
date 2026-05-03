/*
 * Function: FUN_0101ced0
 * Entry:    0101ced0
 * Prototype: uint __stdcall FUN_0101ced0(int param_1, uint param_2)
 */


uint FUN_0101ced0(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  byte *pbVar8;
  bool bVar9;
  uint uVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined *puVar14;
  int extraout_r1;
  undefined4 *puVar15;
  int iVar16;
  undefined4 extraout_r2;
  undefined4 *extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 *extraout_r2_02;
  undefined4 *extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 *extraout_r2_05;
  undefined4 *extraout_r2_06;
  uint extraout_r2_07;
  undefined4 extraout_r2_08;
  byte *pbVar17;
  undefined4 extraout_r2_09;
  undefined4 uVar18;
  undefined4 *extraout_r2_10;
  byte *extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  int extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined4 extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined4 extraout_r2_21;
  undefined4 extraout_r2_22;
  undefined4 extraout_r2_23;
  undefined4 uVar19;
  char cVar20;
  undefined1 uVar21;
  uint uVar22;
  int iVar23;
  undefined4 extraout_r3;
  uint extraout_r3_00;
  int extraout_r3_01;
  undefined4 extraout_r3_02;
  uint extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 *unaff_r4;
  undefined8 uVar24;
  ulonglong uVar25;
  byte abStack_38 [4];
  byte *pbStack_34;
  int iStack_30;
  undefined4 *puStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 *local_20;
  char local_1c;
  
  puVar12 = (undefined4 *)DAT_21001128;
  puVar15 = (undefined4 *)(uint)DAT_2100112e;
  if ((int)puVar15 << 0x17 < 0) {
    *(undefined2 *)((int)DAT_21001128 + 0xf6) = 0;
    if (*(char *)((int)puVar12 + 0xcb) == '\0') goto LAB_0101d068;
LAB_0101cef6:
    if ((int)puVar15 << 0x14 < 0) goto LAB_0101d090;
LAB_0101cefc:
    uVar10 = puVar12[0x3b];
    uVar22 = puVar12[0x3a] + 1;
    puVar12[0x3a] = uVar22;
    if ((uVar10 < uVar22) ||
       (unaff_r4 = (undefined4 *)(*(ushort *)(puVar12 + 7) + 5),
       (undefined4 *)(uVar10 - uVar22) <= unaff_r4)) {
      unaff_r4 = (undefined4 *)&DAT_00000001;
      *(undefined1 *)(puVar12 + 0x3d) = 1;
    }
    if (uVar10 <= uVar22) {
      puVar12[0x3a] = 0;
      FUN_0100f7c8((undefined4 *)((int)puVar12 + 0x1c5),0x10109cd,2);
      puVar15 = (undefined4 *)(uint)DAT_2100112e;
    }
  }
  else {
    *(short *)((int)DAT_21001128 + 0xf6) = *(short *)((int)DAT_21001128 + 0xf6) + 1;
    if (*(char *)((int)puVar12 + 0xcb) != '\0') goto LAB_0101cef6;
LAB_0101d068:
    uVar10 = FUN_0100dbc0((int)(puVar12 + 0x2a),6,(uint)*(byte *)((int)puVar12 + 0xc5),0);
    puVar15 = (undefined4 *)(uint)DAT_2100112e;
    if (uVar10 != 0) {
      puVar12 = (undefined4 *)DAT_21001128;
      if ((-1 < (int)puVar15 << 0x14) || (*(char *)((int)DAT_21001128 + 0xcb) == '\0'))
      goto LAB_0101cefc;
LAB_0101d090:
      puVar12[0x3a] = 0;
    }
  }
  puVar12 = (undefined4 *)DAT_21001128;
  if ((((uint)puVar15 & 0x300) != 0) && (*(char *)((int)DAT_21001128 + 0xc9) == '\0')) {
    *(undefined1 *)((int)DAT_21001128 + 0xc9) = 1;
    FUN_0101c5d4(puVar12,1,puVar15,0);
    puVar15 = extraout_r2_02;
  }
  if (param_1 == 1) goto LAB_0101d09c;
  if (param_2 != 0) goto LAB_0101d09c;
  param_2 = (uint)DAT_2100112e;
  if ((int)(param_2 << 0x1d) < 0) {
    if (*(char *)((int)DAT_21001128 + 0xc5) != '\x03') {
      puVar15 = (undefined4 *)(uint)*(byte *)((int)DAT_21001128 + 199);
      if (puVar15 == (undefined4 *)0x7) {
        DAT_21001138 = '\x01';
        puVar15 = (undefined4 *)0x0;
        *(undefined1 *)((int)DAT_21001128 + 199) = 0;
      }
      goto LAB_0101cf70;
    }
    FUN_01009500(0x36,0x497,3,DAT_21001128);
    puVar15 = extraout_r2_06;
    uVar10 = extraout_r3_00;
LAB_0101d6cc:
    FUN_01009500(0x36,0x58d,puVar15,uVar10);
    goto LAB_0101d6d6;
  }
LAB_0101cf70:
  unaff_r4 = (undefined4 *)(param_2 << 0x1e);
  pcVar4 = DAT_210001e0;
  puVar12 = (undefined4 *)DAT_21001128;
  if ((int)unaff_r4 < 0) {
    uVar10 = (uint)*(byte *)(DAT_21001130 + 3);
    if (uVar10 < 0x2b) {
      puVar15 = &DAT_21000400;
      puVar12 = &DAT_21000400 + uVar10;
      uVar10 = 0;
      if ((code *)*puVar12 != (code *)0x0) {
        (*(code *)*puVar12)(&DAT_21001124);
        param_2 = (uint)DAT_2100112e;
        puVar15 = extraout_r2_00;
        pcVar4 = DAT_210001e0;
        puVar12 = (undefined4 *)DAT_21001128;
        goto joined_r0x0101d0ee;
      }
    }
    goto LAB_0101d6cc;
  }
joined_r0x0101d0ee:
  DAT_210001e0 = pcVar4;
  DAT_21001128 = (ushort *)puVar12;
  if (-1 < (int)(param_2 << 0x1c)) {
    uVar10 = (uint)*(byte *)((int)puVar12 + 0xc5);
    goto LAB_0101cf82;
  }
  uVar10 = (uint)*(byte *)((int)puVar12 + 0x14e);
  switch(uVar10) {
  case 0:
    puVar15 = (undefined4 *)(uint)*(ushort *)((int)puVar12 + 0x31e);
    if (-1 < (int)(((uint)*(ushort *)(puVar12 + 0x2f) - (int)puVar15) * 0x10000)) {
      *(undefined1 *)(puVar12 + 199) = 0;
      uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0x14e);
      puVar12 = (undefined4 *)DAT_21001128;
      goto switchD_0101d0fc_caseD_2;
    }
    break;
  case 1:
    if (-1 < (int)(((uint)*(ushort *)(puVar12 + 0x2f) - (uint)*(ushort *)((int)puVar12 + 0x316)) *
                  0x10000)) {
      *(char *)puVar12[0xc4] = *(char *)puVar12[0xc4] + -1;
    }
    break;
  default:
    goto switchD_0101d0fc_caseD_2;
  case 3:
    if (((*(byte *)((int)puVar12 + 0xc5) & 0xfd) != 0x18) &&
       (*(byte *)((int)puVar12 + 0xc5) != 0x15)) {
      *(undefined1 *)(puVar12 + 0xcc) = 0;
    }
    break;
  case 0x1c:
  case 0x2a:
    puVar15 = (undefined4 *)0x0;
    *(undefined1 *)(puVar12 + 0x5d) = 0;
    puVar12 = (undefined4 *)DAT_21001128;
    uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0x14e);
    *(undefined1 *)((int)DAT_21001128 + 0x100) = 0;
    goto switchD_0101d0fc_caseD_2;
  case 0x21:
    if (DAT_210004ac != (code *)0x0) {
      (*DAT_210004ac)(puVar12);
      uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0x14e);
      puVar15 = extraout_r2_05;
      puVar12 = (undefined4 *)DAT_21001128;
      goto switchD_0101d0fc_caseD_2;
    }
    break;
  case 0x22:
    *(undefined1 *)((int)puVar12 + 0x1aa) = 0;
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)((undefined4 *)((int)DAT_21001128 + 0x158),(undefined *)((int)DAT_21001128 + 0x1aa));
    }
    FUN_0100ff84(0x21001124);
    uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0x14e);
    puVar15 = extraout_r2_03;
    puVar12 = (undefined4 *)DAT_21001128;
switchD_0101d0fc_caseD_2:
    if (uVar10 == 0xfe) goto LAB_0101d860;
  }
  uVar10 = (uint)*(byte *)((int)puVar12 + 0xc5);
  *(undefined1 *)((int)puVar12 + 0x14e) = 0xfe;
  if (uVar10 == 0xe) {
    uVar10 = 0xf;
    *(undefined1 *)((int)puVar12 + 0xc5) = 0xf;
  }
  else if (uVar10 == 0x26) {
    uVar10 = 0x27;
    *(undefined1 *)((int)puVar12 + 0xc5) = 0x27;
  }
  else if (uVar10 == 0xc) {
    uVar10 = 0xd;
    *(undefined1 *)((int)puVar12 + 0xc5) = 0xd;
  }
  if (*(char *)((int)puVar12 + 199) == '\b') {
    DAT_21001138 = '\x02';
    *(undefined1 *)((int)puVar12 + 199) = 0;
  }
  param_2 = (uint)DAT_2100112e;
LAB_0101cf82:
  iVar16 = DAT_21001134;
  uVar22 = param_2 & 1;
  param_2 = 0;
  if (uVar22 != 0) {
    uVar21 = *(undefined1 *)(DAT_21001134 + 3);
    uVar10 = FUN_0100dbc0((int)(puVar12 + 0x2a),5,uVar10,0);
    if (uVar10 != 0) {
      switch(uVar21) {
      case 2:
      case 4:
      case 5:
      case 6:
      case 0xb:
      case 0xd:
      case 0x11:
        break;
      default:
        param_2 = 8;
        uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
        puVar12 = (undefined4 *)DAT_21001128;
        goto LAB_0101cf8a;
      }
    }
    bVar9 = FUN_0100ee10(iVar16);
    if (bVar9) {
      if ((*(byte *)(iVar16 + 3) < 0x2b) &&
         (*(code **)(&DAT_21000354 + (uint)*(byte *)(iVar16 + 3) * 4) != (code *)0x0)) {
        param_2 = (**(code **)(&DAT_21000354 + (uint)*(byte *)(iVar16 + 3) * 4))();
        uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
        puVar12 = (undefined4 *)DAT_21001128;
      }
      else {
        param_2 = FUN_0101006c(0x21001124,iVar16);
        uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
        puVar12 = (undefined4 *)DAT_21001128;
      }
    }
    else {
      param_2 = FUN_0101006c(0x21001124,iVar16);
      uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
      puVar12 = (undefined4 *)DAT_21001128;
    }
  }
LAB_0101cf8a:
  if ((int)((uint)DAT_2100112c << 0x1c) < 0) {
    puVar15 = (undefined4 *)FUN_0100dbc0((int)(puVar12 + 0x2a),5,uVar10,0);
    if (puVar15 == (undefined4 *)0x0) {
      local_20 = puVar15;
      FUN_0100be30(3,(int *)&local_20);
      if (local_20 != (undefined4 *)0x0) {
                    /* WARNING (jumptable): Read-only address (ram,0x00000008) is written */
        *(undefined1 *)(local_20 + 2) = 0;
        FUN_0100f788(local_20,DAT_21001128,0x10);
      }
      uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
      puVar12 = (undefined4 *)DAT_21001128;
    }
    else {
      param_2 = 8;
      uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
      puVar12 = (undefined4 *)DAT_21001128;
    }
  }
  if (uVar10 - 0xc < 2) {
    if (*(short *)((int)puVar12 + 0x316) == (short)(*(short *)(puVar12 + 0x2f) + 1)) {
      *(undefined4 *)((int)puVar12 + 0xce) = *(undefined4 *)(puVar12[0xc4] + 1);
      *(undefined1 *)((int)puVar12 + 0xd2) = *(undefined1 *)(puVar12[0xc4] + 5);
      FUN_0100d94c(puVar12,3);
      uVar19 = 0;
      uVar18 = extraout_r2_01;
      if (*(char *)puVar12[0xc4] == '\0') goto LAB_0101d856;
      if (*(char *)((int)DAT_21001128 + 0x14e) != '\x01') {
        **(char **)((int)DAT_21001128 + 0x310) = **(char **)((int)DAT_21001128 + 0x310) + -1;
      }
      *(undefined1 *)((int)puVar12 + 0xc5) = 0;
      uVar10 = (uint)*(byte *)((int)puVar12 + 0xc5);
      *(undefined1 *)((int)puVar12 + 0x11e) = 0xff;
      goto LAB_0101cf9c;
    }
  }
  else {
LAB_0101cf9c:
    if ((uVar10 - 0xe < 2) &&
       (*(short *)((int)puVar12 + 0x31e) == (short)(*(short *)(puVar12 + 0x2f) + 1))) {
      *(undefined2 *)((int)puVar12 + 0x22e) = *(undefined2 *)puVar12;
      uVar10 = FUN_0100ddd0(puVar12[0xca]);
      *(short *)(puVar12 + 0x8c) = (short)uVar10;
      *(undefined2 *)((int)puVar12 + 0x232) = *(undefined2 *)(puVar12 + 0xcb);
      *(undefined2 *)(puVar12 + 0x8d) = *(undefined2 *)((int)puVar12 + 0x32e);
      *(undefined1 *)((int)puVar12 + 0x22d) = 0;
      FUN_0100f7c8(puVar12 + 0x89,&LAB_010101cc_1,2);
      *(undefined1 *)(puVar12 + 199) = 0;
      FUN_0100d94c(puVar12,2);
      FUN_0101c5d4(puVar12,3,extraout_r2_04,extraout_r3);
      *(undefined1 *)((int)puVar12 + 0xc5) = 0;
    }
  }
  puVar15 = (undefined4 *)DAT_21001128;
  if ((*(char *)((int)DAT_21001128 + 0x14e) != -2) ||
     (uVar10 = FUN_0100dbc0((int)((int)DAT_21001128 + 0xa8),1,
                            (uint)*(byte *)((int)DAT_21001128 + 199),0),
     puVar15 = (undefined4 *)DAT_21001128, uVar10 != 0)) goto LAB_0101cfc0;
  if (*(char *)((int)DAT_21001128 + 0x160) != '\0') {
    *(undefined1 *)((int)DAT_21001128 + 0x14e) = 2;
    goto LAB_0101cfc0;
  }
  uVar10 = FUN_0100dbc0((int)((int)DAT_21001128 + 0xa8),0,(uint)*(byte *)((int)DAT_21001128 + 0xc5),
                        0);
  puVar15 = (undefined4 *)DAT_21001128;
  if ((uVar10 != 0) && (*(char *)((int)DAT_21001128 + 0xf4) != '\0')) {
    *(undefined2 *)((int)DAT_21001128 + 0xfc) = 0;
    *(undefined1 *)(puVar15 + 0x40) = 1;
    *(undefined1 *)((int)puVar15 + 0x14e) = 0x12;
    goto LAB_0101cfc0;
  }
  switch((uint)*(byte *)((int)DAT_21001128 + 0xc5)) {
  case 3:
    *(undefined *)((int)DAT_21001128 + 0x150) = *(undefined *)((int)DAT_21001128 + 0x149);
    *(undefined1 *)((int)puVar15 + 0x14e) = 7;
    break;
  default:
    uVar10 = FUN_0100dbc0((int)((int)DAT_21001128 + 0xa8),4,
                          (uint)*(byte *)((int)DAT_21001128 + 0xc5),0);
    puVar15 = (undefined4 *)DAT_21001128;
    if (uVar10 != 0) goto LAB_0101d09c;
    switch(*(undefined *)((int)DAT_21001128 + 0xc6)) {
    case 1:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0xc;
      *(undefined2 *)((int)puVar15 + 0x102) = 0;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      *(byte *)((int)puVar15 + 0x107) = *(byte *)((int)puVar15 + 0x107) | 1;
      break;
    case 2:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x13;
      *(undefined2 *)((int)puVar15 + 0x102) = 0;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      break;
    case 3:
      *(undefined1 *)((int)DAT_21001128 + 0x150) = *(undefined1 *)((int)DAT_21001128 + 0x148);
      *(undefined1 *)((int)puVar15 + 0x14e) = 7;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      break;
    case 4:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 9;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      break;
    case 6:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x1b;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      break;
    case 0x1f:
    case 0x20:
      if (*(char *)((int)DAT_21001128 + 0x163) == '\0') {
        if (*(char *)((int)DAT_21001128 + 0x162) != '\0') {
          FUN_0100f910((int)DAT_21001128,(int)((int)DAT_21001128 + 0x162),
                       (byte *)((int)DAT_21001128 + 0x31a),
                       (uint)(*(byte *)((int)DAT_21001128 + 0xc5) - 0x26 < 2));
          puVar15 = (undefined4 *)DAT_21001128;
          *(undefined1 *)((int)DAT_21001128 + 0xc6) = 0x20;
          *(undefined1 *)((int)puVar15 + 0x162) = 0;
        }
        if (*(char *)((int)DAT_21001128 + 0xc6) == ' ') {
          FUN_0100f9f8((int)DAT_21001128);
          FUN_010102e4(0x21001124);
          puVar15 = (undefined4 *)DAT_21001128;
          *(undefined2 *)((int)DAT_21001128 + 0x150) = *(undefined2 *)((int)DAT_21001128 + 0x4e);
          *(undefined2 *)((int)puVar15 + 0x152) = *(undefined2 *)((int)puVar15 + 0x52);
          *(undefined1 *)((int)puVar15 + 0x14e) = 0x15;
          *(undefined2 *)((int)puVar15 + 0x102) = 0;
          *(undefined1 *)((int)puVar15 + 0xc6) = 0;
        }
      }
      break;
    case 0x23:
      if ((*(char *)((int)DAT_21001128 + 0x16c) == '\x01') &&
         (*(char *)((int)DAT_21001128 + 0x16d) == '\0')) {
        uVar22 = *(uint *)((int)DAT_21001128 + 0x66);
        uVar10 = *(uint *)((int)DAT_21001128 + 0x16e);
      }
      else {
        if (*(char *)((int)DAT_21001128 + 0x16c) != '\x02') break;
        uVar22 = *(uint *)((int)DAT_21001128 + 0x66);
        uVar10 = *(uint *)((int)DAT_21001128 + 0x6a);
      }
      FUN_0102a0ba(0x21001124,uVar10,uVar22);
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x18;
      break;
    case 0x29:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x24;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      break;
    case 0x30:
      *(undefined1 *)((int)DAT_21001128 + 0x150) = 0;
      *(undefined2 *)((int)puVar15 + 0x102) = 0;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
      *(undefined1 *)((int)puVar15 + 0x14e) = 0x11;
      break;
    case 0x31:
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x1e;
      *(undefined1 *)((int)puVar15 + 0xc6) = 0;
    }
    unaff_r4 = (undefined4 *)DAT_21001128;
    puVar15 = (undefined4 *)DAT_21001128;
    if (*(char *)((int)DAT_21001128 + 0x14e) != -2) break;
    uVar10 = FUN_0100dbc0((int)((int)DAT_21001128 + 0xa8),0,
                          (uint)*(byte *)((int)DAT_21001128 + 0xc5),0);
    if (uVar10 == 0) goto LAB_0101d606;
LAB_0101d6d6:
    if ((*(char *)((int)DAT_21001128 + 0x31c) != '\0') &&
       (uVar10 = FUN_0100ffe0((uint)*(byte *)((int)DAT_21001128 + 0xc6)), uVar10 == 0)) {
      *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0;
      goto LAB_0101d606;
    }
    puVar15 = (undefined4 *)DAT_21001128;
    bVar1 = *(byte *)((int)DAT_21001128 + 0x330);
    if (bVar1 != 0) {
      if (*(char *)((int)DAT_21001128 + 0xca) == '\0') {
LAB_0101d734:
        FUN_0101cc20((int)puVar15);
        goto LAB_0101d606;
      }
      if (*(char *)((int)DAT_21001128 + 0xcb) == '\0') {
        puVar15 = (undefined4 *)FUN_01009500(0x36,0x66a,(uint)bVar1,0);
        goto LAB_0101d734;
      }
      uVar21 = 10;
      goto LAB_0101d6fa;
    }
    if (*(char *)((int)DAT_21001128 + 0x173) != '\0') {
      *(ushort *)((int)DAT_21001128 + 0xfc) = (ushort)bVar1;
      *(undefined1 *)(puVar15 + 0x40) = 1;
      *(undefined1 *)((int)puVar15 + 0x14e) = 8;
      goto LAB_0101d606;
    }
    iVar16 = *(int *)((int)DAT_21001128 + 0x35c);
    uVar19 = 0;
    if (iVar16 != 0) {
      bVar1 = *(byte *)(iVar16 + -0x51);
      uVar10 = (uint)bVar1;
      unaff_r4 = (undefined4 *)0xfffffe17;
      iVar23 = iVar16 + -0x1e9;
      if (uVar10 == 1) {
        bVar2 = *(byte *)(iVar16 + -0x28);
        if (bVar2 == 0) {
          if ((int)((uint)*(byte *)((int)DAT_21001128 + 0x119) << 0x1a) < 0) {
            *(ushort *)((int)DAT_21001128 + 0xfc) = (ushort)bVar2;
            *(byte *)(puVar15 + 0x40) = bVar1;
            *(undefined1 *)((int)puVar15 + 0x14e) = 0x1f;
            goto LAB_0101d606;
          }
          (*DAT_210004bc)();
          goto LAB_0101d606;
        }
        FUN_01009500(0x36,0x683,1,(uint)bVar2);
        uVar10 = extraout_r2_07;
        iVar23 = extraout_r3_01;
      }
      puVar15 = (undefined4 *)FUN_01009500(0x36,0x682,uVar10,iVar23);
      uVar19 = extraout_r2_08;
    }
    if (*(char *)((int)puVar15 + 0x172) != '\0') {
      bVar1 = *(byte *)((int)puVar15 + 0x107);
      if ((bVar1 & 3) != 0) goto LAB_0101d606;
      *(byte *)((int)puVar15 + 0x172) = bVar1 & 3;
      *(byte *)((int)puVar15 + 0x107) = bVar1 | 1;
      *(undefined1 *)((int)puVar15 + 0x14e) = 0xc;
      goto LAB_0101d606;
    }
    if ((*(char *)((int)puVar15 + 0x162) != '\0') && (*(char *)((int)puVar15 + 0x163) == '\0')) {
      puVar14 = (undefined *)((int)puVar15 + 0x162);
      uVar5 = CONCAT44(puVar14,puVar15);
      uVar24 = CONCAT44(puVar14,puVar15);
      pbVar17 = (byte *)((int)puVar15 + 0x31a);
      if (*(char *)((int)puVar15 + 0xc6) == '&') goto LAB_0101d86a;
      if (*(byte *)((int)puVar15 + 0xc5) - 0x26 < 2) {
        iVar16 = 1;
        goto LAB_0101d80a;
      }
      iVar16 = 0;
      uVar5 = CONCAT44(puVar14,puVar15);
      goto LAB_0101d80a;
    }
    if (((*(char *)(puVar15 + 0x5b) != '\x01') || (*(char *)((int)puVar15 + 0x16d) != '\0')) ||
       (uVar10 = FUN_0100ffe0((uint)*(byte *)((int)puVar15 + 0xc6)), uVar19 = extraout_r2_13,
       uVar10 != 0)) {
      puVar15 = (undefined4 *)DAT_21001128;
      bVar1 = *(byte *)((int)DAT_21001128 + 0x174);
      if (bVar1 != 0) {
        iVar16 = FUN_01016a50((uint)*(byte *)((int)DAT_21001128 + 0x178),(uint)bVar1,uVar19,
                              DAT_21001128);
        if (iVar16 == 0) {
          uVar24 = (*DAT_21000210)(&DAT_21001124,(undefined *)((int)DAT_21001128 + 0x179),
                                   (undefined *)((int)DAT_21001128 + 0x19b),
                                   *(undefined1 *)((int)DAT_21001128 + 0x178));
          uVar19 = extraout_r2_14;
        }
        else {
          uVar24 = (*DAT_21000208)(&DAT_21001124,(undefined *)((int)DAT_21001128 + 0x179),
                                   *(undefined1 *)((int)DAT_21001128 + 0x178));
          uVar19 = extraout_r2_12;
        }
        if ((int)uVar24 == 0) {
          iVar16 = FUN_01016a50((uint)*(byte *)((int)DAT_21001128 + 0x178),
                                (int)((ulonglong)uVar24 >> 0x20),uVar19,DAT_21001128);
          puVar15 = (undefined4 *)DAT_21001128;
          *(undefined2 *)((int)DAT_21001128 + 0xfc) = 0;
          *(undefined1 *)(puVar15 + 0x40) = 1;
          if (iVar16 == 0) {
            *(undefined1 *)((int)puVar15 + 0x14e) = 0x2a;
            goto LAB_0101d606;
          }
          *(undefined1 *)((int)puVar15 + 0x14e) = 0x1c;
          goto LAB_0101d606;
        }
        if ((int)uVar24 != 2) goto LAB_0101d606;
        *(undefined1 *)((int)DAT_21001128 + 0x174) = 0;
        goto LAB_0101d606;
      }
      if (*(char *)((int)DAT_21001128 + 0x1a9) != '\0') {
        *(ushort *)((int)DAT_21001128 + 0xfc) = (ushort)bVar1;
        *(undefined1 *)(puVar15 + 0x40) = 1;
        *(undefined1 *)((int)puVar15 + 0x14e) = 0x23;
        goto LAB_0101d606;
      }
      if (*(char *)((int)DAT_21001128 + 0x1a6) != '\0') {
        *(undefined2 *)((int)DAT_21001128 + 0xfc) = 0;
        *(undefined1 *)((int)puVar15 + 0x14e) = 0x25;
        *(undefined1 *)(puVar15 + 0x40) = 1;
        *(undefined1 *)((int)puVar15 + 0x1a6) = 0;
        goto LAB_0101d606;
      }
      if (*(char *)((int)DAT_21001128 + 0x1b2) != '\0') {
        *(undefined2 *)((int)DAT_21001128 + 0xfc) = 0;
        *(undefined1 *)(puVar15 + 0x40) = 1;
        *(undefined1 *)((int)puVar15 + 0x14e) = 0x1d;
        goto LAB_0101d606;
      }
      if (*(char *)((int)DAT_21001128 + 0x1aa) == '\0') goto LAB_0101d606;
      iVar16 = FUN_0100a518(*(ushort *)((int)DAT_21001128 + 0x1ac),8);
      puVar15 = (undefined4 *)DAT_21001128;
      if (iVar16 == 0) {
        *(undefined1 *)((int)DAT_21001128 + 0x1aa) = 0;
        goto LAB_0101d606;
      }
      if (*(char *)(iVar16 + 0x1c0) == '\0') {
        *(undefined1 *)((int)DAT_21001128 + 0x1aa) = 0;
        goto LAB_0101d606;
      }
      switch((uint)*(byte *)(iVar16 + 0x198)) {
      case 2:
        *(undefined1 *)(iVar16 + 0x1c1) = *(undefined1 *)((int)DAT_21001128 + 0x1b0);
      case 0:
      case 1:
        *(undefined1 *)((int)DAT_21001128 + 0x1aa) = 0;
        goto LAB_0101d606;
      case 3:
        *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x22;
        *(undefined2 *)(puVar15 + 0x3f) = 0;
        *(undefined1 *)(puVar15 + 0x40) = 1;
        goto LAB_0101d606;
      }
      FUN_01009500(0x36,0x657,(uint)*(byte *)(iVar16 + 0x198),extraout_r3_04);
      iStack_30 = (int)unaff_r4 >> 4;
      puVar11 = (ushort *)(extraout_r2_16 * 0x100);
      uStack_24 = 0x101dbf7;
      puStack_2c = &DAT_21001124;
      DAT_21001124 = DAT_21001124 & 0xffffff00;
      DAT_2100112e = 0;
      DAT_2100112c = 0;
      DAT_21001138 = 0;
      DAT_21001128 = puVar11;
      uStack_28 = param_2;
      FUN_0100b0f8(*puVar11);
      FUN_0100b154(*DAT_21001128);
      iVar16 = FUN_0100e41c((int)(DAT_21001128 + 0x54),(int)DAT_21001128,
                            (uint)(ushort)(puVar11[0x181] + 1));
      if (iVar16 == 0) {
        puVar11[0x181] = 0;
        if ((char)puVar11[99] == '&') {
          if (-1 < (int)(((uint)puVar11[0x5e] - (uint)puVar11[0x18c]) * 0x10000)) {
            *(undefined1 *)(puVar11 + 99) = 0;
            bVar9 = FUN_0101c730();
            goto joined_r0x0101ddc0;
          }
        }
        else if ((*(byte *)((int)puVar11 + 0xc5) - 0x26 < 3) &&
                (-1 < (int)(((uint)puVar11[0x5e] - (uint)puVar11[0x18c]) * 0x10000))) {
          *(undefined1 *)((int)puVar11 + 0xc5) = 0;
          bVar9 = FUN_0101c730();
joined_r0x0101ddc0:
          if (!bVar9) {
            FUN_0101ced0(0,0);
            return 0;
          }
        }
        if (((char)DAT_21001128[0x80] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x7e])) {
          return 1;
        }
        if (((char)DAT_21001128[0x82] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x81])) {
          return 1;
        }
        if (DAT_21001128[0x7c] <= DAT_21001128[0x7d]) {
          return 1;
        }
        if (*(char *)((int)DAT_21001128 + 0xc9) == '\0') {
          if (5 < DAT_21001128[0x7b]) {
            return 1;
          }
        }
        else if (DAT_21001128[0x7c] <= DAT_21001128[0x7b]) {
          return 1;
        }
        uVar10 = (uint)(byte)DAT_21001128[0xa7];
        if (uVar10 == 0xfe) {
LAB_0101dd7a:
          FUN_0100b980(DAT_21001124,DAT_21001128,0x101cb19,0x101ca35,0x101ced1);
          uVar10 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),5,
                                (uint)*(byte *)((int)DAT_21001128 + 0xc5),0);
          if (uVar10 == 0) {
            return 1;
          }
          FUN_0100b970();
          return uVar10;
        }
        iVar16 = FUN_0100b104(&pbStack_34);
        uVar19 = extraout_r2_18;
        uVar18 = extraout_r3_06;
        if (iVar16 == 0) goto LAB_0101e068;
        FUN_01026284((undefined4 *)pbStack_34,0,0x32);
        pbVar17 = pbStack_34;
        FUN_0100eddc(pbStack_34,3);
        bVar1 = *pbStack_34;
        *pbStack_34 = (byte)(bVar1 & 0xffffffef);
        FUN_0100ee34((uint)pbStack_34,uVar10,extraout_r2_19,bVar1 & 0xffffffef);
        pbVar8 = pbStack_34;
        switch(uVar10) {
        case 0:
          uVar10 = FUN_0100de4c((uint)DAT_21001128[400],*(undefined **)(DAT_21001128 + 0x194));
          pbVar17 = pbStack_34;
          pbVar8[4] = (byte)uVar10;
          uVar10 = FUN_0100de88(*(uint *)(DAT_21001128 + 0x192),
                                *(undefined **)(DAT_21001128 + 0x194));
          pbVar8 = pbStack_34;
          pbVar17[5] = (byte)uVar10;
          pbVar17[6] = (byte)(uVar10 >> 8);
          uVar10 = FUN_0100ddd0(*(uint *)(DAT_21001128 + 0x194));
          pbVar8[7] = (byte)uVar10;
          puVar11 = DAT_21001128;
          pbVar8[8] = (byte)(uVar10 >> 8);
          uVar3 = puVar11[0x196];
          pbStack_34[9] = (byte)uVar3;
          pbStack_34[10] = (byte)(uVar3 >> 8);
          FUN_0100ee8c((int)pbStack_34,(uint)puVar11[0x197]);
          break;
        case 1:
          FUN_0100ef08((int)pbStack_34,(undefined4 *)(*(int *)(DAT_21001128 + 0x188) + 1));
          break;
        case 2:
          pbStack_34[4] = *(byte *)((int)DAT_21001128 + 0x161);
          break;
        case 3:
          FUN_0100ef2c((int)pbStack_34,(undefined4 *)((int)DAT_21001128 + 0x331));
          FUN_0100ef44((int)pbStack_34,(undefined2 *)((int)DAT_21001128 + 0x339));
          FUN_0100ef54((int)pbStack_34,(undefined4 *)((int)DAT_21001128 + 0x34b));
          FUN_0100ef74((int)pbStack_34,(undefined4 *)(DAT_21001128 + 0xa0));
          break;
        default:
          FUN_01009500(0x36,0x8ec,extraout_r2_20,extraout_r3_07);
        case 0x23:
        case 0x24:
        case 0x25:
          (*DAT_210004c8)(uVar10,pbStack_34,&DAT_21001124);
          break;
        case 6:
        case 10:
        case 0xb:
        case 0x12:
        case 0x13:
          break;
        case 7:
          pbStack_34[4] = (byte)DAT_21001128[0xa8];
          break;
        case 8:
          FUN_010108f4((int)pbStack_34);
          break;
        case 9:
          FUN_01010910(0x21001124,(int)pbStack_34);
          break;
        case 0xc:
          pbStack_34[8] = 0x21;
          *(undefined1 **)(pbStack_34 + 4) = &DAT_0200590d;
          break;
        case 0x11:
          if ((char)DAT_21001128[0xa8] == '\0') {
            FUN_0100f0e8((int)pbStack_34,*(undefined1 *)((int)DAT_21001128 + 0x14b));
            FUN_0100f0f0((int)pbStack_34,(char)DAT_21001128[0xa5]);
          }
          else {
            FUN_0100f0e8((int)pbStack_34,*(undefined1 *)((int)DAT_21001128 + 0x14d));
            FUN_0100f0f0((int)pbStack_34,(char)DAT_21001128[0xa6]);
          }
          break;
        case 0x14:
        case 0x15:
          FUN_0100efc0((int)pbStack_34,(uint)DAT_21001128[0x26]);
          FUN_0100efc8((int)pbStack_34,(uint)DAT_21001128[0xa8]);
          FUN_0100efb0((int)pbStack_34,(uint)DAT_21001128[0x28]);
          FUN_0100efb8((int)pbStack_34,(uint)DAT_21001128[0xa9]);
          break;
        case 0x16:
          *(ushort *)(pbStack_34 + 4) = DAT_21001128[0xb7];
          break;
        case 0x18:
          uVar10 = FUN_0102a0a8((uint)*(byte *)((int)DAT_21001128 + 0x31b));
          FUN_0100f0b4((int)pbVar8,(char)uVar10);
          pbVar17 = pbStack_34;
          bVar1 = (byte)DAT_21001128[0x18d];
          if ((((bVar1 & 0xc) == 0) || (((byte)DAT_21001128[0x37] & 0xc) == 0)) ||
             ((uint)bVar1 == (uint)(byte)DAT_21001128[0x37])) {
            uVar10 = FUN_0102a0a8((uint)bVar1);
            FUN_0100f0ac((int)pbVar17,(char)uVar10);
          }
          else {
            uVar10 = FUN_0102a0a8(0);
            FUN_0100f0ac((int)pbVar17,(char)uVar10);
          }
          break;
        case 0x1b:
          abStack_38[0] = 0;
          FUN_0100edf4(pbVar17,1);
          cVar20 = (char)DAT_21001128[8];
          if (cVar20 == '\x03') {
            cVar20 = '\0';
          }
          abStack_38[0] =
               *(byte *)((int)DAT_21001128 + 0x11) & 0x1f | cVar20 << 6 | abStack_38[0] & 0x20;
          FUN_0100ee08((int)pbVar17,abStack_38);
          break;
        case 0x1c:
          FUN_0100f008((int)pbStack_34,(undefined4 *)((int)DAT_21001128 + 0x179));
          break;
        case 0x1d:
          FUN_0102a3da((int)pbStack_34);
          break;
        case 0x1e:
          FUN_0102a3ea((int)pbStack_34);
          break;
        case 0x1f:
          if (DAT_210004b4 != (code *)0x0) {
            (*DAT_210004b4)(pbVar17,DAT_21001128);
          }
          break;
        case 0x21:
          if (DAT_210004b0 != (code *)0x0) {
            (*DAT_210004b0)(pbStack_34,DAT_21001128);
          }
          break;
        case 0x22:
          if (DAT_210001e8 != (code *)0x0) {
            (*DAT_210001e8)(pbStack_34,DAT_21001128 + 0xb0);
          }
          break;
        case 0x2a:
          FUN_0100f03c((int)pbStack_34,(undefined4 *)((int)DAT_21001128 + 0x179),
                       (undefined4 *)((int)DAT_21001128 + 0x19b));
        }
        iVar16 = FUN_0100b134();
        uVar19 = extraout_r2_21;
        uVar18 = extraout_r3_08;
        if (iVar16 != 0) {
          bVar1 = pbStack_34[3];
          if (bVar1 == 1) {
            uVar3 = DAT_21001128[0x18b];
            pbStack_34[9] = (byte)uVar3;
            pbStack_34[10] = (byte)(uVar3 >> 8);
          }
          else if (bVar1 == 0) {
            uVar3 = DAT_21001128[399];
            pbStack_34[0xd] = (byte)uVar3;
            pbStack_34[0xe] = (byte)(uVar3 >> 8);
          }
          else if (bVar1 == 0x18) {
            FUN_0100f0bc((int)pbStack_34,(uint)DAT_21001128[0x18c]);
          }
          goto LAB_0101dd7a;
        }
      }
      else {
        FUN_01009500(0x36,0x18e,extraout_r2_17,extraout_r3_05);
        uVar19 = extraout_r2_22;
        uVar18 = extraout_r3_09;
LAB_0101e068:
        FUN_01009500(0x36,0x810,uVar19,uVar18);
        uVar19 = extraout_r2_23;
        uVar18 = extraout_r3_10;
      }
      FUN_01009500(0x36,0x8f2,uVar19,uVar18);
      iVar16 = *(int *)((int)&DAT_21001124 + extraout_r1) << 7;
      if (((((char)DAT_21001128[0x80] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x7e])) ||
          (((char)DAT_21001128[0x82] != '\0' && (DAT_21001128[0x7f] <= DAT_21001128[0x81])))) ||
         (uVar10 = (uint)DAT_21001128[0x7c], uVar10 <= DAT_21001128[0x7d])) {
LAB_0101e0da:
        uVar10 = FUN_0101ced0(0,0);
        return uVar10;
      }
      if (*(char *)((int)DAT_21001128 + 0xc9) == '\0') {
        if (5 < DAT_21001128[0x7b]) goto LAB_0101e0da;
      }
      else if (uVar10 <= DAT_21001128[0x7b]) goto LAB_0101e0da;
      if (DAT_21000c8c != 0) {
        if ((char)DAT_21000c6c != '\0') {
          if (DAT_21000c8c != 2) {
            FUN_01009500(0x27,0x224,uVar10,(uint)DAT_21000c8c);
            uVar10 = FUN_0100b434();
            return uVar10;
          }
          iVar16 = FUN_01020fcc(*(uint *)(DAT_21000c70 + 0x2f0));
          goto LAB_0100bdb6;
        }
        if (DAT_21000c8c == 1) goto LAB_0100bdb6;
        FUN_01009500(0x27,0x220,uVar10,(uint)DAT_21000c8c);
      }
      iVar16 = FUN_0100b434();
LAB_0100bdb6:
      if ((*(char *)(DAT_21000c70 + 0x7b) == '\0') && (*(int *)(DAT_21000c70 + 0x74) != 0)) {
        uVar10 = FUN_01023250((uint)*(byte *)(DAT_21000c70 + 0x7a),(uint *)0x0,0,DAT_21000c70);
        return uVar10;
      }
                    /* WARNING: Could not recover jumptable at 0x0100bdc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar10 = (*(code *)0x101e07d)(iVar16);
      return uVar10;
    }
    bVar1 = *(byte *)((int)DAT_21001128 + 0x6e);
    uVar7 = (ulonglong)CONCAT14(bVar1,DAT_21001128);
    uVar6 = (ulonglong)CONCAT14(bVar1,DAT_21001128);
    uVar25 = (ulonglong)CONCAT14(bVar1,DAT_21001128);
    iVar16 = bVar1 - 1;
    puVar15 = (undefined4 *)DAT_21001128;
    switch((uint)bVar1) {
    case 1:
      iVar16 = *(byte *)((int)DAT_21001128 + 0x6f) - 1;
      switch(*(byte *)((int)DAT_21001128 + 0x6f)) {
      case 1:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x01') {
LAB_0101db5e:
          uVar7 = (ulonglong)CONCAT14(bVar1,DAT_21001128);
          if (*(char *)((int)DAT_21001128 + 0x16f) == '\x01') goto LAB_0101db66;
        }
        break;
      case 2:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x01') {
LAB_0101db8c:
          if (*(char *)((int)DAT_21001128 + 0x16f) == '\x02') goto LAB_0101db66;
        }
        break;
      default:
        goto switchD_0101dabc_caseD_3;
      case 4:
      case 8:
        if (*(char *)((int)DAT_21001128 + 0x16e) != '\x01') break;
        goto LAB_0101dbb0;
      }
      break;
    case 2:
      iVar16 = *(byte *)((int)DAT_21001128 + 0x6f) - 1;
      switch(*(byte *)((int)DAT_21001128 + 0x6f)) {
      case 1:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x02') goto LAB_0101db5e;
        break;
      case 2:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x02') goto LAB_0101db8c;
        break;
      default:
        goto switchD_0101dabc_caseD_3;
      case 4:
      case 8:
        uVar6 = (ulonglong)CONCAT14(bVar1,DAT_21001128);
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x02') goto LAB_0101dbb0;
      }
      break;
    default:
switchD_0101dabc_caseD_3:
      uVar25 = FUN_01009500(6,0x294,extraout_r2_13,iVar16);
switchD_0101db0a_caseD_4:
      puVar15 = (undefined4 *)uVar25;
      uVar6 = uVar25;
      if (*(char *)((int)(undefined4 *)uVar25 + 0x16e) == '\x04') {
LAB_0101dbb0:
        puVar15 = (undefined4 *)uVar6;
        uVar7 = uVar6;
        if (*(char *)((int)(undefined4 *)uVar6 + 0x16f) == '\x04') {
LAB_0101db66:
          iVar16 = (int)uVar7;
          iVar16 = FUN_0102a082((uint)*(ushort *)(iVar16 + 0x170),(int)(uVar7 >> 0x20),
                                (undefined2 *)(iVar16 + 0x318),*(undefined2 *)(iVar16 + 0xbc));
          if (iVar16 == 0) {
            FUN_01020134(0x21001124,0,extraout_r2_15);
            goto LAB_0101d606;
          }
          *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0x28;
          goto LAB_0101d606;
        }
      }
      break;
    case 4:
    case 8:
      iVar16 = *(byte *)((int)DAT_21001128 + 0x6f) - 1;
      switch(*(byte *)((int)DAT_21001128 + 0x6f)) {
      case 1:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x04') goto LAB_0101db5e;
        break;
      case 2:
        if (*(char *)((int)DAT_21001128 + 0x16e) == '\x04') goto LAB_0101db8c;
        break;
      default:
        goto switchD_0101dabc_caseD_3;
      case 4:
      case 8:
        goto switchD_0101db0a_caseD_4;
      }
    }
    uVar21 = 0x16;
LAB_0101d6fa:
    *(undefined1 *)((int)puVar15 + 0x14e) = uVar21;
    *(undefined2 *)(puVar15 + 0x3f) = 0;
    *(undefined1 *)(puVar15 + 0x40) = 1;
    goto LAB_0101d606;
  case 0x13:
    FUN_0101cc20(uVar10);
    puVar15 = (undefined4 *)DAT_21001128;
    break;
  case 0x14:
    uVar21 = 0xb;
    goto LAB_0101d59a;
  case 0x1a:
    uVar21 = 6;
    goto LAB_0101d59a;
  case 0x25:
    *(undefined1 *)((int)DAT_21001128 + 0x14e) = 0x18;
    *(undefined2 *)(puVar15 + 0x3f) = 0;
    break;
  case 0x2e:
    uVar21 = 0x21;
LAB_0101d59a:
    *(undefined1 *)((int)DAT_21001128 + 0x14e) = uVar21;
    *(undefined2 *)(puVar15 + 0x3f) = 0;
    *(undefined1 *)(puVar15 + 0x40) = 1;
    break;
  case 0x30:
    *(undefined1 *)((int)DAT_21001128 + 0x150) = 1;
    *(undefined1 *)((int)puVar15 + 0x14e) = 0x11;
    *(undefined2 *)(puVar15 + 0x3f) = 0;
    *(undefined1 *)((int)puVar15 + 0xc5) = 0;
  }
LAB_0101cfc0:
  if (*(char *)(puVar15 + 0x58) == '\0') goto LAB_0101d0a6;
  do {
    *(short *)((int)puVar15 + 0xfa) = *(short *)((int)puVar15 + 0xfa) + 1;
    do {
      if (*(char *)(puVar15 + 0x40) != '\0') {
        *(short *)(puVar15 + 0x3f) = *(short *)(puVar15 + 0x3f) + 1;
      }
      uVar10 = (uint)*(char *)(puVar15 + 0x41);
      if (uVar10 != 0) {
        *(short *)((int)puVar15 + 0x102) = *(short *)((int)puVar15 + 0x102) + 1;
      }
      if (param_1 != 0) {
LAB_0101d012:
        cVar20 = '=';
LAB_0101d014:
        *(char *)((int)puVar15 + 0xe5) = cVar20;
        FUN_0100f788(puVar15 + 0x37,&BYTE_010100a1,2);
        puVar12 = (undefined4 *)DAT_21001128;
        *(undefined2 *)((int)puVar15 + 0xc5) = 0;
        *(undefined1 *)((int)puVar15 + 0xc9) = 0;
        FUN_0101c5d4(puVar12,2,extraout_r2,0);
        if (*(char *)((int)DAT_21001128 + 0x14e) == '\x01') {
          **(char **)((int)DAT_21001128 + 0x310) = **(char **)((int)DAT_21001128 + 0x310) + -1;
        }
LAB_0101d04a:
        uVar10 = FUN_0100b184();
        return uVar10;
      }
      if (DAT_21001138 == '\x02') {
        cVar20 = '\x16';
        goto LAB_0101d014;
      }
      if (DAT_21001138 == '\x01') {
        cVar20 = *(char *)((int)DAT_21001128 + 200);
        uVar22 = 0;
        if (cVar20 == '\0') goto LAB_0101d234;
        goto LAB_0101d014;
      }
      if (param_2 == 0) {
        if (((*(char *)(puVar15 + 0x40) == '\0') ||
            (*(ushort *)(puVar15 + 0x3f) <= *(ushort *)((int)puVar15 + 0xfe))) &&
           ((uVar10 == 0 || (*(ushort *)((int)puVar15 + 0x102) <= *(ushort *)((int)puVar15 + 0xfe)))
           )) {
          uVar10 = (uint)*(ushort *)(puVar15 + 0x3e);
          if (((*(ushort *)((int)puVar15 + 0xfa) < uVar10) ||
              (*(char *)((int)DAT_21001128 + 0x160) == '\0')) &&
             ((uint)*(ushort *)((int)puVar15 + 0xfa) < (uint)*(ushort *)((int)puVar15 + 0xfe))) {
            if (*(char *)((int)puVar15 + 0xc9) == '\0') {
              uVar22 = (uint)*(ushort *)((int)puVar15 + 0xf6);
              if (uVar22 < 6) goto LAB_0101d234;
              cVar20 = '>';
            }
            else {
              uVar22 = (uint)*(ushort *)((int)puVar15 + 0xf6);
              if (uVar22 < uVar10) {
LAB_0101d234:
                FUN_0101c5d4((undefined4 *)DAT_21001128,0,uVar10,uVar22);
                goto LAB_0101d04a;
              }
              cVar20 = '\b';
            }
            goto LAB_0101d014;
          }
        }
        cVar20 = '\"';
        goto LAB_0101d014;
      }
      iVar16 = param_2 << 0x1b;
      if (iVar16 < 0) {
        cVar20 = '\x1e';
        goto LAB_0101d014;
      }
      iVar23 = param_2 << 0x1c;
      if (iVar23 < 0) goto LAB_0101d012;
      if ((param_2 & 3) != 0) {
        cVar20 = '*';
        goto LAB_0101d014;
      }
      param_2 = param_2 << 0x1a;
      if ((int)param_2 < 0) {
        cVar20 = '#';
        goto LAB_0101d014;
      }
      FUN_01009500(0x36,0xb03,iVar16,iVar23);
      param_1 = 0;
      uVar18 = extraout_r2_09;
      uVar19 = extraout_r3_02;
LAB_0101d856:
      FUN_01009500(0x36,0x21e,uVar18,uVar19);
      puVar15 = extraout_r2_10;
      uVar10 = extraout_r3_03;
LAB_0101d860:
      uVar24 = FUN_01009500(0x36,0x599,puVar15,uVar10);
      pbVar17 = extraout_r2_11;
LAB_0101d86a:
      iVar16 = 1;
      uVar5 = uVar24;
LAB_0101d80a:
      FUN_0100f910((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),pbVar17,iVar16);
      *(undefined1 *)((int)DAT_21001128 + 0x162) = 0;
      puVar15 = (undefined4 *)DAT_21001128;
      *(undefined2 *)((int)DAT_21001128 + 0xfc) = 0;
      *(undefined1 *)(puVar15 + 0x40) = 1;
      *(undefined2 *)(puVar15 + 0x54) = *(undefined2 *)((int)puVar15 + 0x4e);
      *(undefined2 *)((int)puVar15 + 0x152) = *(undefined2 *)((int)puVar15 + 0x52);
      *(undefined1 *)((int)puVar15 + 0x14e) = 0x14;
LAB_0101d606:
      puVar15 = (undefined4 *)DAT_21001128;
      if (((*(char *)((int)DAT_21001128 + 0x14e) != -2) ||
          (uVar10 = FUN_0100dbc0((int)((int)DAT_21001128 + 0xa8),0,
                                 (uint)*(byte *)((int)DAT_21001128 + 0xc5),0),
          puVar15 = (undefined4 *)DAT_21001128, uVar10 == 0)) ||
         (((*(char *)((int)DAT_21001128 + 0x314) == '\0' ||
           ((uVar10 = FUN_0100ffe0((uint)*(byte *)((int)DAT_21001128 + 0xc6)),
            puVar15 = (undefined4 *)DAT_21001128, uVar10 != 0 ||
            (*(ushort *)((int)DAT_21001128 + 0xbc) < 0xb)))) ||
          (iVar16 = FUN_0100dfbc(&local_20), puVar15 = (undefined4 *)DAT_21001128, iVar16 == 0))))
      goto LAB_0101cfc0;
      iVar16 = FUN_010260cc((byte *)&local_20,(byte *)((int)DAT_21001128 + 0xce),5);
      if (iVar16 == 0) {
        *(undefined1 *)(puVar15 + 0xc5) = 0;
      }
      else {
        pcVar13 = (char *)puVar15[0xc4];
        if (*pcVar13 == '\0') {
          *(undefined4 **)(pcVar13 + 1) = local_20;
          pcVar13[5] = local_1c;
        }
        else {
          iVar16 = FUN_010260cc((byte *)&local_20,(byte *)(pcVar13 + 1),5);
          if (iVar16 != 0) goto LAB_0101d09c;
        }
        puVar15 = (undefined4 *)DAT_21001128;
        **(char **)((int)DAT_21001128 + 0x310) = **(char **)((int)DAT_21001128 + 0x310) + '\x01';
        *(undefined1 *)((int)puVar15 + 0x14e) = 1;
        *(undefined1 *)(puVar15 + 0xc5) = 0;
      }
LAB_0101d09c:
      puVar15 = (undefined4 *)DAT_21001128;
      if (*(char *)((int)DAT_21001128 + 0x160) != '\0') break;
LAB_0101d0a6:
      uVar10 = FUN_0100dbc0((int)(puVar15 + 0x2a),1,(uint)*(byte *)((int)puVar15 + 199),0);
    } while (uVar10 == 0);
  } while( true );
}


