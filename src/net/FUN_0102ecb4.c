/*
 * Function: FUN_0102ecb4
 * Entry:    0102ecb4
 * Prototype: undefined __stdcall FUN_0102ecb4(undefined4 * param_1, uint param_2, uint param_3, uint param_4, undefined4 param_5, byte param_6, byte * param_7, byte * param_8, uint param_9, uint param_10)
 */


void FUN_0102ecb4(undefined4 *param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                 byte param_6,byte *param_7,byte *param_8,uint param_9,uint param_10)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar6;
  uint extraout_r2_03;
  uint extraout_r2_04;
  uint extraout_r2_05;
  uint extraout_r2_06;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  uint uVar7;
  uint uVar8;
  uint local_38;
  byte *local_34;
  
  uVar7 = (uint)param_6;
  local_34 = param_8;
  local_38 = param_9;
  if (uVar7 == 0) {
    if (param_4 == 1) {
      if (param_7 != (byte *)0x0) {
        uVar4 = 0x102ec61;
LAB_0102ee44:
        param_2 = 0;
        goto LAB_0102ee22;
      }
    }
    else if (param_7 != (byte *)0x0) {
      uVar4 = 0x103ab1f;
      goto LAB_0102ee44;
    }
    if (param_9 != 0) {
      param_2 = 0;
      goto LAB_0102ee56;
    }
  }
  else {
    if (uVar7 < 5) goto LAB_0102ecf2;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_output.c"
                 ,0x1bf,param_9);
    while( true ) {
      FUN_0103a370();
LAB_0102ecf2:
      uVar1 = FUN_0103aa88();
      if (uVar1 == 0) {
        iVar2 = 0;
        uVar4 = extraout_r3;
      }
      else {
        iVar2 = FUN_0102ec20(param_1,(byte *)"%s ",uVar1,extraout_r3);
        uVar4 = extraout_r3_00;
      }
      if ((param_10 & 2) != 0) {
        if ((param_10 & 0x44) == 0) {
          iVar3 = FUN_0102ec20(param_1,(byte *)"[%08lu] ",param_2,uVar4);
        }
        else {
          iVar3 = 0;
          if (DAT_21004674 != 0) {
            uVar1 = (param_2 / DAT_21004670) / DAT_21004674;
            iVar3 = FUN_0102ec20(param_1,(byte *)"[%02u:%02u:%02u.%03u,%03u] ",uVar1 / 0xe10,
                                 (uVar1 % 0xe10) / 0x3c);
          }
        }
        iVar2 = iVar2 + iVar3;
      }
      if ((param_10 & 1) != 0) {
        pcVar5 = *(char **)(&DAT_0103c8e4 + uVar7 * 4);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = "\x1b[0m";
        }
        FUN_0102ec20(param_1,(byte *)"%s",(uint)pcVar5,"\x1b[0m");
      }
      if ((param_10 & 8) == 0) {
        uVar1 = param_10 & 8;
      }
      else {
        uVar1 = FUN_0102ec20(param_1,(byte *)"<%s> ",*(uint *)(&DAT_0103c8f8 + uVar7 * 4),
                             &DAT_0103c8f8);
      }
      uVar4 = 0;
      if (param_3 != 0) {
        iVar3 = FUN_0102ec20(param_1,(byte *)"%s/",param_3,param_3);
        uVar1 = uVar1 + iVar3;
        uVar4 = extraout_r3_01;
      }
      if (param_4 != 0) {
        iVar3 = FUN_0102ec20(param_1,(byte *)"%s: ",param_4,uVar4);
        uVar1 = uVar1 + iVar3;
      }
      param_2 = uVar1 + iVar2;
      if (param_7 == (byte *)0x0) {
        if (param_9 != 0) goto LAB_0102ee56;
        goto LAB_0102ed8c;
      }
      uVar4 = 0x102ec61;
LAB_0102ee22:
      iVar2 = FUN_01039e2e(uVar4,(undefined *)0x103020d,param_1,param_7);
      if (-1 < iVar2) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/subsys/logging/log_output.c",0x219,extraout_r3_02);
    }
joined_r0x0102ee4c:
    if (local_38 != 0) {
LAB_0102ee56:
      uVar1 = local_38;
      if (0xf < local_38) {
        uVar1 = 0x10;
      }
      FUN_0102ec44(param_1,param_10);
      uVar6 = extraout_r2;
      uVar4 = extraout_r3_03;
      for (iVar2 = 0; iVar2 < (int)param_2; iVar2 = iVar2 + 1) {
        FUN_0102ec20(param_1,(byte *)0x103e7d4,uVar6,uVar4);
        uVar6 = extraout_r2_05;
        uVar4 = extraout_r3_10;
      }
      FUN_0102ec20(param_1,(byte *)"%02x ",(uint)*local_34,local_34);
      uVar8 = 1;
      uVar6 = extraout_r2_00;
      uVar4 = extraout_r3_04;
      do {
        if ((uVar8 & 7) == 0) {
          FUN_0102ec20(param_1,(byte *)0x103e7d4,uVar6,uVar4);
          uVar6 = extraout_r2_01;
          uVar4 = extraout_r3_05;
        }
        if (uVar8 < uVar1) {
          FUN_0102ec20(param_1,(byte *)"%02x ",(uint)local_34[uVar8],local_34);
          uVar6 = extraout_r2_02;
          uVar4 = extraout_r3_06;
        }
        else {
          FUN_0102ec20(param_1,(byte *)0x103e7d2,uVar6,uVar4);
          uVar6 = extraout_r2_06;
          uVar4 = extraout_r3_11;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 != 0x10);
      uVar8 = 0;
      FUN_0102ec20(param_1,(byte *)"|",uVar6,uVar4);
      do {
        uVar6 = (uint)local_34[uVar8];
        if (((&DAT_0103eb93)[uVar6] & 0x97) == 0) {
          uVar6 = 0x2e;
        }
        FUN_0102ec20(param_1,(byte *)"%c",uVar6,&DAT_0103eb93);
        uVar6 = extraout_r2_03;
        uVar4 = extraout_r3_07;
        while( true ) {
          uVar8 = uVar8 + 1;
          if (uVar8 == 0x10) {
            local_34 = local_34 + uVar1;
            local_38 = local_38 - uVar1;
            goto joined_r0x0102ee4c;
          }
          if ((uVar8 & 7) == 0) {
            FUN_0102ec20(param_1,(byte *)0x103e7d4,uVar6,uVar4);
            uVar4 = extraout_r3_08;
          }
          if (uVar8 < uVar1) break;
          FUN_0102ec20(param_1,(byte *)0x103e7d4,uVar8,uVar4);
          uVar6 = extraout_r2_04;
          uVar4 = extraout_r3_09;
        }
      } while( true );
    }
    if (uVar7 != 0) {
LAB_0102ed8c:
      if ((int)(param_10 << 0x1f) < 0) {
        FUN_0102ec20(param_1,(byte *)"%s",(uint)"\x1b[0m",param_10 << 0x1f);
      }
      FUN_0102ec44(param_1,param_10);
    }
  }
  FUN_0103ab04(param_1);
  return;
}


