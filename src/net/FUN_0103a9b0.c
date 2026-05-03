/*
 * Function: FUN_0103a9b0
 * Entry:    0103a9b0
 * Prototype: undefined4 * __stdcall FUN_0103a9b0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 * FUN_0103a9b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1 * 8 + 0x34;
  puVar1 = FUN_0103bcf0(uVar2,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0103bdee((undefined1 *)puVar1,0,uVar2);
  }
  return puVar1;
}


