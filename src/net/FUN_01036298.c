/*
 * Function: FUN_01036298
 * Entry:    01036298
 * Prototype: undefined __stdcall FUN_01036298(int param_1)
 */


void FUN_01036298(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(&DAT_0103cb08 + (param_1 + 1) * 4);
  for (puVar3 = *(undefined4 **)(&DAT_0103cb08 + param_1 * 4); puVar3 < puVar5; puVar3 = puVar3 + 2)
  {
    pcVar2 = (code *)*puVar3;
    iVar4 = puVar3[1];
    if (iVar4 == 0) {
      (*pcVar2)();
    }
    else {
      if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(iVar4), iVar1 != 0)) {
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if (0xfe < iVar1) {
          iVar1 = 0xff;
        }
        **(undefined1 **)(iVar4 + 0xc) = (char)iVar1;
      }
      *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
    }
  }
  return;
}


