/*
 * Function: FUN_0102cdac
 * Entry:    0102cdac
 * Prototype: undefined __stdcall FUN_0102cdac(uint * param_1, int param_2, uint param_3, undefined4 param_4)
 */


void FUN_0102cdac(uint *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int extraout_r1;
  uint uVar1;
  uint extraout_r2;
  int extraout_r2_00;
  int iVar2;
  int extraout_r2_01;
  int iVar3;
  undefined4 extraout_r3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (0x3ffff < param_3) goto LAB_0102cdd0;
  if (param_3 < 5) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0x1f2,param_4
                );
    while( true ) {
      while( true ) {
        param_1 = (uint *)FUN_0103a370();
        param_2 = extraout_r1;
        param_3 = extraout_r2;
LAB_0102cdd0:
        iVar3 = 8;
LAB_0102cdd2:
        uVar4 = param_2 + 7U & 0xfffffff8;
        uVar1 = (param_2 + (param_3 - iVar3) & 0xfffffff8) - uVar4;
        uVar6 = uVar1 >> 3;
        if (0x17 < uVar1) break;
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0x1fb,
                     iVar3);
      }
      *param_1 = uVar4;
      *(uint *)(uVar4 + 8) = uVar6;
      *(undefined4 *)(uVar4 + 0xc) = 0;
      iVar3 = FUN_01039f92(uVar6);
      uVar1 = FUN_01039f80(uVar6,1);
      uVar5 = extraout_r2_00 * 4 + 7U >> 3;
      if (uVar1 + uVar5 <= uVar6) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0x20c,
                   extraout_r3);
    }
    iVar2 = extraout_r2_00 * 4 + -0x10;
    if (iVar3 < -1) {
      iVar2 = 0;
    }
    FUN_0103bdee((undefined1 *)(uVar4 + 0x10),0,iVar2);
    FUN_01039f64(uVar4,0,uVar5);
    FUN_01039f12(uVar4,0,0,0);
    iVar3 = FUN_01039f34(uVar4,0,1);
    FUN_01039f64(iVar3,uVar5,uVar6 - uVar5);
    FUN_01039f12(uVar4,uVar5,0,uVar5);
    FUN_01039f64(uVar4,uVar6,extraout_r2_01);
    FUN_01039f12(uVar4,uVar6,0,uVar6 - uVar5);
    iVar3 = FUN_01039f34(uVar4,uVar6,1);
    FUN_0103a132(iVar3,uVar5);
    return;
  }
  iVar3 = 4;
  goto LAB_0102cdd2;
}


