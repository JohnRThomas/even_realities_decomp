/*
 * Function: BOOT_HOOK_CALL
 * Entry:    0008269c
 * Prototype: bool __stdcall BOOT_HOOK_CALL(int param_1, undefined1 * param_2)
 */


/* exclude_from_export */

bool BOOT_HOOK_CALL(int param_1,undefined1 *param_2)

{
  if (param_1 == 1) {
    param_2[1] = 1;
    param_2[4] = 1;
    *param_2 = 3;
    param_2[2] = 3;
    param_2[3] = 3;
  }
  return param_1 != 1;
}


