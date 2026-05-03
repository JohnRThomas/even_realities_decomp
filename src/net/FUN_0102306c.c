/*
 * Function: FUN_0102306c
 * Entry:    0102306c
 * Prototype: undefined4 __stdcall FUN_0102306c(int param_1, int param_2)
 */


undefined4 FUN_0102306c(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  int extraout_r1;
  int extraout_r1_00;
  int iVar5;
  int iVar6;
  int extraout_r2;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  
  bVar1 = *(byte *)((int)&DAT_21001720 + param_2 * 3);
  uVar7 = (uint)bVar1;
  if ((uVar7 == 0x20) || (uVar8 = FUN_01022f74(param_2), uVar7 == uVar8)) {
    lVar9 = FUN_01025884();
    iVar5 = (int)((ulonglong)lVar9 >> 0x20);
    if ((DAT_2100173b == ' ') ||
       (uVar8 = (uint)((ulonglong)(lVar9 + 2) >> 0x20),
       uVar8 < DAT_21001704 || DAT_21001704 - uVar8 < (uint)((uint)(lVar9 + 2) <= DAT_21001700))) {
      if (uVar7 == 0x20) {
        iVar6 = DAT_21001730;
        if (DAT_21001734 != -1 || DAT_21001730 != -1) {
          FUN_01024f78();
          DAT_21001734 = -1;
          iVar6 = -1;
          iVar5 = extraout_r1;
        }
        DAT_21001730 = iVar6;
        if (DAT_21001738 != '\0') {
          FUN_01025a4c(5,iVar5,iVar6);
          DAT_21001738 = '\0';
          iVar5 = extraout_r1_00;
          iVar6 = extraout_r2;
        }
        FUN_01025a4c(4,iVar5,iVar6);
        FUN_01025b44();
        DAT_2100173b = 0x20;
        *DAT_21001bc4 = 0;
        return 1;
      }
      puVar4 = FUN_010226e0((undefined1 *)lVar9,iVar5,param_1,uVar7);
      if (puVar4 != (undefined1 *)0x0) {
        DAT_2100173b = bVar1;
        return 2;
      }
      iVar5 = param_2 * 0x20;
      bVar1 = *(byte *)((int)&DAT_21001720 + param_2 * 3);
      *(undefined *)((int)&DAT_21001720 + param_2 * 3) =
           (&DAT_21001741)[(uVar7 + param_2 * 0x20) * 2];
      bVar3 = bVar1;
      do {
        bVar2 = bVar3;
        uVar8 = (uint)bVar2;
        iVar6 = (iVar5 + uVar8) * 2;
        (&DAT_21001740)[iVar6] = 4;
        bVar3 = (&DAT_21001741)[iVar6];
      } while (uVar7 != uVar8);
      if ((&DAT_21001722)[param_2 * 3] == 0x20) {
        *(byte *)((int)&DAT_21001720 + param_2 * 3 + 1) = bVar1;
      }
      else {
        (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[param_2 * 3] + iVar5) * 2] = bVar1;
      }
      (&DAT_21001722)[param_2 * 3] = bVar2;
      (&DAT_21001741)[(iVar5 + uVar8) * 2] = 0x20;
      return 0;
    }
  }
  return 0;
}


