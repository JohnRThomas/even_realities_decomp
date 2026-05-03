/*
 * Function: FUN_010224ec
 * Entry:    010224ec
 * Prototype: int __stdcall FUN_010224ec(int param_1, undefined4 param_2, undefined4 param_3, uint param_4)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_010224ec(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  int extraout_r3;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 unaff_r10;
  uint uVar12;
  uint uVar13;
  byte bStack_52;
  byte abStack_51 [5];
  uint uStack_4c;
  uint uStack_48;
  undefined4 *puStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  uVar13 = (uint)DAT_21001739;
  bVar1 = *(byte *)((int)&DAT_21001720 + uVar13 * 3 + 1);
  uStack_28 = param_4;
  do {
    uVar12 = (uint)bVar1;
    if (uVar12 == 0x20) {
      return param_1;
    }
    uVar7 = (uint)DAT_21001739;
    iVar10 = uVar7 * 0x20;
    switch((&DAT_21001740)[(uVar12 + uVar7 * 0x20) * 2]) {
    case 1:
    case 6:
      unaff_r10 = 7;
      break;
    default:
      FUN_01025edc(0x70,0x8d0,param_3,(byte)(&DAT_21001740)[(uVar12 + uVar7 * 0x20) * 2] - 1);
      uStack_2c = 0x10225e3;
      uStack_38 = 0;
      uStack_3c = 0;
      puStack_44 = &DAT_210016f0;
      uVar11 = uStack_28 & 0xff;
      uStack_4c = uVar12;
      uStack_48 = uVar7;
      iStack_40 = iVar10;
      uStack_34 = unaff_r10;
      iStack_30 = uVar13 * 2;
      uVar13 = FUN_01024dd8(4);
      uVar7 = uVar13 + extraout_r2_00;
      uVar9 = extraout_r3 + (uint)CARRY4(uVar13,extraout_r2_00);
      uVar13 = _MasterStackPointer;
      uVar12 = _Reset;
      if (uVar9 <= _Reset && (uint)(0x96f3b83c < uVar7) <= uVar9 - _Reset) {
        return 0;
      }
      goto LAB_0102262c;
    case 4:
      unaff_r10 = 2;
      break;
    case 5:
      unaff_r10 = 3;
    }
    iVar6 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      iVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    iVar8 = uVar7 + uVar13 * 2;
    bVar1 = (&DAT_21001722)[iVar8];
    *(undefined *)((int)&DAT_21001720 + iVar8 + 1) = (&DAT_21001741)[(iVar10 + uVar12) * 2];
    if (bVar1 == uVar12) {
      (&DAT_21001722)[iVar8] = 0x20;
    }
    if (iVar6 == 0) {
      enableIRQinterrupts();
    }
    iVar6 = (iVar10 + uVar12) * 2;
    cVar2 = (&DAT_21001740)[iVar6];
    if ((((cVar2 == '\0') || (cVar2 == '\x06')) || (cVar2 == '\x03')) || (cVar2 == '\x05')) {
      (&DAT_21001740)[(iVar10 + uVar12) * 2] = 1;
    }
    else {
      (&DAT_21001740)[iVar6] = 1;
    }
    param_1 = (*(code *)(&DAT_210017c0)[uVar12 * 8])((&DAT_210017c4)[uVar12 * 8],unaff_r10);
    uVar13 = (uint)DAT_21001739;
    bVar1 = *(byte *)((int)&DAT_21001720 + uVar13 * 3 + 1);
    param_3 = extraout_r2;
  } while( true );
LAB_0102262c:
  _Reset = uVar12;
  _MasterStackPointer = uVar13;
  iVar10 = FUN_0102237c((uint *)0x0,uVar11,&bStack_52,abStack_51);
  if (iVar10 != 0) {
    return iVar10;
  }
  iVar10 = (uint)abStack_51[0] * 0x20;
  uVar5 = *(uint *)(&DAT_210017d0 + iVar10);
  uVar13 = uVar5 + *(uint *)(&DAT_210017c8 + iVar10);
  uVar12 = *(int *)(&DAT_210017cc + iVar10) + (uint)CARRY4(uVar5,*(uint *)(&DAT_210017c8 + iVar10));
  if (*(short *)(&DAT_210017d6 + iVar10) != 0) {
LAB_01022620:
    if (uVar9 <= uVar12 && (uint)(uVar13 <= uVar7) <= uVar9 - uVar12) {
                    /* WARNING: Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      return 0;
    }
    goto LAB_0102262c;
  }
  sVar4 = FUN_01024ed8();
  if (sVar4 == 0x356) {
    iVar10 = 0x1d;
  }
  else if (sVar4 == 0x5f5) {
    iVar10 = 0x33;
  }
  else if (sVar4 == 0x18c) {
    iVar10 = 0xe;
  }
  else {
    iVar10 = 1;
  }
  if (iVar10 <= (int)uVar5) goto LAB_01022620;
  sVar4 = FUN_01024ed8();
  if (sVar4 == 0x356) {
    uVar12 = 0x1d;
  }
  else if (sVar4 == 0x5f5) {
    uVar12 = 0x33;
  }
  else if (sVar4 == 0x18c) {
    uVar12 = 0xe;
  }
  else {
    uVar12 = 1;
  }
  uVar13 = uVar12 + *(uint *)(&DAT_210017c8 + (uint)abStack_51[0] * 0x20);
  uVar12 = *(int *)(&DAT_210017cc + (uint)abStack_51[0] * 0x20) +
           (uint)CARRY4(uVar12,*(uint *)(&DAT_210017c8 + (uint)abStack_51[0] * 0x20));
  if (uVar9 <= uVar12 && (uint)(uVar13 <= uVar7) <= uVar9 - uVar12) {
    return 0;
  }
  goto LAB_0102262c;
}


