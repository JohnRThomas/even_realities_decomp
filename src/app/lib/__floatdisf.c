/*
 * Function: __floatdisf
 * Entry:    0000e128
 * Prototype: uint __stdcall __floatdisf(uint param_1, uint param_2)
 */


/* exclude_from_export_ai */

uint __floatdisf(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_1 == 0 && param_2 == 0) {
    return param_1;
  }
  uVar4 = param_2 & 0x80000000;
  if ((int)uVar4 < 0) {
    bVar6 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2 - (uint)bVar6;
  }
  bVar6 = param_2 == 0;
  uVar1 = param_1;
  if (bVar6) {
    uVar1 = 0;
    param_2 = param_1;
  }
  uVar4 = uVar4 | 0x5b000000;
  if (bVar6) {
    uVar4 = uVar4 + 0xf0000000;
  }
  uVar2 = LZCOUNT(param_2);
  uVar3 = uVar2 - 8;
  iVar5 = (uVar4 - 0x800000) + uVar3 * -0x800000;
  if (uVar2 < 8) {
    uVar3 = param_2 << uVar2 + 0x18;
    uVar4 = iVar5 + ((param_2 >> (0x20 - (uVar2 + 0x18) & 0xff)) - ((int)uVar3 >> 0x1f));
    if (uVar1 == 0 && (uVar3 & 0x7fffffff) == 0) {
      uVar4 = uVar4 & ~(uVar3 >> 0x1f);
    }
    return uVar4;
  }
  uVar2 = uVar1 << (uVar3 & 0xff);
  uVar4 = iVar5 + (param_2 << (uVar3 & 0xff)) +
          (uVar1 >> (0x20 - uVar3 & 0xff)) + (uint)(0x7fffffff < uVar2);
  if (uVar2 == 0x80000000) {
    uVar4 = uVar4 & 0xfffffffe;
  }
  return uVar4;
}


