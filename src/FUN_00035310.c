/*
 * Function: FUN_00035310
 * Entry:    00035310
 * Prototype: uint __stdcall FUN_00035310(void)
 */


uint FUN_00035310(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  
  uVar4 = 0;
  puVar6 = &DAT_2000878c;
  uVar3 = 0;
  bVar7 = 0;
  uVar5 = 0;
  do {
    uVar2 = uVar3 & 0xff;
    if (*(char *)(puVar6 + 4) == '\0') {
      if (bVar7 != 0) {
        DAT_2001aef9 = (undefined1)uVar4;
      }
      if (uVar5 != 0) goto LAB_00035330;
      if (uVar2 != 0) goto LAB_00035360;
      DAT_2001aef9 = 0xff;
      goto LAB_00035330;
    }
    iVar1 = uVar3 * 0x1b4;
    uVar3 = uVar3 + 1;
    if (((&DAT_2000879b)[iVar1] & 1) != 0) {
      uVar5 = uVar5 + 1 & 0xff;
      uVar4 = uVar2;
      bVar7 = (&DAT_2000879b)[iVar1] & 1;
    }
    puVar6 = puVar6 + 0x6d;
  } while (uVar3 != 10);
  if (bVar7 != 0) {
    DAT_2001aef9 = (undefined1)uVar4;
  }
  uVar2 = 10;
  if (uVar5 == 0) {
LAB_00035360:
    uVar5 = 0;
    DAT_2001aef9 = 0;
  }
LAB_00035330:
  return uVar2 - uVar5 & 0xff;
}


