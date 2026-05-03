/*
 * Function: FUN_010290da
 * Entry:    010290da
 * Prototype: undefined4 __stdcall FUN_010290da(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_010290da(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  byte *extraout_r1;
  
  if (*param_1 < 2) {
    bVar1 = FUN_01028cc2((int)param_1,param_2,param_3);
    if ((bVar1) && (cVar2 = FUN_0100cf0c(), cVar2 != '\0')) {
      return 0xc;
    }
    bVar1 = FUN_01028a96((uint)*param_1);
    cVar2 = FUN_0100cbac((uint)bVar1,extraout_r1);
    if (cVar2 != '\0') {
      return 0;
    }
  }
  return 0x12;
}


