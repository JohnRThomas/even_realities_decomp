/*
 * Function: FUN_0100f094
 * Entry:    0100f094
 * Prototype: byte __stdcall FUN_0100f094(int param_1)
 */


byte FUN_0100f094(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 4) & 7;
  if (((*(byte *)(param_1 + 4) & 7) != 0) &&
     (bVar1 = *(byte *)(param_1 + 5) & 7, (*(byte *)(param_1 + 5) & 7) != 0)) {
    bVar1 = 1;
  }
  return bVar1;
}


