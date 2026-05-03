/*
 * Function: FUN_0004b30c
 * Entry:    0004b30c
 * Prototype: undefined * __stdcall FUN_0004b30c(int param_1, undefined4 * param_2, undefined4 * param_3)
 */


undefined * FUN_0004b30c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_3 = 200;
  if (DAT_2001c4e0 != '\0') {
    *param_2 = 0x27e;
    *param_3 = 199;
    return (undefined *)0x0;
  }
  *param_2 = 0x240;
  *param_3 = 0x88;
  return (&PTR_DAT_0008e7b0)[param_1];
}


