/*
 * Function: FUN_01027c1e
 * Entry:    01027c1e
 * Prototype: byte __stdcall FUN_01027c1e(int param_1, short param_2, byte param_3)
 */


byte FUN_01027c1e(int param_1,short param_2,byte param_3)

{
  byte local_9;
  
  local_9 = param_3;
  do {
    if (param_2 == *(short *)((local_9 + 4) * 2 + param_1 + 2)) {
      return local_9;
    }
    local_9 = (char)(local_9 + 1) -
              (char)((local_9 + 1) / (uint)*(byte *)(param_1 + 2)) * *(byte *)(param_1 + 2);
  } while (local_9 != param_3);
  return 0xff;
}


