/*
 * Function: wdt_nrf_install_timeout
 * Entry:    00066d48
 * Prototype: int __stdcall wdt_nrf_install_timeout(device * dev, wdt_timeout_cfg * cfg)
 */


/* exclude_from_export */

int wdt_nrf_install_timeout(device *dev,wdt_timeout_cfg *cfg)

{
  nrfx_err_t nVar1;
  nrfx_wdt_t *p_instance;
  uint uVar1;
  uint32_t uVar2;
  undefined *puVar3;
  undefined1 auStack_14 [8];
  
  puVar3 = dev->data;
  p_instance = (nrfx_wdt_t *)dev->config;
  if (cfg->flags != '\x02') {
    return -0x86;
  }
  if ((cfg->window).min == 0) {
    uVar2 = (cfg->window).max;
    if (puVar3[0x24] == '\0') {
      if (0x7cffffe < uVar2 - 1) goto LAB_00066d9c;
      *(uint32_t *)(puVar3 + 0x20) = uVar2;
    }
    else if (*(uint32_t *)(puVar3 + 0x20) != uVar2) goto LAB_00066d9c;
    auStack_14._0_4_ = cfg;
    nVar1 = nrfx_wdt_channel_alloc(p_instance,(nrfx_wdt_channel_id *)(auStack_14 + 3));
    if (nVar1 == 0xbad0002) {
      uVar1 = 0xfffffff4;
    }
    else {
      uVar1 = (uint)auStack_14._0_4_ >> 0x18;
      if (cfg->callback != (wdt_callback_t *)0x0) {
        *(wdt_callback_t **)(puVar3 + uVar1 * 4) = cfg->callback;
      }
      puVar3[0x24] = puVar3[0x24] + '\x01';
    }
  }
  else {
LAB_00066d9c:
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


