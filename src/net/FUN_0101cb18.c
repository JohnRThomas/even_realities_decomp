/*
 * Function: FUN_0101cb18
 * Entry:    0101cb18
 * Prototype: uint __stdcall FUN_0101cb18(uint param_1, int param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

uint FUN_0101cb18(uint param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined2 *puVar5;
  uint extraout_r2_01;
  int iVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  int unaff_r7;
  
  puVar5 = DAT_21001128;
  uVar7 = (uint)DAT_2100112e;
  DAT_2100112e = (ushort)(uVar7 | param_1);
  if ((param_1 & 3) != 3) {
    if ((int)(param_1 << 0x1e) < 0) {
      if ((int)(param_1 << 0x1f) < 0) {
        DAT_21001134 = param_2;
      }
      DAT_21001130 = param_2;
      if (*(char *)(param_2 + 3) == '\x06') {
        if (*(char *)((int)DAT_21001128 + 0xc5) == '\x1a') {
          *(undefined4 *)(DAT_21001128 + 0x94) = 0;
          *(undefined4 *)(puVar5 + 0x96) = 0;
          *(undefined1 *)((int)puVar5 + 0xcb) = 1;
        }
      }
      else if ((*(char *)(param_2 + 3) == '\v') && (*(char *)((int)DAT_21001128 + 0xc5) == '\x14'))
      {
        *(undefined1 *)((int)DAT_21001128 + 0xcb) = 0;
      }
    }
    else if ((int)(param_1 << 0x1f) < 0) {
      DAT_21001134 = param_2;
    }
    if ((int)(param_1 << 0x1a) < 0) {
      DAT_2100112c = 8;
    }
    if ((int)(param_1 << 0x18) < 0) {
      param_1 = (uint)*(byte *)(param_2 + 3);
      if (*(undefined **)(DAT_21001128 + 10) < &DAT_00001d4c) {
        uVar7 = 45000U / (uint)*(undefined **)(DAT_21001128 + 10) +
                (uint)(ushort)DAT_21001128[0x5e] + (uint)(ushort)DAT_21001128[0xe];
      }
      else {
        uVar7 = (uint)(ushort)DAT_21001128[0x5e] + (uint)(ushort)DAT_21001128[0xe] + 6;
      }
      uVar8 = uVar7 & 0xffff;
      uVar3 = (undefined1)(uVar8 >> 8);
      if (param_1 == 1) {
        DAT_21001128[0x18b] = (short)uVar7;
        *(char *)(param_2 + 9) = (char)uVar8;
        *(undefined1 *)(param_2 + 10) = uVar3;
        return 1;
      }
      if (param_1 == 0) {
        DAT_21001128[399] = (short)uVar7;
        *(char *)(param_2 + 0xd) = (char)uVar8;
        *(undefined1 *)(param_2 + 0xe) = uVar3;
        return 0;
      }
      if (param_1 == 0x18) {
        uVar7 = 0;
        if ((((DAT_21001128[0x18d] != 0) &&
             (uVar7 = uVar8, (*(byte *)(DAT_21001128 + 0x18d) & 0xc) != 0)) &&
            ((*(byte *)(DAT_21001128 + 0x37) & 0xc) != 0)) &&
           ((*(byte *)(DAT_21001128 + 0x18d) != *(byte *)(DAT_21001128 + 0x37) &&
            (*(char *)((int)DAT_21001128 + 0x31b) == '\0')))) {
          uVar7 = 0;
        }
        DAT_21001128[0x18c] = (short)uVar7;
        uVar7 = FUN_0100f0bc(param_2,uVar7);
        return uVar7;
      }
    }
    return param_1;
  }
  uVar7 = FUN_01009500(0x36,0xa71,3,uVar7 | param_1);
  uVar8 = (uint)*(byte *)(DAT_21001128 + 0xaa);
  puVar5 = DAT_21001128;
  if (uVar8 < 8) {
    uVar7 = FUN_010099f8();
    puVar5 = DAT_21001128;
    uVar8 = *(byte *)(DAT_21001128 + 0xaa) + uVar7 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar7);
  }
  if ((uVar8 - 8 & 0xff) < 4) {
    uVar7 = FUN_010099f8();
    puVar5 = DAT_21001128;
    uVar8 = *(byte *)(DAT_21001128 + 0xaa) + uVar7 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)(*(byte *)(DAT_21001128 + 0xaa) + uVar7);
  }
  if (uVar8 < 0xc) {
    return uVar7;
  }
  if (uVar8 == 0xc) {
    *(undefined1 *)(puVar5 + 0xaa) = 0;
    *(undefined1 *)(puVar5 + 0xa7) = 3;
    puVar5[0x7e] = 0;
    *(undefined1 *)(puVar5 + 0x80) = 1;
    return 3;
  }
  pbVar4 = (byte *)FUN_01009500(0x36,0x963,puVar5,uVar8);
  *(byte *)(*(int *)(pbVar4 + 4) + 0x116) = *(byte *)(*(int *)(pbVar4 + 4) + 0x116) | 4;
  bVar2 = FUN_0100f0ec(0);
  uVar3 = FUN_0100f0f4(0);
  puVar5 = DAT_21001128;
  if (0x25 < bVar2) {
    if (bVar2 == 0xfe) {
      uVar7 = 2;
    }
    else {
      uVar7 = 0;
    }
    return uVar7;
  }
  switch(bVar2) {
  case 3:
    if (((*(char *)((int)DAT_21001128 + 0xc5) != '\x18') &&
        (*(char *)((int)DAT_21001128 + 0xc5) != '\x15')) || (*(char *)(DAT_21001128 + 0x83) != '\0')
       ) {
      return 2;
    }
    cVar1 = *(char *)(DAT_21001128 + 0x160);
    *(undefined1 *)((int)DAT_21001128 + 0x105) = 0;
    *(undefined1 *)(puVar5 + 0x80) = 0;
    if (cVar1 == '\0') {
      *(undefined1 *)((int)puVar5 + 0x2c1) = uVar3;
      puVar5[0x161] = *puVar5;
      *(undefined1 *)(puVar5 + 0x162) = 0;
      *(undefined1 *)(puVar5 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar5 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return 0;
    }
    FUN_01009500(0x36,0x36a,0,puVar5);
    pbVar4 = (byte *)(unaff_r7 * 0x40000);
    uVar8 = (uint)Reset;
    uVar7 = (uint)*(byte *)(*(int *)(pbVar4 + 4) + 0xc5);
    switch(uVar8) {
    case 0x12:
    case 0x14:
    case 0x16:
      if (uVar8 == 0x14) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar7,0);
        if (uVar7 != 0) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar4 + 4) + 0x116) = *(byte *)(*(int *)(pbVar4 + 4) + 0x116) & 0xdf;
          FUN_010102e4(0x21001124);
          return 0;
        }
        return 0;
      }
      if (uVar8 == 0x16) {
        if (uVar7 == 0x21) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar4 + 4) + 0x117) = *(byte *)(*(int *)(pbVar4 + 4) + 0x117) & 0xfe;
          iVar6 = *(int *)(pbVar4 + 4);
          *(byte *)(iVar6 + 0x117) = *(byte *)(iVar6 + 0x117) & 0xf7;
          FUN_01020134((int)pbVar4,0x1a,iVar6);
          return 0;
        }
        return 0;
      }
      if (uVar8 == 0x12) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar7,0);
        if (uVar7 != 0) {
          uVar7 = FUN_010109dc(pbVar4);
          return uVar7;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar7,uVar8 - 0x12);
      uVar7 = extraout_r2_01;
    case 0x23:
      if ((uVar7 == 0x29) && (pcVar9 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
        (*pcVar9)(pbVar4);
      }
      break;
    case 0x1d:
      if (uVar7 != 0x31) {
        return 0;
      }
      pcVar9 = DAT_210004c4;
      if (DAT_210004c4 == (code *)0x0) {
        return 0;
      }
      goto LAB_0101ce24;
    case 0x1f:
      if ((uVar7 == 0x2d) && (DAT_210004bc != (code *)0x0)) {
        (*DAT_210004bc)();
      }
    }
    return 0;
  default:
    break;
  case 0x12:
  case 0x14:
  case 0x16:
    uVar7 = (uint)*(byte *)(*(int *)(pbVar4 + 4) + 0xc5);
    if (bVar2 != 0x14) {
      if (bVar2 == 0x16) {
        if (uVar7 == 0x21) {
          FUN_0100ff84(0x21001124);
          FUN_01020134((int)pbVar4,0x1a,extraout_r2_00);
          return 0;
        }
        return 0;
      }
      if (bVar2 == 0x12) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar7,0);
        if (uVar7 != 0) {
          uVar7 = FUN_010109dc(pbVar4);
          return uVar7;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar7,*(int *)(pbVar4 + 4));
      uVar7 = extraout_r2;
    }
    uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar7,0);
    if (uVar7 != 0) {
      FUN_0100ff84(0x21001124);
      FUN_010102e4(0x21001124);
      return 0;
    }
    return 0;
  case 0x1d:
    if (DAT_210004c0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*DAT_210004c0)(0x1d,uVar3);
      return uVar7;
    }
    break;
  case 0x1f:
    if (DAT_210004b8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cda6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*DAT_210004b8)(DAT_21001128,0x1f,uVar3);
      return uVar7;
    }
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    if (DAT_210004cc != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*DAT_210004cc)(bVar2,uVar3);
      return uVar7;
    }
  }
  return 0;
}


