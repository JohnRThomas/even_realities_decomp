/*
 * Function: ?_is_old_board
 * Entry:    000803d4
 * Prototype: undefined4 __stdcall ?_is_old_board(void)
 */


undefined4 __is_old_board(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00025340();
  if (((*(char *)(puVar1 + 1) == 'E') && (*(char *)((int)puVar1 + 5) == 'G')) &&
     (*(char *)((int)puVar1 + 6) == 'P')) {
    if (*(char *)((int)puVar1 + 7) == '0') {
      return 1;
    }
    if (*(char *)((int)puVar1 + 7) == '1') {
      if (*(byte *)(puVar1 + 2) - 0x30 < 4) {
        return 1;
      }
      return 0;
    }
  }
  return 0;
}


