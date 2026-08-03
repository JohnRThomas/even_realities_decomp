/*
 * Function: pow5mult
 * Entry:    0007bbe4
 * Prototype: undefined4 * __stdcall pow5mult(size_t param_1, undefined4 * param_2, uint param_3)
 */


/* exclude_from_export_ai */

undefined4 * pow5mult(size_t param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if ((param_3 & 3) != 0) {
    param_2 = multadd(param_1,param_2,*(int *)(&DAT_0009c304 + ((param_3 & 3) - 1) * 4),0);
  }
  iVar3 = (int)param_3 >> 2;
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      puVar1 = malloc(0x10);
      *(undefined4 **)(param_1 + 0x24) = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                      ,430,(char *)0x0,"REENT malloc succeeded");
        puVar1 = extraout_r0;
      }
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = 0;
      puVar1[3] = 0;
    }
    iVar5 = *(int *)(param_1 + 0x24);
    puVar1 = *(undefined4 **)(iVar5 + 8);
    puVar4 = param_2;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)i2b(param_1,0x271);
      *(undefined4 **)(iVar5 + 8) = puVar1;
      *puVar1 = 0;
    }
    while( true ) {
      puVar2 = puVar1;
      param_2 = puVar4;
      if (iVar3 << 0x1f < 0) {
        param_2 = (undefined4 *)mult(param_1,(int)puVar4,(int)puVar2);
        Bfree(param_1,puVar4);
      }
      iVar3 = iVar3 >> 1;
      if (iVar3 == 0) break;
      puVar1 = (undefined4 *)*puVar2;
      puVar4 = param_2;
      if ((undefined4 *)*puVar2 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)mult(param_1,(int)puVar2,(int)puVar2);
        *puVar2 = puVar1;
        *puVar1 = 0;
      }
    }
  }
  return param_2;
}


