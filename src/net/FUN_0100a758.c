/*
 * Function: FUN_0100a758
 * Entry:    0100a758
 * Prototype: undefined4 __stdcall FUN_0100a758(ushort param_1, ushort param_2, ushort param_3, undefined4 param_4, short param_5)
 */


undefined4
FUN_0100a758(ushort param_1,ushort param_2,ushort param_3,undefined4 param_4,short param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined4 uVar7;
  
  if (DAT_21000bb4 == (undefined4 *)0x0) {
    FUN_01009500(0x18,0xa5,param_4,0);
  }
  if ((param_1 < *(byte *)(DAT_21000bb4 + 2)) &&
     (*(int *)((uint)param_1 * 4 + DAT_21000bb4[1]) == 0)) {
    uVar3 = FUN_01027fc2(param_2,(short)param_4);
    uVar4 = FUN_01027ff2(param_3,param_5);
    uVar1 = (ushort)uVar4;
    uVar2 = FUN_01028022((ushort)uVar3,uVar1);
    puVar5 = (ushort *)FUN_01027b02((int *)*DAT_21000bb4,(uint)uVar2,(uint)uVar2);
    if (puVar5 == (ushort *)0x0) {
      uVar7 = 1;
    }
    else {
      FUN_01027f6a(puVar5,uVar2,uVar1);
      puVar6 = (ushort *)FUN_01027f90((int)puVar5);
      FUN_01027d9e(puVar6,uVar1,param_3,9,param_5);
      puVar6 = (ushort *)FUN_01027fa6(puVar5);
      FUN_01027eb2(puVar6,(ushort)uVar3,param_2,10,(short)param_4);
      *(ushort **)((uint)param_1 * 4 + DAT_21000bb4[1]) = puVar5;
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 3;
  }
  return uVar7;
}


