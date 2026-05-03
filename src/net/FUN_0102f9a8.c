/*
 * Function: FUN_0102f9a8
 * Entry:    0102f9a8
 * Prototype: undefined __stdcall FUN_0102f9a8(undefined4 * param_1, undefined4 * param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102f9a8(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *extraout_r1;
  undefined4 uVar6;
  uint extraout_r2;
  uint uVar7;
  uint extraout_r3;
  uint extraout_r3_00;
  uint *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined1 *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  undefined4 local_50;
  char local_41;
  undefined4 local_40 [4];
  byte local_30 [4];
  char *local_2c;
  uint local_24;
  
  bVar2 = false;
  uVar7 = _DAT_e000ed04 & 0x1ff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((param_3 & 0xff000000) == 0xff000000) {
    uVar3 = _DAT_e000ed04;
    if ((param_3 & 0xc) != 8) goto LAB_0102fa02;
    local_2c = "SPSEL in thread mode does not indicate PSP";
    local_30[0] = 2;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_30);
    uVar7 = extraout_r3;
  }
  do {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x458,uVar7);
LAB_0102f9fc:
    uVar3 = FUN_0103a370();
    param_2 = extraout_r1;
    param_3 = extraout_r2;
    uVar7 = extraout_r3_00;
LAB_0102fa02:
    puVar9 = param_2;
    if (-1 < (int)(param_3 << 0x1c)) {
      bVar2 = true;
      puVar9 = param_1;
    }
    param_1 = puVar9;
  } while (param_1 == (undefined4 *)0x0);
  local_41 = '\0';
  switch(uVar7) {
  case 3:
    local_2c = "***** HARD FAULT *****";
    local_30[0] = 2;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_30);
    local_41 = '\0';
    if (_DAT_e000ed2c << 0x1e < 0) {
      local_2c = "  Bus fault on vector table read";
      goto LAB_0102fa56;
    }
    if (_DAT_e000ed2c < 0) {
      local_2c = "  Debug event";
      goto LAB_0102fa56;
    }
    if (_DAT_e000ed2c << 1 < 0) {
      local_30[0] = 2;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_2c = "  Fault escalation (see below)";
      FUN_0103ab96(0x103c084,0x1040,local_30);
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffeff;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
      if (*(short *)(param_1[6] + -2) == -0x20fe) {
        local_50 = *param_1;
        local_54 = "ARCH_EXCEPT with reason %x\n";
        local_58 = (char *)0x3;
        FUN_0103ab96(0x103c084,0x1840,(byte *)&local_58);
        puVar8 = (uint *)*param_1;
        goto LAB_0102fada;
      }
      if ((_DAT_e000ed28 & 0xff) != 0) {
        iVar5 = 1;
        goto LAB_0102fb28;
      }
      if ((_DAT_e000ed28 & 0xff00) != 0) {
        iVar5 = 1;
        goto LAB_0102fb3e;
      }
      if (0xffff < _DAT_e000ed28) goto switchD_0102fa1a_caseD_6;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x32a,_DAT_e000ed28);
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x32e,
                   _DAT_e000ed2c << 1);
    }
    goto LAB_0102f9fc;
  case 4:
    iVar5 = 0;
LAB_0102fb28:
    puVar8 = FUN_0102f840((uint)param_1,iVar5,&local_41);
    goto LAB_0102fada;
  case 5:
    iVar5 = 0;
LAB_0102fb3e:
    puVar8 = (uint *)FUN_0102f5e8(iVar5,&local_41);
    goto LAB_0102fada;
  case 6:
switchD_0102fa1a_caseD_6:
    puVar8 = (uint *)FUN_0102f718();
    goto LAB_0102fada;
  default:
    local_58 = "Reserved Exception (";
    if ((uVar3 & 0x1f0) != 0) {
      local_58 = "Spurious interrupt (IRQ ";
    }
    local_54 = (char *)(uVar7 - 0x10);
    local_50 = CONCAT22(local_50._2_2_,0x200);
    local_5c = "***** %s %d) *****";
    local_60 = &DAT_01000004;
    FUN_0103ab96(0x103c084,0x2440,(byte *)&local_60);
    break;
  case 0xc:
    local_2c = "***** Debug monitor exception *****";
LAB_0102fa56:
    local_30[0] = 2;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    local_41 = '\0';
    FUN_0103ab96(0x103c084,0x1040,local_30);
  }
  puVar8 = (uint *)0x0;
LAB_0102fada:
  if (local_41 == '\0') {
    puVar9 = local_40;
    puVar10 = param_1 + 8;
    do {
      uVar4 = *param_1;
      uVar6 = param_1[1];
      param_1 = param_1 + 2;
      *puVar9 = uVar4;
      puVar9[1] = uVar6;
      puVar9 = puVar9 + 2;
    } while (param_1 != puVar10);
    if (bVar2) {
      if ((local_24 & 0x1ff) == 0) {
        local_24 = ~(~(local_24 >> 9) << 9);
      }
    }
    else {
      local_24 = local_24 & 0xfffffe00;
    }
    FUN_0102f200((uint)puVar8,local_40);
  }
  return;
}


