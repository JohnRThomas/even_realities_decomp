/*
 * Function: FUN_01020698
 * Entry:    01020698
 * Prototype: undefined __stdcall FUN_01020698(uint param_1, undefined4 param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020698(uint param_1,undefined4 param_2)

{
  uint uVar1;
  AAR_NS *pAVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  AAR_NS *extraout_r2_00;
  undefined2 *puVar4;
  undefined2 *extraout_r3;
  undefined4 extraout_r3_00;
  
  puVar4 = &DAT_210014dc;
  uVar3 = 0;
  if (DAT_210014dc._1_1_ != '\0') {
    pAVar2 = &Peripherals::AAR_NS;
    Peripherals::AAR_NS._1292_4_ = param_2;
    Peripherals::AAR_NS.ADDRPTR = param_1;
    ram0x210014dd = CONCAT11(1,DAT_210014dc._1_1_);
    if (DAT_210014df == '\0') {
      uVar3 = 0;
      if ((char)DAT_210014dc != '\0') {
        Peripherals::AAR_NS.EVENTS_RESOLVED = 0;
        Peripherals::DPPIC_NS.CHENSET = 0x200;
        uVar1 = Peripherals::AAR_NS.EVENTS_END;
        if (uVar1 == 0) {
          return;
        }
        Peripherals::AAR_NS._4_4_ = 1;
        Peripherals::DPPIC_NS.CHENCLR = 0x200;
        return;
      }
      goto LAB_0102072e;
    }
    if (DAT_210014df == '\x04') {
      DAT_210014dc._0_1_ = 1;
      Peripherals::AAR_NS.EVENTS_RESOLVED = 0;
      Peripherals::AAR_NS._512_4_ = 1;
      Peripherals::AAR_NS.TASKS_START = 1;
      return;
    }
    if ((char)DAT_210014dc != '\0') {
      Peripherals::AAR_NS.EVENTS_RESOLVED = 0;
      if (DAT_210014e0 - 2 < 2) {
        Peripherals::RADIO_NS.EVENTS_RATEBOOST = 0;
        DAT_4100e51c = 3;
      }
      Peripherals::AAR_NS._132_4_ = 0x80000005;
      Peripherals::DPPIC_NS.CHENSET = 0x200;
      return;
    }
    FUN_01009500(0x3c,0xfe,&Peripherals::AAR_NS,&DAT_210014dc);
    uVar3 = extraout_r2;
    puVar4 = extraout_r3;
  }
  FUN_01009500(0x3c,0x20e,uVar3,puVar4);
  pAVar2 = extraout_r2_00;
  uVar3 = extraout_r3_00;
LAB_0102072e:
  puVar4 = (undefined2 *)FUN_01009500(0x3c,0xeb,pAVar2,uVar3);
  *puVar4 = (short)puVar4;
  puVar4 = (undefined2 *)((int)puVar4 >> ((uint)puVar4 & 0xff));
  *puVar4 = (short)puVar4;
  if ((char)DAT_210014dc == '\0') {
    ram0x210014dd = 0;
    return;
  }
  Peripherals::AAR_NS._132_4_ = 0;
  Peripherals::DPPIC_NS.CHENCLR = 0x200;
  Peripherals::AAR_NS.PUBLISH_END = 0;
  Peripherals::AAR_NS._132_4_ = 0;
  Peripherals::RADIO_NS.PUBLISH_RATEBOOST = 0;
  Peripherals::AAR_NS._140_4_ = 0;
  DAT_210014dc._0_1_ = 0;
  ram0x210014dd = 0;
  return;
}


