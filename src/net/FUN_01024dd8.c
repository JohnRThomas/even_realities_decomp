/*
 * Function: FUN_01024dd8
 * Entry:    01024dd8
 * Prototype: int __stdcall FUN_01024dd8(uint param_1)
 */


int FUN_01024dd8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_1 >> 0xd) * 0x8637 >> 0x10;
  uVar2 = param_1 + uVar3 * -0x3d09;
  iVar1 = uVar3 * 0x200;
  if (((uint)(&UNK_00010c6e + uVar2 * 0x10c6f) >> 0x15) * 0x3d09 >> 9 < uVar2) {
    iVar1 = iVar1 + 1;
  }
  return iVar1 + ((uint)(&UNK_00010c6e + uVar2 * 0x10c6f) >> 0x15);
}


