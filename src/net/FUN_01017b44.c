/*
 * Function: FUN_01017b44
 * Entry:    01017b44
 * Prototype: undefined __stdcall FUN_01017b44(byte * param_1)
 */


undefined1 FUN_01017b44(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte bStack_40;
  byte bStack_3f;
  byte *pbStack_3c;
  byte *pbStack_38;
  byte bStack_2f;
  byte bStack_2e;
  
  iVar4 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar4;
  if ((((*param_1 & 0xf) == 8) && (FUN_0101a79c(param_1,&bStack_40), bStack_40 == 0)) &&
     ((bStack_3f & 3) == 3)) {
    bVar1 = DAT_21001008;
    if (DAT_21000fdd != '\0') {
      bVar1 = DAT_2100100b;
    }
    uVar8 = (uint)bVar1;
    if ((DAT_2100100c == '\0') || (uVar7 = FUN_0100d310(), uVar7 == 0xff)) {
      bVar3 = false;
    }
    else {
      DAT_21001009 = (undefined1)uVar7;
      bVar3 = uVar7 == uVar8;
    }
    bVar2 = FUN_0100b23c((uint)bStack_2f,pbStack_3c,(uint)DAT_21001020,(byte *)&DAT_21001019);
    if ((!bVar2) && (!bVar3)) {
      return 1;
    }
    uVar7 = (uint)DAT_21000fd5;
    if ((DAT_2100100d == '\0') || (pbVar6 = FUN_0100d3bc(uVar8), pbVar6 == (byte *)0x0)) {
      pbVar6 = (byte *)&DAT_21000fd6;
    }
    else {
      uVar7 = 1;
    }
    if ((bStack_2e == 1) && ((pbStack_38[5] & 0xc0) == 0x40)) {
      bVar3 = FUN_0100b23c(1,pbStack_38,uVar7,pbVar6);
      if (bVar3) goto LAB_01017bd0;
      if (uVar8 == 0xff) {
        return 1;
      }
      puVar5 = (undefined4 *)FUN_0100d268(uVar8);
      if (puVar5 == (undefined4 *)0x0) {
        return 1;
      }
      bVar3 = FUN_0100b2ac(puVar5,(char *)pbStack_38);
    }
    else {
      bVar3 = FUN_0100b23c((uint)bStack_2e,pbStack_38,uVar7,pbVar6);
    }
    if (bVar3 != false) {
LAB_01017bd0:
      FUN_01029dd6((ushort *)&DAT_21001014,1);
      if (DAT_2100100c != '\0') {
        FUN_010210b0();
        FUN_010204a8();
        DAT_2100100c = '\0';
      }
      FUN_01016ec0(1,param_1);
      FUN_0101bd4c(3,extraout_r1,extraout_r2);
      return 0;
    }
  }
  return 1;
}


