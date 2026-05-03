/*
 * Function: FUN_01018080
 * Entry:    01018080
 * Prototype: uint __stdcall FUN_01018080(undefined * param_1)
 */


uint FUN_01018080(undefined *param_1)

{
  undefined *puVar1;
  
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    param_1 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 1;
  DAT_2100104c = 0;
  puVar1 = FUN_0101bcf4(param_1);
  return (uint)puVar1;
}


