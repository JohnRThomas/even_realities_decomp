/*
 * Function: FUN_01013408
 * Entry:    01013408
 * Prototype: int __stdcall FUN_01013408(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_01013408(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  
  iVar3 = FUN_01009500(6,0x35b,param_3,param_4);
  uVar4 = FUN_01012ee8(iVar3);
  if (uVar4 == 0) {
    iVar3 = 0x8b;
  }
  else {
    uVar2 = FUN_01012eb0(iVar3);
    if ((uVar2 == 0) && (uVar4 = FUN_01012eb8(iVar3), uVar4 == 0)) {
      iVar5 = 0x7f;
      iVar3 = 0x75;
    }
    else {
      iVar5 = 0x89;
      iVar3 = 0x7f;
    }
    FUN_01022108();
    FUN_01022114();
    if (uStack_1a != '\0' || uStack_19 != '\0') {
      iVar3 = iVar5;
    }
    bVar1 = FUN_01026528();
    if (bVar1) {
      return iVar3 + 0x18;
    }
    bVar1 = FUN_010263e0();
    if (bVar1) {
      iVar3 = iVar3 + 0xf;
    }
  }
  return iVar3;
}


