/*
 * Function: FUN_01027c70
 * Entry:    01027c70
 * Prototype: byte __stdcall FUN_01027c70(int param_1, ushort param_2)
 */


byte FUN_01027c70(int param_1,ushort param_2)

{
  byte bVar1;
  
  if (param_1 == 0) {
    bVar1 = 0xff;
  }
  else {
    bVar1 = (char)param_2 - (char)(param_2 / *(byte *)(param_1 + 2)) * *(byte *)(param_1 + 2);
    if (param_2 != *(ushort *)((bVar1 + 4) * 2 + param_1 + 2)) {
      if (*(char *)(param_1 + 3) == '\0') {
        bVar1 = FUN_01027c1e(param_1,param_2,bVar1);
      }
      else {
        bVar1 = 0xff;
      }
    }
  }
  return bVar1;
}


