/*
 * Function: FUN_0102f34c
 * Entry:    0102f34c
 * Prototype: undefined __stdcall FUN_0102f34c(char param_1, int param_2, int param_3)
 */


void FUN_0102f34c(char param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *extraout_r3;
  bool bVar7;
  
  puVar6 = (undefined1 *)(param_3 << 0x1f);
  if (-1 < (int)puVar6) {
    uVar5 = param_2 + 2;
    if (uVar5 < 8) goto LAB_0102f36c;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/irq_manage.c",0x5c,puVar6);
    uVar2 = FUN_0103a370();
    param_1 = (char)uVar2;
    puVar6 = extraout_r3;
  }
  uVar5 = 0;
LAB_0102f36c:
  uVar3 = (uint)param_1;
  bVar7 = -1 < (int)uVar3;
  if (bVar7) {
    uVar3 = uVar3 + 0xe0000000;
  }
  else {
    puVar6 = &DAT_e000ed14;
  }
  uVar1 = (undefined1)(uVar5 << 5);
  if (bVar7) {
    puVar4 = &DAT_0000e100 + uVar3;
    (&UNK_0000e400)[uVar3] = uVar1;
  }
  else {
    puVar4 = (undefined *)(uVar3 & 0xf);
  }
  if (!bVar7) {
    puVar6[(int)puVar4] = uVar1;
  }
  return;
}


