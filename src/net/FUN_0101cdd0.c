/*
 * Function: FUN_0101cdd0
 * Entry:    0101cdd0
 * Prototype: undefined4 __stdcall FUN_0101cdd0(byte * param_1, int param_2)
 */


undefined4 FUN_0101cdd0(byte *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r2;
  int iVar4;
  code *pcVar5;
  
  uVar2 = (uint)*(byte *)(param_2 + 4);
  uVar3 = (uint)*(byte *)(*(int *)(param_1 + 4) + 0xc5);
  switch(uVar2) {
  case 0x12:
  case 0x14:
  case 0x16:
    if (uVar2 == 0x14) {
      uVar3 = FUN_0100dbc0(DAT_21001128 + 0xa8,10,uVar3,0);
      if (uVar3 == 0) {
        return 0;
      }
      FUN_0100ff84(0x21001124);
      *(byte *)(*(int *)(param_1 + 4) + 0x116) = *(byte *)(*(int *)(param_1 + 4) + 0x116) & 0xdf;
      FUN_010102e4(0x21001124);
      return 0;
    }
    if (uVar2 == 0x16) {
      if (uVar3 != 0x21) {
        return 0;
      }
      FUN_0100ff84(0x21001124);
      *(byte *)(*(int *)(param_1 + 4) + 0x117) = *(byte *)(*(int *)(param_1 + 4) + 0x117) & 0xfe;
      iVar4 = *(int *)(param_1 + 4);
      *(byte *)(iVar4 + 0x117) = *(byte *)(iVar4 + 0x117) & 0xf7;
      FUN_01020134((int)param_1,0x1a,iVar4);
      return 0;
    }
    if (uVar2 == 0x12) {
      uVar3 = FUN_0100dbc0(DAT_21001128 + 0xa8,9,uVar3,0);
      if (uVar3 == 0) {
        return 0;
      }
      uVar1 = FUN_010109dc(param_1);
      return uVar1;
    }
    FUN_01009500(0x36,0x3f6,uVar3,uVar2 - 0x12);
    uVar3 = extraout_r2;
  case 0x23:
    if ((uVar3 == 0x29) && (pcVar5 = DAT_210004d4, DAT_210004d4 != (code *)0x0)) {
LAB_0101ce24:
      (*pcVar5)(param_1);
    }
    break;
  case 0x1d:
    if (uVar3 != 0x31) {
      return 0;
    }
    pcVar5 = DAT_210004c4;
    if (DAT_210004c4 == (code *)0x0) {
      return 0;
    }
    goto LAB_0101ce24;
  case 0x1f:
    if ((uVar3 == 0x2d) && (DAT_210004bc != (code *)0x0)) {
      (*DAT_210004bc)();
    }
  }
  return 0;
}


