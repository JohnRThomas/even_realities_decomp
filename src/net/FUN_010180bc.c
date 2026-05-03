/*
 * Function: FUN_010180bc
 * Entry:    010180bc
 * Prototype: uint __stdcall FUN_010180bc(void)
 */


uint FUN_010180bc(void)

{
  undefined *puVar1;
  
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


