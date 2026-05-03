/*
 * Function: FUN_01039228
 * Entry:    01039228
 * Prototype: uint __stdcall FUN_01039228(uint * param_1, uint * param_2)
 */


uint FUN_01039228(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint auStack_70 [8];
  uint auStack_50 [17];
  
  uVar1 = FUN_01039288(auStack_70,param_2);
  uVar2 = FUN_010396e8((undefined8 *)auStack_50,auStack_70);
  FUN_01039560(param_1,auStack_50);
  return uVar1 | uVar2;
}


