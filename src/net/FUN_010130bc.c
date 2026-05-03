/*
 * Function: FUN_010130bc
 * Entry:    010130bc
 * Prototype: undefined __stdcall FUN_010130bc(undefined1 * param_1)
 */


void FUN_010130bc(undefined1 *param_1)

{
  undefined2 uVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(param_1 + 2);
  if ((int)(uVar4 << 0x1c) < 0) {
    param_1[0x85] = 0x3c;
    uVar1 = **(undefined2 **)(param_1 + 0x1c);
    param_1[0xa3] = 0xff;
    *(undefined2 *)(param_1 + 0x86) = uVar1;
    *(undefined2 *)(param_1 + 0xa4) = 0xffff;
    FUN_0100f788((undefined4 *)(param_1 + 0x7c),0x1011869,2);
    uVar4 = (uint)*(ushort *)(param_1 + 2);
  }
  if ((int)(uVar4 << 0x1f) < 0) {
    uVar1 = **(undefined2 **)(param_1 + 0x1c);
    cVar2 = FUN_01020088();
    if (cVar2 != '\0') goto LAB_010130f8;
    cVar2 = param_1[0xd];
    *(undefined2 *)(param_1 + 0xb1) = uVar1;
    param_1[0xb0] = *param_1;
    param_1[0xaf] = 0x3c;
  }
  else {
    cVar2 = FUN_01020088();
    if (cVar2 != '\0') goto LAB_010130f8;
    cVar2 = param_1[0xd];
    param_1[0xb0] = *param_1;
    param_1[0xb1] = 0xff;
    param_1[0xb2] = 0xff;
    param_1[0xaf] = 0x3c;
  }
  uVar3 = 0;
  if (cVar2 != '\0') {
    uVar3 = param_1[0x40];
  }
  param_1[0xb3] = uVar3;
  FUN_0100f788((undefined4 *)(param_1 + 0xa6),0x1011add,2);
LAB_010130f8:
  param_1[0x79] = 1;
  return;
}


