/*
 * Function: FUN_0101f29c
 * Entry:    0101f29c
 * Prototype: undefined4 __stdcall FUN_0101f29c(byte * param_1)
 */


undefined4 FUN_0101f29c(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  bVar1 = *param_1;
  uVar3 = (uint)param_1[1];
  uVar5 = (uint)param_1[2];
  if (uVar3 != 0 || (bVar1 & 1) != 0) {
    if ((bVar1 & 2) == 0) {
      if (uVar5 == 0) {
        return 0x11;
      }
      uVar4 = bVar1 & 2;
      if ((bVar1 & 1) == 0) {
        uVar4 = uVar3;
      }
    }
    else {
      uVar4 = uVar3;
      uVar5 = bVar1 & 1;
      if ((bVar1 & 1) != 0) {
        uVar4 = 0;
        uVar5 = 0;
      }
    }
    iVar2 = FUN_01028ca8(uVar4);
    if ((iVar2 != 0) && (iVar2 = FUN_01028ca8(uVar5), iVar2 != 0)) {
      DAT_21000ebe = (char)uVar4;
      DAT_21000ebf = (char)uVar5;
      DAT_21000ec0 = 0;
      return 0;
    }
  }
  return 0x11;
}


