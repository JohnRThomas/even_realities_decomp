/*
 * Function: FUN_0101cae4
 * Entry:    0101cae4
 * Prototype: uint __stdcall FUN_0101cae4(int param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

uint FUN_0101cae4(int param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined2 *puVar8;
  uint extraout_r2_02;
  int iVar9;
  undefined4 extraout_r3;
  uint uVar10;
  code *pcVar11;
  int unaff_r7;
  undefined8 uVar12;
  
  uVar5 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       0);
  if (uVar5 != 0) {
    puVar6 = *(undefined4 **)(param_1 + 4);
    *(undefined1 *)(puVar6 + 0x41) = 0;
    uVar5 = FUN_0101c5d4(puVar6,4,extraout_r2_01,0);
    return uVar5;
  }
  uVar12 = FUN_01009500(0x36,0x506,extraout_r2_01,extraout_r3);
  puVar8 = DAT_21001128;
  iVar9 = (int)((ulonglong)uVar12 >> 0x20);
  uVar5 = (uint)uVar12;
  uVar10 = (uint)DAT_2100112e;
  DAT_2100112e = (ushort)(uVar10 | uVar5);
  if ((uVar5 & 3) != 3) {
    if ((int)(uVar5 << 0x1e) < 0) {
      if ((int)(uVar5 << 0x1f) < 0) {
        DAT_21001134 = iVar9;
      }
      DAT_21001130 = iVar9;
      if (*(char *)(iVar9 + 3) == '\x06') {
        if (*(char *)((int)DAT_21001128 + 0xc5) == '\x1a') {
          *(undefined4 *)(DAT_21001128 + 0x94) = 0;
          *(undefined4 *)(puVar8 + 0x96) = 0;
          *(undefined1 *)((int)puVar8 + 0xcb) = 1;
        }
      }
      else if ((*(char *)(iVar9 + 3) == '\v') && (*(char *)((int)DAT_21001128 + 0xc5) == '\x14')) {
        *(undefined1 *)((int)DAT_21001128 + 0xcb) = 0;
      }
    }
    else if ((int)(uVar5 << 0x1f) < 0) {
      DAT_21001134 = iVar9;
    }
    if ((int)(uVar5 << 0x1a) < 0) {
      DAT_2100112c = 8;
    }
    if ((int)(uVar5 << 0x18) < 0) {
      uVar5 = (uint)*(byte *)(iVar9 + 3);
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
        *(char *)(iVar9 + 9) = (char)uVar2;
        *(undefined1 *)(iVar9 + 10) = uVar4;
        return 1;
      }
      if (uVar5 == 0) {
        DAT_21001128[399] = (short)uVar10;
        *(char *)(iVar9 + 0xd) = (char)uVar2;
        *(undefined1 *)(iVar9 + 0xe) = uVar4;
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
        uVar5 = FUN_0100f0bc(iVar9,uVar5);
        return uVar5;
      }
    }
    return uVar5;
  }
  uVar5 = FUN_01009500(0x36,0xa71,3,uVar10 | uVar5);
  uVar10 = (uint)*(byte *)(DAT_21001128 + 0xaa);
  puVar8 = DAT_21001128;
  if (uVar10 < 8) {
    uVar5 = FUN_010099f8();
    puVar8 = DAT_21001128;
    uVar10 = *(byte *)(DAT_21001128 + 0xaa) + uVar5 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar5);
  }
  if ((uVar10 - 8 & 0xff) < 4) {
    uVar5 = FUN_010099f8();
    puVar8 = DAT_21001128;
    uVar10 = *(byte *)(DAT_21001128 + 0xaa) + uVar5 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar5);
  }
  if (uVar10 < 0xc) {
    return uVar5;
  }
  if (uVar10 == 0xc) {
    *(undefined1 *)(puVar8 + 0xaa) = 0;
    *(undefined1 *)(puVar8 + 0xa7) = 3;
    puVar8[0x7e] = 0;
    *(undefined1 *)(puVar8 + 0x80) = 1;
    return 3;
  }
  pbVar7 = (byte *)FUN_01009500(0x36,0x963,puVar8,uVar10);
  *(byte *)(*(int *)(pbVar7 + 4) + 0x116) = *(byte *)(*(int *)(pbVar7 + 4) + 0x116) | 4;
  bVar3 = FUN_0100f0ec(0);
  uVar4 = FUN_0100f0f4(0);
  puVar8 = DAT_21001128;
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
    *(undefined1 *)(puVar8 + 0x80) = 0;
    if (cVar1 == '\0') {
      *(undefined1 *)((int)puVar8 + 0x2c1) = uVar4;
      puVar8[0x161] = *puVar8;
      *(undefined1 *)(puVar8 + 0x162) = 0;
      *(undefined1 *)(puVar8 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar8 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return 0;
    }
    FUN_01009500(0x36,0x36a,0,puVar8);
    pbVar7 = (byte *)(unaff_r7 * 0x40000);
    uVar10 = (uint)Reset;
    uVar5 = (uint)*(byte *)(*(int *)(pbVar7 + 4) + 0xc5);
    switch(uVar10) {
    case 0x12:
    case 0x14:
    case 0x16:
      if (uVar10 == 0x14) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar5,0);
        if (uVar5 != 0) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar7 + 4) + 0x116) = *(byte *)(*(int *)(pbVar7 + 4) + 0x116) & 0xdf;
          FUN_010102e4(0x21001124);
          return 0;
        }
        return 0;
      }
      if (uVar10 == 0x16) {
        if (uVar5 == 0x21) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar7 + 4) + 0x117) = *(byte *)(*(int *)(pbVar7 + 4) + 0x117) & 0xfe;
          iVar9 = *(int *)(pbVar7 + 4);
          *(byte *)(iVar9 + 0x117) = *(byte *)(iVar9 + 0x117) & 0xf7;
          FUN_01020134((int)pbVar7,0x1a,iVar9);
          return 0;
        }
        return 0;
      }
      if (uVar10 == 0x12) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar5,0);
        if (uVar5 != 0) {
          uVar5 = FUN_010109dc(pbVar7);
          return uVar5;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar5,uVar10 - 0x12);
      uVar5 = extraout_r2_02;
    case 0x23:
      if ((uVar5 == 0x29) && (pcVar11 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
        (*pcVar11)(pbVar7);
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
    uVar5 = (uint)*(byte *)(*(int *)(pbVar7 + 4) + 0xc5);
    if (bVar3 != 0x14) {
      if (bVar3 == 0x16) {
        if (uVar5 == 0x21) {
          FUN_0100ff84(0x21001124);
          FUN_01020134((int)pbVar7,0x1a,extraout_r2_00);
          return 0;
        }
        return 0;
      }
      if (bVar3 == 0x12) {
        uVar5 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar5,0);
        if (uVar5 != 0) {
          uVar5 = FUN_010109dc(pbVar7);
          return uVar5;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar5,*(int *)(pbVar7 + 4));
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


