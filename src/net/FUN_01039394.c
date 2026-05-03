/*
 * Function: FUN_01039394
 * Entry:    01039394
 * Prototype: undefined __stdcall FUN_01039394(uint * param_1, uint * param_2)
 */


void FUN_01039394(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint auStack_78 [8];
  uint auStack_58 [8];
  uint auStack_38 [9];
  
  FUN_010090e8((int *)auStack_78,param_1,param_2);
  FUN_01009228((undefined8 *)auStack_78,auStack_78);
  puVar1 = param_2 + 8;
  puVar2 = param_1 + 8;
  FUN_010091f8((undefined8 *)auStack_58,param_1,auStack_78);
  FUN_010091f8((undefined8 *)auStack_78,param_2,auStack_78);
  FUN_0100906c((int *)auStack_38,puVar2,puVar1);
  FUN_010090e8((int *)puVar1,puVar2,puVar1);
  FUN_01009228((undefined8 *)param_2,puVar1);
  FUN_0100906c((int *)param_1,auStack_58,auStack_78);
  FUN_010090e8((int *)param_2,param_2,param_1);
  FUN_010090e8((int *)auStack_78,auStack_58,auStack_78);
  FUN_010091f8((undefined8 *)puVar2,puVar2,auStack_78);
  FUN_010090e8((int *)auStack_78,auStack_58,param_2);
  FUN_010091f8((undefined8 *)puVar1,puVar1,auStack_78);
  FUN_010090e8((int *)puVar1,puVar1,puVar2);
  FUN_01009228((undefined8 *)auStack_78,auStack_38);
  FUN_010090e8((int *)param_1,auStack_78,param_1);
  FUN_010090e8((int *)auStack_58,auStack_58,param_1);
  FUN_010091f8((undefined8 *)auStack_38,auStack_38,auStack_58);
  FUN_010090e8((int *)puVar2,auStack_38,puVar2);
  return;
}


