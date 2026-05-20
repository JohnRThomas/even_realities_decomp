/*
 * Function: erase_dfu_flash
 * Entry:    00016828
 * Prototype: undefined4 __stdcall erase_dfu_flash(void)
 */


undefined4 erase_dfu_flash(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
  if (bVar1) {
    qspi_nor_erase((device *)&PTR_s_mx25r6435f_0_0008b3a0,0,0x130000);
    printk("erase_dfu_flash done.\n");
    uVar2 = 0;
  }
  else {
    printk(" [%s] device not ready.\n","mx25r6435f@0");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


