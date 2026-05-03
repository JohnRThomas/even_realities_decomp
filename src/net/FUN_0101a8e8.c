/*
 * Function: FUN_0101a8e8
 * Entry:    0101a8e8
 * Prototype: undefined4 __stdcall FUN_0101a8e8(void)
 */


undefined4 FUN_0101a8e8(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char local_12;
  char local_11;
  
  bVar1 = FUN_01026528();
  if (bVar1) {
    uVar2 = 0xd9;
    uVar3 = 0xcf;
  }
  else {
    bVar1 = FUN_010263e0();
    if (bVar1) {
      uVar2 = 0xd0;
      uVar3 = 0xc6;
    }
    else {
      uVar2 = 0xc1;
      uVar3 = 0xb7;
    }
  }
  FUN_01022108();
  FUN_01022114();
  if (local_11 != '\0' || local_12 != '\0') {
    uVar3 = uVar2;
  }
  return uVar3;
}


