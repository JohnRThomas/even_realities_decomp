/*
 * Function: pdm_nrfx_init0
 * Entry:    000631c8
 * Prototype: int __stdcall pdm_nrfx_init0(int param_1, pinctrl_state * param_2, undefined4 param_3)
 */


/* exclude_from_export */

int pdm_nrfx_init0(int param_1,pinctrl_state *param_2,undefined4 param_3)

{
  int iVar1;
  clock_control_subsys_t sys;
  onoff_manager *poVar2;
  uintptr_t *config;
  undefined4 *puVar3;
  pinctrl_state *local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  z_arm_irq_priority_set(0x26,1,0);
  config = *(uintptr_t **)(*(int *)(param_1 + 4) + 0x1c);
  iVar1 = pinctrl_lookup_state((pinctrl_dev_config *)config,'\0',&local_14);
  if ((-1 < iVar1) &&
     (iVar1 = pinctrl_configure_pins((pinctrl_soc_pin_t *)*local_14,(uint8_t)local_14[1],*config),
     -1 < iVar1)) {
    k_msgq_init((k_msgq *)&DAT_2000ba04,&DAT_2000ba3c,4,10);
    puVar3 = *(undefined4 **)(param_1 + 0x10);
    if (*(char *)(*(int *)(param_1 + 4) + 0x20) == '\x02') {
      sys = 3;
    }
    else {
      sys = 0;
    }
    poVar2 = z_nrf_clock_control_get_onoff(sys);
    *puVar3 = poVar2;
    if (poVar2 == (onoff_manager *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","drv_data->clk_mgr != ((void *)0)",
              "WEST_TOPDIR/zephyr/drivers/audio/dmic_nrfx_pdm.c",529);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar1 = 0;
  }
  return iVar1;
}


