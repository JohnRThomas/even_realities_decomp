/*
 * Function: FUN_01029b42
 * Entry:    01029b42
 * Prototype: int __stdcall FUN_01029b42(ushort * param_1, ushort * param_2)
 */


int FUN_01029b42(ushort *param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort *puStack_20;
  ushort *puStack_1c;
  
  if (param_1[1] == 0) {
    iVar1 = 0x12;
  }
  else {
    puStack_20 = param_1;
    puStack_1c = param_2;
    iVar1 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_20);
    if (iVar1 == 0) {
      *param_2 = *param_1;
      iVar2 = FUN_01028aa6((int)&puStack_20);
      iVar3 = FUN_01028aa2((int)&puStack_20);
      do {
        uVar4 = *(uint *)(iVar3 + 0x14);
        FUN_0100d7a4(iVar2,uVar4,(uint)param_1[1]);
      } while (*(uint *)(iVar3 + 0x14) != uVar4);
    }
  }
  return iVar1;
}


