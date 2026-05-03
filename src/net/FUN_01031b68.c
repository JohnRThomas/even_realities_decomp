/*
 * Function: FUN_01031b68
 * Entry:    01031b68
 * Prototype: undefined8 __stdcall FUN_01031b68(void)
 */


undefined8 FUN_01031b68(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  DataMemoryBarrier(0x1f);
  uVar1 = Peripherals::RTC1_NS.COUNTER;
  uVar2 = uVar1 + DAT_21004970 * 0x1000000;
  uVar3 = (DAT_21004970 >> 8) + (uint)CARRY4(uVar1,DAT_21004970 * 0x1000000);
  if ((uVar1 < 0x100000) &&
     (uVar3 <= DAT_21002b8c && (uint)(DAT_21002b88 <= uVar2) <= uVar3 - DAT_21002b8c)) {
    bVar4 = 0xfeffffff < uVar2;
    uVar2 = uVar2 + 0x1000000;
    uVar3 = uVar3 + bVar4;
  }
  return CONCAT44(uVar3,uVar2);
}


