/*
 * Function: __floatsisf
 * Entry:    0000e0fc
 * Prototype: uint __stdcall __floatsisf(uint param_1)
 */


/* exclude_from_export_ai */

uint __floatsisf(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 & 0x80000000;
  if ((int)uVar3 < 0) {
    param_1 = -param_1;
  }
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = LZCOUNT(param_1);
  uVar2 = uVar1 - 8;
  iVar4 = ((uVar3 | 0x4b000000) - 0x800000) + uVar2 * -0x800000;
  if (7 < uVar1) {
    uVar1 = 0 << (uVar2 & 0xff);
    uVar3 = iVar4 + (param_1 << (uVar2 & 0xff)) +
            (0U >> (0x20 - uVar2 & 0xff)) + (uint)(0x7fffffff < uVar1);
    if (uVar1 == 0x80000000) {
      uVar3 = uVar3 & 0xfffffffe;
    }
    return uVar3;
  }
  uVar2 = param_1 << uVar1 + 0x18;
  uVar3 = iVar4 + ((param_1 >> (0x20 - (uVar1 + 0x18) & 0xff)) - ((int)uVar2 >> 0x1f));
  if ((uVar2 & 0x7fffffff) == 0) {
    uVar3 = uVar3 & ~(uVar2 >> 0x1f);
  }
  return uVar3;
}


