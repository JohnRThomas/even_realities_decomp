/*
 * Function: FUN_01017028
 * Entry:    01017028
 * Prototype: undefined4 __stdcall FUN_01017028(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_01017028(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort *puVar7;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar8;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar9;
  char *pcVar10;
  uint extraout_r3;
  undefined *puVar11;
  undefined *extraout_r3_00;
  char cVar12;
  undefined1 auStack_38 [4];
  char *local_34;
  byte local_27;
  
  pbVar3 = (byte *)FUN_01009500(0x32,0x439,param_3,param_4);
  bVar1 = *pbVar3;
  FUN_0101a734(pbVar3,(int)auStack_38,bVar1 & 0xf);
  FUN_01020d00();
  iVar4 = FUN_0100df60();
  cVar2 = (char)iVar4;
  DAT_2100001c = cVar2;
  if ((((((bVar1 & 0xf) != 4) || (*local_34 != (char)DAT_21001019)) ||
       (local_34[1] != DAT_21001019._1_1_)) ||
      ((local_34[2] != DAT_21001019._2_1_ || (local_34[3] != DAT_21001019._3_1_)))) ||
     ((local_34[4] != (char)DAT_2100101d ||
      ((local_34[5] != DAT_2100101d._1_1_ || ((uint)local_27 != (uint)DAT_21001020)))))) {
                    /* WARNING: Could not recover jumptable at 0x0101705a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*(code *)0x1017035)(5);
    return uVar5;
  }
  if (iVar4 != 0x7f) {
    DAT_2100001c = 0x7f;
    FUN_0101a0cc((int)auStack_38,(uint)DAT_21001009,DAT_21001038,DAT_2100101f,cVar2);
                    /* WARNING: Could not recover jumptable at 0x010170d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*(code *)0x1017035)(5);
    return uVar5;
  }
  FUN_01017028((uint)DAT_21001020,&DAT_21000f90,&DAT_2100001c,0x7f);
  cVar2 = DAT_2100001c;
  uVar6 = extraout_r2 >> 0x1e;
  if (DAT_21001012 == '\0') {
switchD_010170f0_caseD_3:
    FUN_01020d00();
    return 5;
  }
  uVar9 = (uint)DAT_21000fe4;
  if (uVar9 == 2) {
    if (DAT_2100001c != '\x7f') {
      DAT_2100001c = 0x7f;
      FUN_01019f50(uVar6,(short *)0x0,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,cVar2);
      DAT_21001038 = 1;
      return 0xb;
    }
  }
  else {
    if (uVar9 != 1) {
      uVar8 = extraout_r2;
      if (uVar9 == 3) {
        pcVar10 = *(char **)(uVar6 + 4);
        if ((((((*pcVar10 == (char)DAT_21000fec) && (pcVar10[1] == DAT_21000fec._1_1_)) &&
              (pcVar10[2] == DAT_21000fec._2_1_)) &&
             (((pcVar10[3] == DAT_21000fec._3_1_ && (pcVar10[4] == (char)DAT_21000ff0)) &&
              ((pcVar10[5] == DAT_21000ff0._1_1_ && (*(char *)(uVar6 + 0x11) == DAT_21000feb))))))
            || (DAT_21000fe6 == '\x01')) ||
           ((DAT_2100100b != '\b' && (DAT_21001008 == DAT_2100100b)))) {
          return 0xc;
        }
        goto switchD_010170f0_caseD_3;
      }
      goto LAB_010174ba;
    }
    if (DAT_2100001c != '\x7f') {
      DAT_2100001c = 0x7f;
      FUN_01019f50(uVar6,(short *)0x0,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,cVar2);
      return 5;
    }
  }
  FUN_01017028(uVar6,0,(int)DAT_2100001c,&DAT_2100001c);
  uVar8 = extraout_r2_00;
  uVar9 = extraout_r3;
LAB_010174ba:
  puVar7 = (ushort *)FUN_01009500(0x32,0xed2,uVar8,uVar9);
  cVar2 = DAT_2100001c;
  if (DAT_2100001c == '\x7f') {
    FUN_01017028(puVar7,0,0x7f,&DAT_2100001c);
    puVar11 = &DAT_21000f90;
    if (DAT_21001000 < 5) {
      FUN_01009500(0x32,&DAT_0000164b,(uint)DAT_21001000,&DAT_21000f90);
      uVar6 = extraout_r2_02;
      puVar11 = extraout_r3_00;
    }
    else {
      uVar6 = (uint)DAT_21001000;
      if (uVar6 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0101755a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (**(code **)(*(int *)(DAT_21001054 + 0xc) + (DAT_21001000 + 0x3ffffffb) * 4))
                          (extraout_r2_01 >> 0x1e);
        return uVar5;
      }
    }
    FUN_01009500(0x32,&DAT_0000164c,uVar6,puVar11);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_2100001c = 0x7f;
  if (DAT_21001000 == 5) {
    cVar12 = '\0';
  }
  else if (DAT_21001000 == 8) {
    cVar12 = '\x03';
  }
  else {
    cVar12 = '\x01';
  }
  uVar6 = FUN_0101a2a0(puVar7,0,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009,cVar2,
                       cVar12);
  if (uVar6 != 0) {
    uVar5 = FUN_01019e60();
    return uVar5;
  }
  return 0;
}


