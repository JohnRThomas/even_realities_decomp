/*
 * Function: Balloc
 * Entry:    0007b87c
 * Prototype: undefined4 * __stdcall Balloc(size_t param_1, uint param_2)
 */


/* exclude_from_export */

undefined4 * Balloc(size_t param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = malloc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                    ,102,(char *)0x0,"REENT malloc succeeded");
      puVar1 = extraout_r0;
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  iVar4 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar4 + 0xc) == 0) {
    pvVar2 = _calloc_r(param_1,4,0x21);
    iVar3 = *(int *)(param_1 + 0x24);
    *(void **)(iVar4 + 0xc) = pvVar2;
    if (*(int *)(iVar3 + 0xc) != 0) goto LAB_0007b8aa;
LAB_0007b8e0:
    puVar1 = (undefined4 *)0x0;
  }
  else {
LAB_0007b8aa:
    iVar4 = *(int *)(*(int *)(param_1 + 0x24) + 0xc);
    puVar1 = *(undefined4 **)(iVar4 + param_2 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      iVar4 = 1 << (param_2 & 0xff);
      puVar1 = _calloc_r(param_1,1,(iVar4 + 5) * 4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_0007b8e0;
      puVar1[1] = param_2;
      puVar1[2] = iVar4;
    }
    else {
      *(undefined4 *)(iVar4 + param_2 * 4) = *puVar1;
    }
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return puVar1;
}


