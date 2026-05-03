/*
 * Function: FUN_0101cca8
 * Entry:    0101cca8
 * Prototype: undefined4 __stdcall FUN_0101cca8(byte * param_1, int param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

undefined4 FUN_0101cca8(byte *param_1,int param_2)

{
  char cVar1;
  undefined2 *puVar2;
  byte bVar3;
  undefined1 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r2_01;
  int iVar8;
  code *pcVar9;
  undefined4 uVar10;
  int unaff_r7;
  
  *(byte *)(*(int *)(param_1 + 4) + 0x116) = *(byte *)(*(int *)(param_1 + 4) + 0x116) | 4;
  bVar3 = FUN_0100f0ec(param_2);
  uVar4 = FUN_0100f0f4(param_2);
  puVar2 = DAT_21001128;
  if (0x25 < bVar3) {
    if (bVar3 == 0xfe) {
      uVar10 = 2;
    }
    else {
      uVar10 = 0;
    }
    return uVar10;
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
    *(undefined1 *)(puVar2 + 0x80) = 0;
    if (cVar1 == '\0') {
      *(undefined1 *)((int)puVar2 + 0x2c1) = uVar4;
      puVar2[0x161] = *puVar2;
      *(undefined1 *)(puVar2 + 0x162) = 0;
      *(undefined1 *)(puVar2 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar2 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return 0;
    }
    FUN_01009500(0x36,0x36a,0,puVar2);
    pbVar5 = (byte *)(unaff_r7 * 0x40000);
    uVar6 = (uint)Reset;
    uVar7 = (uint)*(byte *)(*(int *)(pbVar5 + 4) + 0xc5);
    switch(uVar6) {
    case 0x12:
    case 0x14:
    case 0x16:
      if (uVar6 == 0x14) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar7,0);
        if (uVar7 != 0) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar5 + 4) + 0x116) = *(byte *)(*(int *)(pbVar5 + 4) + 0x116) & 0xdf;
          FUN_010102e4(0x21001124);
          return 0;
        }
        return 0;
      }
      if (uVar6 == 0x16) {
        if (uVar7 == 0x21) {
          FUN_0100ff84(0x21001124);
          *(byte *)(*(int *)(pbVar5 + 4) + 0x117) = *(byte *)(*(int *)(pbVar5 + 4) + 0x117) & 0xfe;
          iVar8 = *(int *)(pbVar5 + 4);
          *(byte *)(iVar8 + 0x117) = *(byte *)(iVar8 + 0x117) & 0xf7;
          FUN_01020134((int)pbVar5,0x1a,iVar8);
          return 0;
        }
        return 0;
      }
      if (uVar6 == 0x12) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar7,0);
        if (uVar7 != 0) {
          uVar10 = FUN_010109dc(pbVar5);
          return uVar10;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar7,uVar6 - 0x12);
      uVar7 = extraout_r2_01;
    case 0x23:
      if ((uVar7 == 0x29) && (pcVar9 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
        (*pcVar9)(pbVar5);
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
    uVar7 = (uint)*(byte *)(*(int *)(param_1 + 4) + 0xc5);
    if (bVar3 != 0x14) {
      if (bVar3 == 0x16) {
        if (uVar7 == 0x21) {
          FUN_0100ff84(0x21001124);
          FUN_01020134((int)param_1,0x1a,extraout_r2_00);
          return 0;
        }
        return 0;
      }
      if (bVar3 == 0x12) {
        uVar7 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar7,0);
        if (uVar7 != 0) {
          uVar10 = FUN_010109dc(param_1);
          return uVar10;
        }
        return 0;
      }
      FUN_01009500(0x36,0x3f6,uVar7,*(int *)(param_1 + 4));
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
      uVar10 = (*DAT_210004c0)(0x1d,uVar4);
      return uVar10;
    }
    break;
  case 0x1f:
    if (DAT_210004b8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cda6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar10 = (*DAT_210004b8)(DAT_21001128,0x1f,uVar4);
      return uVar10;
    }
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    if (DAT_210004cc != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101cd22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar10 = (*DAT_210004cc)(bVar3,uVar4);
      return uVar10;
    }
  }
  return 0;
}


