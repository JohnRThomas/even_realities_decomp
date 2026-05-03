/*
 * Function: FUN_01017f54
 * Entry:    01017f54
 * Prototype: undefined4 __stdcall FUN_01017f54(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_01017f54(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  FUN_01020afc(0xe,(uint)DAT_21001049,param_3);
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  uVar3 = FUN_01027648(puVar2,(ushort)bVar1);
  if (uVar3 != 0) {
    FUN_01020f64(uVar3);
    uVar4 = DAT_21001049 & 0xc;
    if ((DAT_21001049 & 0xc) != 0) {
      uVar4 = 0x28;
    }
    FUN_01021020(uVar4);
    bVar1 = DAT_21001049;
    DAT_2100100c = FUN_0100d34c(uVar3 + 5);
    uVar5 = 0;
    if (DAT_2100100c != '\0') {
      if ((bVar1 & 0xc) == 0) {
        uVar3 = 0x50;
      }
      else {
        uVar3 = 0x55;
      }
      FUN_01020470();
      uVar5 = FUN_01021098(uVar3);
    }
    DAT_21001000 = 10;
    return uVar5;
  }
  FUN_01009500(0x32,0x62f,extraout_r2,extraout_r3);
  iVar6 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar6;
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    FUN_010204a8();
    DAT_2100100c = 0;
    FUN_01020d00();
    return 5;
  }
  FUN_01020d00();
  return 5;
}


