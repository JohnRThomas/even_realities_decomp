/*
 * Function: FUN_01009bd4
 * Entry:    01009bd4
 * Prototype: undefined4 __stdcall FUN_01009bd4(undefined1 * param_1)
 */


undefined4 FUN_01009bd4(undefined1 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  
  uVar1 = Peripherals::FICR_NS.DEVICEADDRTYPE;
  uVar2 = Peripherals::FICR_NS.DEVICEADDR_0_;
  if (((uVar2 == 0xffffffff) &&
      (uVar2 = Peripherals::FICR_NS.DEVICEADDR_1_, (uVar2 & 0xffff) == 0xffff)) ||
     (-1 < (int)(uVar1 << 0x1f))) {
    uVar6 = 0;
  }
  else {
    uVar1 = Peripherals::FICR_NS.DEVICEADDR_0_;
    uVar2 = Peripherals::FICR_NS.DEVICEADDR_1_;
    *(uint *)(param_1 + 1) = uVar1;
    *(short *)(param_1 + 5) = (short)uVar2;
    param_1[6] = (byte)(uVar2 >> 8) | 0xc0;
    uVar1 = Peripherals::FICR_NS.IR_0_;
    if (((uVar1 == 0xffffffff) || (uVar1 = Peripherals::FICR_NS.IR_1_, uVar1 == 0xffffffff)) ||
       ((uVar1 = Peripherals::FICR_NS.IR_2_, uVar1 == 0xffffffff ||
        ((uVar1 = Peripherals::FICR_NS.IR_3_, uVar1 == 0xffffffff ||
         (cVar5 = FUN_0100b290(0), cVar5 != '\0')))))) {
      FUN_01026284((undefined4 *)(param_1 + 7),0,0x10);
    }
    else {
      uVar1 = Peripherals::FICR_NS.IR_0_;
      uVar2 = Peripherals::FICR_NS.IR_1_;
      uVar3 = Peripherals::FICR_NS.IR_2_;
      uVar4 = Peripherals::FICR_NS.IR_3_;
      *(uint *)(param_1 + 7) = uVar1;
      *(uint *)(param_1 + 0xb) = uVar2;
      *(uint *)(param_1 + 0xf) = uVar3;
      *(uint *)(param_1 + 0x13) = uVar4;
    }
    uVar6 = 1;
  }
  *param_1 = uVar6;
  return 0;
}


