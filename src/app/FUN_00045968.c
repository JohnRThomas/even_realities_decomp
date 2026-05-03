/*
 * Function: FUN_00045968
 * Entry:    00045968
 * Prototype: undefined4 __stdcall FUN_00045968(void)
 */


undefined4 FUN_00045968(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r0;
  undefined4 extraout_r1;
  int iVar3;
  undefined4 extraout_r2;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  do {
    iVar6 = DAT_2000aa14;
    uVar5 = 0;
    do {
      iVar3 = 0;
      do {
        iVar7 = *(int *)(iVar6 + uVar5 * 4);
        bVar1 = *(byte *)(iVar7 + iVar3);
        if (bVar1 != 0) {
          *(byte *)(iVar7 + iVar3) = bVar1 & (&DAT_000ad56b)[iVar3 + (uVar5 % 0x1a) * 0xa00 + iVar4]
          ;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0x140);
      uVar5 = uVar5 + 1;
    } while (uVar5 != 199);
    pGVar2 = __get_dashboard_state();
    iVar6 = *(int *)&pGVar2->field_0xeb4;
    pGVar2 = __get_dashboard_state();
    _reflash_fb_data_to_lcd(iVar6,*(int *)&pGVar2->field_0xeb8,0,0,0x280,199);
    iVar4 = iVar4 + -0x140;
    arch_busy_wait(5000);
  } while (iVar4 != -0xa00);
  gui_screen_clear(extraout_r0,extraout_r1,extraout_r2);
  return 0;
}


