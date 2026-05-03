/*
 * Function: FUN_01031a90
 * Entry:    01031a90
 * Prototype: undefined __stdcall FUN_01031a90(uint param_1, int param_2)
 */


void FUN_01031a90(uint param_1,int param_2)

{
  RTC1_NS *pRVar1;
  undefined1 *puVar2;
  bool bVar3;
  
  if (param_2 != 0) {
    DAT_2100496c = DAT_2100496c | 1 << (param_1 & 0xff);
    pRVar1 = &Peripherals::RTC1_NS;
    Peripherals::RTC1_NS.INTENSET = 0x10000 << (param_1 & 0xff);
    puVar2 = (undefined1 *)((DAT_21004964 >> (param_1 & 0xff)) << 0x1f);
    bVar3 = (int)puVar2 < 0;
    if (bVar3) {
      pRVar1 = (RTC1_NS *)0x400000;
      puVar2 = &DAT_e000e100;
    }
    if (bVar3) {
      *(RTC1_NS **)(puVar2 + 0x100) = pRVar1;
    }
  }
  return;
}


