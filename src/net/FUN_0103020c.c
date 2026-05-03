/*
 * Function: FUN_0103020c
 * Entry:    0103020c
 * Prototype: undefined __stdcall FUN_0103020c(undefined4 param_1, undefined4 param_2, byte * param_3, uint * param_4)
 */


void FUN_0103020c(undefined4 param_1,undefined4 param_2,byte *param_3,uint *param_4)

{
  undefined1 auStack_30 [2];
  undefined1 local_2e;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  FUN_0103bdee(auStack_30,0,0x10);
  local_2e = 2;
  local_2c = 0x103abef;
  local_20 = param_1;
  uStack_1c = param_2;
  FUN_01039950((int)auStack_30,param_3,param_4);
  return;
}


