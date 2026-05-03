/*
 * Function: FUN_01009a24
 * Entry:    01009a24
 * Prototype: uint __stdcall FUN_01009a24(byte * param_1, undefined4 param_2, int * param_3)
 */


uint FUN_01009a24(byte *param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined *extraout_r2;
  undefined *puVar5;
  int *extraout_r2_00;
  undefined *extraout_r2_01;
  int *extraout_r2_02;
  int *piVar6;
  undefined *extraout_r2_03;
  int *extraout_r2_04;
  int *extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar7;
  undefined4 extraout_r3_01;
  undefined8 uVar8;
  byte *local_18;
  undefined4 local_14;
  
  DAT_21000a6c = param_1 + 4;
  local_18 = param_1;
  local_14 = param_2;
LAB_01009a2e:
  do {
    do {
      uVar2 = FUN_0100f488((char *)&DAT_21000a6c,param_2,param_3);
      if (uVar2 == 2) {
        FUN_0102682e(param_1,&DAT_21000a6c);
        return 2;
      }
      if (uVar2 != 4) {
        if (uVar2 != 8) {
          return uVar2;
        }
        FUN_0102689e(param_1,&DAT_21000a6c);
        return 8;
      }
      if (((uint)DAT_21000a6c & 0xff) != 9) {
        puVar5 = extraout_r2;
        if (((uint)DAT_21000a6c & 0xff) == 0x25) goto LAB_01009a94;
        goto LAB_01009a56;
      }
      iVar3 = FUN_010267d4(0x3e,5);
      puVar5 = extraout_r2_01;
      if (iVar3 != 0) goto LAB_01009a56;
      local_18 = (byte *)CONCAT22(local_18._2_2_,
                                  CONCAT11((undefined1)DAT_21000a70,DAT_21000a6c._3_1_));
      cVar1 = FUN_01026ffe((ushort *)&local_18,(ushort *)&local_14);
      param_2 = extraout_r1_00;
      param_3 = extraout_r2_02;
    } while (cVar1 == '\0');
    uVar4 = 0x53;
    piVar6 = extraout_r2_02;
    uVar7 = extraout_r3_00;
    while( true ) {
      while( true ) {
        FUN_01009500(8,uVar4,piVar6,uVar7);
LAB_01009a94:
        iVar3 = FUN_010267d4(0x3e,0x1a);
        puVar5 = extraout_r2_03;
        if (iVar3 != 0) break;
        local_14._0_3_ = CONCAT12(0x11,(short)((uint)DAT_21000a70 >> 8));
        iVar3 = src/*FUN_01029ca2((ushort *)&local_14,(ushort *)&local_18);
        param_2 = extraout_r1_01;
        param_3 = extraout_r2_04;
        if (iVar3 == 0) goto LAB_01009a2e;
        uVar4 = 0x65;
        piVar6 = extraout_r2_04;
        uVar7 = extraout_r3_01;
      }
LAB_01009a56:
      uVar2 = FUN_01026922((undefined4 *)param_1,(byte *)&DAT_21000a6c,puVar5);
      if (uVar2 < 0x102) break;
      uVar4 = 0x72;
      piVar6 = extraout_r2_00;
      uVar7 = extraout_r3;
    }
    param_2 = extraout_r1;
    param_3 = extraout_r2_00;
    if (uVar2 != 0) {
      uVar8 = FUN_010267d4((uint)*param_1,(uint)param_1[2]);
      param_2 = (undefined4)((ulonglong)uVar8 >> 0x20);
      param_3 = extraout_r2_05;
      if ((int)uVar8 != 0) {
        return 4;
      }
    }
  } while( true );
}


