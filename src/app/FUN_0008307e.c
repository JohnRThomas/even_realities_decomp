/*
 * Function: FUN_0008307e
 * Entry:    0008307e
 * Prototype: undefined4 __stdcall FUN_0008307e(void * param_1)
 */


undefined4 FUN_0008307e(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    memset(param_1,0,0x2c);
    uVar1 = 0;
  }
  return uVar1;
}


