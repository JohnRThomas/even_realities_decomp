/*
 * Function: FUN_01029640
 * Entry:    01029640
 * Prototype: undefined4 __stdcall FUN_01029640(undefined4 * param_1, undefined4 param_2)
 */


undefined4 FUN_01029640(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  bVar1 = FUN_0100da9c((int)param_1);
  if (bVar1) {
    FUN_0100dfe4(param_1);
    local_10 = (undefined4 *)0x0;
    uStack_c = 0;
    while (iVar2 = FUN_0100a5d8((int *)&local_10), iVar2 == 0) {
      *(undefined1 *)(local_10 + 0xc5) = 0xff;
    }
    local_10 = (undefined4 *)0x0;
    uStack_c = 0x20000;
    while (iVar2 = FUN_0100a5d8((int *)&local_10), iVar2 == 0) {
      *(undefined1 *)((int)local_10 + 0x7a) = 1;
    }
    local_10 = (undefined4 *)0x0;
    uStack_c = 0x30000;
    while (iVar2 = FUN_0100a5d8((int *)&local_10), iVar2 == 0) {
      *(undefined1 *)(local_10 + 0xd) = 0xff;
    }
    local_10 = (undefined4 *)0x0;
    uStack_c = 0x50000;
    while (iVar2 = FUN_0100a5d8((int *)&local_10), iVar2 == 0) {
      *(undefined1 *)(local_10 + 0xd) = 0xff;
    }
    local_10 = (undefined4 *)0x0;
    uStack_c = 0x90000;
    while (iVar2 = FUN_0100a5d8((int *)&local_10), iVar2 == 0) {
      if (*(char *)(local_10 + 0xc) == '\x03') {
        *(undefined1 *)((int)local_10 + 0x1e) = 0xff;
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x12;
  }
  return uVar3;
}


