/*
 * Function: FUN_0100a9e0
 * Entry:    0100a9e0
 * Prototype: uint __stdcall FUN_0100a9e0(uint param_1, char param_2, char param_3, ushort param_4)
 */


uint FUN_0100a9e0(uint param_1,char param_2,char param_3,ushort param_4)

{
  ushort uVar1;
  byte local_f;
  short local_e;
  int local_c;
  
  DAT_21000bb8 = param_3 + param_2;
  if ((param_1 & 3) != 0) {
    FUN_01009500(9,0x4e,(uint)DAT_21000bb8,param_1 & 3);
  }
  if (param_4 < 0x20) {
    local_e = param_4 << 2;
  }
  else if (param_4 < 0x100) {
    if (param_4 == 0x3e || (uint)param_4 * 2 < 0x7c) {
      local_e = 0x7c;
    }
    else {
      local_e = param_4 << 1;
    }
  }
  else if (param_4 + 0xff < (uint)param_4 * 2) {
    local_e = param_4 + 0xff;
  }
  else {
    local_e = param_4 << 1;
  }
  uVar1 = local_e + 3U & 0xfffc;
  if (param_1 != 0) {
    DAT_21000bbc = param_1;
    DAT_21000bc0 = uVar1;
  }
  local_c = (uint)DAT_21000bb8 * 0x28;
  for (local_f = 0; local_f < DAT_21000bb8; local_f = local_f + 1) {
    if (param_1 != 0) {
      *(undefined1 *)((uint)local_f * 0x28 + DAT_21000bbc) = 1;
      *(uint *)((uint)local_f * 0x28 + DAT_21000bbc + 4) = local_c + param_1;
    }
    local_c = (uint)uVar1 + local_c;
  }
  return local_c + 7U & 0xfffffff8;
}


