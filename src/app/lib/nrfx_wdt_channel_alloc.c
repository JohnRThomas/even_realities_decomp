/*
 * Function: nrfx_wdt_channel_alloc
 * Entry:    0006b134
 * Prototype: nrfx_err_t __stdcall nrfx_wdt_channel_alloc(nrfx_wdt_t * p_instance, nrfx_wdt_channel_id * p_channel_id)
 */


/* exclude_from_export */

nrfx_err_t nrfx_wdt_channel_alloc(nrfx_wdt_t *p_instance,nrfx_wdt_channel_id *p_channel_id)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  nrfx_err_t nVar5;
  undefined4 uVar6;
  
  bVar1 = (byte)p_instance[1];
  if (p_channel_id == (nrfx_wdt_channel_id *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_channel_id",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",162);
  }
  else {
    if ((&wdt_m_cb.state)[bVar1] == NRFX_DRV_STATE_INITIALIZED) {
      uVar6 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar6 = getBasePriority();
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if ((bVar3) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = (&wdt_m_cb)[bVar1].alloc_index;
      if (bVar2 < 8) {
        *(byte *)p_channel_id = bVar2;
        (&wdt_m_cb)[bVar1].alloc_index = bVar2 + 1;
        nVar5 = NRFX_SUCCESS;
        *(uint *)(*p_instance + 0x508) = 1 << (uint)bVar2 | *(uint *)(*p_instance + 0x508);
      }
      else {
        nVar5 = NRFX_ERROR_NO_MEM;
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return nVar5;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state == NRFX_DRV_STATE_INITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",0xa3);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


