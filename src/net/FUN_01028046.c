/*
 * Function: FUN_01028046
 * Entry:    01028046
 * Prototype: int __stdcall FUN_01028046(ushort param_1, ushort param_2, short param_3, short param_4)
 */


int FUN_01028046(ushort param_1,ushort param_2,short param_3,short param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_01027fc2(param_1,param_3);
  uVar3 = FUN_01027ff2(param_2,param_4);
  sVar1 = FUN_01028022((short)uVar2,(short)uVar3);
  return (int)sVar1;
}


