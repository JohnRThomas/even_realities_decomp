/*
 * Function: FUN_01012438
 * Entry:    01012438
 * Prototype: undefined __stdcall FUN_01012438(void)
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_01012438(void)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  uint extraout_r3;
  uint uVar2;
  
  if (DAT_21000f32 != '\0') {
    FUN_010210b0();
    FUN_010204a8();
  }
  cVar1 = FUN_01014534(DAT_21000f4c);
  uVar2 = extraout_r3;
  if ((cVar1 != '\0') &&
     (uVar2 = *(ushort *)(DAT_21000f4c + 2) & 0x18, (*(ushort *)(DAT_21000f4c + 2) & 0x18) != 0)) {
    if ((DAT_21000f24 != 2) && (DAT_21000f24 != 3)) {
      FUN_01009500(0x2d,0xbfa,extraout_r2,(uint)DAT_21000f24);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Could not recover jumptable at 0x01012470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(DAT_21000f48 + 0xc) + (DAT_21000f24 + 0x3ffffffe) * 4))();
    return;
  }
  FUN_01011e64(DAT_21000f4c,extraout_r1,extraout_r2,uVar2);
  return;
}


