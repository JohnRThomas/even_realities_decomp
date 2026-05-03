/*
 * Function: FUN_01039460
 * Entry:    01039460
 * Prototype: undefined __stdcall FUN_01039460(uint * param_1, uint * param_2, uint * param_3)
 */


void FUN_01039460(uint *param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint auStack_38 [8];
  
  FUN_010090e8((int *)auStack_38,param_1,param_2);
  FUN_01009228((undefined8 *)auStack_38,auStack_38);
  puVar1 = param_2 + 8;
  FUN_010091f8((undefined8 *)param_1,param_1,auStack_38);
  puVar2 = param_1 + 8;
  FUN_010091f8((undefined8 *)auStack_38,param_2,auStack_38);
  FUN_010090e8((int *)puVar1,puVar2,puVar1);
  FUN_01009228((undefined8 *)param_2,puVar1);
  FUN_010090e8((int *)param_2,param_2,param_1);
  FUN_010090e8((int *)param_2,param_2,auStack_38);
  FUN_010090e8((int *)param_3,param_1,auStack_38);
  FUN_010091f8((undefined8 *)puVar2,puVar2,param_3);
  FUN_010090e8((int *)auStack_38,param_1,param_2);
  FUN_010091f8((undefined8 *)puVar1,puVar1,auStack_38);
  FUN_010090e8((int *)puVar1,puVar1,puVar2);
  return;
}


