/*
 * Function: FUN_01014aa8
 * Entry:    01014aa8
 * Prototype: undefined4 __stdcall FUN_01014aa8(byte * param_1, int param_2)
 */


undefined4 FUN_01014aa8(byte *param_1,int param_2)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (uint)*(byte *)(param_2 + 4);
  cVar1 = *(char *)(*(int *)(param_1 + 4) + 0xc5);
  if (0x23 < uVar4) {
    if ((uVar4 == 0xff) && (DAT_21000f70 != 0)) {
      *(undefined1 *)(*(int *)(param_1 + 4) + 0x3b6) = 1;
    }
    return 0;
  }
  if (uVar4 < 0xe) {
    return 0;
  }
  switch(uVar4) {
  case 0xe:
  case 0x12:
  case 0x14:
  case 0x17:
    uVar3 = FUN_010149f4(uVar4,1,param_1);
    return uVar3;
  default:
    goto switchD_01014ac4_caseD_f;
  case 0x16:
    if ((cVar1 != '\"') && (cVar1 != '/')) {
      return 0;
    }
    FUN_0100ff84((int)param_1);
    iVar5 = *(int *)(param_1 + 4);
    if (*(char *)(iVar5 + 0xc6) == '#') {
      return 0;
    }
    *(byte *)(iVar5 + 0x117) = *(byte *)(iVar5 + 0x117) & 0xfe;
    iVar5 = *(int *)(param_1 + 4);
    *(byte *)(iVar5 + 0x117) = *(byte *)(iVar5 + 0x117) & 0xf7;
    FUN_01020134((int)param_1,0x1a,iVar5);
    return 0;
  case 0x1d:
    pcVar2 = DAT_21000200;
    if (cVar1 != '1') {
      return 0;
    }
    break;
  case 0x23:
    pcVar2 = DAT_210001f8;
    if (cVar1 != ')') {
      return 0;
    }
  }
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)();
  }
switchD_01014ac4_caseD_f:
  return 0;
}


