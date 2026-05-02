/*
 * Function: FUN_0003555c
 * Entry:    0003555c
 * Prototype: undefined4 __stdcall FUN_0003555c(uint param_1, int param_2)
 */


undefined4 FUN_0003555c(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = 0;
  while( true ) {
    uVar2 = (uint)bVar1;
    if (param_1 <= uVar2) {
      return 0;
    }
    if (((&DAT_2000879c)[uVar2 * 0x1b4] != '\0') && ((&DAT_20008794)[uVar2 * 0x6d] == param_2))
    break;
    bVar1 = bVar1 + 1;
  }
  return 1;
}


