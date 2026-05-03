/*
 * Function: FUN_0100ae64
 * Entry:    0100ae64
 * Prototype: int __stdcall FUN_0100ae64(byte param_1, byte param_2, uint param_3, undefined4 param_4)
 */


int FUN_0100ae64(byte param_1,byte param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint local_18;
  char local_13;
  byte local_12;
  byte local_11;
  int local_c;
  
  puVar3 = &local_18;
  local_13 = (char)param_4;
  uVar2 = 0;
  local_18 = param_3;
  local_12 = param_2;
  local_11 = param_1;
  if (((param_3 & 7) == 0) || (uVar2 = param_3 & 3, uVar2 != 0)) {
    FUN_01009500(0x4c,0x1f,param_4,uVar2);
  }
  local_c = FUN_010281e6((int *)0x0,(ushort)local_11,0x10e);
  if (local_13 != '\0') {
    puVar3 = (undefined4 *)0x0;
  }
  iVar1 = FUN_01027a58(puVar3,local_c * (uint)local_12,local_c * (uint)local_12);
  if (local_13 != '\x01') {
    DAT_21000bec = local_18;
    DAT_21000bf0 = local_c;
  }
  return iVar1;
}


