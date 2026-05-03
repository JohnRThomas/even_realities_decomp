/*
 * Function: FUN_0103a9cc
 * Entry:    0103a9cc
 * Prototype: undefined4 __stdcall FUN_0103a9cc(undefined1 * param_1)
 */


undefined4 FUN_0103a9cc(undefined1 *param_1)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  FUN_0103bdee(param_1,0,0x30);
  FUN_0103bdee(param_1 + 0xbc,0,0x18);
  FUN_0103bdee(param_1 + 0xa4,0,0x18);
  FUN_01035b74(*(int *)(param_1 + 0xd8));
  FUN_01035b74(*(int *)(param_1 + 0xd4));
  *(undefined4 *)(param_1 + 0xa0) = 0;
  FUN_010359e0((int)(param_1 + 0x34),extraout_r1,extraout_r2,0);
  FUN_01035a8c();
  if (*(code **)(param_1 + 0x6c) != (code *)0x0) {
    (**(code **)(param_1 + 0x6c))(param_1 + 0x40);
  }
  FUN_0103bdee(param_1 + 0x40,0,0x38);
  return 0;
}


