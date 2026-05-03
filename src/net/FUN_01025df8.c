/*
 * Function: FUN_01025df8
 * Entry:    01025df8
 * Prototype: undefined __stdcall FUN_01025df8(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025df8(void)

{
  int iVar1;
  int iVar2;
  
  Peripherals::RADIO_NS.POWER = 0;
  Peripherals::RADIO_NS.POWER = 1;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    if ((RADIO_NS *)((&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar1 * 2] & 0xfffff000) ==
        &Peripherals::RADIO_NS) {
      *(uint *)(&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar1 * 2] =
           (&Peripherals::FICR_NS.TRIMCNF_0__DATA)[iVar1 * 2];
    }
    iVar1 = iVar2;
  } while (iVar2 != 0x20);
  _DAT_e000e180 = 0x100;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e280 = 0x100;
  return;
}


