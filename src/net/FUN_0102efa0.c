/*
 * Function: FUN_0102efa0
 * Entry:    0102efa0
 * Prototype: undefined __stdcall FUN_0102efa0(undefined4 * param_1, ushort * param_2, uint param_3)
 */


void FUN_0102efa0(undefined4 *param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar1 = *param_2;
  uVar6 = *(uint *)(param_2 + 4);
  uVar2 = 0;
  if (*(int *)(param_2 + 2) != 0) {
    uVar2 = (*(int *)(param_2 + 2) + -0x103bfac) * 0x2000 >> 0x10;
    if ((int)uVar2 < 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0102e9e0(((uint)(byte)*param_2 << 0x1a) >> 0x1d,uVar2);
    }
  }
  puVar3 = param_2 + 8;
  uVar4 = (uint)(*(int *)param_2 << 0xc) >> 0x15;
  pbVar5 = (byte *)((int)puVar3 + uVar4);
  if (uVar4 == 0) {
    puVar3 = (ushort *)0x0;
  }
  FUN_0102ecb4(param_1,uVar6,0,uVar2,0,(byte)(((uint)uVar1 << 0x17) >> 0x1d),(byte *)puVar3,pbVar5,
               ((uint)param_2[1] << 0x10) >> 0x14,param_3);
  return;
}


