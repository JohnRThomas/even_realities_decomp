/*
 * Function: _reflash_fb_data_to_lcd
 * Entry:    0004abd0
 * Prototype: undefined4 __stdcall _reflash_fb_data_to_lcd(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
 */


undefined4
_reflash_fb_data_to_lcd(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  jdb_panel_context *pjVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  k_timeout_t timeout;
  undefined1 local_38 [4];
  uint local_34;
  undefined4 local_30;
  undefined1 local_2c;
  
  local_38[0] = 0;
  pjVar2 = get_jdb_panel_context();
  if (pjVar2->__initialized == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n",
                   "_reflash_fb_data_to_lcd",extraout_r2,BLE_DEBUG);
      }
    }
    uVar3 = 0xffffffff;
  }
  else {
    if (199 < param_6) {
      param_6 = 200;
    }
    if (0x27f < param_5) {
      param_5 = 0x280;
    }
    iVar7 = (5 - param_3 / 2) + param_5 / 2;
    uVar5 = param_3 + param_1 & 1023;
    uVar3 = extraout_r1;
    for (; param_4 <= param_6; param_4 = param_4 + 1) {
      iVar10 = pjVar2->__frame_buffers;
      iVar9 = param_4 * 320 + param_3 / 2 + -5;
      iVar8 = iVar10 + iVar9;
      local_2c = *(undefined1 *)(iVar8 + 4);
      local_30 = *(undefined4 *)(iVar10 + iVar9);
      uVar6 = (param_2 + param_4) * 0x400 & 0x7fc00;
      local_34 = uVar6 | uVar5;
      *(undefined1 *)(iVar10 + iVar9) = 2;
      *(char *)(iVar8 + 1) = (char)(uVar6 >> 0x10);
      *(char *)(iVar8 + 2) = (char)(local_34 >> 8);
      *(char *)(iVar8 + 3) = (char)uVar5;
      *(undefined1 *)(iVar8 + 4) = 0xff;
      uVar1 = *(undefined1 *)(iVar8 + iVar7);
      *(undefined1 *)(iVar8 + iVar7) = 0;
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar3;
      z_impl_k_mutex_lock(&lcd_mutex,timeout);
      iVar4 = (*(code *)pjVar2->spi_callbacks->rx_tx)(pjVar2->spi_callbacks,iVar8,iVar7,local_38,1);
      z_impl_k_mutex_unlock(&lcd_mutex);
      uVar3 = extraout_r1_00;
      if ((iVar4 != 0) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): spi transfer error....\n");
          uVar3 = extraout_r1_02;
        }
        else {
          ble_printk("%s(): spi transfer error....\n","_reflash_fb_data_to_lcd",extraout_r2_00,
                     BLE_DEBUG);
          uVar3 = extraout_r1_01;
        }
      }
      *(undefined1 *)(iVar8 + iVar7) = uVar1;
      *(undefined4 *)(iVar10 + iVar9) = local_30;
      *(undefined1 *)(iVar8 + 4) = local_2c;
    }
    FUN_00080ece(0x97);
    busy_wait_seconds(1);
    uVar3 = 0;
  }
  return uVar3;
}


