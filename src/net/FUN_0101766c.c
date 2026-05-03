/*
 * Function: FUN_0101766c
 * Entry:    0101766c
 * Prototype: undefined4 __stdcall FUN_0101766c(int param_1, uint param_2)
 */


undefined4 FUN_0101766c(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 *puVar5;
  
  if (0x5f < DAT_2100104c) goto LAB_010176e2;
  puVar5 = (undefined4 *)(uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
  while( true ) {
    uVar1 = (uint)(byte)DAT_2100104a;
    FUN_01020cf4((byte)DAT_2100104a & 0x3f);
    DAT_2100101f = (byte)((uVar1 << 0x1a) >> 0x1a);
    if (param_1 != 0) break;
    puVar3 = FUN_0102126c(&DAT_00000001,DAT_21001004,puVar5);
    uVar4 = extraout_r2_00;
    if (puVar3 != (undefined4 *)0x0) goto LAB_010176a6;
    FUN_01009500(0x32,0x93e,extraout_r2_00,extraout_r3);
LAB_010176e2:
    puVar5 = (undefined4 *)0x0;
  }
  uVar1 = FUN_01021aec(1,puVar5);
  uVar2 = 0;
  uVar4 = extraout_r2;
  if (uVar1 != 0) {
LAB_010176a6:
    if (DAT_21001018 == '\x02') {
      uVar1 = 0x40;
    }
    else {
      uVar1 = 0xff;
    }
    FUN_01020afc(uVar1,puVar5,uVar4);
    if ((DAT_21001038 == '\0') && (DAT_2100100c = FUN_0100d34c(param_2 + 5), DAT_2100100c != '\0'))
    {
      if (((uint)puVar5 & 0xc) == 0) {
        uVar1 = 0x50;
      }
      else {
        uVar1 = 0x55;
      }
      FUN_01020470();
      FUN_01021098(uVar1);
    }
    FUN_01020f64(param_2);
    uVar2 = 1;
  }
  return uVar2;
}


