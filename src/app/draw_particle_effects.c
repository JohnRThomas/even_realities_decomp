/*
 * Function: draw_particle_effects
 * Entry:    00037728
 * Prototype: undefined __stdcall draw_particle_effects(int param_1, undefined4 param_2, undefined4 * param_3)
 */


void draw_particle_effects(int param_1,undefined4 param_2,undefined4 *param_3)

{
  byte bVar1;
  char *fmt;
  GlassesState *pGVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint32_t uVar6;
  int iVar7;
  int iVar8;
  byte local_30 [12];
  
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = 0x20a;
    fmt = "[%s-%d]curMsg is NULL !\n";
  }
  else {
    if (param_1 != 0) {
      __clear_showing_notification_on_gui();
      iVar7 = 0;
      do {
        draw_message(param_2,param_3);
        uVar5 = 0;
        do {
          iVar4 = 0;
          do {
            iVar8 = *(int *)(param_1 + uVar5 * 4);
            local_30[0] = 1;
            local_30[1] = 3;
            local_30[2] = 5;
            local_30[3] = 7;
            local_30[4] = 7;
            local_30[5] = 7;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar1 = *(byte *)(iVar8 + iVar4);
            if (bVar1 != 0) {
              *(byte *)(iVar8 + iVar4) =
                   bVar1 & (&DAT_000accab)
                           [iVar4 + (uint)local_30[iVar7] * 0x140 + (uVar5 % 0x1a) * 0xa00];
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != 0x140);
          uVar5 = uVar5 + 1;
        } while (uVar5 != 199);
        z_impl_k_sleep((k_timeout_t)0xa4);
        pGVar2 = __get_dashboard_state();
        uVar6 = (pGVar2->jdb_panel_context).current_row;
        pGVar2 = __get_dashboard_state();
        iVar7 = iVar7 + 1;
        _reflash_fb_data_to_lcd(uVar6,(pGVar2->jdb_panel_context).current_column,0,0,0x280,199);
      } while (iVar7 != 8);
      __set_showing_notification_on_gui();
      return;
    }
    uVar3 = 0x20f;
    fmt = "[%s-%d]fb is NULL !\n";
  }
  if (BLE_DEBUG != 0) {
    ble_printk(fmt);
    return;
  }
  printk(fmt,"draw_particle_effects",uVar3);
  return;
}


