/*
 * Function: FUN_0100fdd8
 * Entry:    0100fdd8
 * Prototype: undefined __stdcall FUN_0100fdd8(void)
 */


void FUN_0100fdd8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    FUN_01009a04();
  } while (DAT_21000ef4 == 0 && DAT_21000ef8 == 0);
  do {
    uVar1 = DAT_21000ef8 ^ DAT_21000ef4;
    uVar2 = uVar1 ^ (DAT_21000ef4 >> 6 | DAT_21000ef4 << 0x1a);
    uVar3 = uVar2 ^ uVar1 << 9;
    DAT_21000efc = (DAT_21000ef4 * -0x61c88645 >> 0x1b | DAT_21000ef4 * -0x3910c8a0) * 5;
    uVar1 = uVar3 ^ (uVar1 >> 0x13 | uVar1 << 0xd);
    DAT_21000f00 = (uVar3 * -0x61c88645 >> 0x1b | uVar3 * -0x3910c8a0) * 5;
    DAT_21000ef8 = uVar1 >> 0x13 | uVar1 << 0xd;
    DAT_21000ef4 = uVar1 ^ (uVar3 >> 6 | uVar2 << 0x1a) ^ uVar1 << 9;
  } while (DAT_21000f00 == 0 && DAT_21000efc == 0);
  return;
}


