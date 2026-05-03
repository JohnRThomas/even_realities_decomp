/*
 * Function: FUN_01029d58
 * Entry:    01029d58
 * Prototype: undefined __stdcall FUN_01029d58(void)
 */


void FUN_01029d58(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 uVar5;
  undefined4 extraout_r3_00;
  
  uVar1 = FUN_0101b650();
  if (uVar1 == 0) goto LAB_01029d6a;
  uVar3 = 0x155;
  uVar4 = extraout_r2;
  uVar5 = extraout_r3;
  while( true ) {
    FUN_01009500(1,uVar3,uVar4,uVar5);
LAB_01029d6a:
    iVar2 = FUN_0101c3a8();
    if (iVar2 == 0) break;
    uVar3 = 0x156;
    uVar4 = extraout_r2_00;
    uVar5 = extraout_r3_00;
  }
  iVar2 = FUN_0101f160();
  FUN_010194ac((char)iVar2);
  FUN_0101e4d8();
  return;
}


