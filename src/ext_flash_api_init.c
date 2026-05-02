/*
 * Function: ext_flash_api_init
 * Entry:    0002f970
 * Prototype: undefined4 __stdcall ext_flash_api_init(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3)
 */


undefined4 ext_flash_api_init(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined2 extraout_r0;
  GlassesState *pGVar2;
  undefined4 uVar3;
  flash_page_cb extraout_r1;
  flash_page_cb extraout_r1_00;
  flash_page_cb cb;
  flash_page_cb extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 *data;
  undefined4 *extraout_r2_00;
  undefined4 *extraout_r2_01;
  
  z_impl_k_mutex_init((k_mutex *)&DAT_20008534);
  bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
  if (bVar1) {
    *param_1 = 0x2f821;
    *param_2 = 0x2f8c9;
    *param_3 = 0x2f789;
    data = &DAT_20008548;
    DAT_20008548 = &DAT_0008b3a0;
    cb = extraout_r1;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): flash init success!\n");
        cb = extraout_r1_01;
        data = extraout_r2_01;
      }
      else {
        ble_printk("%s(): flash init success!\n","ext_flash_api_init",&DAT_20008548,BLE_DEBUG);
        cb = extraout_r1_00;
        data = extraout_r2_00;
      }
    }
    flash_page_foreach((device *)&DAT_0008b3a0,cb,data);
    pGVar2 = __get_dashboard_state();
    uVar3 = 0;
    *(undefined2 *)&pGVar2->field_0x10a2 = extraout_r0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): FAILURE!\n");
      }
      else {
        ble_printk("%s(): FAILURE!\n","ext_flash_api_init",extraout_r2,BLE_DEBUG);
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


