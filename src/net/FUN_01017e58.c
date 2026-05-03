/*
 * Function: FUN_01017e58
 * Entry:    01017e58
 * Prototype: undefined __stdcall FUN_01017e58(int param_1, undefined4 param_2, char * param_3, byte * param_4)
 */


void FUN_01017e58(int param_1,undefined4 param_2,char *param_3,byte *param_4)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  undefined4 *puVar5;
  uint uVar6;
  byte bVar7;
  
  bVar7 = DAT_2100100d ^ 1;
  if ((*(char *)(param_1 + 0x12) == '\x01') &&
     ((*(byte *)(*(int *)(param_1 + 8) + 5) & 0xc0) == 0x40)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  cVar3 = '\0';
  if (DAT_2100100c != '\0') {
    if (((((DAT_21000fe4 == '\x03') && (bVar2 = DAT_2100100b, DAT_21000fdd != '\0')) ||
         (bVar2 = DAT_21001008, *(int *)(param_1 + 4) != 0)) ||
        (bVar4 = FUN_0101a1cc(), bVar2 = DAT_21001008, bVar4)) &&
       ((uVar6 = (uint)bVar2, uVar6 != 0xff && (uVar6 != 8)))) {
      bVar2 = FUN_0100c404(uVar6);
      if (bVar2 != 0) {
        bVar7 = bVar2;
      }
      if (bVar1) {
        if (DAT_21001011 == '\0') {
          puVar5 = (undefined4 *)FUN_0100d268(uVar6);
          cVar3 = FUN_0100b2ac(puVar5,*(char **)(param_1 + 8));
        }
        else {
          cVar3 = thunk_FUN_01020520();
          DAT_21001011 = '\0';
        }
        goto LAB_01017ebe;
      }
    }
    else if ((bVar1) && (DAT_21001010 == '\0')) {
      cVar3 = FUN_0100d2d4(*(int *)(param_1 + 8),0);
      DAT_2100100c = cVar3;
      if (cVar3 != '\0') {
        uVar6 = FUN_0100d310();
        if (uVar6 == 0xff) {
          cVar3 = '\0';
        }
        else {
          DAT_21001008 = (byte)uVar6;
        }
      }
      goto LAB_01017ebe;
    }
    cVar3 = '\0';
  }
LAB_01017ebe:
  *param_3 = cVar3;
  *(bool *)param_2 = bVar1;
  *param_4 = bVar7;
  return;
}


