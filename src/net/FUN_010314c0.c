/*
 * Function: FUN_010314c0
 * Entry:    010314c0
 * Prototype: undefined4 __stdcall FUN_010314c0(int param_1, uint param_2, int param_3)
 */


undefined4 FUN_010314c0(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  byte local_18 [4];
  char *local_14;
  
  if (param_3 != 0) {
    local_14 = "Sending data not supported";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    FUN_0102ea44(0x103c054,0x1080,local_18,(undefined1 *)0x0);
  }
  if ((param_2 < 0x10) &&
     ((int)((*(uint *)(*(int *)(param_1 + 4) + 4) >> (param_2 & 0xff)) << 0x1f) < 0)) {
    uVar1 = 0;
    (&Peripherals::IPC_NS.TASKS_SEND_0_)[param_2 & 0x3f] = 1;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


