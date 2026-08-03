/*
 * Function: i2b
 * Entry:    0007ba64
 * Prototype: undefined __stdcall i2b(size_t param_1, undefined4 param_2)
 */


/* exclude_from_export_ai */

void i2b(size_t param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  
  puVar1 = Balloc(param_1,1);
  if (puVar1 == (undefined4 *)0x0) {
    __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                  ,0x140,(char *)0x0,"Balloc succeeded");
    puVar1 = extraout_r0;
  }
  puVar1[5] = param_2;
  puVar1[4] = 1;
  return;
}


