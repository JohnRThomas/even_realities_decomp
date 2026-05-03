/*
 * Function: FUN_0102933c
 * Entry:    0102933c
 * Prototype: int __stdcall FUN_0102933c(undefined2 * param_1, undefined2 * param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_0102933c(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  ushort local_14;
  undefined2 local_12;
  ushort local_10;
  undefined2 local_e;
  ushort local_c;
  undefined2 uStack_a;
  
  uVar4 = param_1[2];
  if (uVar4 < 0x4291) {
    uVar1 = *param_1;
    if (0xa8f < uVar4) {
      uVar4 = 0xa90;
    }
    uVar2 = param_1[1];
    *param_2 = uVar1;
    _local_14 = CONCAT22(uVar2,uVar1);
    _local_10 = CONCAT22(uVar2,uVar4);
    _local_c = CONCAT22((short)((uint)param_4 >> 0x10),uVar4);
    iVar3 = FUN_01028e56(&local_14);
  }
  else {
    iVar3 = 0x12;
  }
  return iVar3;
}


