/*
 * Function: FUN_010304ac
 * Entry:    010304ac
 * Prototype: int __stdcall FUN_010304ac(undefined4 param_1)
 */


int FUN_010304ac(undefined4 param_1)

{
  int iVar1;
  byte local_38 [4];
  char *local_34;
  int iStack_30;
  byte local_18 [4];
  char *local_14;
  
  DAT_210047fc = param_1;
  if (DAT_210047f8 == 0) {
    local_14 = "No HCI driver registered";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    iVar1 = -0x13;
    FUN_0102ea44(0x103bfe4,0x1040,local_18,(undefined1 *)0x0);
  }
  else {
    iVar1 = (**(code **)(DAT_210047f8 + 0xc))();
    if (iVar1 == 0) {
      local_14 = "Bluetooth enabled in RAW mode";
      local_18[0] = 2;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      FUN_0102ea44(0x103bfe4,0x10c0,local_18,(undefined1 *)0x0);
    }
    else {
      local_34 = "HCI driver open failed (%d)";
      local_38[0] = 3;
      local_38[1] = 0;
      local_38[2] = 0;
      local_38[3] = 0;
      iStack_30 = iVar1;
      FUN_0102ea44(0x103bfe4,0x1840,local_38,(undefined1 *)0x0);
    }
  }
  return iVar1;
}


