/*
 * Function: FUN_010132d4
 * Entry:    010132d4
 * Prototype: uint __stdcall FUN_010132d4(byte * param_1)
 */


uint FUN_010132d4(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1[2];
  uVar1 = (uint)param_1[3];
  return (((-((int)(uVar2 << 0x1d) >> 0x1f) - ((int)(uVar2 << 0x1e) >> 0x1f)) + (uVar2 & 1)) *
          ((uint)*param_1 - (uint)param_1[4]) * (uint)param_1[1] - (uint)param_1[5]) -
         ((-((int)(uVar1 << 0x1e) >> 0x1f) - ((int)(uVar1 << 0x1d) >> 0x1f)) + (uVar1 & 1)) *
         (uint)param_1[1] & 0xff;
}


