/*
 * Function: Bfree
 * Entry:    0007b8fc
 * Prototype: undefined __stdcall Bfree(int param_1, undefined4 * param_2)
 */


/* exclude_from_export_ai */

void Bfree(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  int iVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = malloc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                    ,138,(char *)0x0,"REENT malloc succeeded");
      puVar1 = extraout_r0;
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0xc);
    *param_2 = *(undefined4 *)(iVar2 + param_2[1] * 4);
    *(undefined4 **)(iVar2 + param_2[1] * 4) = param_2;
  }
  return;
}


