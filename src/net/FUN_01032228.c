/*
 * Function: FUN_01032228
 * Entry:    01032228
 * Prototype: int __stdcall FUN_01032228(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_01032228(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar4;
  undefined4 extraout_r1_01;
  undefined4 *extraout_r2;
  undefined4 *extraout_r2_00;
  undefined4 *puVar5;
  undefined4 *extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar6;
  undefined4 extraout_r3_01;
  int iVar7;
  undefined1 *local_50;
  char *local_4c;
  char *local_48;
  undefined2 local_44;
  undefined1 *local_40;
  undefined4 auStack_3c [5];
  undefined1 *local_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  byte local_18 [4];
  char *local_14;
  
  FUN_010373ac(&DAT_21004974,0x103af23,param_3,param_4);
  FUN_01032e40();
  FUN_01009854(auStack_3c);
  local_4c = "%s";
  local_48 = "SoftDevice Controller build revision: ";
  local_44 = 0x200;
  local_50 = &DAT_01000003;
  FUN_0102ea44(0x103c004,0x1401cc0,(byte *)&local_50,(undefined1 *)auStack_3c);
  bVar1 = FUN_0103b8b0(0x103bf30);
  if (!bVar1) {
    local_14 = "Entropy source device not ready";
    local_18[0] = 2;
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    FUN_0102ea44(0x103c004,0x1040,local_18,(undefined1 *)0x0);
    return -0x13;
  }
  local_28 = &LAB_01032058_1;
  puStack_24 = &LAB_010320a8_1;
  puStack_20 = &LAB_0103200c_1;
  iVar2 = FUN_010099e8(&local_28);
  if (iVar2 != 0) {
    local_4c = "Failed to register rand source (%d)";
    local_50 = (undefined1 *)0x3;
    local_48 = (char *)iVar2;
    FUN_0102ea44(0x103c004,0x1840,(byte *)&local_50,(undefined1 *)0x0);
    return -0x16;
  }
  iVar2 = FUN_01031fc4(0xffffffff,0xffffffff);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_010099cc(3);
  uVar4 = extraout_r1;
  puVar5 = extraout_r2;
  uVar6 = extraout_r3;
  if (iVar2 == 0) {
    iVar7 = FUN_010097d4(0x1032099,0x21002b90);
    iVar3 = iVar7;
    uVar4 = extraout_r1_00;
    puVar5 = extraout_r2_00;
    uVar6 = extraout_r3_00;
    if (iVar7 == 0) {
      local_40 = &DAT_003d0900;
      iVar2 = thunk_FUN_0101fe50((uint *)&local_40,extraout_r1_00,extraout_r2_00);
      iVar3 = 0;
      uVar4 = extraout_r1_01;
      puVar5 = extraout_r2_01;
      uVar6 = extraout_r3_01;
      if (iVar2 != 0) goto LAB_010322e4;
    }
    FUN_01031fd4(iVar3,uVar4,puVar5,uVar6);
  }
  else {
LAB_010322e4:
    FUN_01031fd4(iVar2,uVar4,puVar5,uVar6);
    iVar7 = -0x86;
  }
  return iVar7;
}


