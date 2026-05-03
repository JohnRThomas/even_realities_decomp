/*
 * Function: FUN_01031210
 * Entry:    01031210
 * Prototype: undefined4 __stdcall FUN_01031210(int param_1, uint param_2, uint param_3, undefined4 param_4)
 */


undefined4 FUN_01031210(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint extraout_r1;
  int iVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  iVar10 = *(int *)(param_1 + 4);
  uVar9 = param_2 & 0x1f | (uint)*(byte *)(iVar10 + 0xc) << 5;
  uStack_24 = param_2;
  local_20 = param_3;
  uStack_1c = param_4;
  puVar2 = FUN_0103510c(uVar9,(int)&uStack_24 + 3,param_3,(uint)*(byte *)(iVar10 + 0xc));
  if ((param_3 & 0x30000) != 0) goto LAB_01031264;
  FUN_01035324(uVar9,extraout_r1);
  if ((puVar2 == &DAT_0bad0000) &&
     (puVar3 = (undefined1 *)FUN_010351e8(uStack_24 >> 0x18), puVar3 != &DAT_0bad0000)) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/drivers/gpio/gpio_nrfx.c",
                 0x6c,extraout_r3);
    while( true ) {
      FUN_0103a370();
LAB_01031264:
      local_20 = 0;
      uStack_1c = 0;
      puVar3 = FUN_01034e98(uVar9,0,(byte *)&local_20,(int *)0x0);
      if (puVar3 != &DAT_0bad0000) goto LAB_010312b6;
      if ((puVar2 != &DAT_0bad0000) ||
         (puVar3 = (undefined1 *)FUN_010351e8(uStack_24 >> 0x18), puVar3 == &DAT_0bad0000)) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/drivers/gpio/gpio_nrfx.c",
                   0x7f,extraout_r3_00);
    }
    uVar1 = local_20;
    if ((int)(param_3 << 0xe) < 0) {
      uVar6 = param_3 & 0x306;
      if (uVar6 == 0x106) {
        uVar6 = 7;
LAB_010312e0:
        if ((int)(param_3 << 0x1b) < 0) {
          uVar7 = 3;
        }
        else {
          uVar7 = (param_3 << 0x1a) >> 0x1f;
        }
        local_20._3_1_ = SUB41(uVar1,3);
        local_20._0_3_ =
             CONCAT12((char)uVar7,CONCAT11((byte)(((param_3 ^ 0x10000) << 0xf) >> 0x1f),(char)uVar6)
                     );
        if ((int)(param_3 << 0xc) < 0) {
          uVar7 = 1 << (param_2 & 0xff);
          *(uint *)(*(int *)(iVar10 + 4) + 8) = uVar7;
        }
        else {
          iVar5 = param_3 << 0xd;
          bVar11 = iVar5 < 0;
          if (bVar11) {
            iVar5 = *(int *)(iVar10 + 4);
            uVar7 = 1 << (param_2 & 0xff);
          }
          if (bVar11) {
            *(uint *)(iVar5 + 0xc) = uVar7;
          }
        }
        puVar2 = FUN_01035000(uVar9,&local_20,(byte *)0x0,uVar7);
        goto LAB_01031316;
      }
      if (0x106 < uVar6) {
        if (uVar6 == 0x202) {
          uVar6 = 5;
        }
        else if (uVar6 == 0x300) {
          uVar6 = 3;
        }
        else {
          if (uVar6 != 0x200) goto LAB_010312b6;
          uVar6 = 2;
        }
        goto LAB_010312e0;
      }
      if (uVar6 == 6) goto LAB_010312e0;
      if (uVar6 < 7) {
        if (uVar6 != 0) {
          if (uVar6 != 2) goto LAB_010312b6;
          uVar6 = 4;
        }
        goto LAB_010312e0;
      }
      if (uVar6 == 0x100) {
        uVar6 = 1;
        goto LAB_010312e0;
      }
    }
    else {
      if ((int)(param_3 << 0x1b) < 0) {
        bVar8 = 3;
      }
      else {
        bVar8 = (byte)((param_3 << 0x1a) >> 0x1f);
      }
      local_20 = CONCAT31(local_20._1_3_,bVar8);
      puVar2 = FUN_01034e98(uVar9,&local_20,(byte *)0x0,(int *)0x0);
LAB_01031316:
      if (puVar2 == &DAT_0bad0000) goto LAB_0103131c;
    }
LAB_010312b6:
    uVar4 = 0xffffffea;
  }
  else {
LAB_0103131c:
    uVar4 = 0;
  }
  return uVar4;
}


