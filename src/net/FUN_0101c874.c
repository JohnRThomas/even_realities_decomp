/*
 * Function: FUN_0101c874
 * Entry:    0101c874
 * Prototype: char * __stdcall FUN_0101c874(byte * param_1, int param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0101c856) */
/* WARNING: Removing unreachable block (ram,0x0101c828) */

char * FUN_0101c874(byte *param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined4 extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar7;
  uint extraout_r2_02;
  undefined4 extraout_r2_03;
  int iVar8;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  
  puVar3 = DAT_21001128;
  uVar1 = *(undefined1 *)(param_2 + 4);
  uVar10 = (uint)*(byte *)((int)DAT_21001128 + 0xc5);
  if (0xc < uVar10 - 0x11) {
    if (uVar10 == 0x29) {
      if (DAT_210004cc == (code *)0x0) {
        return (char *)0x0;
      }
                    /* WARNING: Could not recover jumptable at 0x0101c902. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pcVar5 = (char *)(*DAT_210004cc)(0x23);
      return pcVar5;
    }
    if (uVar10 == 0x1e) {
      iVar11 = 0x14;
    }
    else if (uVar10 == 5) {
      iVar11 = 0x12;
    }
    else {
      if (uVar10 != 0x21) goto LAB_0101c89a;
      iVar11 = 0x16;
    }
    uVar10 = (uint)*(byte *)(*(int *)(param_1 + 4) + 0xc5);
    if (iVar11 != 0x14) {
      if (iVar11 == 0x16) {
        if (uVar10 != 0x21) {
          return (char *)0x0;
        }
        FUN_0100ff84(0x21001124);
        FUN_01020134((int)param_1,0x1a,extraout_r2_03);
        return (char *)0x0;
      }
      if (iVar11 == 0x12) {
        uVar10 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),9,uVar10,0);
        if (uVar10 == 0) {
          return (char *)0x0;
        }
        pcVar5 = (char *)FUN_010109dc(param_1);
        return pcVar5;
      }
      FUN_01009500(0x36,0x3f6,uVar10,*(int *)(param_1 + 4));
      uVar10 = extraout_r2_02;
    }
    uVar10 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),10,uVar10,0);
    if (uVar10 == 0) {
      return (char *)0x0;
    }
    FUN_0100ff84(0x21001124);
    FUN_010102e4(0x21001124);
    return (char *)0x0;
  }
  if (((uVar10 == 0x18) || (uVar10 == 0x15)) && (*(char *)(DAT_21001128 + 0x83) == '\0')) {
    cVar2 = *(char *)(DAT_21001128 + 0x160);
    *(undefined1 *)((int)DAT_21001128 + 0x105) = 0;
    *(undefined1 *)(puVar3 + 0x80) = 0;
    if (cVar2 == '\0') {
      *(undefined1 *)((int)puVar3 + 0x2c1) = uVar1;
      puVar3[0x161] = *puVar3;
      *(undefined1 *)(puVar3 + 0x162) = 0;
      *(undefined1 *)(puVar3 + 0x198) = 0;
      FUN_0100f788((undefined4 *)(puVar3 + 0x15c),0x1010485,2);
      *(undefined1 *)((int)DAT_21001128 + 0xc5) = 0;
      return (char *)0x0;
    }
    pcVar5 = (char *)FUN_01009500(0x36,0x36a,uVar10 - 0x11,0);
    if (*pcVar5 == '\0') {
      pcVar4 = (char *)FUN_0100dbc0(*(int *)(pcVar5 + 4) + 0xa8,0,
                                    (uint)*(byte *)(*(int *)(pcVar5 + 4) + 0xc6),0);
      uVar7 = extraout_r2;
      uVar9 = extraout_r3;
      if (pcVar4 != (char *)0x0) {
        *(undefined1 *)(*(int *)(pcVar5 + 4) + 0x104) = 0;
        return pcVar4;
      }
    }
    else {
      iVar11 = *(int *)(pcVar5 + 4);
      iVar8 = *(uint *)(iVar11 + 0xb4) << 0x1f;
      if (iVar8 < 0) {
        cVar2 = *(char *)(iVar11 + 0x104) + -1;
        *(char *)(iVar11 + 0x104) = cVar2;
        if (-1 < cVar2) {
          *(uint *)(iVar11 + 0xb4) = *(uint *)(iVar11 + 0xb4) & 0xfffffffe;
          return pcVar5;
        }
        FUN_01009500(0x1c,0xb9,iVar11,(int)cVar2);
        iVar11 = extraout_r2_00;
        iVar8 = extraout_r3_00;
      }
      FUN_01009500(0x1c,0xb7,iVar11,iVar8);
      uVar7 = extraout_r2_01;
      uVar9 = extraout_r3_01;
    }
    uVar12 = FUN_01009500(0x1c,0xb2,uVar7,uVar9);
    puVar6 = (undefined1 *)((ulonglong)uVar12 >> 0x20);
    pcVar5 = (char *)((int)uVar12 + -0x1c5);
    *puVar6 = 0xe;
    *(undefined2 *)(puVar6 + 2) = *(undefined2 *)pcVar5;
    return pcVar5;
  }
LAB_0101c89a:
  return &LAB_00000002;
}


