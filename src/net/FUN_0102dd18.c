/*
 * Function: FUN_0102dd18
 * Entry:    0102dd18
 * Prototype: undefined4 __stdcall FUN_0102dd18(int param_1)
 */


undefined4 FUN_0102dd18(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    FUN_0103a612(0x103c034,0x1040,&stack0xfffffff0);
    uVar1 = 0xffffffea;
  }
  else if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    FUN_0103a612(0x103c034,0x1040,&stack0xfffffff0);
    uVar1 = 0xfffffffb;
  }
  else {
    UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(param_1 + 8);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0102dd62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


