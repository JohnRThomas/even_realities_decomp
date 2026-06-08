/*
 * Function: FUN_00045a0c
 * Entry:    00045a0c
 * Prototype: undefined4 __stdcall FUN_00045a0c(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_00045a0c(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  int iVar4;
  undefined4 extraout_r2;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = 0;
  do {
    iVar7 = __frame_buffer;
    uVar6 = 0;
    do {
      iVar4 = 0;
      do {
        iVar8 = *(int *)(iVar7 + uVar6 * 4);
        bVar1 = *(byte *)(iVar8 + iVar4);
        if (bVar1 != 0) {
          *(byte *)(iVar8 + iVar4) = bVar1 & (&DAT_000ad56b)[iVar4 + (uVar6 % 0x1a) * 0xa00 + iVar5]
          ;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x140);
      uVar6 = uVar6 + 1;
    } while (uVar6 != 199);
    pGVar2 = __get_dashboard_state();
    iVar7 = *(int *)&(pGVar2->jdb_panel_context).field_0x348;
    pGVar2 = __get_dashboard_state();
    iVar5 = iVar5 + -0x140;
    uVar3 = _reflash_fb_data_to_lcd
                      (iVar7,*(int *)&(pGVar2->jdb_panel_context).field_0x34c,0,0,0x280,199);
  } while (iVar5 != -0xa00);
  gui_screen_clear(uVar3,extraout_r1,extraout_r2);
  return 0;
}


