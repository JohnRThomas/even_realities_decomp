/*
 * Function: FUN_0101a984
 * Entry:    0101a984
 * Prototype: undefined * __stdcall FUN_0101a984(uint param_1)
 */


undefined * FUN_0101a984(uint param_1)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  cVar1 = FUN_010198c4();
  if (cVar1 == '\x01') {
    if (param_1 == 8) {
      return &DAT_00004290;
    }
    if (param_1 != 4) {
      puVar3 = &DAT_00000848;
      if (param_1 == 2) {
        puVar3 = &DAT_00000428;
      }
      return puVar3;
    }
    return &DAT_000011be;
  }
  if (param_1 == 8) {
    iVar2 = 400;
    puVar4 = &UNK_00001f9c;
    puVar3 = &DAT_00004100;
    goto LAB_0101a9ba;
  }
  if (param_1 == 4) {
    iVar2 = 0x17e;
    puVar4 = (undefined *)0xb38;
LAB_0101aa02:
    if (param_1 == 4) {
      puVar3 = &DAT_00001040;
      goto LAB_0101a9ba;
    }
  }
  else {
    puVar4 = (undefined *)0x4dc;
    if (param_1 == 2) {
      iVar2 = 0x18;
      puVar4 = (undefined *)0x30c;
    }
    else {
      iVar2 = 0x28;
    }
    if ((param_1 & 0xc) != 0) {
      puVar4 = puVar4 + 0x50;
      goto LAB_0101aa02;
    }
  }
  if (param_1 == 2) {
    puVar3 = (undefined *)0x410;
  }
  else {
    puVar3 = (undefined *)0x820;
  }
LAB_0101a9ba:
  return puVar3 + iVar2 + (int)puVar4;
}


