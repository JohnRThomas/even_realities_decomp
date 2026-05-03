/*
 * Function: FUN_01020134
 * Entry:    01020134
 * Prototype: undefined __stdcall FUN_01020134(int param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_01020134(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined2 *puVar2;
  
  puVar2 = *(undefined2 **)(param_1 + 4);
  *(char *)((int)puVar2 + 0x20b) = (char)param_2;
  puVar2[0x106] = *puVar2;
  iVar1 = FUN_01028c86((uint)*(byte *)(puVar2 + 0x37),param_2,param_3);
  *(char *)(puVar2 + 0x107) = (char)iVar1;
  iVar1 = FUN_01028c86((uint)*(byte *)((int)puVar2 + 0x6f),extraout_r1,extraout_r2);
  *(char *)((int)puVar2 + 0x20f) = (char)iVar1;
  FUN_0100f7c8((undefined4 *)(puVar2 + 0x101),&LAB_01029e3c_1,2);
  *(undefined1 *)(puVar2 + 0xb6) = 0;
  return;
}


