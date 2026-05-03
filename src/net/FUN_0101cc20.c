/*
 * Function: FUN_0101cc20
 * Entry:    0101cc20
 * Prototype: int __stdcall FUN_0101cc20(int param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

int FUN_0101cc20(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  uint uVar5;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined2 *puVar6;
  uint extraout_r2_01;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  int unaff_r7;
  
  uVar7 = (uint)*(byte *)(DAT_21001128 + 0xaa);
  puVar6 = DAT_21001128;
  if (uVar7 < 8) {
    param_1 = FUN_010099f8();
    puVar6 = DAT_21001128;
    uVar7 = (uint)*(byte *)(DAT_21001128 + 0xaa) + param_1 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)((uint)*(byte *)(DAT_21001128 + 0xaa) + param_1);
  }
  if ((uVar7 - 8 & 0xff) < 4) {
    param_1 = FUN_010099f8();
    puVar6 = DAT_21001128;
    uVar7 = (uint)*(byte *)(DAT_21001128 + 0xaa) + param_1 & 0xff;
    *(char *)(DAT_21001128 + 0xaa) = (char)((uint)*(byte *)(DAT_21001128 + 0xaa) + param_1);
  }
  if (uVar7 < 0xc) {
    return param_1;
  }
  if (uVar7 == 0xc) {
    *(undefined1 *)(puVar6 + 0xaa) = 0;
    *(undefined1 *)(puVar6 + 0xa7) = 3;
    puVar6[0x7e] = 0;
    *(undefined1 *)(puVar6 + 0x80) = 1;
    return 3;
  }
  pbVar4 = (byte *)FUN_01009500(0x36,0x963,puVar6,uVar7);
  *(byte *)(*(int *)(pbVar4 + 4) + 0x116) = *(byte *)(*(int *)(pbVar4 + 4) + 0x116) | 4;
  bVar2 = FUN_0100f0ec(0);
  uVar3 = FUN_0100f0f4(0);
  puVar6 = DAT_21001128;
  if (0x25 < bVar2) {
    if (bVar2 == 0xfe) {
      iVar9 = 2;
    }
    else {
      iVar9 = 0;
    }
    return iVar9;
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
    *(undefined1 *)(puVar6 + 0x80) = 0;
    if (cVar1 == '\0') {
      *(undefined1 *)((int)puVar6 + 0x2c1) = uVar3;
      puVar6[0x161] = *puVar6;
      *(undefined1 *)(puVar6 + 0x162) = 0;
      *(undefined1 *)(puVar6 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar6 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return 0;
    }
    FUN_01009500(0x36,0x36a,0,puVar6);
    pbVar4 = (byte *)(unaff_r7 * 0x40000);
    uVar5 = (uint)Reset;
    uVar7 = (uint)*(byte *)(*(int *)(pbVar4 + 4) + 0xc5);
    switch(uVar5) {
    case 0x12:
    case 0x14:
    case 0x16:
      if (uVar5 == 0x14) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar7,0);
        if (uVar7 != 0) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar4 + 4) + 0x116) = *(byte *)(*(int *)(pbVar4 + 4) + 0x116) & 0xdf;
          FUN_010102e4(0x21001124);
          return 0;
        }
        return 0;
      }
      if (uVar5 == 0x16) {
        if (uVar7 == 0x21) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar4 + 4) + 0x117) = *(byte *)(*(int *)(pbVar4 + 4) + 0x117) & 0xfe;
          iVar9 = *(int *)(pbVar4 + 4);
          *(byte *)(iVar9 + 0x117) = *(byte *)(iVar9 + 0x117) & 0xf7;
          FUN_01020134((int)pbVar4,0x1a,iVar9);
          return 0;
        }
        return 0;
      }
      if (uVar5 == 0x12) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar7,0);
        if (uVar7 != 0) {
          iVar9 = FUN_010109dc(pbVar4);
          return iVar9;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar7,uVar5 - 0x12);
      uVar7 = extraout_r2_01;
    case 0x23:
      if ((uVar7 == 0x29) && (pcVar8 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
        (*pcVar8)(pbVar4);
      }
      break;
    case 0x1d:
      if (uVar7 != 0x31) {
        return 0;
      }
      pcVar8 = DAT_210004c4;
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
          iVar9 = FUN_010109dc(pbVar4);
          return iVar9;
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
      iVar9 = (*DAT_210004c0)(0x1d,uVar3);
      return iVar9;
    }
    break;
  case 0x1f:
    if (DAT_210004b8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cda6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar9 = (*DAT_210004b8)(DAT_21001128,0x1f,uVar3);
      return iVar9;
    }
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    if (DAT_210004cc != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar9 = (*DAT_210004cc)(bVar2,uVar3);
      return iVar9;
    }
  }
  return 0;
}


