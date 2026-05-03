/*
 * Function: FUN_0101015c
 * Entry:    0101015c
 * Prototype: undefined4 __stdcall FUN_0101015c(int param_1, int param_2)
 */


undefined4 FUN_0101015c(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       1);
  if (uVar2 == 0) {
    return 1;
  }
  iVar4 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100ef20(param_2);
  iVar3 = *(int *)(param_1 + 4);
  *(undefined2 *)(iVar4 + 0x3bc) = uVar1;
  if (0x7ffd < (ushort)((*(short *)(iVar3 + 0x3bc) + -1) - *(short *)(iVar3 + 0xbc))) {
    *(undefined1 *)(iVar3 + 0xe5) = 0x28;
    FUN_0100f788((undefined4 *)(iVar3 + 0xdc),&BYTE_010100a1,2);
    return 0;
  }
  FUN_0100ef14(param_2,(undefined4 *)(iVar3 + 0x3be));
  *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0xb;
  return 0;
}


