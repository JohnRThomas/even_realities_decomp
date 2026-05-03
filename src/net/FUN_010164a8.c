/*
 * Function: FUN_010164a8
 * Entry:    010164a8
 * Prototype: undefined4 __stdcall FUN_010164a8(byte * param_1, int param_2)
 */


undefined4 FUN_010164a8(byte *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  
  *(byte *)(*(int *)(param_1 + 4) + 0x116) = *(byte *)(*(int *)(param_1 + 4) + 0x116) | 4;
  bVar2 = FUN_0100f0ec(param_2);
  uVar5 = (uint)bVar2;
  bVar2 = FUN_0100f0f4(param_2);
  uVar3 = (uint)bVar2;
  switch(uVar5) {
  case 0xe:
  case 0x12:
  case 0x14:
  case 0x17:
    uVar4 = FUN_010149f4(uVar5,0,param_1);
    return uVar4;
  case 0x16:
    if (*(char *)(DAT_21000f6c + 0xc5) == '\"') {
      FUN_01020134(0x21000f68,uVar3,extraout_r2);
    }
    else {
      if (*(char *)(DAT_21000f6c + 0xc5) != '/') {
        return 0;
      }
      uVar5 = FUN_0100dbc0(DAT_21000f6c + 0xa8,0xb,(uint)*(byte *)(DAT_21000f6c + 0xc6),1);
      if (uVar5 == 0) {
        FUN_01020134(0x21000f68,0x2a,extraout_r2_00);
      }
    }
    iVar1 = DAT_21000f6c;
    *(undefined1 *)(DAT_21000f6c + 0xc5) = 0;
    *(undefined1 *)(iVar1 + 0x100) = 0;
    break;
  case 0x1d:
    if (DAT_210001fc != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01016534. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*DAT_210001fc)(0x1d,uVar3);
      return uVar4;
    }
    break;
  case 0x20:
    if (DAT_210001d8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0101654a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*DAT_210001d8)(DAT_21000f6c,0x20,uVar3);
      return uVar4;
    }
    break;
  case 0x23:
  case 0x24:
  case 0x25:
    if (DAT_210001f0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01016522. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*DAT_210001f0)(uVar5,uVar3);
      return uVar4;
    }
  }
  return 0;
}


