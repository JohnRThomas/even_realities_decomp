/*
 * Function: nrfx_ipc_config_load
 * Entry:    00069034
 * Prototype: void __stdcall nrfx_ipc_config_load(nrfx_ipc_config_t * p_config)
 */


/* exclude_from_export */

void nrfx_ipc_config_load(nrfx_ipc_config_t *p_config)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (p_config == (nrfx_ipc_config_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",70);
  }
  else {
    if (DAT_2000bd10 == '\x01') {
      iVar3 = 0;
      do {
        iVar2 = iVar3 + 1;
        (&Peripherals::IPC_S.SEND_CNF_0_)[iVar3] = p_config[iVar3];
        iVar3 = iVar2;
      } while (iVar2 != 0x10);
      puVar1 = p_config + 0xf;
      iVar3 = 0;
      do {
        puVar1 = puVar1 + 1;
        iVar2 = iVar3 + 1;
        (&Peripherals::IPC_S.RECEIVE_CNF_0_)[iVar3] = *puVar1;
        iVar3 = iVar2;
      } while (iVar2 != 0x10);
      Peripherals::IPC_S.INTENSET = p_config[0x20];
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state == NRFX_DRV_STATE_INITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",71);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


