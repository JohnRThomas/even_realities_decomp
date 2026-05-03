/*
 * Function: FUN_0101a870
 * Entry:    0101a870
 * Prototype: undefined __stdcall FUN_0101a870(byte * param_1, byte * param_2)
 */


void FUN_0101a870(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  if ((bVar1 & 0xf) == 7) {
    FUN_0101a79c(param_1,param_2);
    return;
  }
  uVar3 = FUN_0100e84c(param_1);
  param_2[0x11] = (byte)uVar3;
  bVar2 = FUN_0100e864(param_1);
  param_2[0x12] = bVar2;
  switch(bVar1 & 0xf) {
  case 0:
  case 2:
  case 4:
  case 6:
    param_2[1] = 1;
    *(byte **)(param_2 + 4) = param_1 + 3;
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
    bVar1 = param_1[1];
    param_2[0x10] = bVar1 - 6;
    if ((byte)(bVar1 - 6) != 0) {
      *(byte **)(param_2 + 0xc) = param_1 + 9;
      return;
    }
    break;
  case 1:
    param_2[1] = 3;
    param_2[0x10] = 0;
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    *(byte **)(param_2 + 4) = param_1 + 3;
    *(byte **)(param_2 + 8) = param_1 + 9;
    return;
  default:
    param_2[1] = 0;
    param_2[0x10] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    param_2[0xb] = 0;
  }
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  return;
}


