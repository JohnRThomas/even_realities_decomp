/*
 * Function: FUN_01009c78
 * Entry:    01009c78
 * Prototype: undefined4 __stdcall FUN_01009c78(uint * param_1)
 */


undefined4 FUN_01009c78(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  
  uVar5 = Peripherals::FICR_NS.DEVICEADDRTYPE;
  FUN_01026284(param_1,0,0x10);
  FUN_01026284(param_1 + 4,0,0x10);
  uVar1 = Peripherals::FICR_NS.ER_0_;
  if ((((uVar1 != 0xffffffff) || (uVar1 = Peripherals::FICR_NS.ER_1_, uVar1 != 0xffffffff)) ||
      (uVar1 = Peripherals::FICR_NS.ER_2_, uVar1 != 0xffffffff)) ||
     (uVar1 = Peripherals::FICR_NS.ER_3_, uVar1 != 0xffffffff)) {
    uVar1 = Peripherals::FICR_NS.ER_0_;
    uVar2 = Peripherals::FICR_NS.ER_1_;
    uVar3 = Peripherals::FICR_NS.ER_2_;
    uVar4 = Peripherals::FICR_NS.ER_3_;
    param_1[4] = uVar1;
    param_1[5] = uVar2;
    param_1[6] = uVar3;
    param_1[7] = uVar4;
  }
  cVar6 = FUN_0100b290(0);
  if (((cVar6 != '\0') || (-1 < (int)(uVar5 << 0x1f))) &&
     (((uVar1 = Peripherals::FICR_NS.IR_0_, uVar1 != 0xffffffff ||
       ((uVar1 = Peripherals::FICR_NS.IR_1_, uVar1 != 0xffffffff ||
        (uVar1 = Peripherals::FICR_NS.IR_2_, uVar1 != 0xffffffff)))) ||
      (uVar1 = Peripherals::FICR_NS.IR_3_, uVar1 != 0xffffffff)))) {
    uVar1 = Peripherals::FICR_NS.IR_0_;
    uVar5 = Peripherals::FICR_NS.IR_1_;
    uVar2 = Peripherals::FICR_NS.IR_2_;
    uVar3 = Peripherals::FICR_NS.IR_3_;
    *param_1 = uVar1;
    param_1[1] = uVar5;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
  }
  return 0;
}


