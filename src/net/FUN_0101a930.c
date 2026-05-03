/*
 * Function: FUN_0101a930
 * Entry:    0101a930
 * Prototype: undefined4 __stdcall FUN_0101a930(void)
 */


undefined4 FUN_0101a930(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char local_12;
  char local_11;
  
  bVar1 = FUN_01026528();
  if (bVar1) {
    uVar2 = 0x15c;
    uVar3 = 0x152;
  }
  else {
    bVar1 = FUN_010263e0();
    uVar2 = 0x153;
    uVar3 = 0x149;
    if (!bVar1) {
      uVar2 = 0x144;
      uVar3 = 0x13a;
    }
  }
  FUN_01022108();
  FUN_01022114();
  if (local_11 != '\0' || local_12 != '\0') {
    uVar3 = uVar2;
  }
  return uVar3;
}


