/*
 * Function: FUN_01010000
 * Entry:    01010000
 * Prototype: undefined4 __stdcall FUN_01010000(int param_1, byte * param_2, int param_3, undefined1 * param_4)
 */


undefined4 FUN_01010000(int param_1,byte *param_2,int param_3,undefined1 *param_4)

{
  if (param_3 == 0x16) {
    if (param_1 - 0xcU < 4) {
LAB_0101002a:
      *param_4 = 0x2a;
      return 1;
    }
    if (param_1 == 0x21) {
LAB_01010022:
      *param_4 = 0x23;
      return 1;
    }
    if (param_2 != (byte *)0x0) {
      if (*param_2 < 2) goto LAB_0101002a;
      if (*param_2 == 0x16) goto LAB_01010022;
    }
  }
  return 0;
}


