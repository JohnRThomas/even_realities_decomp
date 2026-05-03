/*
 * Function: FUN_0102f0b4
 * Entry:    0102f0b4
 * Prototype: undefined __stdcall FUN_0102f0b4(undefined4 param_1, undefined * param_2)
 */


void FUN_0102f0b4(undefined4 param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 *puStack_18;
  undefined *puStack_14;
  
  puStack_18 = &DAT_0103c928;
  puVar2 = &DAT_0000270f;
  if (param_2 < &DAT_00002710) {
    puVar2 = param_2;
  }
  puStack_14 = param_2;
  iVar1 = FUN_010398f8((undefined1 *)&puStack_18,5,(byte *)0x103e4db,(uint)puVar2);
  FUN_0103aaea(&LAB_0102f0e4_1,0x103d6f9,0xb,DAT_21004684);
  FUN_0103aaea(&LAB_0102f0e4_1,(int)&puStack_18,iVar1,DAT_21004684);
  FUN_0103aaea(&LAB_0102f0e4_1,0x103d6dd,0x1b,DAT_21004684);
  return;
}


