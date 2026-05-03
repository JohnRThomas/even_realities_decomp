/*
 * Function: FUN_0100e8ac
 * Entry:    0100e8ac
 * Prototype: bool __stdcall FUN_0100e8ac(byte * param_1, uint param_2)
 */


bool FUN_0100e8ac(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((*param_1 & 0xf) == 3) {
    return param_1[1] == 0xc;
  }
  if ((((*param_1 & 0xf) != 5) ||
      ((((param_1[0x1f] == 0 && param_1[0x20] == 0) && param_1[0x21] == 0) && param_1[0x22] == 0) &&
       (param_1[0x23] & 0xe0) == 0)) || (param_1[1] != 0x22)) {
    return false;
  }
  uVar2 = (uint)*(ushort *)(param_1 + 0x19);
  if (uVar2 - 0xd01 < 7) {
    uVar1 = param_2 & 1;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
LAB_0100e940:
    if (499 < *(ushort *)(param_1 + 0x1b)) {
      return false;
    }
    return (ushort)(*(short *)(param_1 + 0x1d) - 10U) < 0xc77;
  }
  if (((uVar2 - 6 & 0xffff) < 0xc7b) && (param_1[0x16] - 1 < 8)) {
    uVar1 = (uint)*(ushort *)(param_1 + 0x17);
    if (*(ushort *)(param_1 + 0x17) <= uVar2) {
      uVar1 = (uint)param_1[0x16];
    }
    if (uVar1 < uVar2) goto LAB_0100e940;
  }
  return false;
}


