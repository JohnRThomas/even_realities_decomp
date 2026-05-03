/*
 * Function: FUN_01028d28
 * Entry:    01028d28
 * Prototype: bool __stdcall FUN_01028d28(uint param_1, undefined4 param_2, undefined4 param_3)
 */


bool FUN_01028d28(uint param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  cVar1 = FUN_01028b7a(param_1,param_2,param_3);
  if (cVar1 != '\0') {
    cVar1 = FUN_01020088();
    if (cVar1 != '\0') {
      puVar4 = FUN_0101ee2c();
      uVar5 = FUN_01012eb8((int)puVar4);
      if (uVar5 == 0) {
        uVar3 = FUN_01012eb0((int)puVar4);
        uVar5 = (uint)(byte)((byte)uVar3 ^ 1);
      }
      else {
        uVar5 = 0;
      }
      param_1 = uVar5 & 1;
    }
    if (param_1 == 0) {
      return false;
    }
  }
  bVar2 = FUN_01028ba4();
  if (bVar2) {
    cVar1 = FUN_010198c4();
    bVar2 = cVar1 == '\x01';
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


