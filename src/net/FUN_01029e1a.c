/*
 * Function: FUN_01029e1a
 * Entry:    01029e1a
 * Prototype: bool __stdcall FUN_01029e1a(int param_1)
 */


bool FUN_01029e1a(int param_1)

{
  if (*(char *)(param_1 + 2) != '\0') {
    *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + -1;
  }
  return *(char *)(param_1 + 2) == '\0';
}


