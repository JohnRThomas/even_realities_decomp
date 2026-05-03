/*
 * Function: FUN_0101f50c
 * Entry:    0101f50c
 * Prototype: uint __stdcall FUN_0101f50c(undefined1 * param_1)
 */


uint FUN_0101f50c(undefined1 *param_1)

{
  uint uVar1;
  byte local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  int local_1c;
  int local_14;
  undefined2 local_c;
  
  local_24 = param_1[5];
  local_23 = param_1[6];
  local_22 = 1;
  local_21 = *param_1;
  local_1c = (uint)*(ushort *)(param_1 + 1) * 0x271;
  local_14 = (uint)*(ushort *)(param_1 + 3) * 0x271;
  local_c = 7;
  if ((local_14 - 0x9c4U < 0x9c363d) && (local_1c - 0x9c4U < 0x9c363d)) {
    uVar1 = FUN_0101f364(&local_24);
  }
  else {
    uVar1 = 0x30;
  }
  return uVar1;
}


