/*
 * Function: FUN_010225f0
 * Entry:    010225f0
 * Prototype: int __stdcall FUN_010225f0(uint param_1, uint * param_2, uint param_3, int param_4, byte param_5)
 */


int FUN_010225f0(uint param_1,uint *param_2,uint param_3,int param_4,byte param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bStack_2a;
  byte local_29 [5];
  
  uVar2 = FUN_01024dd8(param_1);
  uVar5 = uVar2 + param_3;
  uVar2 = param_4 + (uint)CARRY4(uVar2,param_3);
  if (param_2[1] < uVar2 || uVar2 - param_2[1] < (uint)(*param_2 <= uVar5)) {
    while (iVar3 = FUN_0102237c(param_2,(uint)param_5,&bStack_2a,local_29), iVar3 == 0) {
      iVar3 = (uint)local_29[0] * 0x20;
      uVar4 = *(uint *)(&DAT_210017d0 + iVar3);
      uVar7 = uVar4 + *(uint *)(&DAT_210017c8 + iVar3);
      uVar6 = *(int *)(&DAT_210017cc + iVar3) + (uint)CARRY4(uVar4,*(uint *)(&DAT_210017c8 + iVar3))
      ;
      if ((*(short *)(&DAT_210017d6 + iVar3) == 0) && (*(short *)((int)param_2 + 0xe) != 0)) {
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
        if (iVar3 <= (int)uVar4) goto LAB_01022620;
        sVar1 = FUN_01024ed8();
        if (sVar1 == 0x356) {
          uVar4 = 0x1d;
        }
        else if (sVar1 == 0x5f5) {
          uVar4 = 0x33;
        }
        else if (sVar1 == 0x18c) {
          uVar4 = 0xe;
        }
        else {
          uVar4 = 1;
        }
        uVar7 = uVar4 + *(uint *)(&DAT_210017c8 + (uint)local_29[0] * 0x20);
        uVar6 = *(int *)(&DAT_210017cc + (uint)local_29[0] * 0x20) +
                (uint)CARRY4(uVar4,*(uint *)(&DAT_210017c8 + (uint)local_29[0] * 0x20));
        if (uVar2 <= uVar6 && (uint)(uVar7 <= uVar5) <= uVar2 - uVar6) goto LAB_010226c2;
      }
      else {
LAB_01022620:
        if (uVar2 <= uVar6 && (uint)(uVar7 <= uVar5) <= uVar2 - uVar6) goto LAB_010226c2;
      }
      *param_2 = uVar7;
      param_2[1] = uVar6;
    }
  }
  else {
LAB_010226c2:
    iVar3 = 0;
  }
  return iVar3;
}


