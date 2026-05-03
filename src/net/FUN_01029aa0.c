/*
 * Function: FUN_01029aa0
 * Entry:    01029aa0
 * Prototype: undefined1 __stdcall FUN_01029aa0(ushort * param_1)
 */


undefined1 FUN_01029aa0(ushort *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  iVar2 = FUN_0100a518(*param_1,1);
  if (iVar2 == 0) {
    uVar1 = 2;
  }
  else if (((*(char *)(iVar2 + 0x3a0) == '\0') && (*(byte *)(iVar2 + 0xc6) - 0x16 < 2)) &&
          (*(char *)(iVar2 + 0x3d4) == '\0')) {
    puVar3 = (undefined4 *)(iVar2 + 0x3a1);
    puVar4 = param_1 + 1;
    do {
      puVar5 = puVar4 + 2;
      *puVar3 = *(undefined4 *)puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar5;
    } while (puVar5 != param_1 + 9);
    *(undefined1 *)(iVar2 + 0x3a0) = 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc;
  }
  return uVar1;
}


