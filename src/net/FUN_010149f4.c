/*
 * Function: FUN_010149f4
 * Entry:    010149f4
 * Prototype: undefined4 __stdcall FUN_010149f4(int param_1, int param_2, byte * param_3)
 */


undefined4 FUN_010149f4(int param_1,int param_2,byte *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 unaff_r5;
  
  iVar3 = *(int *)(param_3 + 4);
  cVar1 = *(char *)(iVar3 + 0xc5);
  switch(param_1) {
  case 0xe:
    if (cVar1 == '\x04') {
      FUN_0100ff84((int)param_3);
      FUN_010108cc((int)param_3);
    }
    break;
  default:
    FUN_01009500(0x31,0x24e,iVar3,param_1 + -0xe);
    uVar2 = extraout_r2;
LAB_01014a96:
    FUN_01020134((int)param_3,unaff_r5,uVar2);
    iVar3 = *(int *)(param_3 + 4);
    goto LAB_01014a84;
  case 0x12:
    if (cVar1 == '\x10') {
      uVar2 = FUN_010109dc(param_3);
      return uVar2;
    }
    break;
  case 0x14:
    if (cVar1 == '\x1e') {
      FUN_0100ff84((int)param_3);
      if (param_2 != 0) {
        *(byte *)(*(int *)(param_3 + 4) + 0x116) = *(byte *)(*(int *)(param_3 + 4) + 0x116) & 0xdf;
      }
      FUN_010102e4(0x21000f68);
    }
    break;
  case 0x17:
    if (*(char *)(iVar3 + 0xc6) != '$') {
      return 0;
    }
    unaff_r5 = 0;
    *(undefined1 *)(iVar3 + 0xc6) = 0;
    FUN_0100ffb0((int)param_3);
    iVar3 = *(int *)(param_3 + 4);
    uVar2 = 1;
    if (*(char *)(iVar3 + 0x16c) == '\x01') goto LAB_01014a96;
LAB_01014a84:
    *(undefined1 *)(iVar3 + 0x16c) = 0;
  }
  return 0;
}


