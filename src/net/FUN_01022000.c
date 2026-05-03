/*
 * Function: FUN_01022000
 * Entry:    01022000
 * Prototype: undefined __stdcall FUN_01022000(int param_1)
 */


void FUN_01022000(int param_1)

{
  undefined4 *puVar1;
  
  while (puVar1 = (undefined4 *)FUN_0102a422((int *)(param_1 + 0x38)), puVar1 != (undefined4 *)0x0)
  {
    FUN_01028294(DAT_21001680,puVar1);
  }
  return;
}


