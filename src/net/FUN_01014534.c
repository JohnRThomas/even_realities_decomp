/*
 * Function: FUN_01014534
 * Entry:    01014534
 * Prototype: char __stdcall FUN_01014534(undefined1 * param_1)
 */


char FUN_01014534(undefined1 *param_1)

{
  char cVar1;
  
  if (param_1[0x148] == '\0') {
    cVar1 = param_1[0x108];
    if (cVar1 == '\0') {
      cVar1 = '\x01';
    }
    else if (*(uint *)(param_1 + 0x10c) < *(uint *)(param_1 + 0x110)) {
      FUN_010130bc(param_1);
      cVar1 = '\0';
    }
    return cVar1;
  }
  return '\0';
}


