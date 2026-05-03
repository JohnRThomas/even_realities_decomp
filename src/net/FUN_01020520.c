/*
 * Function: FUN_01020520
 * Entry:    01020520
 * Prototype: bool __stdcall FUN_01020520(void)
 */


bool FUN_01020520(void)

{
  bool bVar1;
  uint uVar2;
  AAR_NS *pAVar3;
  AAR_NS *extraout_r2;
  uint uVar4;
  
  pAVar3 = (AAR_NS *)&DAT_210014d8;
  uVar2 = (uint)(byte)DAT_210014d9;
  if (DAT_210014d8 != '\0') {
    uVar2 = 2;
  }
  bVar1 = uVar2 == 2;
  if (DAT_210014d8 == '\0') goto LAB_0102056a;
  uVar4 = 200;
  pAVar3 = &Peripherals::AAR_NS;
  do {
    uVar2 = Peripherals::AAR_NS.EVENTS_END;
    uVar4 = uVar4 - 1 & 0xff;
    if (uVar2 != 0) {
      uVar2 = Peripherals::AAR_NS.EVENTS_RESOLVED;
      bVar1 = false;
      if (uVar2 != 0) {
        uVar2 = Peripherals::AAR_NS.EVENTS_NOTRESOLVED;
        bVar1 = uVar2 == 0;
      }
      return bVar1;
    }
  } while ((uVar4 != 0) && (bVar1));
  do {
    uVar2 = FUN_01009500(0x3b,0x104,pAVar3,uVar4);
    pAVar3 = extraout_r2;
LAB_0102056a:
    uVar4 = 200;
    do {
      uVar4 = uVar4 - 1 & 0xff;
      if (uVar4 == 0) break;
    } while (bVar1);
    if (uVar2 != 2) {
      return uVar2 == 1;
    }
  } while( true );
}


