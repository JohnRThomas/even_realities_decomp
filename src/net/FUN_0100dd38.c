/*
 * Function: FUN_0100dd38
 * Entry:    0100dd38
 * Prototype: uint __stdcall FUN_0100dd38(uint param_1, uint param_2)
 */


uint FUN_0100dd38(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 & 0xc) != 0) {
    if ((int)(param_2 << 0x1d) < 0) {
      iVar1 = 0x20e;
      iVar2 = 0x10;
      if (param_1 < 0x20f) {
        return 0;
      }
    }
    else {
      iVar2 = 0x40;
      iVar1 = 0x3d0;
      if (param_1 < 0x3d1) {
        return 0;
      }
    }
    return (int)(param_1 - iVar1) / iVar2 & 0xffff;
  }
  if (param_2 == 2) {
    if (0x3c < param_1) {
      return (param_1 - 0x3c) * 0x4000 >> 0x10;
    }
  }
  else if (0x70 < param_1) {
    return (param_1 - 0x70) * 0x2000 >> 0x10;
  }
  return 0;
}


