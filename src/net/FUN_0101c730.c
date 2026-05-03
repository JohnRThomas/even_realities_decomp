/*
 * Function: FUN_0101c730
 * Entry:    0101c730
 * Prototype: bool __stdcall FUN_0101c730(void)
 */


bool FUN_0101c730(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  char cVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar9;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r3;
  undefined4 uVar10;
  undefined4 extraout_r3_00;
  
  puVar2 = DAT_21001128;
  cVar7 = *(char *)((int)DAT_21001128 + 0x31a);
  if (cVar7 == '\0') {
    cVar7 = *(char *)((int)DAT_21001128 + 0x6e);
  }
  cVar8 = *(char *)((int)DAT_21001128 + 0x31b);
  if (cVar8 == '\0') {
    cVar8 = *(char *)((int)DAT_21001128 + 0x6f);
  }
  *(char *)((int)DAT_21001128 + 0x6e) = cVar7;
  *(char *)((int)puVar2 + 0x6f) = cVar8;
  pcVar1 = DAT_210004d0;
  *(undefined1 *)(puVar2 + 0x1c) = 0xff;
  uVar9 = 0;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(DAT_21001128);
    uVar9 = extraout_r2;
  }
  FUN_01020134(0x21001124,0,uVar9);
  uVar4 = FUN_0100f8fc((int)(DAT_21001128 + 0xc));
  bVar3 = FUN_0100f9f8((int)DAT_21001128);
  uVar9 = extraout_r2_00;
  uVar10 = extraout_r3;
  if (bVar3) {
    FUN_0100fb00(*(undefined2 *)DAT_21001128,(int)(DAT_21001128 + 0xc),
                 (undefined4 *)((int)DAT_21001128 + 0x1ce));
    uVar9 = extraout_r2_01;
    uVar10 = extraout_r3_00;
  }
  FUN_0101c5d4(DAT_21001128,4,uVar9,uVar10);
  uVar5 = FUN_0100f8fc((int)(DAT_21001128 + 0xc));
  if (uVar5 <= uVar4) {
    return true;
  }
  uVar6 = FUN_01024688();
  uVar5 = uVar5 - uVar4;
  if (uVar5 < 0x76) {
    uVar5 = 0x76;
  }
  uVar4 = FUN_010246a8(uVar5,uVar6,extraout_r2_02);
  return uVar4 == 0;
}


