/*
 * Function: FUN_0100ec9c
 * Entry:    0100ec9c
 * Prototype: bool __stdcall FUN_0100ec9c(byte * param_1)
 */


bool FUN_0100ec9c(byte *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = param_1[1];
  uVar3 = (uint)bVar1;
  switch(*param_1 & 0xf) {
  case 0:
  case 2:
  case 6:
    if (uVar3 - 6 < 0x20) {
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
    }
    break;
  case 1:
    return uVar3 == 0xc;
  default:
    return false;
  case 7:
    if (uVar3 != 0) {
      bVar1 = param_1[3];
      if (bVar1 >> 6 == 3) {
        return false;
      }
      if (uVar3 <= (bVar1 & 0x3f)) {
        return false;
      }
      cVar2 = FUN_0100ec48((int)param_1);
      if ((bVar1 & 0x3f) < (uint)(int)cVar2) {
        return false;
      }
      if ((bVar1 & 0x3f) != 0) {
        bVar1 = param_1[4];
        uVar3 = (uint)bVar1;
        if ((int)(uVar3 << 0x1b) < 0) {
          if ((bVar1 & 1) == 0) {
            iVar5 = 0xb;
            iVar4 = 5;
          }
          else {
            iVar5 = 0x11;
            iVar4 = 0xb;
          }
          if ((bVar1 & 2) == 0) {
            iVar5 = iVar4;
          }
          if ((int)(uVar3 << 0x1d) < 0) {
            iVar5 = iVar5 + 1;
          }
          if ((int)(uVar3 << 0x1c) < 0) {
            iVar5 = iVar5 + 2;
          }
          if (0x24 < (param_1[iVar5] & 0x3f)) {
            return false;
          }
          return param_1[iVar5 + 2] < 0x60;
        }
      }
      return true;
    }
  }
  return (bool)bVar1;
}


