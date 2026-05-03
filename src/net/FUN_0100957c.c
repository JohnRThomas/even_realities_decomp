/*
 * Function: FUN_0100957c
 * Entry:    0100957c
 * Prototype: undefined __stdcall FUN_0100957c(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0100957c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r3;
  undefined4 uVar4;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 local_14;
  uint local_10;
  ushort local_c;
  undefined2 uStack_a;
  
  _local_c = CONCAT22((short)((uint)param_4 >> 0x10),(ushort)DAT_21000a35._1_1_);
  local_10 = (uint)CONCAT12((undefined1)DAT_21000a35,CONCAT11(DAT_21000a35._3_1_,DAT_21000a35._2_1_)
                           );
  local_14 = param_2;
  iVar1 = FUN_0101fe24((char *)&local_10);
  if (iVar1 == 0) goto LAB_010095a8;
  uVar2 = 0xb3;
  uVar3 = extraout_r2;
  uVar4 = extraout_r3;
  while( true ) {
    while( true ) {
      while( true ) {
        FUN_01009500(3,uVar2,uVar3,uVar4);
LAB_010095a8:
        local_14 = CONCAT31(local_14._1_3_,1);
        iVar1 = FUN_01029c1c((char *)&local_14);
        if (iVar1 == 0) break;
        uVar2 = 0xb7;
        uVar3 = extraout_r2_00;
        uVar4 = extraout_r3_00;
      }
      iVar1 = FUN_0101fe74(DAT_21000a42);
      if (iVar1 == 0) break;
      uVar2 = 0xba;
      uVar3 = extraout_r2_01;
      uVar4 = extraout_r3_01;
    }
    iVar1 = FUN_0101fe68(DAT_21000a40._1_1_);
    if (iVar1 == 0) break;
    uVar2 = 0xbb;
    uVar3 = extraout_r2_02;
    uVar4 = extraout_r3_02;
  }
  return;
}


