/*
 * Function: FUN_010295a4
 * Entry:    010295a4
 * Prototype: int __stdcall FUN_010295a4(ushort * param_1)
 */


int FUN_010295a4(ushort *param_1)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  iVar2 = FUN_0102955c(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_0100a518(*param_1,0);
    if ((iVar2 == 0) || (bVar1 = FUN_01028ac4(iVar2), !bVar1)) {
      iVar2 = 2;
    }
    else if (*(char *)(iVar2 + 0x31c) == '\0') {
      puVar3 = (undefined *)FUN_0100de00((uint)param_1[2]);
      puVar4 = (undefined *)FUN_0100de24(5,puVar3);
      puVar5 = (undefined *)FUN_0100de24(8,puVar3);
      if ((puVar5 < puVar4) || (puVar3 <= puVar4)) {
        iVar2 = 0x12;
      }
      else if ((&DAT_00001d4b < puVar3) || (*(short *)(iVar2 + 0x6e) == 0x202)) {
        *(short *)(iVar2 + 800) = (short)puVar4;
        *(undefined4 *)(iVar2 + 0x324) = 0;
        *(undefined **)(iVar2 + 0x328) = puVar3;
        *(ushort *)(iVar2 + 0x32c) = param_1[3];
        *(ushort *)(iVar2 + 0x32e) = param_1[4];
        *(undefined1 *)(iVar2 + 0x31c) = 0xff;
        iVar2 = 0;
      }
      else {
        iVar2 = 0xc;
      }
    }
    else {
      iVar2 = 0x3a;
    }
  }
  return iVar2;
}


