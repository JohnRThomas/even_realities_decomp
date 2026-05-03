/*
 * Function: FUN_0102e07c
 * Entry:    0102e07c
 * Prototype: undefined __stdcall FUN_0102e07c(int param_1)
 */


void FUN_0102e07c(int param_1)

{
  if (param_1 != 0) {
    FUN_01035be4(param_1,*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x28),0x103ce8c,0);
  }
  if ((code *)**(undefined4 **)(param_1 + 0x68) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0102e0a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)**(undefined4 **)(param_1 + 0x68))(*(undefined4 *)(param_1 + 0x6c));
    return;
  }
  return;
}


