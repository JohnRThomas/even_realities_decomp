/*
 * Function: FUN_01028bb8
 * Entry:    01028bb8
 * Prototype: undefined4 __stdcall FUN_01028bb8(int param_1, undefined4 param_2)
 */


undefined4 FUN_01028bb8(int param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  bVar2 = FUN_01028ba4();
  if ((!bVar2) || (bVar2 = FUN_01019888(), !bVar2)) {
    local_10 = 0;
    uStack_c = 0x20000;
    do {
      iVar4 = FUN_0100a5d8(&local_10);
      iVar1 = local_10;
      if (iVar4 != 0) {
        return 0;
      }
      cVar3 = FUN_010149d4(local_10);
    } while ((cVar3 == '\0') || (bVar2 = FUN_01012b30(iVar1), !bVar2));
  }
  return 1;
}


