/*
 * Function: FUN_0100a65c
 * Entry:    0100a65c
 * Prototype: undefined4 __stdcall FUN_0100a65c(void)
 */


undefined4 FUN_0100a65c(void)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (*(byte *)(DAT_21000bb4 + 8) <= local_9) {
      return 1;
    }
    if (*(int *)((uint)local_9 * 4 + *(int *)(DAT_21000bb4 + 4)) != 0) break;
    local_9 = local_9 + 1;
  }
  return 0;
}


