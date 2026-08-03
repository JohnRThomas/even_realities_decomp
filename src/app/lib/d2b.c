/*
 * Function: d2b
 * Entry:    0007bf88
 * Prototype: undefined4 * __stdcall d2b(uint param_1, uint param_2, size_t param_3, int * param_4, int * param_5)
 */


/* exclude_from_export */

undefined4 * d2b(uint param_1,uint param_2,size_t param_3,int *param_4,int *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int extraout_r2;
  uint uVar4;
  uint uVar5;
  size_t local_28;
  int *local_24;
  int *piStack_20;
  
  local_28 = param_3;
  local_24 = param_4;
  piStack_20 = param_5;
  puVar1 = Balloc(param_3,1);
  if (puVar1 == (undefined4 *)0x0) {
    __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                  ,778,(char *)0x0,"Balloc succeeded");
  }
  uVar5 = (param_2 & 0x7fffffff) >> 0x14;
  local_24 = (int *)(param_2 & 0xfffff);
  if (uVar5 != 0) {
    local_24 = (int *)((uint)local_24 | 0x100000);
  }
  if (param_1 == 0) {
    iVar3 = lo0bits((uint *)&local_24);
    uVar2 = iVar3 + 0x20;
    iVar3 = 1;
    puVar1[5] = local_24;
  }
  else {
    local_28 = param_1;
    uVar2 = lo0bits(&local_28);
    if (uVar2 == 0) {
      puVar1[5] = local_28;
    }
    else {
      uVar4 = (int)local_24 << (0x20 - uVar2 & 0xff);
      local_24 = (int *)((uint)local_24 >> (uVar2 & 0xff));
      puVar1[5] = uVar4 | local_28;
    }
    puVar1[6] = local_24;
    if (local_24 == (int *)0x0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 2;
    }
  }
  puVar1[4] = iVar3;
  if (uVar5 == 0) {
    *param_4 = uVar2 - 0x432;
    iVar3 = hi0bits(puVar1[iVar3 + 4]);
    iVar3 = extraout_r2 * 0x20 - iVar3;
  }
  else {
    iVar3 = 0x35 - uVar2;
    *param_4 = (uVar5 - 0x433) + uVar2;
  }
  *param_5 = iVar3;
  return puVar1;
}


