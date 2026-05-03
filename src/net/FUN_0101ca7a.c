/*
 * Function: FUN_0101ca7a
 * Entry:    0101ca7a
 * Prototype: uint __stdcall FUN_0101ca7a(uint param_1, undefined4 param_2, undefined4 param_3, int param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

uint FUN_0101ca7a(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined2 *puVar9;
  uint extraout_r2_02;
  undefined4 extraout_r3;
  uint uVar10;
  code *pcVar11;
  int unaff_r7;
  undefined8 uVar12;
  
  if (*(char *)(param_4 + 0xc6) == '#') {
    if (*(short *)(param_4 + 0x31a) == 0) {
      *(undefined1 *)(param_4 + 0xc6) = 0;
      uVar5 = param_1;
      if (*(char *)(param_4 + 0x16c) == '\x01') {
        uVar5 = FUN_01020134(param_1,0,1);
        param_4 = *(int *)(param_1 + 4);
      }
      *(undefined1 *)(param_4 + 0x16c) = 0;
      param_1 = uVar5;
    }
    else {
      *(undefined1 *)(param_4 + 0xc6) = 0x26;
    }
    *(undefined1 *)(param_4 + 0x104) = 0;
    return param_1;
  }
  if (*(byte *)(param_4 + 0xc5) == 0x25) {
    if (*(short *)(param_4 + 0x31a) == 0) {
      *(undefined1 *)(param_4 + 0xc5) = 0;
      uVar5 = FUN_01020134(param_1,0,0x25);
      param_4 = *(int *)(param_1 + 4);
    }
    else {
      *(undefined1 *)(param_4 + 0xc5) = 0x26;
      uVar5 = param_1;
    }
    *(undefined1 *)(param_4 + 0x100) = 0;
    return uVar5;
  }
  iVar6 = FUN_01009500(0x36,0x535,(uint)*(byte *)(param_4 + 0xc5),param_4);
  uVar5 = FUN_0100dbc0(*(int *)(iVar6 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar6 + 4) + 0xc6),0);
  if (uVar5 != 0) {
    puVar7 = *(undefined4 **)(iVar6 + 4);
    *(undefined1 *)(puVar7 + 0x41) = 0;
    uVar5 = FUN_0101c5d4(puVar7,4,extraout_r2_01,0);
    return uVar5;
  }
  uVar12 = FUN_01009500(0x36,0x506,extraout_r2_01,extraout_r3);
  puVar9 = DAT_21001128;
  iVar6 = (int)((ulonglong)uVar12 >> 0x20);
  uVar5 = (uint)uVar12;
  uVar10 = (uint)DAT_2100112e;
  DAT_2100112e = (ushort)(uVar10 | uVar5);
  if ((uVar5 & 3) != 3) {
    if ((int)(uVar5 << 0x1e) < 0) {
      if ((int)(uVar5 << 0x1f) < 0) {
        DAT_21001134 = iVar6;
      }
      DAT_21001130 = iVar6;
      if (*(char *)(iVar6 + 3) == '\x06') {
        if (*(char *)((int)DAT_21001128 + 0xc5) == '\x1a') {
          *(undefined4 *)(DAT_21001128 + 0x94) = 0;
          *(undefined4 *)(puVar9 + 0x96) = 0;
          *(undefined1 *)((int)puVar9 + 0xcb) = 1;
        }
      }
      else if ((*(char *)(iVar6 + 3) == '\v') && (*(char *)((int)DAT_21001128 + 0xc5) == '\x14')) {
        *(undefined1 *)((int)DAT_21001128 + 0xcb) = 0;
      }
    }
    else if ((int)(uVar5 << 0x1f) < 0) {
      DAT_21001134 = iVar6;
    }
    if ((int)(uVar5 << 0x1a) < 0) {
      DAT_2100112c = 8;
    }
    if ((int)(uVar5 << 0x18) < 0) {
      uVar5 = (uint)*(byte *)(iVar6 + 3);
      if (*(undefined **)(DAT_21001128 + 10) < &DAT_00001d4c) {
        uVar10 = 45000U / (uint)*(undefined **)(DAT_21001128 + 10) +
                 (uint)(ushort)DAT_21001128[0x5e] + (uint)(ushort)DAT_21001128[0xe];
      }
      else {
        uVar10 = (uint)(ushort)DAT_21001128[0x5e] + (uint)(ushort)DAT_21001128[0xe] + 6;
      }
      uVar2 = uVar10 & 0xffff;
      uVar4 = (undefined1)(uVar2 >> 8);
      if (uVar5 == 1) {
        DAT_21001128[0x18b] = (short)uVar10;
        *(char *)(iVar6 + 9) = (char)uVar2;
        *(undefined1 *)(iVar6 + 10) = uVar4;
        return 1;
      }
      if (uVar5 == 0) {
        DAT_21001128[399] = (short)uVar10;
        *(char *)(iVar6 + 0xd) = (char)uVar2;
        *(undefined1 *)(iVar6 + 0xe) = uVar4;
        return 0;
      }
      if (uVar5 == 0x18) {
        uVar5 = 0;
        if ((((DAT_21001128[0x18d] != 0) &&
             (uVar5 = uVar2, (*(byte *)(DAT_21001128 + 0x18d) & 0xc) != 0)) &&
            ((*(byte *)(DAT_21001128 + 0x37) & 0xc) != 0)) &&
           ((*(byte *)(DAT_21001128 + 0x18d) != *(byte *)(DAT_21001128 + 0x37) &&
            (*(char *)((int)DAT_21001128 + 0x31b) == '\0')))) {
          uVar5 = 0;
        }
        DAT_21001128[0x18c] = (short)uVar5;
        uVar5 = FUN_0100f0bc(iVar6,uVar5);
        return uVar5;
      }
    }
    return uVar5;
  }
  uVar5 = FUN_01009500(0x36,0xa71,3,uVar10 | uVar5);
  uVar10 = (uint)*(byte *)(DAT_21001128 + 0xaa);
  puVar9 = DAT_21001128;
  if (uVar10 < 8) {
    uVar5 = FUN_010099f8();
    puVar9 = DAT_21001128;
    uVar10 = *(byte *)(DAT_21001128 + 0xaa) + uVar5 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar5);
  }
  if ((uVar10 - 8 & 0xff) < 4) {
    uVar5 = FUN_010099f8();
    puVar9 = DAT_21001128;
    uVar10 = *(byte *)(DAT_21001128 + 0xaa) + uVar5 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar5);
  }
  if (uVar10 < 0xc) {
    return uVar5;
  }
  if (uVar10 == 0xc) {
    *(undefined1 *)(puVar9 + 0xaa) = 0;
    *(undefined1 *)(puVar9 + 0xa7) = 3;
    puVar9[0x7e] = 0;
    *(undefined1 *)(puVar9 + 0x80) = 1;
    return 3;
  }
  pbVar8 = (byte *)FUN_01009500(0x36,0x963,puVar9,uVar10);
  *(byte *)(*(int *)(pbVar8 + 4) + 0x116) = *(byte *)(*(int *)(pbVar8 + 4) + 0x116) | 4;
  bVar3 = FUN_0100f0ec(0);
  uVar4 = FUN_0100f0f4(0);
  puVar9 = DAT_21001128;
  if (0x25 < bVar3) {
    if (bVar3 == 0xfe) {
      uVar5 = 2;
    }
    else {
      uVar5 = 0;
    }
    return uVar5;
  }
  switch(bVar3) {
  case 3:
    if (((*(char *)((int)DAT_21001128 + 0xc5) != '\x18') &&
        (*(char *)((int)DAT_21001128 + 0xc5) != '\x15')) || (*(char *)(DAT_21001128 + 0x83) != '\0')
       ) {
      return 2;
    }
    cVar1 = *(char *)(DAT_21001128 + 0x160);
    *(undefined1 *)((int)DAT_21001128 + 0x105) = 0;
    *(undefined1 *)(puVar9 + 0x80) = 0;
    if (cVar1 == '\0') {
      *(undefined1 *)((int)puVar9 + 0x2c1) = uVar4;
      puVar9[0x161] = *puVar9;
      *(undefined1 *)(puVar9 + 0x162) = 0;
      *(undefined1 *)(puVar9 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar9 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return 0;
    }
    FUN_01009500(0x36,0x36a,0,puVar9);
    pbVar8 = (byte *)(unaff_r7 * 0x40000);
    uVar10 = (uint)Reset;
    uVar5 = (uint)*(byte *)(*(int *)(pbVar8 + 4) + 0xc5);
    switch(uVar10) {
    case 0x12:
    case 0x14:
    case 0x16:
      if (uVar10 == 0x14) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar5,0);
        if (uVar5 != 0) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar8 + 4) + 0x116) = *(byte *)(*(int *)(pbVar8 + 4) + 0x116) & 0xdf;
          FUN_010102e4(0x21001124);
          return 0;
        }
        return 0;
      }
      if (uVar10 == 0x16) {
        if (uVar5 == 0x21) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar8 + 4) + 0x117) = *(byte *)(*(int *)(pbVar8 + 4) + 0x117) & 0xfe;
          iVar6 = *(int *)(pbVar8 + 4);
          *(byte *)(iVar6 + 0x117) = *(byte *)(iVar6 + 0x117) & 0xf7;
          FUN_01020134((int)pbVar8,0x1a,iVar6);
          return 0;
        }
        return 0;
      }
      if (uVar10 == 0x12) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar5,0);
        if (uVar5 != 0) {
          uVar5 = FUN_010109dc(pbVar8);
          return uVar5;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar5,uVar10 - 0x12);
      uVar5 = extraout_r2_02;
    case 0x23:
      if ((uVar5 == 0x29) && (pcVar11 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
        (*pcVar11)(pbVar8);
      }
      break;
    case 0x1d:
      if (uVar5 != 0x31) {
        return 0;
      }
      pcVar11 = DAT_210004c4;
      if (DAT_210004c4 == (code *)0x0) {
        return 0;
      }
      goto LAB_0101ce24;
    case 0x1f:
      if ((uVar5 == 0x2d) && (DAT_210004bc != (code *)0x0)) {
        (*DAT_210004bc)();
      }
    }
    return 0;
  default:
    break;
  case 0x12:
  case 0x14:
  case 0x16:
    uVar5 = (uint)*(byte *)(*(int *)(pbVar8 + 4) + 0xc5);
    if (bVar3 != 0x14) {
      if (bVar3 == 0x16) {
        if (uVar5 == 0x21) {
          FUN_0100ff84(0x21001124);
          FUN_01020134((int)pbVar8,0x1a,extraout_r2_00);
          return 0;
        }
        return 0;
      }
      if (bVar3 == 0x12) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar5,0);
        if (uVar5 != 0) {
          uVar5 = FUN_010109dc(pbVar8);
          return uVar5;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar5,*(int *)(pbVar8 + 4));
      uVar5 = extraout_r2;
    }
    uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar5,0);
    if (uVar5 != 0) {
      FUN_0100ff84(0x21001124);
      FUN_010102e4(0x21001124);
      return 0;
    }
    return 0;
  case 0x1d:
    if (DAT_210004c0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*DAT_210004c0)(0x1d,uVar4);
      return uVar5;
    }
    break;
  case 0x1f:
    if (DAT_210004b8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cda6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*DAT_210004b8)(DAT_21001128,0x1f,uVar4);
      return uVar5;
    }
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    if (DAT_210004cc != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*DAT_210004cc)(bVar3,uVar4);
      return uVar5;
    }
  }
  return 0;
}


