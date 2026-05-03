/*
 * Function: FUN_0103abee
 * Entry:    0103abee
 * Prototype: undefined4 __stdcall FUN_0103abee(undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0103abee(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_2 + 0x10))
            (param_1,*(undefined4 *)(param_2 + 0x14),param_3,*(code **)(param_2 + 0x10),param_4);
  return 0;
}


