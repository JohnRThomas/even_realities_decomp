/*
 * Function: FUN_010195ac
 * Entry:    010195ac
 * Prototype: undefined __stdcall FUN_010195ac(undefined4 param_1)
 */


void FUN_010195ac(undefined4 param_1)

{
  byte bVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  undefined4 extraout_r3;
  
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  iVar3 = FUN_01027648(puVar2,(ushort)bVar1);
  if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x010195d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*DAT_21001054)(param_1,iVar3);
    return;
  }
  FUN_01009500(0x32,0xaa5,extraout_r2,extraout_r3);
                    /* WARNING: Could not recover jumptable at 0x010195f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_21001054[1])(extraout_r2_00 >> 0x1e,0);
  return;
}


