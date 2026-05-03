/*
 * Function: FUN_01022f74
 * Entry:    01022f74
 * Prototype: uint __stdcall FUN_01022f74(int param_1)
 */


uint FUN_01022f74(int param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  bVar2 = *(byte *)((int)&DAT_21001720 + param_1 * 3);
  if (DAT_2100171a == '\0') {
    uVar8 = 2;
  }
  else {
    uVar8 = 0;
  }
  uVar4 = FUN_01025828();
  uVar6 = (uint)bVar2;
  uVar9 = 0x20;
  do {
    uVar7 = uVar6;
    uVar6 = *(int *)(&DAT_210017c8 + uVar7 * 0x20) - uVar4 & 0xffffff;
    if (((*(int *)(&DAT_210017d0 + uVar7 * 0x20) + *(int *)(&DAT_210017c8 + uVar7 * 0x20)) - uVar4 &
        0xffffff) < 0x800001) {
      bVar11 = uVar6 <= uVar8;
      bVar10 = uVar8 == uVar6;
      if (!bVar11 || bVar10) {
        bVar11 = 0x7fffff < uVar6;
        bVar10 = uVar6 == 0x800000;
      }
      uVar6 = uVar7;
      if (!bVar11 || bVar10) break;
    }
    uVar6 = (uint)(byte)(&DAT_21001741)[(param_1 * 0x20 + uVar7) * 2];
    uVar9 = uVar7;
  } while (uVar6 != 0x20);
  if (uVar9 == 0x20) {
    return uVar6;
  }
  iVar5 = param_1 * 0x20;
  bVar2 = *(byte *)((int)&DAT_21001720 + param_1 * 3);
  *(undefined *)((int)&DAT_21001720 + param_1 * 3) = (&DAT_21001741)[(uVar9 + param_1 * 0x20) * 2];
  uVar8 = (uint)bVar2;
  do {
    uVar6 = uVar8;
    iVar1 = (iVar5 + uVar6) * 2;
    bVar3 = (&DAT_21001741)[iVar1];
    (&DAT_21001740)[iVar1] = 4;
    uVar8 = (uint)bVar3;
  } while (uVar9 != uVar6);
  if ((&DAT_21001722)[param_1 * 3] == 0x20) {
    *(byte *)((int)&DAT_21001720 + param_1 * 3 + 1) = bVar2;
  }
  else {
    (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[param_1 * 3] + iVar5) * 2] = bVar2;
  }
  (&DAT_21001741)[(uVar6 + iVar5) * 2] = 0x20;
  (&DAT_21001722)[param_1 * 3] = (char)uVar6;
  return (uint)bVar3;
}


