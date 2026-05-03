/*
 * Function: FUN_01029bee
 * Entry:    01029bee
 * Prototype: undefined4 __stdcall FUN_01029bee(byte * param_1)
 */


undefined4 FUN_01029bee(byte *param_1)

{
  int iVar1;
  
  if (*param_1 == 0xff) {
    FUN_010149dc(*(undefined2 *)(param_1 + 1));
  }
  else {
    iVar1 = FUN_0100a518((ushort)*param_1,2);
    if (iVar1 == 0) {
      return 0x42;
    }
    *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_1 + 1);
  }
  return 0;
}


