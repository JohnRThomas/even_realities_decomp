/*
 * Function: FUN_01012514
 * Entry:    01012514
 * Prototype: uint __stdcall FUN_01012514(uint param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Removing unreachable block (ram,0x01012828) */
/* WARNING: Removing unreachable block (ram,0x01012830) */
/* WARNING: Removing unreachable block (ram,0x010128d6) */
/* WARNING: Removing unreachable block (ram,0x01012838) */
/* WARNING: Removing unreachable block (ram,0x010128e0) */
/* WARNING: Removing unreachable block (ram,0x0101293c) */
/* WARNING: Removing unreachable block (ram,0x01012958) */
/* WARNING: Removing unreachable block (ram,0x0101295e) */
/* WARNING: Removing unreachable block (ram,0x01012964) */
/* WARNING: Removing unreachable block (ram,0x0101296a) */
/* WARNING: Removing unreachable block (ram,0x01012966) */
/* WARNING: Removing unreachable block (ram,0x010128ec) */
/* WARNING: Removing unreachable block (ram,0x0101284a) */
/* WARNING: Removing unreachable block (ram,0x0101290c) */
/* WARNING: Removing unreachable block (ram,0x01012916) */
/* WARNING: Removing unreachable block (ram,0x0101287a) */
/* WARNING: Removing unreachable block (ram,0x0101287e) */
/* WARNING: Removing unreachable block (ram,0x01012810) */
/* WARNING: Removing unreachable block (ram,0x01012882) */
/* WARNING: Removing unreachable block (ram,0x01012926) */
/* WARNING: Removing unreachable block (ram,0x01012816) */
/* WARNING: Removing unreachable block (ram,0x0101281c) */
/* WARNING: Removing unreachable block (ram,0x01012888) */
/* WARNING: Removing unreachable block (ram,0x010128fa) */
/* WARNING: Removing unreachable block (ram,0x010128fe) */
/* WARNING: Removing unreachable block (ram,0x01012902) */
/* WARNING: Removing unreachable block (ram,0x0101290a) */
/* WARNING: Removing unreachable block (ram,0x0101288e) */
/* WARNING: Removing unreachable block (ram,0x01012932) */
/* WARNING: Removing unreachable block (ram,0x01012894) */
/* WARNING: Removing unreachable block (ram,0x010127fa) */
/* WARNING: Removing unreachable block (ram,0x01012802) */
/* WARNING: Removing unreachable block (ram,0x010128d2) */

