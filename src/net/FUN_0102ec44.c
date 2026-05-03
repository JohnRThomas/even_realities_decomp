/*
 * Function: FUN_0102ec44
 * Entry:    0102ec44
 * Prototype: undefined __stdcall FUN_0102ec44(undefined4 param_1, int param_2)
 */


void FUN_0102ec44(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_2 << 0x1b < 0) {
    return;
  }
  if (param_2 << 0x1a < 0) {
    pbVar1 = (byte *)0x103ce8b;
  }
  else {
    pbVar1 = (byte *)0x103e54b;
  }
  FUN_0102ec20(param_1,pbVar1,param_2 << 0x1b,param_2 << 0x1a);
  return;
}


