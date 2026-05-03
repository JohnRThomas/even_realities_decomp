/*
 * Function: FUN_01035a4c
 * Entry:    01035a4c
 * Prototype: undefined4 __stdcall FUN_01035a4c(undefined4 * param_1)
 */


undefined4 FUN_01035a4c(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_0103bdee(&DAT_21004b04,0,0x20);
  *(undefined4 *)(puVar1 + 4) = *param_1;
  *puVar1 = *(undefined1 *)(param_1 + 1);
  *(undefined1 **)(puVar1 + 8) = puVar1 + 8;
  *(undefined1 **)(puVar1 + 0xc) = puVar1 + 8;
  *(undefined1 **)(puVar1 + 0x10) = puVar1 + 0x10;
  *(undefined1 **)(puVar1 + 0x14) = puVar1 + 0x10;
  *(undefined1 **)(puVar1 + 0x18) = puVar1 + 0x18;
  *(undefined1 **)(puVar1 + 0x1c) = puVar1 + 0x18;
  FUN_01035984(&DAT_21000724);
  return 0;
}


