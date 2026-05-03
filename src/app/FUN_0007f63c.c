/*
 * Function: FUN_0007f63c
 * Entry:    0007f63c
 * Prototype: undefined4 __stdcall FUN_0007f63c(int param_1)
 */


undefined4 FUN_0007f63c(int param_1)

{
  *(undefined1 *)(param_1 + 0xfee) = 10;
  *(undefined1 *)(param_1 + 0xed5) = 0x15;
  *(undefined4 *)(param_1 + 0xf70) = 400;
  *(undefined1 *)(param_1 + 0xf64) = 1;
  *(undefined1 *)(param_1 + 0xf9c) = 1;
  *(undefined1 *)(param_1 + 0x10d4) = 1;
  *(undefined1 *)(param_1 + 0x1088) = 0;
  *(undefined1 *)(param_1 + 0xec0) = 3;
  *(undefined4 *)(param_1 + 0x1081) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1084) = 0xffffffff;
  *(undefined2 *)(param_1 + 0xef8) = 0x114;
  *(undefined1 *)(param_1 + 0x10d6) = 0;
  *(undefined2 *)(param_1 + 0x10d8) = 0;
  __set_test_mode((char *)0x0,param_1 + 0x1081,0x1081);
  *(undefined1 *)(param_1 + 0xec1) = 3;
  *(undefined4 *)(param_1 + 0xf6c) = 0;
  *(undefined1 *)(param_1 + 0x10d7) = 0xf;
  *(undefined1 *)(param_1 + 0x1244) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x5f) = 0;
  *(undefined1 *)(param_1 + 0xee0) = 100;
  *(undefined2 *)(param_1 + 0x1246) = 0;
  FUN_0007f556(param_1);
  return 0;
}


