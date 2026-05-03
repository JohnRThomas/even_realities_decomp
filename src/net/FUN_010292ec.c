/*
 * Function: FUN_010292ec
 * Entry:    010292ec
 * Prototype: undefined1 __stdcall FUN_010292ec(ushort * param_1, ushort * param_2)
 */


undefined1 FUN_010292ec(ushort *param_1,ushort *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *extraout_r1;
  undefined1 extraout_r2;
  ushort *puStack_18;
  ushort *puStack_14;
  
  puStack_18 = param_1;
  puStack_14 = param_2;
  iVar2 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_18);
  if (iVar2 == 0) {
    iVar2 = FUN_01028aa6((int)&puStack_18);
    do {
      *(undefined1 *)(iVar2 + 0x76) = extraout_r2;
      *extraout_r1 = *(undefined4 *)(iVar2 + 0x26);
      *(undefined1 *)(extraout_r1 + 1) = *(undefined1 *)(iVar2 + 0x2a);
      *param_2 = *param_1;
      uVar1 = 0;
    } while (*(char *)(iVar2 + 0x76) != '\0');
  }
  else {
    uVar1 = 2;
    param_2[1] = 0;
    param_2[2] = 0;
    *(undefined1 *)(param_2 + 3) = 0;
    *(undefined1 *)param_2 = 0;
    *(undefined1 *)((int)param_2 + 1) = 0;
  }
  return uVar1;
}


