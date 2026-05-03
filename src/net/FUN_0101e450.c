/*
 * Function: FUN_0101e450
 * Entry:    0101e450
 * Prototype: uint __stdcall FUN_0101e450(int param_1)
 */


uint FUN_0101e450(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0xc9) == '\0') {
    uVar2 = 2 - *(ushort *)(param_1 + 0xf6);
  }
  else {
    uVar2 = ((uint)*(ushort *)(param_1 + 0xf8) - (uint)*(ushort *)(param_1 + 0xf6)) - 4;
  }
  if ((*(char *)(param_1 + 0xf4) != '\0') &&
     (uVar1 = FUN_0100dbc0(param_1 + 0xa8,9,(uint)*(byte *)(param_1 + 0xc5),0), uVar1 == 0)) {
    uVar2 = uVar2 & (int)uVar2 >> 0x1f;
    return uVar2 & ~((int)uVar2 >> 0x1f) & 0xffff;
  }
  if ((*(char *)(param_1 + 0xcb) == '\0') &&
     (uVar1 = FUN_0100dbc0(param_1 + 0xa8,6,(uint)*(byte *)(param_1 + 0xc5),0), uVar1 == 0)) {
    return uVar2 & ~((int)uVar2 >> 0x1f) & 0xffff;
  }
  uVar1 = (*(int *)(param_1 + 0xec) + -4) - *(int *)(param_1 + 0xe8);
  if ((int)uVar1 <= (int)uVar2) {
    uVar2 = uVar1;
  }
  return uVar2 & ~((int)uVar2 >> 0x1f) & 0xffff;
}


