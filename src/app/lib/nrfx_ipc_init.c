/*
 * Function: nrfx_ipc_init
 * Entry:    00068fe4
 * Prototype: nrfx_err_t __stdcall nrfx_ipc_init(uint8_t irq_priority, nrfx_ipc_handler_t handler, void * p_context)
 */


/* exclude_from_export */

nrfx_err_t nrfx_ipc_init(uint8_t irq_priority,nrfx_ipc_handler_t handler,void *p_context)

{
  nrfx_err_t nVar1;
  
  if (handler == (nrfx_ipc_handler_t)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","handler",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",52);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (DAT_2000bd10 == '\0') {
    arch_irq_enable(42);
    nVar1 = NRFX_SUCCESS;
    DAT_2000bd10 = '\x01';
    DAT_2000bd0c = handler;
    DAT_2000bd14 = p_context;
  }
  else {
    nVar1 = NRFX_ERROR_FORBIDDEN|NRFX_ERROR_INVALID_PARAM;
  }
  return nVar1;
}


