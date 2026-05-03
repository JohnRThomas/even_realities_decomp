/*
 * Function: FUN_0101ee2c
 * Entry:    0101ee2c
 * Prototype: undefined4 * __stdcall FUN_0101ee2c(void)
 */


undefined4 * FUN_0101ee2c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  puVar1 = (undefined4 *)FUN_0100a518(0,2);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_0100a468(0,2);
    puVar2 = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_01009500(0x39,0x330,extraout_r2,extraout_r3);
    }
    FUN_010129e4(puVar2,DAT_21001224);
  }
  return puVar1;
}


