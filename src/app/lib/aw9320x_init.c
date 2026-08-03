/*
 * Function: aw9320x_init
 * Entry:    00031fdc
 * Prototype: int32_t __stdcall aw9320x_init(aw9320x_func * hw_fun)
 */


/* exclude_from_export */

int32_t aw9320x_init(aw9320x_func *hw_fun)

{
  int32_t iVar1;
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t auStack_14 [2];
  
  if ((((hw_fun != (aw9320x_func *)0x0) && ((hw_fun->i2c_func).i2c_r != (aw9320x_i2c_r_t *)0x0)) &&
      ((hw_fun->i2c_func).i2c_w != (aw9320x_i2c_w_t *)0x0)) &&
     ((hw_fun->irq_init != (aw9320x_irq_init_t *)0x0 && (hw_fun->delay != (aw9320x_delay_t *)0x0))))
  {
    g_aw9320x_func.irq_init = (aw9320x_irq_init_t *)0x0;
    g_aw9320x_func.i2c_func.i2c_w = (aw9320x_i2c_w_t *)0x0;
    AW_UPDATE_FW_STATE_2001aa7b = SEND_UPDTAE_CMD;
    uint8_t_20003053 = 1;
    g_aw9320x_func.i2c_func.i2c_r = (aw9320x_i2c_r_t *)hw_fun;
    iVar1 = aw9320x_read_chipid();
    if ((iVar1 != -1) &&
       ((iVar1 = aw9320x_soft_reset(), iVar1 == 0 &&
        (iVar1 = aw9320x_init_irq_handle(), iVar1 != -1)))) {
      if (iVar1 == -2) {
        aw9320x_i2c_write(0xff20,0x3c00f091);
        aw9320x_i2c_read(0x1c00,&uStack_1c);
        aw9320x_i2c_read(0x4744,auStack_14);
        aw9320x_i2c_read(0x4444,&uStack_18);
        aw9320x_i2c_write(0xff20,0x3c00f011);
      }
      iVar1 = aw9320x_fw_update(iVar1 == -2);
      if ((iVar1 == 0) ||
         ((((iVar1 = aw9320x_update_fw_to_flash(), iVar1 == 0 &&
            (iVar1 = aw9320x_soft_reset(), iVar1 == 0)) &&
           (iVar1 = aw9320x_read_chipid(), iVar1 == 0)) &&
          (iVar1 = aw9320x_init_irq_handle(), iVar1 == 0)))) {
        iVar1 = aw9320x_para_loaded();
        return -(uint)(iVar1 != 0);
      }
    }
  }
  return -1;
}


