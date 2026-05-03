/*
 * Function: FUN_010144d8
 * Entry:    010144d8
 * Prototype: undefined4 __stdcall FUN_010144d8(int param_1)
 */


undefined4 FUN_010144d8(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r3;
  undefined4 extraout_r3_00;
  
  if (*(char *)(param_1 + 0x120) == '\0') {
    return 0;
  }
  *(undefined1 *)(param_1 + 0x148) = 1;
  FUN_01013160(param_1,1);
  if (*(char *)(param_1 + 0x120) == '\0') {
    return 0;
  }
  FUN_01023fb0((uint)*(byte *)(param_1 + 0x100));
  FUN_0102491c((uint)*(byte *)(param_1 + 0x100),extraout_r1,extraout_r2,extraout_r3);
  cVar1 = FUN_010236bc((uint)*(byte *)(param_1 + 0x100));
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x120) = 0;
    return 0;
  }
  uVar2 = FUN_01009500(0x30,0x20a,extraout_r2_00,extraout_r3_00);
  DAT_21000f5c = (char)uVar2;
  return uVar2;
}


