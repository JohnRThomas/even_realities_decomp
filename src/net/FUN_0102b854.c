/*
 * Function: FUN_0102b854
 * Entry:    0102b854
 * Prototype: undefined4 __stdcall FUN_0102b854(undefined1 * param_1)
 */


undefined4 FUN_0102b854(undefined1 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_r2;
  uint uVar5;
  undefined4 extraout_r3;
  undefined1 auStack_2c [20];
  
  uVar1 = Peripherals::FICR_NS.DEVICEADDR_0_;
  if ((uVar1 == 0xffffffff) &&
     (uVar1 = Peripherals::FICR_NS.DEVICEADDR_1_, (uVar1 & 0xffff) == 0xffff)) {
    uVar4 = 0;
  }
  else {
    uVar1 = Peripherals::FICR_NS.DEVICEADDRTYPE;
    uVar4 = 0;
    if ((uVar1 & 1) != 0) {
      uVar2 = Peripherals::FICR_NS.DEVICEADDR_0_;
      uVar3 = Peripherals::FICR_NS.DEVICEADDR_1_;
      uVar1 = Peripherals::FICR_NS.IR_0_;
      uVar5 = (uVar3 << 0x10) >> 0x18 | 0xc0;
      if ((((uVar1 != 0xffffffff) && (uVar1 = Peripherals::FICR_NS.IR_1_, uVar1 != 0xffffffff)) &&
          (uVar1 = Peripherals::FICR_NS.IR_2_, uVar1 != 0xffffffff)) &&
         (uVar1 = Peripherals::FICR_NS.IR_3_, uVar1 != 0xffffffff)) {
        uVar1 = Peripherals::FICR_NS.IR_0_;
        uVar1 = Peripherals::FICR_NS.IR_1_;
        uVar1 = Peripherals::FICR_NS.IR_2_;
        uVar1 = Peripherals::FICR_NS.IR_3_;
      }
      param_1[1] = (char)(uVar2 >> 8);
      param_1[3] = (char)(uVar2 >> 0x18);
      param_1[5] = (char)uVar5;
      *param_1 = (char)uVar2;
      param_1[2] = (char)(uVar2 >> 0x10);
      param_1[4] = (char)uVar3;
      FUN_010398f8(auStack_2c,0x12,(byte *)"%02X:%02X:%02X:%02X:%02X:%02X",uVar5);
      FUN_01039ee2((byte *)"BT addr: %s\n",auStack_2c,extraout_r2,extraout_r3);
      uVar4 = 1;
    }
  }
  return uVar4;
}


