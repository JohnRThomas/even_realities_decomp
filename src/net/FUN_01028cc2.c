/*
 * Function: FUN_01028cc2
 * Entry:    01028cc2
 * Prototype: bool __stdcall FUN_01028cc2(int param_1, undefined4 param_2, undefined4 param_3)
 */


bool FUN_01028cc2(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  int local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  bVar1 = FUN_01028ba4();
  if (((!bVar1) && (cVar2 = FUN_01028b7a(0,extraout_r1,extraout_r2), cVar2 == '\0')) &&
     (bVar1 = FUN_01019a88(), !bVar1)) {
    uStack_c = (uint)CONCAT12(5,(ushort)bVar1);
    local_10 = 0;
    do {
      iVar3 = FUN_0100a5d8(&local_10);
      if (iVar3 != 0) {
        local_10 = 0;
        uStack_c = 0x60000;
        do {
          iVar3 = FUN_0100a5d8(&local_10);
          if (iVar3 != 0) {
            return false;
          }
          bVar1 = FUN_0102a324(*(int *)(local_10 + 0x74) + 0x50);
        } while (!bVar1);
        return bVar1;
      }
      bVar1 = FUN_0102a324(local_10 + 0x40);
    } while (!bVar1);
    return bVar1;
  }
  return true;
}


