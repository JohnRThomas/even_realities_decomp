/*
 * Function: FUN_0100b73c
 * Entry:    0100b73c
 * Prototype: undefined __stdcall FUN_0100b73c(int param_1)
 */


void FUN_0100b73c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_21000c70;
  uVar3 = (uint)*(byte *)(DAT_21000c70 + 0xcb);
  uVar2 = (uint)DAT_21000cc2;
  DAT_21000c74 = DAT_21000d00;
  if (uVar3 != 0) {
    uVar2 = uVar2 + 4 & 0xff;
  }
  if (((uVar2 != 0xff) || (param_1 != 0)) ||
     ((uint)*(byte *)(DAT_21000c70 + 0x6f) != (uint)*(byte *)(DAT_21000c70 + 0x6e))) {
    FUN_01020afc(uVar2,(uint)*(byte *)(DAT_21000c70 + 0x6f),uVar3);
    uVar3 = (uint)*(byte *)(iVar1 + 0xcb);
  }
  if (uVar3 == 0) {
    FUN_01020f64(DAT_21000c74);
    FUN_0102074c();
  }
  else {
    FUN_01020f64(DAT_21000ccc);
    DAT_21000ce8 = (char)DAT_21000c6c != '\0';
    DAT_21000ce0 = *(undefined4 *)(iVar1 + 0x128);
    DAT_21000ce4 = *(undefined4 *)(iVar1 + 300);
    FUN_01020698(DAT_21000c74,DAT_21000ccc);
  }
  if (param_1 == 0) {
    uVar2 = *(byte *)(iVar1 + 0x6f) & 0xc;
    if ((*(byte *)(iVar1 + 0x6f) & 0xc) != 0) {
      uVar2 = 0x28;
    }
    FUN_01021020(uVar2);
  }
  if (*(undefined **)(iVar1 + 0x14) < &DAT_00001d4c) {
    FUN_010210f0(1,0,(uint)*(byte *)(iVar1 + 0x6e));
    DAT_21000c8c = 2;
    return;
  }
  FUN_010210f0(0,0,(uint)*(byte *)(iVar1 + 0x6e));
  DAT_21000c8c = 2;
  return;
}


