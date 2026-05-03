/*
 * Function: FUN_0102f840
 * Entry:    0102f840
 * Prototype: uint * __stdcall FUN_0102f840(uint param_1, int param_2, char * param_3)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0102f9fa) overlaps instruction at (ram,0x0102f9f8)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_0102f840(uint param_1,int param_2,char *param_3)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *extraout_r1;
  uint *extraout_r1_00;
  char *pcVar8;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar9;
  uint uVar10;
  uint extraout_r3;
  uint extraout_r3_00;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  char in_OV;
  char cVar14;
  uint uStack_80;
  char acStack_79 [21];
  char *pcStack_64;
  uint *puStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 *local_48;
  char *local_44;
  uint uStack_40;
  undefined4 uStack_3c;
  uint auStack_38 [4];
  byte local_28 [4];
  char *local_24;
  
  puVar12 = auStack_38;
  puVar7 = auStack_38;
  local_24 = "***** MPU FAULT *****";
  local_28[0] = 2;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  FUN_0103ab96(0x103c084,0x1040,local_28);
  if ((int)(_DAT_e000ed28 << 0x1b) < 0) {
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    local_24 = "  Stacking error (context area might be not valid)";
    puVar11 = (uint *)0x11;
    FUN_0103ab96(0x103c084,0x1040,local_28);
  }
  else {
    puVar11 = (uint *)&MemManage;
  }
  if ((int)(_DAT_e000ed28 << 0x1c) < 0) {
    puVar11 = (uint *)&LAB_00000012;
    local_24 = "  Unstacking error";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_28);
  }
  if ((int)(_DAT_e000ed28 << 0x1e) < 0) {
    local_24 = "  Data Access Violation";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_28);
    uVar5 = _DAT_e000ed34;
    if ((int)(_DAT_e000ed28 << 0x18) < 0) {
      local_44 = "  MMFAR Address: 0x%x";
      uStack_40 = _DAT_e000ed34;
      local_48 = &LAB_00000002_1;
      FUN_0103ab96(0x103c084,0x1840,(byte *)&local_48);
      in_OV = '\0';
      if (param_2 != 0) {
        _DAT_e000ed28 = _DAT_e000ed28 & 0xffffff7f;
      }
    }
    else {
      uVar5 = 0xffffffea;
    }
    puVar11 = (uint *)0x13;
  }
  else {
    uVar5 = 0xffffffea;
  }
  if ((int)(_DAT_e000ed28 << 0x1f) < 0) {
    puVar11 = (uint *)&BusFault;
    local_24 = "  Instruction Access Violation";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0103ab96(0x103c084,0x1040,local_28);
  }
  if ((((int)(_DAT_e000ed28 << 0x1b) < 0) || ((int)(_DAT_e000ed28 << 0x1e) < 0)) &&
     ((int)(_DAT_e000ed04 << 0x14) < 0)) {
    uVar3 = FUN_0102f4d8(uVar5,param_1);
    if (uVar3 == 0) {
      cVar14 = (int)(_DAT_e000ed28 << 0x1b) < 0;
      if ((bool)cVar14) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x15d,
                     _DAT_e000ed28 << 0x1b);
        puVar4 = (uint *)FUN_0103a370();
        if (cVar14 != in_OV) {
          *puVar4 = extraout_r2;
          puVar4[1] = (uint)auStack_38;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if (((uint)puVar4 & 0x10000000) != 0) {
          extraout_r1[6] = (int)puVar4 << 4;
          puVar4 = puVar11;
          uVar3 = uVar5;
          goto LAB_0102f9fc;
        }
        uStack_3c = 0x102f981;
        uStack_50 = 0xe000ed00;
        uVar3 = 0;
        uVar10 = _DAT_e000ed04 & 0x1ff;
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(0);
        }
        InstructionSynchronizationBarrier(0xf);
        puVar12 = &uStack_80;
        puVar7 = &uStack_80;
        puStack_54 = puVar11;
        uStack_4c = uVar5;
        local_48 = (undefined1 *)auStack_38;
        local_44 = param_3;
        uStack_40 = param_1;
        if ((extraout_r2 & 0xff000000) == 0xff000000) {
          uVar5 = _DAT_e000ed04;
          puVar11 = extraout_r1;
          uVar9 = extraout_r2;
          puVar12 = &uStack_80;
          puVar7 = &uStack_80;
          local_48 = (undefined1 *)auStack_38;
          if ((extraout_r2 & 0xc) != 8) goto LAB_0102fa02;
          pcStack_64 = "SPSEL in thread mode does not indicate PSP";
          acStack_79[0x11] = '\x02';
          acStack_79[0x12] = '\0';
          acStack_79[0x13] = '\0';
          acStack_79[0x14] = '\0';
          local_48 = (undefined1 *)auStack_38;
          FUN_0103ab96(0x103c084,0x1040,(byte *)(acStack_79 + 0x11));
          uVar10 = extraout_r3;
          puVar12 = &uStack_80;
          puVar7 = &uStack_80;
        }
        do {
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                       "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x458,uVar10);
LAB_0102f9fc:
          uVar5 = FUN_0103a370();
          puVar11 = extraout_r1_00;
          uVar9 = extraout_r2_00;
          uVar10 = extraout_r3_00;
LAB_0102fa02:
          if (-1 < (int)(uVar9 << 0x1c)) {
            uVar3 = 1;
            puVar11 = puVar4;
          }
          puVar4 = puVar11;
        } while (puVar4 == (uint *)0x0);
        *(undefined1 *)((int)puVar12 + 7) = 0;
        switch(uVar10) {
        case 3:
          puVar12[7] = (uint)"***** HARD FAULT *****";
          puVar12[6] = 2;
          FUN_0103ab96(0x103c084,0x1040,(byte *)(puVar12 + 6));
          *(undefined1 *)((int)puVar12 + 7) = 0;
          if (_DAT_e000ed2c << 0x1e < 0) {
            pcVar8 = "  Bus fault on vector table read";
LAB_0102fa52:
            puVar12[6] = 2;
            puVar12[7] = (uint)pcVar8;
            goto LAB_0102fa56;
          }
          if (_DAT_e000ed2c < 0) {
            pcVar8 = "  Debug event";
            goto LAB_0102fa52;
          }
          if (_DAT_e000ed2c << 1 < 0) {
            puVar12[6] = 2;
            puVar12[7] = (uint)"  Fault escalation (see below)";
            FUN_0103ab96(0x103c084,0x1040,(byte *)(puVar12 + 6));
            DataSynchronizationBarrier(0xf);
            InstructionSynchronizationBarrier(0xf);
            _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffeff;
            DataSynchronizationBarrier(0xf);
            InstructionSynchronizationBarrier(0xf);
            if (*(short *)(puVar4[6] - 2) == -0x20fe) {
              uVar5 = *puVar4;
              *(char **)((int)puVar7 + -0xc) = "ARCH_EXCEPT with reason %x\n";
              *(uint *)((int)puVar7 + -8) = uVar5;
              pbVar1 = (byte *)((int)puVar7 + -0x10);
              pbVar1[0] = 3;
              pbVar1[1] = 0;
              pbVar1[2] = 0;
              pbVar1[3] = 0;
              puVar7 = (uint *)FUN_0103ab96(0x103c084,0x1840,pbVar1);
              puVar11 = (uint *)*puVar4;
              break;
            }
            if ((_DAT_e000ed28 & 0xff) != 0) {
              iVar6 = 1;
              goto LAB_0102fb28;
            }
            if ((_DAT_e000ed28 & 0xff00) != 0) {
              iVar6 = 1;
              goto LAB_0102fb3e;
            }
            if (0xffff < _DAT_e000ed28) goto switchD_0102fa1a_caseD_6;
            FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                         "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x32a,
                         _DAT_e000ed28);
          }
          else {
            FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                         "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",0x32e,
                         _DAT_e000ed2c << 1);
          }
          goto LAB_0102f9fc;
        case 4:
          iVar6 = 0;
LAB_0102fb28:
          puVar7 = FUN_0102f840((uint)puVar4,iVar6,(char *)((int)puVar12 + 7));
          puVar11 = puVar7;
          break;
        case 5:
          iVar6 = 0;
LAB_0102fb3e:
          puVar7 = (uint *)FUN_0102f5e8(iVar6,(undefined1 *)((int)puVar12 + 7));
          puVar11 = puVar7;
          break;
        case 6:
switchD_0102fa1a_caseD_6:
          puVar7 = (uint *)FUN_0102f718();
          puVar11 = puVar7;
          break;
        default:
          pcVar8 = "Reserved Exception (";
          if ((uVar5 & 0x1f0) != 0) {
            pcVar8 = "Spurious interrupt (IRQ ";
          }
          *(uint *)((int)puVar7 + -0xc) = uVar10 - 0x10;
          *(undefined2 *)((int)puVar7 + -8) = 0x200;
          *(char **)((int)puVar7 + -0x14) = "***** %s %d) *****";
          *(char **)((int)puVar7 + -0x10) = pcVar8;
          *(undefined1 **)((int)puVar7 + -0x18) = &DAT_01000004;
          puVar7 = (uint *)FUN_0103ab96(0x103c084,0x2440,(byte *)((int)puVar7 + -0x18));
          goto LAB_0102fa64;
        case 0xc:
          puVar12[7] = (uint)"***** Debug monitor exception *****";
          puVar12[6] = 2;
LAB_0102fa56:
          puVar7 = (uint *)FUN_0103ab96(0x103c084,0x1040,(byte *)(puVar12 + 6));
LAB_0102fa64:
          puVar11 = (uint *)0x0;
        }
        if (*(char *)((int)puVar12 + 7) == '\0') {
          puVar13 = puVar4 + 8;
          puVar7 = puVar12;
          do {
            uVar5 = *puVar4;
            uVar10 = puVar4[1];
            puVar4 = puVar4 + 2;
            puVar7[2] = uVar5;
            puVar7[3] = uVar10;
            puVar7 = puVar7 + 2;
          } while (puVar4 != puVar13);
          uVar5 = puVar12[9];
          if (uVar3 == 0) {
            uVar5 = uVar5 & 0xfffffe00;
LAB_0102fb0a:
            puVar12[9] = uVar5;
          }
          else if ((uVar5 & 0x1ff) == 0) {
            uVar5 = ~(~(uVar5 >> 9) << 9);
            goto LAB_0102fb0a;
          }
          puVar7 = (uint *)FUN_0102f200((uint)puVar11,puVar12 + 2);
        }
        return puVar7;
      }
    }
    else {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setProcessStackPointer(uVar3);
      }
      puVar11 = (uint *)&LAB_00000002;
    }
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff;
  *param_3 = '\0';
  return puVar11;
}


