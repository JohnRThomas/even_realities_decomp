/*
 * Function: FUN_01012ec8
 * Entry:    01012ec8
 * Prototype: uint __stdcall FUN_01012ec8(int param_1)
 */


uint FUN_01012ec8(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1b) < 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = ((*(ushort *)(param_1 + 2) ^ 2) << 0x1e) >> 0x1f;
  }
  bVar1 = FUN_01028810(*(int *)(param_1 + 0x44));
  return bVar1 | uVar2;
}


