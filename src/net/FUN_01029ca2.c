/*
 * Function: FUN_01029ca2
 * Entry:    01029ca2
 * Prototype: undefined4 __stdcall FUN_01029ca2(ushort * param_1, ushort * param_2)
 */


undefined4 FUN_01029ca2(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *extraout_r1;
  uint uVar7;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  uint extraout_r2_07;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 *puVar8;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar9;
  undefined4 *extraout_r3_05;
  uint extraout_r3_06;
  uint uVar10;
  char *unaff_r4;
  int unaff_r5;
  undefined4 unaff_lr;
  undefined4 *puVar11;
  undefined8 uVar12;
  
  uVar1 = *param_1;
  uVar10 = (uint)uVar1;
  *param_2 = uVar1;
  uVar7 = (uint)(byte)param_1[1];
  uVar12 = FUN_010200cc();
  if ((int)uVar12 << 2 < 0) {
    iVar5 = FUN_0100a518(uVar1,8);
    if (iVar5 == 0) {
      return 2;
    }
    iVar6 = FUN_0101e890(iVar5);
    uVar12 = CONCAT44(iVar5,iVar6);
    if (iVar6 != 0) {
      do {
        iVar5 = (int)((ulonglong)uVar12 >> 0x20);
        pcVar4 = (char *)uVar12;
        *(undefined4 *)((int)register0x00000054 + -4) = unaff_lr;
        *(int *)((int)register0x00000054 + -8) = unaff_r5;
        *(char **)((int)register0x00000054 + -0xc) = unaff_r4;
        *(uint *)((int)register0x00000054 + -0x10) = uVar10;
        if (pcVar4 == (char *)0x0) {
          FUN_01009500(0x1a,0xb1,uVar7,uVar10);
          uVar7 = extraout_r2_01;
          iVar6 = extraout_r3_00;
LAB_0101e8fc:
          uVar12 = CONCAT44(unaff_r5,unaff_r4);
          FUN_01009500(0x1a,0xd8,uVar7,iVar6);
          uVar3 = extraout_r2_02;
          uVar9 = extraout_r3_01;
        }
        else {
          if (pcVar4[0xc6] != '*') {
            return 0xc;
          }
          if (uVar7 == 0) {
            pcVar4[0xc6] = '+';
            iVar5 = unaff_r5;
LAB_0101e8ba:
            iVar6 = (int)pcVar4[0x104];
            unaff_r4 = pcVar4;
            unaff_r5 = iVar5;
            if (-1 < iVar6) {
              return 0;
            }
            goto LAB_0101e8fc;
          }
          pcVar4[0x14a] = (char)uVar7;
          pcVar4[0x14b] = '\x1f';
          pcVar4[0xc6] = '0';
          if (iVar5 == 0) goto LAB_0101e8ba;
          pcVar2 = (char *)FUN_0100a518(*(ushort *)(iVar5 + 0x17e),7);
          uVar3 = extraout_r2;
          uVar9 = extraout_r3;
          if (pcVar2 != (char *)0x0) {
            FUN_0101e784(pcVar2,iVar5);
            uVar7 = extraout_r2_00;
            goto LAB_0101e8ba;
          }
        }
        unaff_r5 = (int)((ulonglong)uVar12 >> 0x20);
        FUN_01009500(0x1a,0xd3,uVar3,uVar9);
        puVar11 = (undefined4 *)((int)register0x00000054 + -0x14);
        *puVar11 = 0x101e90d;
        register0x00000054 = (BADSPACEBASE *)((int)register0x00000054 + -0x18);
        *(int *)register0x00000054 = (int)uVar12;
        iVar5 = FUN_0102a388((int)(extraout_r1 + 0x20));
        uVar3 = extraout_r2_03;
        uVar9 = extraout_r3_02;
        if (iVar5 == 0) {
          puVar8 = *(undefined4 **)(extraout_r1 + 0x74);
          if (*extraout_r1 == '\x01') {
            if (puVar8 != (undefined4 *)0x0) {
              while( true ) {
                uVar1 = *(ushort *)((int)puVar8 + -0x61);
                *(undefined4 *)(extraout_r1 + 0x74) = *puVar8;
                iVar5 = FUN_0100a564(uVar1,8);
                if (iVar5 != 0) break;
                puVar8 = *(undefined4 **)(extraout_r1 + 0x74);
                if (puVar8 == (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101e940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  uVar3 = (*(code *)*puVar11)();
                  return uVar3;
                }
              }
              FUN_01009500(0x11,0x44,extraout_r2_04,extraout_r3_03);
              uVar3 = extraout_r2_05;
              uVar9 = extraout_r3_04;
              goto LAB_0101e94a;
            }
LAB_0101e924:
                    /* WARNING: Could not recover jumptable at 0x0101e924. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (*(code *)*puVar11)();
            return uVar3;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0101e924;
        }
        else {
LAB_0101e94a:
          FUN_01009500(0x11,0x39,uVar3,uVar9);
          uVar3 = extraout_r2_06;
          puVar8 = extraout_r3_05;
        }
        unaff_lr = 0x101e95b;
        uVar12 = FUN_01009500(0x11,0x4c,uVar3,puVar8);
        uVar7 = extraout_r2_07;
        uVar10 = extraout_r3_06;
        unaff_r4 = extraout_r1;
      } while( true );
    }
  }
  return 0xc;
}


