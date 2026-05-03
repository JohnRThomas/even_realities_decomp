/*
 * Function: FUN_0100a8dc
 * Entry:    0100a8dc
 * Prototype: undefined __stdcall FUN_0100a8dc(undefined4 param_1, undefined4 param_2)
 */


void FUN_0100a8dc(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  undefined1 local_9;
  
  if (DAT_21000bb4 != 0) {
    for (local_9 = 0; (uint)local_9 < (uint)*(byte *)(DAT_21000bb4 + 8); local_9 = local_9 + 1) {
      FUN_0100a848((ushort)local_9,param_2,(uint)local_9);
      param_2 = extraout_r1;
    }
  }
  return;
}


