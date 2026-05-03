/*
 * Function: FUN_0101c3c8
 * Entry:    0101c3c8
 * Prototype: uint __stdcall FUN_0101c3c8(uint * param_1)
 */


uint FUN_0101c3c8(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0101a930();
  uVar2 = FUN_0100fdb4(param_1,iVar1 + 0x111);
  if (0xa8f < uVar2) {
    uVar2 = 0xa90;
  }
  return uVar2 & 0xffff;
}


