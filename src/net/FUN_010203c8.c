/*
 * Function: FUN_010203c8
 * Entry:    010203c8
 * Prototype: undefined __stdcall FUN_010203c8(ushort param_1, int param_2)
 */


void FUN_010203c8(ushort param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  code *extraout_r3;
  code *pcVar6;
  undefined4 extraout_r3_00;
  
  FUN_0100a564(param_1,6);
  if ((DAT_2100052c != (code *)0x0) && (*(char *)(param_2 + 0x38) != '\0')) {
    pcVar6 = DAT_21000528;
    if (DAT_21000528 != (code *)0x0) goto LAB_010203ee;
    uVar3 = 0x245;
    uVar5 = 0;
    uVar4 = extraout_r2;
    while( true ) {
      FUN_01009500(0xd,uVar3,uVar4,uVar5);
      pcVar6 = extraout_r3;
LAB_010203ee:
      uVar1 = (*pcVar6)();
      iVar2 = FUN_0100a518(uVar1,9);
      if (iVar2 != 0) break;
      uVar3 = 0x248;
      uVar4 = extraout_r2_00;
      uVar5 = extraout_r3_00;
    }
                    /* WARNING: Could not recover jumptable at 0x01020408. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_2100052c)(iVar2,0x3e);
    return;
  }
  return;
}


