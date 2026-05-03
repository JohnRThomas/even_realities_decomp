/*
 * Function: FUN_01028d76
 * Entry:    01028d76
 * Prototype: uint __stdcall FUN_01028d76(char * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0101b94a) */

uint FUN_01028d76(char *param_1)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar9;
  undefined4 extraout_r2_03;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar10;
  undefined4 extraout_r3_03;
  int iVar11;
  uint uVar12;
  code *UNRECOVERED_JUMPTABLE;
  byte abStack_30 [28];
  
  if (*param_1 == '\x01') {
    bVar2 = FUN_01019458();
    if (bVar2) {
      uVar7 = 0x3a;
    }
    else {
      cVar3 = FUN_01019704();
      if (cVar3 == '\0') {
        uVar7 = 0x12;
      }
      else {
        FUN_01019728();
        uVar7 = func_0x01019918();
        cVar3 = DAT_210010a0;
        if (uVar7 == 0) {
          uVar1 = *(ushort *)(param_1 + 2);
          if (*(short *)(param_1 + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0101b920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar7 = (*UNRECOVERED_JUMPTABLE)(0x11);
            return uVar7;
          }
          if (DAT_210010a0 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0101b916. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar7 = (*UNRECOVERED_JUMPTABLE)(0xc);
            return uVar7;
          }
          pbVar4 = FUN_01019a04();
          DAT_210010a1 = cVar3;
          DAT_210010a0 = 4;
          DAT_210010ce = cVar3;
          DAT_21001114 = 0;
          iVar5 = FUN_0101a930();
          uVar7 = 0;
          iVar11 = 0;
          uVar12 = 0;
          do {
            iVar8 = uVar7 + 2;
            uVar12 = uVar12 + 1;
            uVar7 = uVar12 & 0xff;
            iVar11 = iVar11 + *(int *)(&DAT_210010a0 + iVar8 * 4) + iVar5;
          } while (uVar7 <= DAT_210010cf);
          DAT_210010f8 = iVar11;
          uVar7 = FUN_01023634(0x101b321,0);
          *pbVar4 = (byte)uVar7;
          uVar9 = extraout_r2;
          uVar10 = extraout_r3;
          if (uVar7 != 0x20) {
            pbVar6 = FUN_0101ab8c(abStack_30,1,(uint *)0x0,(uint *)(uint)uVar1);
            uVar9 = extraout_r2_00;
            uVar10 = extraout_r3_00;
            if (pbVar6 != (byte *)0x0) {
              uVar7 = FUN_010239c8((uint)*pbVar4,abStack_30);
              if (uVar7 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0101b90c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                uVar7 = (*UNRECOVERED_JUMPTABLE)(0);
                return uVar7;
              }
              FUN_01009500(0x21,0x369,extraout_r2_01,extraout_r3_01);
              uVar9 = extraout_r2_02;
              uVar10 = extraout_r3_02;
            }
            FUN_01009500(0x21,0x368,uVar9,uVar10);
            uVar9 = extraout_r2_03;
            uVar10 = extraout_r3_03;
          }
          FUN_01009500(0x21,0x366,uVar9,uVar10);
          uVar7 = (iVar11 >> 2) - (int)(uint)uVar1;
          if (uVar7 < *(int *)(pbVar4 + 0x38) - 0x11aU) {
            uVar12 = 1;
          }
          else {
            uVar12 = 0;
            iVar11 = FUN_0101aa18();
            if (iVar11 != 0) {
              return (uint)(uVar7 < *(int *)(pbVar4 + 0x38) - 0x11aU);
            }
          }
          return uVar12;
        }
      }
    }
  }
  else {
    cVar3 = FUN_0101bf4c();
    if ((cVar3 != '\x05') && (uVar7 = FUN_0101b538(), uVar7 == 0)) {
      return 0;
    }
    uVar7 = 0xc;
  }
  return uVar7;
}


