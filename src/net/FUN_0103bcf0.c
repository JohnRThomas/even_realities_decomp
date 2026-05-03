/*
 * Function: FUN_0103bcf0
 * Entry:    0103bcf0
 * Prototype: undefined4 * __stdcall FUN_0103bcf0(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0103916c) */

undefined4 * FUN_0103bcf0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint extraout_r2;
  undefined4 extraout_r3;
  
  uVar3 = 4;
  while ((uVar3 - 1 & uVar3) != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mempool.c",0x46,
                 uVar3 - 1);
    uVar3 = FUN_0103a370();
    param_1 = extraout_r2;
  }
  if ((param_1 < 0xfffffffc) &&
     (puVar1 = (undefined4 *)FUN_010364d8((int *)0x210008b4,uVar3 | 4,param_1 + 4,param_4,0,0),
     puVar1 != (undefined4 *)0x0)) {
    puVar2 = puVar1 + 1;
    *puVar1 = 0x210008b4;
    if (uVar3 == 0) {
      return puVar2;
    }
    if (((uint)puVar2 & uVar3 - 1) == 0) {
      return puVar2;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mempool.c",0x25,
                 extraout_r3);
    FUN_0103a370();
  }
  return (undefined4 *)0x0;
}


