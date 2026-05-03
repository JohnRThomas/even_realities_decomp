/*
 * Function: FUN_01031420
 * Entry:    01031420
 * Prototype: undefined4 __stdcall FUN_01031420(int param_1, uint param_2, int param_3)
 */


undefined4 FUN_01031420(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  byte local_18 [4];
  char *local_14;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if ((0xf < param_2) || (-1 < (int)((**(uint **)(param_1 + 4) >> (param_2 & 0xff)) << 0x1f))) {
    return 0xffffffea;
  }
  uVar1 = *(uint *)(iVar2 + 0x84) >> (param_2 & 0xff) & 1;
  if (param_3 == 0) {
    if (uVar1 != 0) {
      FUN_01035648(param_2 & 0xff);
      *(uint *)(iVar2 + 0x84) = *(uint *)(iVar2 + 0x84) & ~(1 << (param_2 & 0xff));
LAB_010314a0:
      if (*(int *)(iVar2 + 0x84) == 0) {
        FUN_0102f308('\x12');
      }
      return 0;
    }
  }
  else if (uVar1 == 0) {
    if (*(int *)(iVar2 + param_2 * 4) == 0) {
      local_14 = "Enabling channel without a registered callback\n";
      local_18[0] = 2;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      FUN_0102ea44(0x103c054,0x1080,local_18,(undefined1 *)0x0);
    }
    if (*(int *)(iVar2 + 0x84) == 0) {
      FUN_0102f2ec('\x12');
    }
    *(uint *)(iVar2 + 0x84) = *(uint *)(iVar2 + 0x84) | 1 << (param_2 & 0xff);
    FUN_01035610(param_2 & 0xff);
    goto LAB_010314a0;
  }
  return 0xffffff88;
}


