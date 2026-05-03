/*
 * Function: FUN_0102237c
 * Entry:    0102237c
 * Prototype: undefined4 __stdcall FUN_0102237c(uint * param_1, int param_2, byte * param_3, byte * param_4)
 */


undefined4 FUN_0102237c(uint *param_1,int param_2,byte *param_3,byte *param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  
  bVar8 = *(byte *)((int)&DAT_21001720 + param_2 * 3);
  *param_3 = 0x20;
  uVar2 = (uint)bVar8;
  uVar6 = 0x20;
  if (bVar8 == 0x20) {
    *param_4 = bVar8;
  }
  else {
    while( true ) {
      uVar4 = uVar2;
      bVar8 = (byte)uVar6;
      iVar5 = uVar4 * 0x20;
      uVar6 = *(uint *)(&DAT_210017c8 + iVar5);
      uVar7 = *param_1;
      uVar2 = *(int *)(&DAT_210017cc + iVar5) + (uint)CARRY4(*(uint *)(&DAT_210017d0 + iVar5),uVar6)
      ;
      if (param_1[1] <= uVar2 &&
          (uint)(*(uint *)(&DAT_210017d0 + iVar5) + uVar6 <= uVar7) <= param_1[1] - uVar2) break;
      if ((*(short *)((int)param_1 + 0xe) != 0) && (*(short *)(&DAT_210017d6 + iVar5) == 0)) {
        sVar1 = FUN_01024ed8();
        if (sVar1 == 0x356) {
          iVar5 = 0x1d;
        }
        else if (sVar1 == 0x5f5) {
          iVar5 = 0x33;
        }
        else if (sVar1 == 0x18c) {
          iVar5 = 0xe;
        }
        else {
          iVar5 = 1;
        }
        if ((int)(uVar7 - uVar6) < iVar5) {
          bVar8 = *param_3;
          break;
        }
      }
      *param_3 = (byte)uVar4;
      uVar2 = (uint)(byte)(&DAT_21001741)[(uVar4 + param_2 * 0x20) * 2];
      uVar6 = uVar4;
      if ((byte)(&DAT_21001741)[(uVar4 + param_2 * 0x20) * 2] == 0x20) {
        *param_4 = (byte)uVar4;
        return 1;
      }
    }
    *param_4 = bVar8;
    do {
      iVar5 = uVar4 * 0x20;
      uVar7 = *param_1;
      uVar6 = *(uint *)(&DAT_210017c8 + iVar5);
      uVar2 = param_1[1] + (uint)CARRY4(param_1[2],uVar7);
      if (uVar2 < *(uint *)(&DAT_210017cc + iVar5) ||
          *(uint *)(&DAT_210017cc + iVar5) - uVar2 < (uint)(param_1[2] + uVar7 <= uVar6)) {
        if (*(short *)(&DAT_210017d6 + iVar5) == 0) {
          return 1;
        }
        if (*(short *)((int)param_1 + 0xe) != 0) {
          return 1;
        }
        sVar1 = FUN_01024ed8();
        if (sVar1 == 0x356) {
          iVar3 = 0x1d;
        }
        else if (sVar1 == 0x5f5) {
          iVar3 = 0x33;
        }
        else if (sVar1 == 0x18c) {
          iVar3 = 0xe;
        }
        else {
          iVar3 = 1;
        }
        if (iVar3 <= (int)(uVar6 - uVar7)) {
          return 1;
        }
      }
      *param_4 = (byte)uVar4;
      if ((byte)(&DAT_210017d8)[iVar5] <= (byte)param_1[4]) {
        return 0;
      }
      uVar4 = (uint)(byte)(&DAT_21001741)[(uVar4 + param_2 * 0x20) * 2];
    } while (uVar4 != 0x20);
  }
  return 1;
}


