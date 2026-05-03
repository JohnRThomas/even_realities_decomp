/*
 * Function: FUN_01022304
 * Entry:    01022304
 * Prototype: uint __stdcall FUN_01022304(void)
 */


uint FUN_01022304(void)

{
  short sVar1;
  uint *puVar2;
  uint uVar3;
  byte *extraout_r2;
  byte *extraout_r3;
  int iVar4;
  uint uVar5;
  int unaff_r6;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  
  iVar6 = (uint)DAT_21001739 * 3;
  bVar9 = *(byte *)((int)&DAT_21001720 + iVar6);
  uVar3 = (uint)bVar9;
  if (uVar3 != 0x20) {
    iVar4 = (uVar3 + (uint)DAT_21001739 * 0x20) * 2;
    *(undefined *)((int)&DAT_21001720 + iVar6) = (&DAT_21001741)[iVar4];
    DAT_21001729 = 0xff;
    uVar3 = (uint)(byte)(&DAT_210017d8)[uVar3 * 0x20];
    DAT_21001728 = 0;
    DAT_2100171a = 0;
    DAT_2100173a = bVar9;
    (&DAT_21001740)[iVar4] = 2;
    if (uVar3 == 0) {
      uVar3 = FUN_01026438();
    }
    if (DAT_21001bc0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0102235e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*DAT_21001bc0)(0);
      return uVar3;
    }
    return uVar3;
  }
  FUN_01025edc(0x70,0x331,(int)&DAT_210016f0 + iVar6,(uint)DAT_21001739);
  bVar9 = (byte)DAT_21001720;
  puVar2 = (uint *)(unaff_r6 >> 0x1b);
  uVar3 = (uint)(byte)DAT_21001720;
  *extraout_r2 = 0x20;
  uVar7 = 0x20;
  if (uVar3 == 0x20) {
    *extraout_r3 = bVar9;
  }
  else {
    while( true ) {
      uVar5 = uVar3;
      bVar9 = (byte)uVar7;
      iVar6 = uVar5 * 0x20;
      uVar7 = *(uint *)(&DAT_210017c8 + iVar6);
      uVar8 = *puVar2;
      uVar3 = *(int *)(&DAT_210017cc + iVar6) + (uint)CARRY4(*(uint *)(&DAT_210017d0 + iVar6),uVar7)
      ;
      if (puVar2[1] <= uVar3 &&
          (uint)(*(uint *)(&DAT_210017d0 + iVar6) + uVar7 <= uVar8) <= puVar2[1] - uVar3) break;
      if ((*(short *)((int)puVar2 + 0xe) != 0) && (*(short *)(&DAT_210017d6 + iVar6) == 0)) {
        sVar1 = FUN_01024ed8();
        if (sVar1 == 0x356) {
          iVar6 = 0x1d;
        }
        else if (sVar1 == 0x5f5) {
          iVar6 = 0x33;
        }
        else if (sVar1 == 0x18c) {
          iVar6 = 0xe;
        }
        else {
          iVar6 = 1;
        }
        if ((int)(uVar8 - uVar7) < iVar6) {
          bVar9 = *extraout_r2;
          break;
        }
      }
      *extraout_r2 = (byte)uVar5;
      uVar3 = (uint)(byte)(&DAT_21001741)[uVar5 * 2];
      uVar7 = uVar5;
      if ((byte)(&DAT_21001741)[uVar5 * 2] == 0x20) {
        *extraout_r3 = (byte)uVar5;
        return 1;
      }
    }
    *extraout_r3 = bVar9;
    do {
      iVar6 = uVar5 * 0x20;
      uVar8 = *puVar2;
      uVar7 = *(uint *)(&DAT_210017c8 + iVar6);
      uVar3 = puVar2[1] + (uint)CARRY4(puVar2[2],uVar8);
      if (uVar3 < *(uint *)(&DAT_210017cc + iVar6) ||
          *(uint *)(&DAT_210017cc + iVar6) - uVar3 < (uint)(puVar2[2] + uVar8 <= uVar7)) {
        if (*(short *)(&DAT_210017d6 + iVar6) == 0) {
          return 1;
        }
        if (*(short *)((int)puVar2 + 0xe) != 0) {
          return 1;
        }
        sVar1 = FUN_01024ed8();
        if (sVar1 == 0x356) {
          iVar4 = 0x1d;
        }
        else if (sVar1 == 0x5f5) {
          iVar4 = 0x33;
        }
        else if (sVar1 == 0x18c) {
          iVar4 = 0xe;
        }
        else {
          iVar4 = 1;
        }
        if (iVar4 <= (int)(uVar7 - uVar8)) {
          return 1;
        }
      }
      *extraout_r3 = (byte)uVar5;
      if ((byte)(&DAT_210017d8)[iVar6] <= (byte)puVar2[4]) {
        return 0;
      }
      uVar5 = (uint)(byte)(&DAT_21001741)[uVar5 * 2];
    } while (uVar5 != 0x20);
  }
  return 1;
}


