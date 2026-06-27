/*
 * Function: spi_master_init
 * Entry:    000284f4
 * Prototype: undefined4 __stdcall spi_master_init(spi_master_callbacks * param_1)
 */


undefined4 spi_master_init(spi_master_callbacks *param_1)

{
  spi_master_callbacks *p_context;
  int iVar1;
  nrfx_err_t nVar2;
  SPIM4_S *pSVar3;
  uint uVar4;
  uint uVar5;
  code *handler;
  SPIM4_S **ppSVar6;
  byte abVar7 [4];
  SPIM3_S *local_58;
  undefined1 local_54;
  SPIM4_S *local_50;
  undefined4 uStack_4c;
  nrfx_spim_config_t local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_58 = &Peripherals::SPIM3_S;
  ppSVar6 = &local_50;
  local_50 = &Peripherals::SPIM4_S;
  uStack_4c = 1;
  local_54 = 0;
  memset(&local_48,0,0x28);
  iVar1 = LOG_LEVEL;
  local_38 = 0xff0700;
  local_2c = 0xffffffff;
  uStack_28 = 0x20002;
  if (param_1[1].rx_tx == 1) {
    return 0;
  }
  uVar5 = (uint)*(byte *)((int)&param_1[2].deinit + 1);
  local_48.opaque[0] = *(byte *)((int)&param_1[2].init_cb + 1);
  abVar7[1] = 0;
  abVar7[2] = 0;
  abVar7[3] = 0;
  abVar7[0] = local_48.opaque[0];
  local_34 = uVar5 * 1000000;
  uVar4 = (uint)*(byte *)&param_1[2].init_cb;
  local_44 = (uint)*(byte *)((int)&param_1[2].init_cb + 2);
  local_40 = (uint)*(byte *)((int)&param_1[2].init_cb + 3);
  local_3c = (uint)*(byte *)&param_1[2].deinit;
  local_48.opaque[1] = 0;
  local_48.opaque[2] = 0;
  local_48.opaque[3] = 0;
  if (uVar4 == 3) {
    ppSVar6 = (SPIM4_S **)&local_58;
  }
  else if (uVar4 != 4) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    if (BLE_DEBUG != 0) {
      ble_printk("%s():  SPIM BUS ERR!\n","spi_master_init",uVar4,BLE_DEBUG);
      return 0;
    }
    printk("%s():  SPIM BUS ERR!\n");
    return 0;
  }
  pSVar3 = ppSVar6[1];
  param_1[1].init_cb = *ppSVar6;
  param_1[1].deinit = pSVar3;
  if (2 < iVar1) {
    if (BLE_DEBUG == 0) {
      printk("%s(): *SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n","spi_master_init",uVar4,
             uVar5,abVar7,local_44,local_40,local_3c);
    }
    else {
      ble_printk("%s(): *SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n","spi_master_init",
                 uVar4,uVar5);
    }
  }
  if (*(char *)&param_1[2].init_cb == '\x03') {
    handler = (code *)0x7fdf1;
    p_context = param_1;
  }
  else {
    handler = (code *)0x0;
    p_context = (spi_master_callbacks *)handler;
  }
  nVar2 = nrfx_spim_init((nrfx_spim_t *)(param_1 + 1),&local_48,handler,p_context);
  if ((undefined1 *)(uint)nVar2 != &DAT_0bad0000) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","status == NRFX_SUCCESS","../src/spim_spis/spim.c",104);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (*(char *)&param_1[2].init_cb == '\x03') {
    if (DAT_2001993a != '\0') goto LAB_00028600;
    uVar4 = 0xc;
    DAT_2001993a = '\x01';
  }
  else {
    if (DAT_2001993b != '\0') goto LAB_00028600;
    uVar4 = 10;
    DAT_2001993b = '\x01';
  }
  z_arm_irq_priority_set(uVar4,6,0);
LAB_00028600:
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): spim(bus=%d): init finish\n");
    }
    else {
      ble_printk("%s(): spim(bus=%d): init finish\n","spi_master_init",
                 (uint)*(byte *)&param_1[2].init_cb,BLE_DEBUG);
    }
  }
  param_1[1].rx_tx = 1;
  return 0;
}


