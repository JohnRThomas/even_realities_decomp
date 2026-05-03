/*
 * Function: FUN_010394f8
 * Entry:    010394f8
 * Prototype: int __stdcall FUN_010394f8(uint * param_1, uint * param_2)
 */


int FUN_010394f8(uint *param_1,uint *param_2)

{
  uint uVar1;
  byte abStack_50 [32];
  byte abStack_30 [32];
  
  FUN_01039730(param_1,param_2);
  FUN_01039730(param_1 + 8,param_2 + 8);
  FUN_01009228((undefined8 *)abStack_30,param_1);
  FUN_0100906c((int *)abStack_30,(uint *)abStack_30,(uint *)&DAT_0103cc00);
  FUN_010091f8((undefined8 *)abStack_30,(uint *)abStack_30,param_1);
  FUN_0100906c((int *)abStack_30,(uint *)abStack_30,(uint *)&LAB_0103cbe0);
  FUN_01009228((undefined8 *)abStack_50,param_1 + 8);
  uVar1 = FUN_01009010(abStack_30,abStack_50,0x20);
  return uVar1 - 1;
}


