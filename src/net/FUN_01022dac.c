/*
 * Function: FUN_01022dac
 * Entry:    01022dac
 * Prototype: undefined __stdcall FUN_01022dac(uint param_1, uint param_2, char * param_3, uint * param_4, byte param_5)
 */


void FUN_01022dac(uint param_1,uint param_2,char *param_3,uint *param_4,byte param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  longlong lVar14;
  char cStack_35;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  
  uVar1 = *(ushort *)(param_3 + 8);
  uVar2 = *(undefined2 *)(param_3 + 10);
  cVar3 = *param_3;
  param_4[4] = 0;
  param_4[3] = 0;
  *(undefined2 *)(param_4 + 4) = uVar2;
  param_4[2] = 0;
  param_4[5] = 0;
  *(ushort *)((int)param_4 + 0xe) = uVar1;
  *(char *)((int)param_4 + 0x12) = cVar3;
  *param_4 = 0;
  param_4[1] = 0;
  if (cVar3 != '\0') {
    FUN_01024ccc((int)&DAT_1e847fff - (uint)uVar1,(int *)&local_34,(char *)(param_4 + 3));
    uVar1 = *(ushort *)((int)param_4 + 0xe);
    FUN_01024ccc((uint)uVar1,(int *)&local_30,&cStack_35);
    uVar5 = FUN_01024e44();
    uVar10 = FUN_01024dd8((uint)uVar5);
    if (DAT_2100173a == ' ') {
      uVar11 = param_1 + 0xb;
      uVar12 = param_2 + (0xfffffff4 < param_1);
      if ((uVar1 != 0) && (bVar4 = FUN_010252d0(), bVar4 == 0)) {
        sVar6 = FUN_01024ed8();
        if (sVar6 == 0x356) {
          uVar11 = param_1 + 0x27;
          uVar12 = param_2 + (0xffffffd8 < param_1);
        }
        else if (sVar6 == 0x5f5) {
          uVar11 = param_1 + 0x3d;
          uVar12 = param_2 + (0xffffffc2 < param_1);
        }
        else if (sVar6 == 0x18c) {
          uVar11 = param_1 + 0x18;
          uVar12 = param_2 + (0xffffffe7 < param_1);
        }
      }
      if (local_30 < uVar10) {
        bVar13 = CARRY4(uVar10 - local_30,uVar11);
        uVar11 = (uVar10 - local_30) + uVar11;
        uVar12 = uVar12 + bVar13;
      }
    }
    else {
      uVar11 = DAT_21001700 + 7 + DAT_21001708;
      uVar12 = DAT_21001704 + (uint)(0xfffffff8 < DAT_21001700) +
               (uint)CARRY4(DAT_21001700 + 7,DAT_21001708);
    }
    iVar8 = *(int *)(param_3 + 4);
    if (param_3[0xb] == '\0') {
      iVar9 = 0x7a;
    }
    else {
      iVar9 = 0x60;
    }
    *param_4 = uVar11;
    param_4[1] = uVar12;
    uVar10 = FUN_01024dd8(iVar9 + (uint)*(ushort *)((int)param_4 + 0xe) + (uint)(byte)param_4[3] +
                                  iVar8 + 2);
    param_4[2] = uVar10;
    iVar8 = FUN_010225f0(*(uint *)(param_3 + 0x10),param_4,param_1,param_2,param_5);
    if (iVar8 == 0) {
      *param_4 = param_1;
      param_4[1] = param_2;
    }
    return;
  }
  lVar14 = FUN_01024c5c(param_1,param_2);
  uVar11 = *(uint *)(param_3 + 0x10);
  uVar10 = *(uint *)(param_3 + 0x14);
  uVar12 = (uint)((ulonglong)(lVar14 + 256000000) >> 0x20);
  if ((uVar10 <= uVar12 && (uint)((uint)(lVar14 + 256000000) <= uVar11) <= uVar10 - uVar12) &&
     (uVar12 = (uint)((ulonglong)(lVar14 + 0x2f) >> 0x20),
     uVar12 < uVar10 || uVar10 - uVar12 < (uint)((uint)(lVar14 + 0x2f) <= uVar11))) {
    uVar12 = *(ushort *)(param_3 + 8) + 1;
    if (uVar10 == 0 && (uVar12 <= uVar11) <= uVar10) {
      uVar7 = 0;
      uVar10 = 0;
    }
    else {
      uVar7 = uVar11 - uVar12;
      uVar10 = uVar10 - (uVar11 < uVar12);
    }
    FUN_01024d24(uVar7,uVar10,&local_34,(int *)&local_30,(char *)(param_4 + 3));
    if (param_3[0xb] == '\0') {
      iVar8 = 0x7a;
    }
    else {
      iVar8 = 0x60;
    }
    iVar8 = FUN_01024dd8(iVar8 + local_34 + 2 + *(int *)(param_3 + 4) +
                                 (uint)*(ushort *)(param_3 + 8));
    *param_4 = local_30;
    param_4[1] = uStack_2c;
    param_4[2] = iVar8 - local_30 & 0xffffff;
    return;
  }
  *param_4 = param_1 - 1;
  param_4[1] = (param_2 - 1) + (uint)(param_1 != 0);
  param_4[2] = 1000;
  return;
}


