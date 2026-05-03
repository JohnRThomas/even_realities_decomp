/*
 * Function: FUN_0101065c
 * Entry:    0101065c
 * Prototype: undefined4 __stdcall FUN_0101065c(int param_1, int param_2)
 */


undefined4 FUN_0101065c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       1);
  if (uVar1 == 0) {
    iVar2 = *(int *)(param_1 + 4);
    if (*(byte *)(iVar2 + 0xc6) != 0x14) {
      uVar1 = FUN_0100dbc0(iVar2 + 0xa8,5,(uint)*(byte *)(iVar2 + 0xc6),1);
      if (uVar1 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 8;
      }
      return uVar3;
    }
    iVar5 = *(int *)(iVar2 + 0x158);
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    iVar5 = *(int *)(iVar2 + 0x158);
  }
  if (iVar5 == 0) {
    if (*(char *)(iVar2 + 0x106) == '\0') {
      FUN_0100ff98(param_1);
      iVar2 = *(int *)(param_1 + 4);
    }
    FUN_0100ef64(param_2,(undefined4 *)(iVar2 + 0x2f8));
    FUN_0100ef7c(param_2,(undefined4 *)(*(int *)(param_1 + 4) + 0x140));
    puVar4 = *(undefined2 **)(param_1 + 4);
    *(undefined2 *)((int)puVar4 + 0x3d5) = *puVar4;
    FUN_0100ef38(param_2,(undefined4 *)((int)puVar4 + 0x3d7));
    FUN_0100ef4c(param_2,(undefined2 *)(*(int *)(param_1 + 4) + 0x3df));
    FUN_0100f788((undefined4 *)(*(int *)(param_1 + 4) + 0x3cc),0x10104b5,2);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x16;
    return 0;
  }
  FUN_0100ffd0(param_1,3,0xc);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x30;
  FUN_0100ff98(param_1);
  return 0;
}


