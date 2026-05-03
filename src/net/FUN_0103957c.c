/*
 * Function: FUN_0103957c
 * Entry:    0103957c
 * Prototype: uint __stdcall FUN_0103957c(undefined8 * param_1, uint * param_2, uint * param_3)
 */


uint FUN_0103957c(undefined8 *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint auStack_100 [8];
  uint auStack_e0 [8];
  uint auStack_c0 [8];
  uint auStack_a0 [8];
  uint auStack_80 [8];
  uint auStack_60 [8];
  int aiStack_40 [8];
  
  bVar1 = FUN_01008ab0((int *)auStack_c0,param_3,(uint *)&DAT_0103cb60);
  uVar7 = FUN_01008af0(auStack_c0,(uint *)&DAT_0103cb80,(uint)bVar1);
  uVar5 = (uint)uVar7 & auStack_c0[7] >> 0x1f;
  FUN_01008af0(auStack_c0,(uint *)&DAT_0103cb60,1 - uVar5);
  FUN_010392dc(auStack_a0,auStack_60,param_2);
  uVar6 = 0xfe;
  FUN_010396f4((int *)auStack_80,auStack_80,((int)~auStack_c0[7] >> 0x1f) + 1);
  uVar2 = -((int)~auStack_c0[7] >> 0x1f);
  do {
    FUN_01039460(auStack_60,auStack_a0,auStack_100);
    uVar3 = auStack_c0[(int)uVar6 >> 5] >> (uVar6 & 0x1f) & 1;
    FUN_01008ba8((int *)auStack_a0,(int *)auStack_60,uVar2 ^ uVar3);
    FUN_01008ba8((int *)auStack_80,aiStack_40,uVar2 ^ uVar3);
    uVar6 = uVar6 - 1;
    FUN_01039394(auStack_a0,auStack_60);
    uVar2 = uVar3;
  } while (uVar6 != 0xffffffff);
  FUN_010396f4((int *)auStack_e0,auStack_80,1 - uVar3);
  uVar5 = uVar5 ^ uVar3;
  FUN_01039460(auStack_60,auStack_a0,auStack_100);
  FUN_01008ba8((int *)auStack_a0,(int *)auStack_60,uVar5);
  FUN_01008ba8((int *)auStack_80,aiStack_40,uVar5);
  FUN_010091f8((undefined8 *)auStack_e0,auStack_e0,auStack_100);
  FUN_01039798((undefined8 *)auStack_e0,auStack_e0);
  puVar4 = (uint *)(param_1 + 4);
  FUN_010091f8((undefined8 *)auStack_e0,auStack_e0,param_2 + 8);
  FUN_010091f8((undefined8 *)puVar4,auStack_80,auStack_e0);
  FUN_010091f8((undefined8 *)auStack_100,auStack_a0,auStack_e0);
  FUN_01009228((undefined8 *)auStack_100,auStack_100);
  FUN_010091f8((undefined8 *)auStack_e0,auStack_100,auStack_a0);
  FUN_01009228((undefined8 *)auStack_100,puVar4);
  FUN_010090e8((int *)auStack_e0,auStack_100,auStack_e0);
  FUN_010090e8((int *)auStack_100,auStack_e0,(uint *)&LAB_0103cbe0);
  uVar2 = FUN_01009038((byte *)puVar4,0x20);
  FUN_01008ba8((int *)auStack_100,(int *)auStack_e0,uVar2);
  FUN_010091f8(param_1,auStack_100,(uint *)&DAT_0103cb40);
  return -uVar2 | 1 - (uint)uVar7;
}


