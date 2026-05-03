/*
 * Function: FUN_010294be
 * Entry:    010294be
 * Prototype: uint __stdcall FUN_010294be(ushort * param_1, uint param_2, undefined4 param_3)
 */


uint FUN_010294be(ushort *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint local_10;
  uint local_c;
  undefined4 uStack_8;
  
  local_10 = (uint)*param_1;
  local_c = param_2 & 0xffff0000;
  if ((char)*param_1 == '\x01') {
    if (1 < *(byte *)((int)param_1 + 1)) {
      return 0x12;
    }
  }
  else if ((char)*param_1 != '\0') {
    return 0x12;
  }
  uStack_8 = param_3;
  uVar1 = FUN_01028d76((char *)&local_10);
  return uVar1;
}


