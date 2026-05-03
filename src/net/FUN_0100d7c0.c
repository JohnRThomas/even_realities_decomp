/*
 * Function: FUN_0100d7c0
 * Entry:    0100d7c0
 * Prototype: undefined4 __stdcall FUN_0100d7c0(ushort param_1, undefined1 * param_2)
 */


undefined4 FUN_0100d7c0(ushort param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_0100a518(param_1,0);
  *(int *)(param_2 + 4) = iVar1;
  if (iVar1 != 0) {
    *param_2 = 0;
    return 0;
  }
  iVar1 = FUN_0100a518(param_1,1);
  *(int *)(param_2 + 4) = iVar1;
  if (iVar1 != 0) {
    *param_2 = 1;
    return 0;
  }
  return 2;
}


