/*
 * Function: FUN_010131f4
 * Entry:    010131f4
 * Prototype: undefined4 __stdcall FUN_010131f4(int param_1)
 */


undefined4 FUN_010131f4(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint extraout_r2;
  int extraout_r3;
  
  uVar3 = (uint)*(byte *)(param_1 + 2);
  if ((int)(uVar3 << 0x1f) < 0) {
    bVar1 = *(byte *)(param_1 + 3);
    if ((bVar1 & 1) == 0) {
      cVar2 = *(char *)(param_1 + 5) + '\x01';
      *(char *)(param_1 + 5) = cVar2;
      if (*(char *)(param_1 + 1) == cVar2) {
        *(byte *)(param_1 + 5) = bVar1 & 1;
        *(char *)(param_1 + 3) = (char)(bVar1 | 1);
        if (uVar3 == (bVar1 | 1)) {
          *(byte *)(param_1 + 3) = bVar1 & 1;
          *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
          return 0x25;
        }
      }
      return 0x25;
    }
  }
  if ((int)(uVar3 << 0x1e) < 0) {
    bVar1 = *(byte *)(param_1 + 3);
    if ((bVar1 & 2) == 0) {
      cVar2 = *(char *)(param_1 + 5) + '\x01';
      *(char *)(param_1 + 5) = cVar2;
      if (*(char *)(param_1 + 1) == cVar2) {
        *(byte *)(param_1 + 5) = bVar1 & 2;
        *(char *)(param_1 + 3) = (char)(bVar1 | 2);
        if (uVar3 == (bVar1 | 2)) {
          *(byte *)(param_1 + 3) = bVar1 & 2;
          *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
        }
      }
      return 0x26;
    }
  }
  if ((int)(uVar3 << 0x1d) < 0) goto LAB_01013252;
  do {
    cVar2 = *(char *)(param_1 + 5) + '\x01';
    *(char *)(param_1 + 5) = cVar2;
    if ((*(char *)(param_1 + 1) == cVar2) &&
       (*(undefined1 *)(param_1 + 5) = 0, *(byte *)(param_1 + 3) == uVar3)) {
      *(undefined1 *)(param_1 + 3) = 0;
      uVar3 = *(byte *)(param_1 + 4) + 1;
      *(char *)(param_1 + 4) = (char)uVar3;
    }
    FUN_01009500(0x2e,0x39,uVar3,param_1);
    uVar3 = extraout_r2;
    param_1 = extraout_r3;
LAB_01013252:
    bVar1 = *(byte *)(param_1 + 3);
  } while ((bVar1 & 4) != 0);
  cVar2 = *(char *)(param_1 + 5) + '\x01';
  *(char *)(param_1 + 5) = cVar2;
  if (*(char *)(param_1 + 1) == cVar2) {
    *(byte *)(param_1 + 5) = bVar1 & 4;
    *(char *)(param_1 + 3) = (char)(bVar1 | 4);
    if (uVar3 == (bVar1 | 4)) {
      *(byte *)(param_1 + 3) = bVar1 & 4;
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    }
  }
  return 0x27;
}


