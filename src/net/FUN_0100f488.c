/*
 * Function: FUN_0100f488
 * Entry:    0100f488
 * Prototype: uint __stdcall FUN_0100f488(char * param_1, undefined4 param_2, int * param_3)
 */


uint FUN_0100f488(char *param_1,undefined4 param_2,int *param_3)

{
  ushort uVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  uint extraout_r1_04;
  undefined4 extraout_r2;
  int *extraout_r2_00;
  undefined4 extraout_r2_01;
  int *extraout_r2_02;
  int *extraout_r2_03;
  undefined4 extraout_r2_04;
  int *extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar7;
  int *extraout_r2_07;
  int *extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 *puVar8;
  int iVar9;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  code *extraout_r3_02;
  code *pcVar10;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar11;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  int extraout_r3_07;
  uint uVar12;
  ulonglong uVar13;
  
  do {
    piVar2 = DAT_21000ed0;
    if ((((char)DAT_21000ed0[2] == '\x10') && (DAT_21000ec2._1_1_ != '\0')) && (DAT_21000ec4 == 0))
    {
      return 0;
    }
    do {
      while( true ) {
        DAT_21000ed0 = piVar2;
        if ((DAT_21000edc != (int *)0x0) && ((char)DAT_21000edc[2] != '\0')) goto LAB_0100f4ca;
        if ((char)DAT_21000ed0[2] == '\x01') {
          return 0;
        }
        iVar9 = 0;
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          iVar9 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        param_3 = (int *)*DAT_21000ed0;
        if (iVar9 != 0) break;
        enableIRQinterrupts();
        piVar2 = param_3;
        if ((char)DAT_21000ed0[2] != '\0') goto LAB_0100f4c8;
      }
      piVar2 = param_3;
    } while ((char)DAT_21000ed0[2] == '\0');
LAB_0100f4c8:
    DAT_21000edc = DAT_21000ed0;
    DAT_21000ed0 = param_3;
LAB_0100f4ca:
    piVar2 = DAT_21000edc;
    uVar12 = (uint)*(byte *)(DAT_21000edc + 2);
    *(undefined1 *)(DAT_21000edc + 2) = 5;
    switch(uVar12) {
    case 2:
      uVar7 = 0;
      if ((code *)piVar2[1] != (code *)0x0) {
        (*(code *)piVar2[1])(piVar2,param_1);
        uVar12 = 4;
        param_2 = extraout_r1_03;
        goto LAB_0100f526;
      }
      goto LAB_0100f67c;
    case 3:
      uVar7 = 0;
      if ((code *)piVar2[1] == (code *)0x0) goto LAB_0100f6aa;
      uVar13 = (*(code *)piVar2[1])(piVar2,param_1);
      param_2 = (undefined4)(uVar13 >> 0x20);
      uVar12 = (uint)uVar13 & 0xff;
      if (((uint)uVar13 << 0x10) >> 0x18 != 1) goto LAB_0100f526;
      *(undefined1 *)(piVar2 + 2) = 3;
      param_3 = extraout_r2_02;
      if ((uVar13 & 0xff) != 0) {
        return uVar12;
      }
      break;
    case 4:
      uVar7 = 0;
      if ((code *)piVar2[1] != (code *)0x0) {
        (*(code *)piVar2[1])(piVar2);
        uVar12 = 0;
        param_2 = extraout_r1_02;
        goto LAB_0100f526;
      }
      goto LAB_0100f6a0;
    default:
      FUN_01009500(0x10,0x247,param_3,uVar12 - 2);
      DAT_21000edc = (int *)0x0;
      return 4;
    case 7:
    case 9:
    case 0xc:
    case 0xd:
    case 0xe:
      if (DAT_21000058 != (code *)0x0) {
        (*DAT_21000058)(piVar2[1],param_1,uVar12);
        param_2 = extraout_r1;
        if (uVar12 == 0xd) {
          DAT_21000edc = (int *)0x0;
          return 4;
        }
        goto LAB_0100f524;
      }
      goto LAB_0100f596;
    case 8:
      uVar7 = 0;
      if ((ushort *)piVar2[1] == (ushort *)0x0) goto LAB_0100f690;
      uVar1 = *(ushort *)piVar2[1];
      psVar5 = (short *)FUN_0100a97c(uVar1,param_2,param_3);
      uVar7 = extraout_r2_01;
      uVar11 = extraout_r3_00;
      if (psVar5 != (short *)0x0) {
        *(ushort *)(param_1 + 3) = uVar1;
        *param_1 = '\r';
        param_1[6] = '\0';
        param_1[5] = '\x01';
        param_1[2] = '\x01';
        FUN_01027494(psVar5,(undefined4 *)0x0);
        DAT_21000edc = (int *)0x0;
        return 4;
      }
      goto LAB_0100f698;
    case 10:
    case 0xb:
      if (DAT_2100005c == (code *)0x0) goto LAB_0100f596;
      iVar9 = piVar2[1];
      (*DAT_2100005c)(iVar9,param_1,uVar12);
      if ((*param_1 != '\x1d') &&
         ((param_2 = extraout_r1_00, *param_1 != '\x1a' || (param_1[2] == '\0'))))
      goto LAB_0100f524;
      iVar9 = FUN_0100a564(*(ushort *)(iVar9 + 8),4);
      if (iVar9 == 0) {
        DAT_21000edc = (int *)0x0;
        return 4;
      }
      FUN_01009500(0x10,0x1e8,extraout_r2,extraout_r3);
      param_3 = extraout_r2_00;
    case 6:
      if ((code *)piVar2[1] == (code *)0x0) {
        FUN_01009500(0x10,0x20e,param_3,0);
        param_3 = extraout_r2_03;
        uVar7 = extraout_r3_01;
LAB_0100f67c:
        FUN_01009500(0x10,0x1c0,param_3,uVar7);
        uVar7 = extraout_r2_04;
        pcVar10 = extraout_r3_02;
LAB_0100f686:
        FUN_01009500(0x10,0x23d,uVar7,pcVar10);
        param_3 = extraout_r2_05;
        uVar7 = extraout_r3_03;
LAB_0100f690:
        FUN_01009500(0x10,0xe3,param_3,uVar7);
        uVar7 = extraout_r2_06;
        uVar11 = extraout_r3_04;
LAB_0100f698:
        FUN_01009500(0x10,0xc5,uVar7,uVar11);
        param_3 = extraout_r2_07;
        uVar7 = extraout_r3_05;
LAB_0100f6a0:
        FUN_01009500(0x10,0x1d3,param_3,uVar7);
        param_3 = extraout_r2_08;
        uVar7 = extraout_r3_06;
LAB_0100f6aa:
        FUN_01009500(0x10,0x1c9,param_3,uVar7);
        puVar6 = (undefined4 *)(extraout_r3_07 * 2);
        if (*(byte *)(puVar6 + 2) != 0) {
          FUN_0100f3b8(puVar6,0,extraout_r2_09,(uint)*(byte *)(puVar6 + 2));
          uVar12 = extraout_r1_04;
          while( true ) {
            puVar6 = (undefined4 *)(uVar12 >> 0x1b);
            uVar12 = 0;
            if (*(char *)(puVar6 + 2) == '\0') break;
            *(undefined1 *)(puVar6 + 2) = 3;
          }
          puVar6[1] = 0;
          *(undefined1 *)(puVar6 + 2) = 3;
          iVar9 = 0;
          bVar4 = (bool)isCurrentModePrivileged();
          if (bVar4) {
            iVar9 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          *puVar6 = &DAT_21000ed0;
          uVar12 = 0;
          if ((DAT_21000ed0 == (int *)0x0) ||
             (uVar12 = (uint)*(byte *)(DAT_21000ed0 + 2), puVar8 = &DAT_21000ed0, uVar12 != 1)) {
            puVar8 = DAT_21000ecc;
          }
          *puVar8 = puVar6;
          if (iVar9 == 0) {
            enableIRQinterrupts();
          }
          DAT_21000ecc = puVar6;
          uVar12 = FUN_0102603c((uint)DAT_21000ec8,uVar12,puVar8,0x21000ec8);
          return uVar12;
        }
        puVar6[1] = 0;
        *(undefined1 *)(puVar6 + 2) = 3;
        iVar9 = 0;
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          iVar9 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        *puVar6 = &DAT_21000ed0;
        uVar12 = 0;
        if ((DAT_21000ed0 == (int *)0x0) ||
           (uVar12 = (uint)*(byte *)(DAT_21000ed0 + 2), puVar8 = &DAT_21000ed0, uVar12 != 1)) {
          puVar8 = DAT_21000ecc;
        }
        *puVar8 = puVar6;
        if (iVar9 == 0) {
          enableIRQinterrupts();
        }
        DAT_21000ecc = puVar6;
        uVar12 = FUN_0102603c((uint)DAT_21000ec8,uVar12,puVar8,0x21000ec8);
        return uVar12;
      }
      (*(code *)piVar2[1])(piVar2,param_1);
      cVar3 = FUN_0101bf4c();
      if ((cVar3 != '\0') || (bVar4 = FUN_01019458(), param_2 = extraout_r1_01, bVar4)) {
        DAT_21000edc = (int *)0x0;
        return 4;
      }
LAB_0100f596:
      uVar12 = 0;
      param_3 = (int *)0x0;
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        param_3 = (int *)isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      cVar3 = (char)piVar2[2];
joined_r0x0100f5a2:
      if ((cVar3 == '\x05') || (cVar3 == '\0')) {
        *(undefined1 *)(piVar2 + 2) = 0;
        DAT_21000edc = (int *)0x0;
        if (param_3 == (int *)0x0) {
          enableIRQinterrupts();
        }
        if (uVar12 != 0) {
          DAT_21000edc = (int *)0x0;
          return uVar12;
        }
      }
      else if (param_3 == (int *)0x0) {
        enableIRQinterrupts();
      }
      break;
    case 0xf:
      *param_1 = '\x1e';
      *(undefined4 *)(param_1 + 3) = *(undefined4 *)((int)piVar2 + 9);
LAB_0100f524:
      uVar12 = 4;
LAB_0100f526:
      param_3 = (int *)0x0;
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        param_3 = (int *)isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      cVar3 = (char)piVar2[2];
      goto joined_r0x0100f5a2;
    case 0x10:
      if (DAT_21000054 == (code *)0x0) {
        DAT_21000edc = (int *)0x0;
        return 2;
      }
      uVar7 = 0;
      pcVar10 = DAT_21000054;
      if ((undefined2 *)piVar2[1] != (undefined2 *)0x0) {
        (*DAT_21000054)(*(undefined2 *)piVar2[1],param_1);
        DAT_21000edc = (int *)0x0;
        return 2;
      }
      goto LAB_0100f686;
    }
  } while( true );
}


