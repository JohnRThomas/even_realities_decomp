/*
 * Function: $_?_FUN_0000de58
 * Entry:    0000de58
 * Prototype: uint __stdcall $_?_FUN_0000de58(uint param_1, uint param_2)
 */


uint ____FUN_0000de58(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  uVar1 = param_2 & 0x80000000;
  if (uVar1 == 0) {
    uVar1 = 0x7fffffff;
  }
  return uVar1;
}


