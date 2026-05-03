/*
 * Function: FUN_010105f0
 * Entry:    010105f0
 * Prototype: undefined4 __stdcall FUN_010105f0(int param_1)
 */


undefined4 FUN_010105f0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       1);
  if (uVar1 == 0) {
    uVar1 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,5,
                         (uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),1);
    if (uVar1 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 8;
    }
    return uVar2;
  }
  if (*(char *)(*(int *)(param_1 + 4) + 0xcb) != '\0') {
    if (*(int *)(*(int *)(param_1 + 4) + 0x158) != 0) {
      FUN_0100ffd0(param_1,10,0xc);
      *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x30;
      FUN_0100ff98(param_1);
      return 0;
    }
    FUN_0100ff98(param_1);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x12;
  }
  return 0;
}


