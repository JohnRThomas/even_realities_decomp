/*
 * Function: FUN_01029734
 * Entry:    01029734
 * Prototype: undefined4 __stdcall FUN_01029734(ushort * param_1)
 */


undefined4 FUN_01029734(ushort *param_1)

{
  bool bVar1;
  int iVar2;
  int extraout_r1;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  iVar2 = FUN_0100a518(*param_1,0);
  if (iVar2 == 0) {
    return 2;
  }
  bVar1 = FUN_01028ac4(iVar2);
  if (bVar1) {
    if (*(char *)(extraout_r1 + 0x330) != '\0') {
      return 0x3a;
    }
    if (-1 < (int)((uint)*(byte *)(extraout_r1 + 0x116) << 0x1f)) {
      return 0x1a;
    }
    if (*(int *)(extraout_r1 + 0x158) == 0) {
      *(undefined4 *)(extraout_r1 + 0x331) = *(undefined4 *)(param_1 + 1);
      *(undefined4 *)(extraout_r1 + 0x335) = *(undefined4 *)(param_1 + 3);
      *(ushort *)(extraout_r1 + 0x339) = param_1[5];
      puVar3 = (undefined4 *)(extraout_r1 + 0x33b);
      puVar4 = param_1 + 6;
      do {
        puVar5 = puVar4 + 2;
        *puVar3 = *(undefined4 *)puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar5;
      } while (puVar5 != param_1 + 0xe);
      *(undefined1 *)(extraout_r1 + 0x330) = 1;
      return 0;
    }
  }
  return 0xc;
}


