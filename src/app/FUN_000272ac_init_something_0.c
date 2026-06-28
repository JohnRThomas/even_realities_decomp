/*
 * Function: FUN_000272ac_init_something_0
 * Entry:    000272ac
 * Prototype: undefined4 __stdcall FUN_000272ac_init_something_0(astruct_1 * param_1, undefined4 * param_2)
 */


undefined4 FUN_000272ac_init_something_0(astruct_1 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if ((param_1 != (astruct_1 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    param_1->field0_0x0 = 7;
    uVar1 = 0;
    param_1->field4_0x4 = 0x7f6f3;
    param_1->field5_0x8 = 0x26c5d;
    param_1->field6_0xc = 0x2723d;
    param_1->field7_0x10 = *param_2;
    param_1->field8_0x14 = param_2[1];
    param_1->field9_0x18 = *(undefined2 *)(param_2 + 2);
  }
  return uVar1;
}


