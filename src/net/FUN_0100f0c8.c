/*
 * Function: FUN_0100f0c8
 * Entry:    0100f0c8
 * Prototype: bool __stdcall FUN_0100f0c8(int param_1)
 */


bool FUN_0100f0c8(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 4) & 7;
  bVar2 = *(byte *)(param_1 + 5) & 7;
  return (bVar2 & bVar2 - 1) == 0 && (bVar1 & bVar1 - 1) == 0;
}


