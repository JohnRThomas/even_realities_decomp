/*
 * Function: FUN_01028b7a
 * Entry:    01028b7a
 * Prototype: char __stdcall FUN_01028b7a(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


char FUN_01028b7a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int local_10 [3];
  
  local_10[0] = 0;
  local_10[1] = 0x20000;
  local_10[2] = param_3;
  do {
    iVar2 = FUN_0100a5d8(local_10);
    if (iVar2 != 0) {
      return '\0';
    }
    cVar1 = FUN_010149d4(local_10[0]);
  } while (cVar1 == '\0');
  return cVar1;
}


