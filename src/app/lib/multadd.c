/*
 * Function: multadd
 * Entry:    0007b940
 * Prototype: undefined4 * __stdcall multadd(size_t param_1, undefined4 * param_2, int param_3, uint param_4)
 */


/* exclude_from_export_ai */

undefined4 * multadd(size_t param_1,undefined4 *param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *extraout_r0;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar6 = param_2[4];
  iVar1 = 0;
  puVar7 = param_2 + 5;
  do {
    iVar1 = iVar1 + 1;
    uVar4 = param_3 * (*puVar7 & 0xffff) + param_4;
    uVar5 = param_3 * (*puVar7 >> 0x10) + (uVar4 >> 0x10);
    param_4 = uVar5 >> 0x10;
    *puVar7 = (uVar4 & 0xffff) + uVar5 * 0x10000;
    puVar7 = puVar7 + 1;
  } while (iVar1 < iVar6);
  puVar2 = param_2;
  if (param_4 != 0) {
    if ((int)param_2[2] <= iVar6) {
      puVar2 = Balloc(param_1,param_2[1] + 1);
      puVar3 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                      ,0xb5,(char *)0x0,"Balloc succeeded");
        puVar3 = extraout_r0;
      }
      memcpy(puVar3 + 3,param_2 + 3,(param_2[4] + 2) * 4);
      Bfree(param_1,param_2);
    }
    puVar2[iVar6 + 5] = param_4;
    puVar2[4] = iVar6 + 1;
  }
  return puVar2;
}