uint FUN_01012514(uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined1 uVar13;
  int iVar14;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 unaff_r4;
  ushort uVar15;
  undefined4 unaff_r6;
  byte bVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  byte local_49;
  uint auStackY_48 [3];
  
  if ((byte *)*param_2 != (byte *)0x0) {
    uVar7 = FUN_01013324((byte *)*param_2);
    uVar18 = (uint)*(byte *)(param_2 + 3);
    uVar12 = (uint)*(byte *)((int)param_2 + 0xd);
    if (uVar18 == 4) {
      if (uVar12 == 4) {
        uVar17 = 0x2c;
        iVar14 = (uVar7 - 1) * 0x80;
        uVar12 = 8;
        iVar10 = 0x690;
      }
      else {
        iVar14 = (uVar7 - 1) * 0x80;
        uVar17 = 0x2c;
        iVar10 = 0x690;
      }
    }
    else {
      if (uVar12 == 4) {
        uVar12 = 8;
      }
      iVar14 = (uVar7 - 1) * 0x80;
      if (uVar18 == 8) {
        uVar17 = (*(ushort *)(&DAT_0103c17c + uVar18 * 2) + 999) / 1000;
        iVar10 = 0x690;
      }
      else {
        uVar17 = (*(ushort *)(&DAT_0103c17c + uVar18 * 2) + 999) / 1000;
        if (uVar18 == 2) {
          iVar10 = 0x60;
        }
        else {
          iVar10 = 0xf0;
        }
      }
    }
    uVar19 = FUN_010111ec(param_1,(undefined *)(iVar10 * uVar7 + iVar14 + uVar17),uVar12,0,
                          *(ushort *)(param_2 + 1));
    return (uint)((int)uVar19 + 0x131U <= (uint)param_2[2]);
  }
  uVar19 = FUN_01009500(0x2d,0x3fc,param_3,param_4);
  puVar11 = (undefined4 *)((ulonglong)uVar19 >> 0x20);
  puVar8 = (undefined1 *)uVar19;
  *puVar11 = extraout_r2;
  puVar11[1] = extraout_r3;
  puVar11[2] = unaff_r4;
  puVar11[3] = param_1;
  puVar11[4] = unaff_r6;
  if (puVar8[0x78] != '\0') goto LAB_0101266a;
  uVar15 = *(ushort *)(puVar8 + 2) & 1;
  bVar6 = (byte)uVar15;
  if ((*(ushort *)(puVar8 + 2) & 1) == 0) goto LAB_0101266a;
  if ((DAT_21000f32 == '\0') || (uVar12 = FUN_0100d310(), uVar12 == 0xff)) {
    uVar12 = 0xff;
    iVar10 = FUN_01011090(((uint)*DAT_21000f20 << 0x19) >> 0x1f,(uint *)(DAT_21000f20 + 3));
  }
  else {
    iVar10 = FUN_0100d298(uVar12,&local_49,auStackY_48);
    if (iVar10 == 0) {
      FUN_01009500(0x2d,0xf45,extraout_r2_00,extraout_r3_00);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar10 = FUN_01011090((uint)local_49,auStackY_48);
  }
  bVar3 = FUN_0100b23c(((uint)*DAT_21000f20 << 0x19) >> 0x1f,DAT_21000f20 + 3,
                       (uint)(byte)puVar8[0x67],puVar8 + 0x68);
  uVar7 = FUN_0100cf44(((uint)*DAT_21000f20 << 0x19) >> 0x1f,DAT_21000f20 + 3);
  bVar4 = FUN_0100d400(uVar7);
  if ((bVar4) && (puVar9 = FUN_0100d280(uVar7), puVar9 != (undefined *)0x0)) {
    bVar6 = FUN_0100c3ec(uVar7);
    bVar16 = bVar6 ^ 1;
  }
  else {
    bVar16 = 0;
  }
  if (uVar12 == 0xff) {
    bVar3 = (bool)(bVar3 & bVar6);
LAB_01012660:
    if ((int)((uint)*(ushort *)(puVar8 + 2) << 0x1d) < 0) {
      if (bVar3 == false) goto LAB_0101266a;
    }
    else {
LAB_0101277e:
      if ((bVar16 != 0) || ((iVar10 == 0 && (1 < (byte)puVar8[0x11])))) goto LAB_0101266a;
    }
  }
  else {
    if (!bVar3) {
      bVar3 = (byte)puVar8[0x1b] == uVar12;
      goto LAB_01012660;
    }
    if (-1 < (int)((uint)*(ushort *)(puVar8 + 2) << 0x1d)) goto LAB_0101277e;
  }
  bVar3 = FUN_0100b23c(((uint)*DAT_21000f20 << 0x19) >> 0x1f,DAT_21000f20 + 3,(uint)DAT_21000f40,
                       (byte *)&DAT_21000f41);
  if (!bVar3) {
    iVar10 = *(int *)(puVar8 + 0x1c);
    *(byte *)(iVar10 + 0xcd) = *(byte *)(iVar10 + 0xcd) & *DAT_21000f20 >> 5 & 1;
    FUN_01011734((int)puVar8,iVar10,1);
    puVar8[0x85] = 0;
    uVar1 = **(undefined2 **)(puVar8 + 0x1c);
    *(undefined2 *)(puVar8 + 0xa4) = 0xffff;
    *(undefined2 *)(puVar8 + 0x86) = uVar1;
    puVar8[0xa3] = 0xff;
    FUN_01011988((uint)puVar8,(int)*(undefined2 **)(puVar8 + 0x1c),uVar12);
    FUN_0100f788((undefined4 *)(puVar8 + 0x7c),0x1011869,2);
    *(undefined2 *)(puVar8 + 0xbd) = **(undefined2 **)(puVar8 + 0x1c);
    puVar8[0xbf] = *(undefined1 *)((int)*(undefined2 **)(puVar8 + 0x1c) + 0xcd);
    FUN_0100f788((undefined4 *)(puVar8 + 0xb4),0x1011101,2);
    uVar1 = **(undefined2 **)(puVar8 + 0x1c);
    cVar5 = FUN_01020088();
    if (cVar5 == '\0') {
      *(undefined2 *)(puVar8 + 0xb1) = uVar1;
      puVar8[0xaf] = 0;
      puVar8[0xb0] = *puVar8;
      uVar13 = 0;
      if (puVar8[0xd] != '\0') {
        uVar13 = puVar8[0x40];
      }
      puVar8[0xb3] = uVar13;
      FUN_0100f788((undefined4 *)(puVar8 + 0xa6),0x1011add,2);
    }
    DAT_21000f24 = 0;
    if (DAT_21000074 != (code *)0x0) {
      (*DAT_21000074)(*(undefined4 *)(puVar8 + 0x1c),puVar8);
    }
    pbVar2 = DAT_21000f20;
    iVar10 = *(int *)(puVar8 + 0x1c);
    *(undefined4 *)(iVar10 + 3) = *(undefined4 *)(DAT_21000f20 + 3);
    *(undefined2 *)(iVar10 + 7) = *(undefined2 *)(pbVar2 + 7);
    *(byte *)(*(int *)(puVar8 + 0x1c) + 2) = (byte)(((uint)*pbVar2 << 0x19) >> 0x1f);
                    /* WARNING: Could not recover jumptable at 0x0101275e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)0x10125d3)(uVar15);
    return uVar12;
  }
LAB_0101266a:
                    /* WARNING: Could not recover jumptable at 0x01012670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar12 = (*(code *)0x10125d3)(0);
  return uVar12;
}


