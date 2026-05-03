/*
 * Function: FUN_01039798
 * Entry:    01039798
 * Prototype: undefined __stdcall FUN_01039798(undefined8 * param_1, uint * param_2)
 */


void FUN_01039798(undefined8 *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint auStack_70 [8];
  uint auStack_50 [8];
  uint auStack_30 [8];
  
  iVar3 = 5;
  puVar2 = auStack_70;
  FUN_01009228((undefined8 *)auStack_30,param_2);
  FUN_010091f8((undefined8 *)auStack_70,auStack_30,param_2);
  FUN_01009228((undefined8 *)auStack_30,auStack_70);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_010091f8((undefined8 *)auStack_50,auStack_30,auStack_70);
  FUN_01009228((undefined8 *)auStack_30,auStack_50);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_010091f8((undefined8 *)auStack_30,auStack_30,auStack_50);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_01009228((undefined8 *)auStack_30,auStack_30);
  FUN_010091f8((undefined8 *)auStack_50,auStack_30,auStack_70);
  puVar1 = auStack_50;
  do {
    FUN_01009228((undefined8 *)auStack_30,puVar1);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
    puVar1 = auStack_30;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)puVar1,puVar1,auStack_50);
  iVar3 = 5;
  do {
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)auStack_30,auStack_30,auStack_50);
  FUN_01009228((undefined8 *)auStack_50,auStack_30);
  FUN_01009228((undefined8 *)auStack_50,auStack_50);
  FUN_010091f8((undefined8 *)auStack_70,auStack_50,auStack_70);
  iVar3 = 0x10;
  do {
    FUN_01009228((undefined8 *)auStack_30,puVar2);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
    puVar2 = auStack_30;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)puVar2,puVar2,param_2);
  iVar3 = 0x40;
  do {
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)auStack_30,auStack_30,auStack_70);
  iVar3 = 0x10;
  do {
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)auStack_30,auStack_30,auStack_70);
  iVar3 = 0x10;
  do {
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    FUN_01009228((undefined8 *)auStack_30,auStack_30);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_010091f8((undefined8 *)auStack_30,auStack_30,auStack_50);
  FUN_010091f8(param_1,auStack_30,param_2);
  return;
}


