/*
 * Function: FUN_0101a734
 * Entry:    0101a734
 * Prototype: undefined __stdcall FUN_0101a734(byte * param_1, int param_2, undefined4 param_3)
 */


void FUN_0101a734(byte *param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = FUN_0100e84c(param_1);
  *(char *)(param_2 + 0x11) = (char)uVar2;
  bVar1 = FUN_0100e864(param_1);
  *(byte *)(param_2 + 0x12) = bVar1;
  switch(param_3) {
  case 0:
  case 2:
  case 4:
  case 6:
    *(undefined1 *)(param_2 + 1) = 1;
    *(byte **)(param_2 + 4) = param_1 + 3;
    *(undefined4 *)(param_2 + 8) = 0;
    bVar1 = param_1[1];
    *(byte *)(param_2 + 0x10) = bVar1 - 6;
    if ((byte)(bVar1 - 6) != '\0') {
      *(byte **)(param_2 + 0xc) = param_1 + 9;
      return;
    }
    break;
  case 1:
    *(undefined1 *)(param_2 + 1) = 3;
    *(undefined1 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(byte **)(param_2 + 4) = param_1 + 3;
    *(byte **)(param_2 + 8) = param_1 + 9;
    return;
  default:
    *(undefined1 *)(param_2 + 1) = 0;
    *(undefined1 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 8) = 0;
  }
  *(undefined4 *)(param_2 + 0xc) = 0;
  return;
}


