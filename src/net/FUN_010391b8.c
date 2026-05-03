/*
 * Function: FUN_010391b8
 * Entry:    010391b8
 * Prototype: undefined4 * __stdcall FUN_010391b8(uint param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 * FUN_010391b8(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 extraout_r3;
  int *piVar4;
  
  bVar1 = FUN_0103b90a();
  if (bVar1) {
    piVar4 = (int *)0x210008b4;
  }
  else {
    piVar4 = *(int **)(DAT_21004b30 + 0x84);
    if (piVar4 == (int *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  if ((param_2 < 0xfffffffc) &&
     (puVar2 = (undefined4 *)FUN_010364d8(piVar4,param_1 | 4,param_2 + 4,param_4,0,0),
     puVar2 != (undefined4 *)0x0)) {
    puVar3 = puVar2 + 1;
    *puVar2 = piVar4;
    if (param_1 == 0) {
      return puVar3;
    }
    if (((uint)puVar3 & param_1 - 1) == 0) {
      return puVar3;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mempool.c",0x25,
                 extraout_r3);
    FUN_0103a370();
  }
  return (undefined4 *)0x0;
}


