/*
 * Function: FUN_0102e6ec
 * Entry:    0102e6ec
 * Prototype: bool __stdcall FUN_0102e6ec(void)
 */


bool FUN_0102e6ec(void)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *extraout_r3;
  uint uVar6;
  undefined4 *puVar7;
  bool bVar8;
  ulonglong uVar9;
  
  if (DAT_21004fac == '\0') {
    return false;
  }
  puVar3 = (uint *)FUN_0102e6c4();
  if (puVar3 != (uint *)0x0) {
    puVar5 = &DAT_21004668;
    DAT_21004668 = DAT_21004668 + -1;
    puVar7 = &DAT_0103c0ac;
    do {
      if (puVar7 < (undefined4 *)((int)&DAT_0103c0bc + 1)) {
        if (&UNK_0103c0bb < puVar7) goto code_r0x0102e742;
      }
      else {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",0x1c5,puVar5);
        FUN_0103a370();
      }
      puVar5 = (undefined4 *)0x0;
      if (*(char *)(puVar7[1] + 5) != '\0') {
        (**(code **)*puVar7)(puVar7,puVar3);
        puVar5 = extraout_r3;
      }
      puVar7 = puVar7 + 4;
    } while( true );
  }
LAB_0102e748:
  if ((0 < DAT_21004664) &&
     (uVar9 = src/*FUN_01038a44(), lVar2 = (uVar9 & 0xffffffff) * 1000,
     uVar4 = (int)(uVar9 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20),
     uVar6 = (uint)lVar2 >> 0xf | uVar4 * 0x20000, uVar4 = (uVar4 >> 0xf) - DAT_2100278c,
     uVar1 = (uint)(uVar6 < DAT_21002788),
     uVar4 != uVar1 || uVar4 - uVar1 < (uint)(1000 < uVar6 - DAT_21002788))) {
    FUN_0102e610();
  }
  bVar8 = 0xfffffc17 < DAT_21002788;
  DAT_21002788 = DAT_21002788 + 1000;
  DAT_2100278c = DAT_2100278c + (uint)bVar8;
  if ((DAT_2100087c << 0x1c < 0) || (uVar4 = DAT_21000870, DAT_21000870 < DAT_21000874)) {
    uVar4 = DAT_21000890;
  }
  return uVar4 != DAT_21000874;
code_r0x0102e742:
  FUN_0102e6d0(puVar3);
  goto LAB_0102e748;
}


