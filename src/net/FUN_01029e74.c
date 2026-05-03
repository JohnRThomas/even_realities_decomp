/*
 * Function: FUN_01029e74
 * Entry:    01029e74
 * Prototype: byte __stdcall FUN_01029e74(int param_1, undefined1 * param_2)
 */


byte FUN_01029e74(int param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 uVar5;
  undefined4 extraout_r3_00;
  ushort local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined2 local_1c;
  byte local_18 [4];
  int local_14;
  
  bVar1 = FUN_0100f124();
  if (bVar1 == 0) {
    *param_2 = 0x30;
    *(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 9);
    local_18[0] = 4;
  }
  else {
    local_20 = *(ushort *)(param_1 + -0x1f5);
    iVar2 = FUN_0100d7c0(local_20,local_18);
    if (iVar2 == 0) goto LAB_01029e9e;
    uVar3 = 0x2e;
    uVar4 = extraout_r2;
    uVar5 = extraout_r3;
    while( true ) {
      FUN_01009500(0x7e,uVar3,uVar4,uVar5);
LAB_01029e9e:
      local_1e = *(undefined1 *)(local_14 + 0x6a);
      local_1d = *(undefined1 *)(local_14 + 0x6b);
      local_1c = *(undefined2 *)(local_14 + 0x6c);
      iVar2 = FUN_01028f8a(&local_20,2);
      if (iVar2 == 0) break;
      uVar3 = 0x44;
      uVar4 = extraout_r2_00;
      uVar5 = extraout_r3_00;
    }
    local_18[0] = 0;
  }
  return local_18[0];
}


