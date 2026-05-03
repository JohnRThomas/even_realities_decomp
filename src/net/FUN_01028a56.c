/*
 * Function: FUN_01028a56
 * Entry:    01028a56
 * Prototype: uint __stdcall FUN_01028a56(void)
 */


uint FUN_01028a56(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0x23;
  uVar6 = 0;
  do {
    uVar2 = FUN_0100fe6c();
    bVar1 = FUN_0101eb98(uVar2);
    iVar3 = 0;
    uVar4 = extraout_r2;
    uVar5 = extraout_r3;
    if (bVar1) {
      iVar3 = FUN_01028934(uVar2,0,extraout_r2);
      uVar4 = extraout_r2_00;
      uVar5 = extraout_r3_00;
      if (iVar3 != 0) goto LAB_01028a8e;
      iVar3 = FUN_0101ec04(uVar2);
      uVar4 = extraout_r2_01;
      uVar5 = extraout_r3_01;
      uVar6 = uVar2;
    }
    while ((iVar7 = iVar7 + -1, iVar7 == 0 || (iVar3 != 0))) {
      if (uVar6 != 0) {
        return uVar6;
      }
      FUN_01009500(0xf,0x20a,uVar4,uVar5);
      uVar4 = extraout_r2_02;
      uVar5 = extraout_r3_02;
LAB_01028a8e:
      iVar3 = 0;
    }
  } while( true );
}


