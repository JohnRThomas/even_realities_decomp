/*
 * Function: FUN_01034c4c
 * Entry:    01034c4c
 * Prototype: undefined4 __stdcall FUN_01034c4c(uint param_1)
 */


undefined1 * FUN_01034c4c(uint param_1)

{
  undefined1 *puVar1;
  
  (&Peripherals::DPPIC_NS.TASKS_CHG_0__DIS)[param_1 * 2] = 1;
  puVar1 = FUN_01034b28((uint *)&DAT_210006a0,param_1);
  return puVar1;
}


