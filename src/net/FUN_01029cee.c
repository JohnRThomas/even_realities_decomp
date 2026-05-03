/*
 * Function: FUN_01029cee
 * Entry:    01029cee
 * Prototype: undefined __stdcall FUN_01029cee(void)
 */


void FUN_01029cee(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 uVar4;
  undefined4 extraout_r3_00;
  
  iVar1 = FUN_01014248();
  if (iVar1 == 0) goto LAB_01029d00;
  uVar2 = 0x117;
  uVar3 = extraout_r2;
  uVar4 = extraout_r3;
  while( true ) {
    FUN_01009500(1,uVar2,uVar3,uVar4);
LAB_01029d00:
    iVar1 = FUN_01012978();
    if (iVar1 == 0) break;
    uVar2 = 0x11c;
    uVar3 = extraout_r2_00;
    uVar4 = extraout_r3_00;
  }
  FUN_01027d4c(2);
  return;
}


