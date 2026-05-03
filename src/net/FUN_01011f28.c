/*
 * Function: FUN_01011f28
 * Entry:    01011f28
 * Prototype: undefined __stdcall FUN_01011f28(int param_1, int param_2, undefined4 param_3)
 */


void FUN_01011f28(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    FUN_01011e64(DAT_21000f4c,param_2,param_3,&DAT_21000f20);
    return;
  }
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x01011f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(DAT_21000f48 + 0x10) + (DAT_21000f24 + 0x3ffffffc) * 4))(DAT_21000f4c);
    return;
  }
  return;
}


