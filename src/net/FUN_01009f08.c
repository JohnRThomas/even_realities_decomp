/*
 * Function: FUN_01009f08
 * Entry:    01009f08
 * Prototype: undefined __stdcall FUN_01009f08(byte param_1, undefined4 * param_2, undefined4 param_3)
 */


void FUN_01009f08(byte param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint local_14;
  
  if ((DAT_21000ba8 != 1) && (DAT_21000ba8 != 3)) {
    FUN_01009500(0x17,0x120,param_3,(uint)DAT_21000ba8);
    param_3 = extraout_r2;
  }
  if (8 < *(byte *)((int)param_2 + 6)) {
    FUN_01009500(0x17,0x122,param_3,(uint)*(byte *)((int)param_2 + 6));
  }
  iVar2 = DAT_21000bac;
  if (*(char *)((int)param_2 + 7) != '\0') {
    iVar1 = FUN_01027cd0(*(byte *)((int)param_2 + 7));
    bVar3 = *(byte *)((int)param_2 + 6);
    if (bVar3 < 2) {
      bVar3 = 2;
    }
    bVar4 = *(byte *)((int)param_2 + 6);
    if (bVar4 < 2) {
      bVar4 = 2;
    }
    uVar5 = -(uint)bVar4 & (iVar1 + iVar2 + (uint)bVar3) - 1;
    uVar6 = -(uint)*(byte *)((int)param_2 + 6) &
            ((uint)*(byte *)((int)param_2 + 6) + (uint)*(ushort *)(param_2 + 1)) - 1;
    if (0xfffe < uVar6) {
      FUN_01009500(0x17,0x12d,0xfffe,uVar6);
    }
    if (DAT_21000ba8 == 3) {
      iVar2 = FUN_01027cd0(*(byte *)((int)param_2 + 7));
      puVar7 = (undefined2 *)(uVar5 - iVar2);
      if (*(int *)(&DAT_21000b7c + (uint)param_1 * 4) != 0) {
        FUN_01009500(0x17,0x132,&DAT_21000b7c,*(int *)(&DAT_21000b7c + (uint)param_1 * 4));
      }
      *(undefined2 **)(&DAT_21000b7c + (uint)param_1 * 4) = puVar7;
      *puVar7 = (short)uVar6;
      *(undefined1 *)(puVar7 + 1) = *(undefined1 *)((int)param_2 + 7);
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined1 *)(puVar7 + 2) = *(undefined1 *)(param_2 + 2);
      puVar7[3] = (short)((uint)*param_2 >> 0x10);
      puVar7[4] = (short)*param_2;
      for (local_14 = 0; local_14 < *(byte *)((int)param_2 + 7); local_14 = local_14 + 1) {
        puVar7[local_14 + 5] = 0xfff0;
      }
    }
    DAT_21000bac = *(byte *)((int)param_2 + 7) * uVar6 + uVar5;
  }
  return;
}


