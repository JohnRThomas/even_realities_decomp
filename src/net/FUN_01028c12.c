/*
 * Function: FUN_01028c12
 * Entry:    01028c12
 * Prototype: bool __stdcall FUN_01028c12(int param_1, uint param_2, byte * param_3)
 */


bool FUN_01028c12(int param_1,uint param_2,byte *param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  byte *extraout_r3;
  int local_20 [2];
  
  local_20[0] = 0;
  local_20[1] = 0;
  do {
    do {
      iVar3 = FUN_0100a5d8(local_20);
      iVar1 = local_20[0];
      if (iVar3 != 0) {
        return false;
      }
    } while (local_20[0] == param_1);
    bVar2 = FUN_01028a96(param_2);
    bVar2 = FUN_0100b23c((uint)bVar2,param_3,(uint)*(byte *)(iVar1 + 2),extraout_r3);
  } while ((!bVar2) ||
          (bVar2 = FUN_0100b23c((uint)*(byte *)(param_1 + 9),(byte *)(param_1 + 10),
                                (uint)*(byte *)(iVar1 + 9),(byte *)(iVar1 + 10)), !bVar2));
  return bVar2;
}


