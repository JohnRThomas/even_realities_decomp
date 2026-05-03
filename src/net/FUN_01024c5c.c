/*
 * Function: FUN_01024c5c
 * Entry:    01024c5c
 * Prototype: undefined8 __stdcall FUN_01024c5c(uint param_1, uint param_2)
 */


undefined8 FUN_01024c5c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 >> 0x18 | param_2 << 8;
  uVar2 = param_2 >> 0x18;
  iVar4 = ((uVar2 << 5 | (param_2 << 8) >> 0x1b) - uVar2) - (uint)(uVar3 * 0x20 < uVar3);
  uVar1 = ((param_1 << 8) >> 0x11) * 0x3d09 + ((param_1 & 0x1ff) * 0x3d09 + 0x100 >> 9);
  return CONCAT44(((uVar2 + ((((iVar4 * 0x40 | uVar3 * 0x1f >> 0x1a) - iVar4) -
                             (uint)(uVar3 * 0x7c0 < uVar3 * 0x1f)) * 8 | uVar3 * 0x7a1 >> 0x1d) +
                            (uint)CARRY4(uVar3 * 0x3d08,uVar3)) * 0x8000 | uVar3 * 0x3d09 >> 0x11) +
                  (uint)CARRY4(uVar1,uVar3 * 512000000),uVar1 + uVar3 * 512000000);
}


