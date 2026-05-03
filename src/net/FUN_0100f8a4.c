/*
 * Function: FUN_0100f8a4
 * Entry:    0100f8a4
 * Prototype: undefined2 __stdcall FUN_0100f8a4(int param_1, undefined1 * param_2)
 */


undefined2 FUN_0100f8a4(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_14;
  
  uVar2 = FUN_0100f148(*(byte *)(param_1 + 0x13) & 1);
  if (uVar2 == 0) {
    uVar4 = *(undefined4 *)(param_1 + 9);
    uVar3 = *(undefined4 *)(param_1 + 0xd);
    *param_2 = 0x14;
    *(undefined4 *)(param_2 + 2) = uVar4;
    uVar1 = *(undefined1 *)(param_1 + 0x13);
    *(undefined2 *)(param_2 + 10) = *(undefined2 *)(param_1 + 0x11);
    *(undefined4 *)(param_2 + 6) = uVar3;
    param_2[0xc] = uVar1;
    local_14 = 4;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


