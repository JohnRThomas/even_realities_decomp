/*
 * Function: FUN_01036178
 * Entry:    01036178
 * Prototype: undefined __stdcall FUN_01036178(uint param_1, int param_2)
 */


void FUN_01036178(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 *local_50;
  char *local_4c;
  int *piStack_48;
  char *local_44;
  undefined4 local_40;
  undefined2 local_3c;
  byte local_28 [4];
  char *local_24;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0103be10();
  piVar4 = *(int **)(iVar3 + 8);
  if (param_1 < 5) {
    local_44 = *(char **)(&DAT_0103caf4 + param_1 * 4);
  }
  else {
    local_44 = "Unknown error";
  }
  local_3c = 0x301;
  local_4c = ">>> ZEPHYR FATAL ERROR %d: %s on CPU %d";
  local_40 = 0;
  local_50 = &DAT_01000005;
  piStack_48 = (int *)param_1;
  FUN_0102ea44(0x103c084,0x2c40,(byte *)&local_50,(undefined1 *)0x0);
  if ((param_2 != 0) && ((*(uint *)(param_2 + 0x1c) & 0x1ff) != 0)) {
    local_24 = "Fault during interrupt handling\n";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0102ea44(0x103c084,0x1040,local_28,(undefined1 *)0x0);
  }
  if (((piVar4 == (int *)0x0) || (local_44 = (char *)FUN_0103b91c(), local_44 == (char *)0x0)) ||
     (*local_44 == '\0')) {
    local_44 = "unknown";
  }
  local_4c = "Current thread: %p (%s)";
  local_40 = CONCAT22(local_40._2_2_,0x301);
  local_50 = &DAT_01000004;
  piStack_48 = piVar4;
  FUN_0102ea44(0x103c084,0x2440,(byte *)&local_50,(undefined1 *)0x0);
  FUN_01031fe0();
  if (param_1 == 4) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/fatal.c",0x93,
                 extraout_r3);
    FUN_0103a370();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0102fd40(piVar4);
  return;
}


