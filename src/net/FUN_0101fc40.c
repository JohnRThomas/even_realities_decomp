/*
 * Function: FUN_0101fc40
 * Entry:    0101fc40
 * Prototype: int __stdcall FUN_0101fc40(char * param_1, byte * param_2)
 */


int FUN_0101fc40(char *param_1,byte *param_2)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  undefined *puVar9;
  undefined4 extraout_r2;
  undefined4 uVar10;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 uVar11;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  ushort *extraout_r3_02;
  ushort *extraout_r3_03;
  ushort *puVar12;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  int iVar13;
  undefined4 uStack_1c;
  
  uStack_1c = param_2;
  bVar2 = FUN_01012aa8(param_1);
  if (bVar2) {
    uVar6 = FUN_01012ec0((int)param_1);
    if ((uVar6 == 0) || (*(ushort *)(param_2 + 1) - 1 < 0x80)) {
      uVar6 = FUN_01012ec8((int)param_1);
      if ((uVar6 == 0) ||
         ((cVar3 = FUN_010149d4((int)param_1), cVar3 != '\0' ||
          (bVar4 = FUN_01012950((int)param_1), bVar4 != 0)))) {
        return 0xc;
      }
      iVar13 = FUN_01012b3c((int)param_1);
      if (iVar13 != 0) {
        uVar1 = *(ushort *)(param_2 + 1);
        FUN_01012e94((int)param_1,param_2[3]);
        iVar7 = FUN_0100a518((ushort)*param_2,3);
        iVar13 = FUN_0100a518((ushort)*param_2,5);
        if (iVar7 == 0) {
          if (iVar13 != 0) goto LAB_0101fcce;
          goto LAB_0101fdb6;
        }
        bVar2 = iVar13 == 0;
        cVar3 = '\0';
        iVar13 = iVar7;
        if (bVar2) goto LAB_0101fcd4;
        puVar9 = &DAT_00001747;
        uVar10 = extraout_r2;
        uVar11 = extraout_r3;
LAB_0101fcc8:
        do {
          while( true ) {
            iVar13 = FUN_01009500(0x39,puVar9,uVar10,uVar11);
LAB_0101fcce:
            cVar3 = *(char *)(iVar13 + 0xbd);
LAB_0101fcd4:
            if (DAT_210004dc == (code *)0x0) break;
            iVar13 = iVar13 + 0x40;
            bVar2 = FUN_0102a338(iVar13);
            if ((!bVar2) || (bVar2 = FUN_0102a324(iVar13), bVar2)) break;
            if (cVar3 == '\0') {
              iVar13 = (*DAT_210004dc)(iVar13,DAT_21000eb8,0);
              if (iVar13 == 0) break;
              puVar9 = &DAT_00001760;
              uVar10 = extraout_r2_01;
              uVar11 = extraout_r3_01;
            }
            else {
              iVar13 = (*DAT_210004d8)(iVar13);
              if (iVar13 == 0) break;
              puVar9 = &DAT_0000175b;
              uVar10 = extraout_r2_00;
              uVar11 = extraout_r3_00;
            }
          }
LAB_0101fdb6:
          uVar5 = FUN_01012eb0((int)param_1);
          if (uVar5 == 0) {
            iVar13 = FUN_0101434c((int)param_1,0,(uint)uVar1 * 10000);
            if (iVar13 == 0) {
              return 0;
            }
            puVar9 = &DAT_00001769;
            uVar10 = extraout_r2_05;
            uVar11 = extraout_r3_05;
            goto LAB_0101fcc8;
          }
          uVar6 = FUN_01012ec0((int)param_1);
          if (((uVar6 != 0) && (uVar6 = FUN_01012ee8((int)param_1), uVar6 == 0)) &&
             ((char)DAT_2100120c == '\0')) break;
          puVar8 = (ushort *)FUN_0100a3c4((ushort *)((int)&uStack_1c + 2),1);
          if (puVar8 == (ushort *)0x0) {
            return 0xd;
          }
          FUN_0100d7f4((undefined4 *)puVar8,0);
          *puVar8 = uStack_1c._2_2_;
          FUN_01012f14((int)param_1,(int)puVar8);
          uVar6 = FUN_01012ee8((int)param_1);
          if (uVar6 == 0) {
            bVar4 = FUN_01012f00((int)param_1);
            uVar6 = (uint)bVar4;
            uVar10 = extraout_r2_03;
            puVar12 = extraout_r3_03;
          }
          else {
            uVar6 = 1;
            uVar10 = extraout_r2_02;
            puVar12 = extraout_r3_02;
          }
          iVar13 = FUN_0101f0a0(puVar8,uVar6,uVar10,puVar12);
          if (iVar13 != 0) {
            return iVar13;
          }
          iVar13 = FUN_0101434c((int)param_1,(int)puVar8,(uint)uVar1 * 10000);
          if (iVar13 == 0) {
            if (DAT_2100122c == (code *)0x0) {
              return 0;
            }
            (*DAT_2100122c)(puVar8,puVar8 + 0xb1,0);
            return 0;
          }
          puVar9 = &DAT_0000178c;
          uVar10 = extraout_r2_04;
          uVar11 = extraout_r3_04;
        } while( true );
      }
    }
    iVar13 = 0x12;
  }
  else {
    iVar13 = 0x42;
  }
  return iVar13;
}


