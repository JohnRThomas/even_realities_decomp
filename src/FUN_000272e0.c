/*
 * Function: FUN_000272e0
 * Entry:    000272e0
 * Prototype: undefined4 __stdcall FUN_000272e0(astruct_2 * param_1, undefined4 * param_2)
 */


undefined4 FUN_000272e0(astruct_2 *param_1,undefined4 *param_2)

{
  if ((param_1 != (astruct_2 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    param_1->field0_0x0 = 8;
    param_1->field4_0x4 = 0x7f705;
    param_1->field5_0x8 = 0x26cf5;
    param_1->field6_0xc = 0x27275;
    param_1->field7_0x10 = *param_2;
    param_1->field8_0x14 = param_2[1];
    param_1->field9_0x18 = *(undefined1 *)(param_2 + 2);
    return 0;
  }
  return 7;
}


