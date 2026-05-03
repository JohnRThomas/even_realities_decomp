/*
 * Function: FUN_0103ab9c
 * Entry:    0103ab9c
 * Prototype: uint __stdcall FUN_0103ab9c(undefined4 param_1)
 */


uint FUN_0103ab9c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = TT(param_1);
  uVar1 = uVar2 & 0xff;
  if ((uVar2 & 0x10000) == 0) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


