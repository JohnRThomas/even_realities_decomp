/*
 * Function: FUN_01034d38
 * Entry:    01034d38
 * Prototype: undefined __stdcall FUN_01034d38(uint param_1)
 */


void FUN_01034d38(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *extraout_r3;
  ushort *puVar6;
  
  uVar2 = FUN_01034c68(param_1);
  uVar1 = *(ushort *)((int)&DAT_210006a8 + (uVar2 + 8) * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar5 = ((uint)uVar1 << 0x13) >> 0x1c;
    *(ushort *)((int)&DAT_210006a8 + (uVar2 + 8) * 2) = uVar1 & 0xe0ff;
    iVar3 = 0;
    puVar6 = (ushort *)((int)&DAT_210006b4 + 2);
    do {
      puVar6 = puVar6 + 1;
      if (((*puVar6 & 0x100) != 0) && (uVar5 == ((uint)*puVar6 << 0x13) >> 0x1c)) {
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x30);
    (&DAT_210006a8)[uVar5 * 2] = 0;
    puVar4 = FUN_01034b28(&DAT_2100071c,uVar5);
    if (puVar4 != &DAT_0bad0000) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_gpiote.c",0x15f,
                   &DAT_0bad0000);
      FUN_0103a370();
                    /* WARNING: Could not recover jumptable at 0x01034996. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*extraout_r3)(0,0);
      return;
    }
  }
  return;
}


