/*
 * Function: FUN_0102de5c
 * Entry:    0102de5c
 * Prototype: undefined __stdcall FUN_0102de5c(int param_1, char * param_2, char * param_3, undefined4 param_4)
 */


void FUN_0102de5c(int param_1,char *param_2,char *param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = FUN_01035c7c(param_2,param_1 + 0xe0,param_3,0xffffffff,param_4,*(int *)(param_1 + 0x1ac),
                       &LAB_0103a708_1);
  if (uVar1 == 0) {
    param_2[100] = '\x01';
    if (*(code **)(param_1 + 0x1a8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0102de94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(param_1 + 0x1a8))(param_2);
      return;
    }
  }
  return;
}


