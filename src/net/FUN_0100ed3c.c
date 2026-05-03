/*
 * Function: FUN_0100ed3c
 * Entry:    0100ed3c
 * Prototype: bool __stdcall FUN_0100ed3c(byte * param_1)
 */


bool FUN_0100ed3c(byte *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = *param_1 & 0xf;
  if (bVar4 == 7) {
    bVar4 = param_1[3];
    if (bVar4 >> 6 != 3) {
      if (((bVar4 & 0x3f) < (uint)param_1[1]) &&
         (cVar1 = FUN_0100ec48((int)param_1), (uint)(int)cVar1 <= (bVar4 & 0x3f))) {
        if ((bVar4 & 0x3f) != 0) {
          bVar4 = param_1[4];
          uVar5 = (uint)bVar4;
          if ((int)(uVar5 << 0x1b) < 0) {
            if ((bVar4 & 1) == 0) {
              iVar3 = 0xb;
              iVar2 = 5;
            }
            else {
              iVar3 = 0x11;
              iVar2 = 0xb;
            }
            if ((bVar4 & 2) == 0) {
              iVar3 = iVar2;
            }
            if ((int)(uVar5 << 0x1d) < 0) {
              iVar3 = iVar3 + 1;
            }
            if ((int)(uVar5 << 0x1c) < 0) {
              iVar3 = iVar3 + 2;
            }
            if (0x24 < (param_1[iVar3] & 0x3f)) {
              return false;
            }
            return param_1[iVar3 + 2] < 0x60;
          }
        }
        return true;
      }
    }
  }
  else {
    if (bVar4 == 8) {
      return param_1[1] == 0xe;
    }
    if (bVar4 == 4) {
      return param_1[1] - 6 < 0x20;
    }
  }
  return false;
}


