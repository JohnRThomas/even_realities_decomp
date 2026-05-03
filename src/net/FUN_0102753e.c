/*
 * Function: FUN_0102753e
 * Entry:    0102753e
 * Prototype: uint __stdcall FUN_0102753e(short * param_1)
 */


uint FUN_0102753e(short *param_1)

{
  ushort uVar1;
  int local_c;
  
  local_c = ((ushort)param_1[4] & 0x7fff) - ((ushort)param_1[3] & 0x7fff);
  if (-1 < (short)(param_1[4] ^ param_1[3])) {
    local_c = local_c + (uint)(ushort)param_1[1];
  }
  uVar1 = FUN_01027072(*param_1,*(byte *)((int)param_1 + 0x13));
  return local_c / (int)(uint)uVar1 & 0xffff;
}


