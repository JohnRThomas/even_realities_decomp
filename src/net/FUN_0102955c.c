/*
 * Function: FUN_0102955c
 * Entry:    0102955c
 * Prototype: undefined4 __stdcall FUN_0102955c(ushort * param_1)
 */


undefined4 FUN_0102955c(ushort *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_10 [8];
  
  if (*param_1 == 0xffff) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0100d7c0(*param_1,auStack_10);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = FUN_01028aa2((int)auStack_10);
  }
  bVar1 = FUN_0101ed30(iVar2,(uint)param_1[1],(uint)param_1[2],(uint)param_1[3],param_1[4],
                       param_1[5],param_1[6]);
  if (bVar1) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x30;
  }
  return uVar3;
}


