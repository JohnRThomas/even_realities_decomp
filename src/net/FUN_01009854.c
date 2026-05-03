/*
 * Function: FUN_01009854
 * Entry:    01009854
 * Prototype: undefined4 __stdcall FUN_01009854(undefined4 * param_1)
 */


undefined4 FUN_01009854(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = &DAT_0103eb77;
    do {
      puVar2 = puVar1 + 1;
      *param_1 = *puVar1;
      param_1 = param_1 + 1;
      puVar1 = puVar2;
    } while (puVar2 != (undefined4 *)&UNK_0103eb8b);
    return 0;
  }
  return 0xffffffea;
}


