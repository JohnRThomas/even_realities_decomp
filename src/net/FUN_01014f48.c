/*
 * Function: FUN_01014f48
 * Entry:    01014f48
 * Prototype: bool __stdcall FUN_01014f48(void)
 */


bool FUN_01014f48(void)

{
  char cVar1;
  char cVar2;
  code *pcVar3;
  undefined4 *puVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  char cVar10;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar11;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r3;
  undefined4 uVar12;
  undefined4 extraout_r3_00;
  
  puVar4 = DAT_21000f6c;
  cVar1 = *(char *)((int)DAT_21000f6c + 0x3be);
  cVar2 = *(char *)((int)DAT_21000f6c + 0x3bf);
  cVar9 = cVar1;
  if (cVar1 == '\0') {
    cVar9 = *(char *)((int)DAT_21000f6c + 0x6e);
  }
  cVar10 = cVar2;
  if (cVar2 == '\0') {
    cVar10 = *(char *)((int)DAT_21000f6c + 0x6f);
  }
  *(char *)((int)DAT_21000f6c + 0x6f) = cVar10;
  *(char *)((int)puVar4 + 0x6e) = cVar9;
  pcVar3 = DAT_210001f4;
  *(undefined1 *)(puVar4 + 0x1c) = 0xff;
  uVar11 = 0;
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(DAT_21000f6c);
    uVar11 = extraout_r2;
  }
  if ((*(char *)(DAT_21000f6c + 0x5b) == '\x01') || (cVar1 != '\0' || cVar2 != '\0')) {
    FUN_01020134(0x21000f68,0,uVar11);
  }
  uVar6 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
  bVar5 = FUN_0100f9f8((int)DAT_21000f6c);
  uVar11 = extraout_r2_00;
  uVar12 = extraout_r3;
  if (bVar5) {
    FUN_0100fb00(*(undefined2 *)DAT_21000f6c,(int)(DAT_21000f6c + 0xc),
                 (undefined4 *)((int)DAT_21000f6c + 0x1ce));
    uVar11 = extraout_r2_01;
    uVar12 = extraout_r3_00;
  }
  FUN_01014698(DAT_21000f6c,5,uVar11,uVar12);
  uVar7 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
  if (uVar6 < uVar7) {
    uVar8 = FUN_01024688();
    uVar7 = uVar7 - uVar6;
    if (uVar7 < 0x76) {
      uVar7 = 0x76;
    }
    uVar6 = FUN_010246a8(uVar7,uVar8,extraout_r2_02);
    return uVar6 == 0;
  }
  return true;
}


