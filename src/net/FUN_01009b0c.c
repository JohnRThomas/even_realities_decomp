/*
 * Function: FUN_01009b0c
 * Entry:    01009b0c
 * Prototype: uint __stdcall FUN_01009b0c(uint param_1)
 */


uint FUN_01009b0c(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 < 0x40) {
    uVar1 = param_1 - 1;
    puVar2 = &DAT_21000000;
  }
  else {
    if (param_1 == 0xff) {
      return 1;
    }
    uVar1 = param_1 - 0x40;
    puVar2 = &DAT_21000b70;
  }
  return (uint)puVar2[uVar1 * 0x1000000 >> 0x1d] >> (uVar1 & 0x1f) & 1;
}


