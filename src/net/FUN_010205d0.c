/*
 * Function: FUN_010205d0
 * Entry:    010205d0
 * Prototype: undefined __stdcall FUN_010205d0(uint param_1, uint param_2, uint param_3, int param_4, byte param_5)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010205d0(uint param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  uint uVar1;
  undefined2 *puVar2;
  DPPIC_NS *pDVar3;
  undefined4 extraout_r2;
  AAR_NS *pAVar4;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  AAR_NS *extraout_r2_01;
  int extraout_r3;
  undefined2 *puVar6;
  undefined2 *extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar8 = (uint)param_5;
  FUN_01020888(1);
  pDVar3 = &Peripherals::DPPIC_NS;
  Peripherals::AAR_NS.NIRK = param_1 & 3 | param_4 << 0x10 | 0x1000000;
  Peripherals::AAR_NS.IRKPTR = param_2;
  uVar1 = DAT_4100e518;
  DAT_4100e518 = uVar1 & 0xffffff00 | param_3;
  Peripherals::AAR_NS._132_4_ = 0;
  DAT_210014e0 = (byte)param_4;
  Peripherals::DPPIC_NS.CHENCLR = 0x200;
  if ((param_1 & 0xfb) == 0) {
    pDVar3 = (DPPIC_NS *)&DAT_80000009;
    Peripherals::AAR_NS.PUBLISH_END = 0x80000009;
    Peripherals::AAR_NS._132_4_ = 0x80000009;
  }
  if (uVar8 < 3) {
    DAT_4100e520 = (uint)(byte)(&DAT_0103c48c)[uVar8];
    if (param_1 == 1) {
      Peripherals::RADIO_NS.PUBLISH_RATEBOOST = 0x80000009;
      Peripherals::AAR_NS._140_4_ = 0x80000009;
    }
    else {
      DAT_210014df = (char)param_1;
      ram0x210014dd = CONCAT11(DAT_210014de,1);
      if (2 < param_1) {
        return;
      }
    }
    ram0x210014dd = CONCAT11(DAT_210014de,1);
    DAT_210014df = (char)param_1;
    DAT_210014dc._0_1_ = 1;
    Peripherals::AAR_NS.EVENTS_END = 0;
    Peripherals::AAR_NS._512_4_ = 0;
    Peripherals::AAR_NS.TASKS_START = 1;
    return;
  }
  puVar2 = (undefined2 *)FUN_01009500(0x3c,0x1d7,pDVar3,&DAT_210014dc);
  puVar7 = (undefined4 *)(extraout_r3 >> 0x13);
  *puVar2 = (short)puVar2;
  *puVar7 = extraout_r2;
  puVar7[1] = extraout_r3;
  puVar7[2] = uVar8;
  *puVar2 = (short)puVar2;
  puVar6 = &DAT_210014dc;
  uVar5 = 0;
  if (DAT_210014dc._1_1_ != '\0') {
    pAVar4 = &Peripherals::AAR_NS;
    Peripherals::AAR_NS._1292_4_ = 0;
    Peripherals::AAR_NS.ADDRPTR = (int)puVar2 >> ((uint)puVar2 & 0xff);
    ram0x210014dd = CONCAT11(1,DAT_210014dc._1_1_);
    if (DAT_210014df == '\0') {
      uVar5 = 0;
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
    uVar5 = extraout_r2_00;
    puVar6 = extraout_r3_00;
  }
  FUN_01009500(0x3c,0x20e,uVar5,puVar6);
  pAVar4 = extraout_r2_01;
  uVar5 = extraout_r3_01;
LAB_0102072e:
  puVar6 = (undefined2 *)FUN_01009500(0x3c,0xeb,pAVar4,uVar5);
  *puVar6 = (short)puVar6;
  puVar6 = (undefined2 *)((int)puVar6 >> ((uint)puVar6 & 0xff));
  *puVar6 = (short)puVar6;
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


