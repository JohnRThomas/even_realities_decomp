/*
 * Function: FUN_0100f10c
 * Entry:    0100f10c
 * Prototype: undefined __stdcall FUN_0100f10c(char * param_1)
 */


void FUN_0100f10c(char *param_1)

{
  undefined4 *puVar1;
  
  if ((*param_1 != '\0') &&
     (puVar1 = *(undefined4 **)(param_1 + 4), *(char *)((int)puVar1 + 0x2ea) != '\0')) {
    *(undefined1 *)((int)puVar1 + 0x2ea) = 0;
    FUN_010145a8(puVar1);
    return;
  }
  return;
}


