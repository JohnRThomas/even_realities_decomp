/*
 * Function: FUN_01029208
 * Entry:    01029208
 * Prototype: undefined4 __stdcall FUN_01029208(ushort * param_1, ushort * param_2)
 */


undefined4 FUN_01029208(ushort *param_1,ushort *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puStack_18;
  ushort *puStack_14;
  
  puStack_18 = param_1;
  puStack_14 = param_2;
  iVar2 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_18);
  if (iVar2 == 0) {
    if ((char)param_1[1] == '\0') {
      iVar2 = FUN_01028aa2((int)&puStack_18);
      *(undefined1 *)(param_2 + 1) = *(undefined1 *)(iVar2 + 0x72);
    }
    else {
      uVar1 = FUN_01028bfe();
      *(undefined1 *)(param_2 + 1) = uVar1;
    }
    *param_2 = *param_1;
    iVar2 = FUN_0100df14((int)(char)param_2[1]);
    *(char *)(param_2 + 1) = (char)iVar2;
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


