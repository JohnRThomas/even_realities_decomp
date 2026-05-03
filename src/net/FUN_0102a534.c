/*
 * Function: FUN_0102a534
 * Entry:    0102a534
 * Prototype: undefined __stdcall FUN_0102a534(undefined4 param_1, int param_2)
 */


void FUN_0102a534(undefined4 param_1,int param_2)

{
  char cVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  uint extraout_r3;
  uint uVar5;
  
  cVar1 = FUN_010236bc((uint)*(byte *)(param_2 + 0x27));
  if (cVar1 != '\0') goto LAB_0102a54c;
  uVar3 = 0xd8;
  uVar4 = extraout_r2;
  uVar5 = extraout_r3;
  while( true ) {
    FUN_01025edc(0x6a,uVar3,uVar4,uVar5);
LAB_0102a54c:
    *(undefined2 *)(param_2 + 0x24) = 0;
    *(undefined1 *)(param_2 + 0x26) = 0;
    pbVar2 = (byte *)(**(code **)(param_2 + 0x20))(param_1,9);
    if ((pbVar2 == (byte *)0x0) || (uVar5 = (uint)*pbVar2, uVar5 == 0)) break;
    uVar3 = 0xdc;
    uVar4 = extraout_r2_00;
  }
  return;
}


