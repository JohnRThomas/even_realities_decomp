/*
 * Function: FUN_0003519c
 * Entry:    0003519c
 * Prototype: undefined * __stdcall FUN_0003519c(void)
 */


undefined * FUN_0003519c(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (DAT_200098a4 != '\0') {
    if (DAT_200098a2 == '\0') {
      puVar1 = (undefined *)0x0;
      if (DAT_200098a1 < 4) {
        DAT_200098a0 = 10;
        memcpy(&DAT_200085d4,&DAT_20009894,0x1b4);
        puVar1 = &DAT_200085d4;
      }
    }
    else {
      puVar1 = (undefined *)0x0;
    }
  }
  return puVar1;
}


