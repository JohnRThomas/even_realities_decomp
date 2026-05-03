/*
 * Function: FUN_01030028
 * Entry:    01030028
 * Prototype: undefined __stdcall FUN_01030028(int * param_1, int param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01030028(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int extraout_r2;
  byte *pbVar4;
  byte *extraout_r3;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = &DAT_210046a0;
  for (iVar6 = 0; iVar6 < param_2; iVar6 = iVar6 + 1) {
    iVar7 = param_1[1];
    if (iVar7 != 0) {
      iVar3 = *param_1;
      uVar1 = FUN_0103ab9c(iVar3);
      uVar2 = FUN_0103ab9c(iVar7 + iVar3 + -1);
      iVar7 = 0x14;
      pbVar4 = &DAT_21004fb0;
      if (uVar1 == uVar2) goto LAB_01030092;
      pbVar4 = (byte *)(iVar6 * 0x14);
      pbVar4[0x210046a0] = 0xea;
      pbVar4[0x210046a1] = 0xff;
      pbVar4[0x210046a2] = 0xff;
      pbVar4[0x210046a3] = 0xff;
      do {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",299,pbVar4);
        FUN_0103a370();
        iVar7 = extraout_r2;
        pbVar4 = extraout_r3;
LAB_01030092:
        *puVar5 = uVar1;
      } while ((uVar1 == 0xffffffea) || ((int)(uint)*pbVar4 <= (int)uVar1));
      iVar7 = iVar7 * iVar6;
      _DAT_e000ed98 = uVar1;
      (&DAT_210046ac)[iVar7] = (&DAT_210046ac)[iVar7] & 0xe0 | (byte)_DAT_e000ed9c & 0x1f;
      (&DAT_210046ac)[iVar7] = (&DAT_210046ac)[iVar7] & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5)
      ;
      puVar5[1] = _DAT_e000ed9c & 0xffffffe0;
      puVar5[4] = _DAT_e000eda0 & 0xffffffe0;
    }
    puVar5 = puVar5 + 5;
    param_1 = param_1 + 3;
  }
  return;
}


