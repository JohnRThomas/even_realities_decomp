/*
 * Function: FUN_01018104
 * Entry:    01018104
 * Prototype: uint __stdcall FUN_01018104(void)
 */


uint FUN_01018104(void)

{
  undefined *puVar1;
  
  FUN_01019ee0();
  puVar1 = (undefined *)FUN_0100df60();
  DAT_2100001c = SUB41(puVar1,0);
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    puVar1 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 1;
  DAT_2100104c = 0;
  puVar1 = FUN_0101bcf4(puVar1);
  return (uint)puVar1;
}


