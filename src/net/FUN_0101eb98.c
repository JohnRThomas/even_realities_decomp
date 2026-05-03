/*
 * Function: FUN_0101eb98
 * Entry:    0101eb98
 * Prototype: bool __stdcall FUN_0101eb98(uint param_1)
 */


bool FUN_0101eb98(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = FUN_010288f2(param_1);
  if (((((bVar1) && (bVar1 = FUN_010288f2(~param_1), bVar1)) &&
       (uVar2 = (int)param_1 >> 0x1b ^ (int)param_1 >> 0x1a, (uVar2 - 1 & uVar2) != 0)) &&
      ((uVar2 = param_1 & 0xff & (param_1 & 0xff) - 1, (uVar2 & uVar2 - 1) != 0 &&
       (uVar2 = FUN_0100ff48(param_1 & 0xffff), uVar2 < 0xc)))) &&
     ((uVar2 = FUN_0100ff0c(param_1), uVar2 < 0x19 &&
      (((param_1 & 0xffff) != param_1 >> 0x10 || (((param_1 ^ param_1 >> 8) & 0xff00ff) != 0)))))) {
    bVar1 = ((param_1 ^ 0x8e89bed6) - 1 & (param_1 ^ 0x8e89bed6)) != 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


