/*
 * Function: FUN_0102f5e8
 * Entry:    0102f5e8
 * Prototype: undefined4 __stdcall FUN_0102f5e8(int param_1, undefined1 * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0102f5e8(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  byte local_40 [4];
  char *local_3c;
  undefined4 uStack_38;
  byte local_20 [4];
  char *local_1c;
  
  local_1c = "***** BUS FAULT *****";
  local_20[0] = 2;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  FUN_0103ab96(0x103c084,0x1040,local_20);
  if ((int)(_DAT_e000ed28 << 0x13) < 0) {
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    local_1c = "  Stacking error";
    FUN_0103ab96(0x103c084,0x1040,local_20);
    uVar1 = 0x17;
  }
  else {
    uVar1 = 0x16;
  }
  if ((int)(_DAT_e000ed28 << 0x14) < 0) {
    local_1c = "  Unstacking error";
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_20);
    uVar1 = 0x18;
  }
  if ((int)(_DAT_e000ed28 << 0x16) < 0) {
    local_1c = "  Precise data bus error";
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_20);
    if ((int)(_DAT_e000ed28 << 0x10) < 0) {
      local_3c = "  BFAR Address: 0x%x";
      uStack_38 = _DAT_e000ed38;
      local_40[0] = 3;
      local_40[1] = 0;
      local_40[2] = 0;
      local_40[3] = 0;
      FUN_0103ab96(0x103c084,0x1840,local_40);
      if (param_1 != 0) {
        _DAT_e000ed28 = _DAT_e000ed28 & 0xffff7fff;
      }
    }
    uVar1 = 0x19;
  }
  if ((int)(_DAT_e000ed28 << 0x15) < 0) {
    local_1c = "  Imprecise data bus error";
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_20);
    uVar1 = 0x1a;
  }
  if ((int)(_DAT_e000ed28 << 0x17) < 0) {
    local_1c = "  Instruction bus error";
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_20);
    uVar1 = 0x1b;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff00;
  *param_2 = 0;
  return uVar1;
}


