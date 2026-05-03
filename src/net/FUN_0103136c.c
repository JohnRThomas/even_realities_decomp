/*
 * Function: FUN_0103136c
 * Entry:    0103136c
 * Prototype: undefined4 __stdcall FUN_0103136c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0103136c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  byte local_98 [4];
  char *local_94;
  int aiStack_8c [16];
  int local_4c [16];
  undefined4 local_c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)(iVar1 + 0x80) = param_1;
  FUN_0103554c(0,0x1031515,iVar1,param_4);
  FUN_0102f34c('\x12',1,0);
  puVar5 = *(uint **)(param_1 + 4);
  FUN_0103bdee((undefined1 *)aiStack_8c,0,0x84);
  if (0xffff < puVar5[1]) {
    local_94 = "tx_mask too big (or IPC_CONF_NUM too small)";
    local_98[0] = 2;
    local_98[1] = 0;
    local_98[2] = 0;
    local_98[3] = 0;
    FUN_0102ea44(0x103c054,0x1080,local_98,(undefined1 *)0x0);
  }
  if (0xffff < *puVar5) {
    local_94 = "rx_mask too big (or IPC_CONF_NUM too small)";
    local_98[0] = 2;
    local_98[1] = 0;
    local_98[2] = 0;
    local_98[3] = 0;
    FUN_0102ea44(0x103c054,0x1080,local_98,(undefined1 *)0x0);
  }
  uVar4 = 0;
  local_c = 0;
  piVar2 = aiStack_8c;
  do {
    piVar3 = piVar2 + 1;
    if ((int)((puVar5[1] >> (uVar4 & 0xff)) << 0x1f) < 0) {
      *piVar2 = 1 << (uVar4 & 0xff);
    }
    iVar1 = (*puVar5 >> (uVar4 & 0xff)) << 0x1f;
    if (iVar1 < 0) {
      iVar1 = 1 << (uVar4 & 0xff);
      piVar2[0x10] = iVar1;
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar3;
  } while (uVar4 != 0x10);
  FUN_01035598((int)aiStack_8c,iVar1,piVar3,0x10);
  return 0;
}


