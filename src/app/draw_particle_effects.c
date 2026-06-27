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
  int iVar6;
  int iVar7;
  byte local_30 [12];
  
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = 0x20a;
    fmt = "[%s-%d]curMsg is NULL !\n";
  }
  else {
    if (param_1 != 0) {
      FUN_00045428();
      iVar6 = 0;
      do {
        draw_message(param_2,param_3);
        uVar5 = 0;
        do {
          iVar4 = 0;
          do {
            iVar7 = *(int *)(param_1 + uVar5 * 4);
            local_30[0] = 1;
            local_30[1] = 3;
            local_30[2] = 5;
            local_30[3] = 7;
            local_30[4] = 7;
            local_30[5] = 7;
            local_30[6] = 7;
            local_30[7] = 7;
            bVar1 = *(byte *)(iVar7 + iVar4);
            if (bVar1 != 0) {
              *(byte *)(iVar7 + iVar4) =
                   bVar1 & (&DAT_000accab)
                           [iVar4 + (uint)local_30[iVar6] * 0x140 + (uVar5 % 0x1a) * 0xa00];
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 != 0x140);
          uVar5 = uVar5 + 1;
        } while (uVar5 != 199);
        z_impl_k_sleep((k_timeout_t)0xa4);
        pGVar2 = __get_dashboard_state();
        iVar4 = *(int *)&(pGVar2->jdb_panel_context).field_0x348;
        pGVar2 = __get_dashboard_state();
        iVar6 = iVar6 + 1;
        _reflash_fb_data_to_lcd
                  (iVar4,*(int *)&(pGVar2->jdb_panel_context).field_0x34c,0,0,0x280,199);
      } while (iVar6 != 8);
      FUN_0004540c();
      return;
    }
    uVar3 = 0x20f;
    fmt = "[%s-%d]fb is NULL !\n";
  }
  if (BLE_DEBUG != 0) {
    ble_printk(fmt,"draw_particle_effects",uVar3,BLE_DEBUG);
    return;
  }
  printk(fmt);
  return;
}


