/*
 * Function: _reflash_fb_data_to_lcd_ex
 * Entry:    0004ad38
 * Prototype: undefined4 __stdcall _reflash_fb_data_to_lcd_ex(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
 */


undefined4
_reflash_fb_data_to_lcd_ex
          (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  byte bVar1;
  jbd_panel_context *pjVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  k_timeout_t timeout;
  undefined1 local_38 [4];
  uint local_34;
  undefined4 local_30;
  byte local_2c;
  
  local_38[0] = 0;
  pjVar2 = get_jdb_panel_context();
  if (pjVar2->init_done == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n",
               "_reflash_fb_data_to_lcd_ex");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
      }
    }
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0x140;
    if (199 < param_6) {
      param_6 = 200;
    }
    if (0x27f < param_5) {
      param_5 = 0x280;
    }
    iVar9 = (5 - param_3 / 2) + param_5 / 2;
    uVar5 = param_3 + param_1 & 0x3ff;
    for (; param_4 <= param_6; param_4 = param_4 + 1) {
      pbVar10 = pjVar2->current_buffer;
      iVar8 = param_4 * 0x140 + param_7 * 0x140 + param_3 / 2 + -5;
      pbVar7 = pbVar10 + iVar8;
      local_2c = pbVar7[4];
      local_30 = *(undefined4 *)(pbVar10 + iVar8);
      uVar6 = (param_4 + param_2) * 0x400 & 0x7fc00;
      local_34 = uVar6 | uVar5;
      pbVar10[iVar8] = 2;
      pbVar7[1] = (byte)(uVar6 >> 0x10);
      pbVar7[2] = (byte)(local_34 >> 8);
      pbVar7[3] = (byte)uVar5;
      pbVar7[4] = 0xff;
      bVar1 = pbVar7[iVar9];
      pbVar7[iVar9] = 0;
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar3;
      z_impl_k_mutex_lock(&lcd_mutex,timeout);
      iVar4 = (*(code *)pjVar2->spi_callbacks->rx_tx)(pjVar2->spi_callbacks,pbVar7,iVar9,local_38,1)
      ;
      z_impl_k_mutex_unlock(&lcd_mutex);
      uVar3 = extraout_r1;
      if ((iVar4 != 0) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): spi transfer error....\n","_reflash_fb_data_to_lcd_ex");
          uVar3 = extraout_r1_01;
        }
        else {
          ble_printk("%s(): spi transfer error....\n");
          uVar3 = extraout_r1_00;
        }
      }
      pbVar7[iVar9] = bVar1;
      *(undefined4 *)(pbVar10 + iVar8) = local_30;
      pbVar7[4] = local_2c;
    }
    __send_cmd(SPI_SYNC);
    delay_ms(1);
    uVar3 = 0;
  }
  return uVar3;
}


