/*
 * Function: FUN_0102937c
 * Entry:    0102937c
 * Prototype: int __stdcall FUN_0102937c(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_0102937c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *extraout_r2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  local_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_0100d7c0((ushort)param_1,(undefined1 *)&local_18);
  if (iVar1 == 0) {
    puVar2 = (undefined2 *)FUN_01028aa2((int)&local_18);
    FUN_01028afc(puVar2,(uint)((char)local_18 == '\0'),extraout_r2);
  }
  return iVar1;
}


