/*
 * Function: FUN_01019728
 * Entry:    01019728
 * Prototype: int __stdcall FUN_01019728(void)
 */


int FUN_01019728(void)

{
  char cVar1;
  ushort uVar2;
  int iVar4;
  longlong lVar5;
  uint uVar3;
  
  DAT_21000fd5 = (DAT_21000fd4 & 0xfd) != 0;
  cVar1 = FUN_0100b204((uint)(byte)DAT_21000fd5,&DAT_21000fd6);
  lVar5 = CONCAT44(DAT_21001034,DAT_21001030);
  iVar4 = (int)cVar1;
  DAT_21000fe8 = DAT_21000fd5;
  DAT_2100100d = (byte)(DAT_21000fd4 - 2) < 2;
  if (((DAT_21000fd5 == '\x01') && (-1 < DAT_21000fdb)) ||
     (DAT_21000fe8 = '\0', (byte)(DAT_21000fd4 - 2) < 2)) {
    uVar2 = FUN_0100cf38();
    uVar3 = (uint)uVar2;
    lVar5 = src/*FUN_01025834();
    iVar4 = (uint)(uVar3 * 0x20 < uVar3) * -0x200 + (uint)CARRY4(uVar3 * 0x3e00,uVar3);
    lVar5 = lVar5 + CONCAT44((((iVar4 * 0x40 | uVar3 * 0x3e01 >> 0x1a) - iVar4) -
                             (uint)(uVar3 * 0xf8040 < uVar3 * 0x3e01)) +
                             (uint)CARRY4(uVar3 * 999999,uVar3),uVar3 * 1000000);
    DAT_21001030 = (undefined4)lVar5;
    DAT_21001034 = (undefined4)((ulonglong)lVar5 >> 0x20);
    iVar4 = 0;
    if (DAT_2100100d != '\0') {
      iVar4 = FUN_0100d370(0);
      return iVar4;
    }
  }
  DAT_21001034 = (undefined4)((ulonglong)lVar5 >> 0x20);
  DAT_21001030 = (undefined4)lVar5;
  return iVar4;
}


