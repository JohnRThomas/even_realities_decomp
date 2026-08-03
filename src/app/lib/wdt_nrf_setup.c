/*
 * Function: wdt_nrf_setup
 * Entry:    000884aa
 * Prototype: undefined4 __stdcall wdt_nrf_setup(int param_1, uint param_2)
 */


/* exclude_from_export */

undefined4 wdt_nrf_setup(int param_1,uint param_2)

{
  undefined4 extraout_r0;
  int iVar1;
  uint uVar2;
  nrfx_wdt_t *p_instance;
  
  p_instance = *(nrfx_wdt_t **)(param_1 + 4);
  uVar2 = 9 - (param_2 & 1);
  iVar1 = *(int *)(param_1 + 0x10);
  if ((int)(param_2 << 0x1e) < 0) {
    uVar2 = uVar2 & 0xfffffff7;
  }
  *(uint *)(*p_instance + 0x50c) = uVar2;
  uVar2 = *(uint *)(iVar1 + 0x20);
  __aeabi_uldivmod(uVar2 << 0xf,uVar2 >> 0x11,1000,0);
  *(undefined4 *)(*p_instance + 0x504) = extraout_r0;
  nrfx_wdt_enable(p_instance);
  return 0;
}


