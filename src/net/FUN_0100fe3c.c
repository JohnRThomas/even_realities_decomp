/*
 * Function: FUN_0100fe3c
 * Entry:    0100fe3c
 * Prototype: int __stdcall FUN_0100fe3c(void)
 */


int FUN_0100fe3c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_21000f00 ^ DAT_21000efc;
  uVar2 = DAT_21000efc * -0x61c88645;
  uVar1 = DAT_21000efc * -0x3910c8a0;
  DAT_21000efc = uVar3 ^ (DAT_21000efc >> 6 | DAT_21000efc << 0x1a) ^ uVar3 << 9;
  DAT_21000f00 = uVar3 >> 0x13 | uVar3 << 0xd;
  return (uVar2 >> 0x1b | uVar1) * 5;
}


