/*
 * Function: ?_dump_pmic_state
 * Entry:    000161b0
 * Prototype: undefined4 __stdcall ?_dump_pmic_state(void)
 */


undefined4 __dump_pmic_state(void)

{
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_gpiote_channel_get(0x8b430,(uint8_t *)0x3);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x10);
  printk("0x10 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x11);
  printk("0x11 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x12);
  printk("0x12 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x13);
  printk("0x13 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x14);
  printk("0x14 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x15);
  printk("0x15 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x16);
  printk("0x16 is %x\n",0);
  nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x17);
  printk("0x17 is %x\n",0);
  return 0;
}


