/*
 * Function: crc32
 * Entry:    000256c4
 * Prototype: uint __stdcall crc32(uint param_1, byte * param_2, int param_3)
 */


uint crc32(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = ~param_1;
  pbVar2 = param_2 + param_3;
  for (; param_2 != pbVar2; param_2 = param_2 + 1) {
    uVar1 = (&DAT_20007f80)[(*param_2 ^ uVar1) & 0xff] ^ uVar1 >> 8;
  }
  return ~uVar1;
}


