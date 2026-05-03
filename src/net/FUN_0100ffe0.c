/*
 * Function: FUN_0100ffe0
 * Entry:    0100ffe0
 * Prototype: uint __stdcall FUN_0100ffe0(uint param_1)
 */


uint FUN_0100ffe0(uint param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (4 < param_1 - 0xb) {
    uVar1 = param_1 - 0x21;
    bVar3 = 0x2e < param_1;
    bVar2 = param_1 == 0x2f;
    if (!bVar2) {
      bVar3 = 5 < uVar1;
    }
    if (!bVar3 || (bVar2 || uVar1 == 6)) {
      param_1 = 1;
    }
    if (bVar3 && (!bVar2 && uVar1 != 6)) {
      param_1 = 0;
    }
    return param_1;
  }
  return 1;
}


