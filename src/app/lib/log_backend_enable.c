/*
 * Function: log_backend_enable
 * Entry:    00050b98
 * Prototype: void __stdcall log_backend_enable(log_backend * backend, void * ctx, uint32_t level)
 */


/* exclude_from_export */

void log_backend_enable(log_backend *backend,void *ctx,uint32_t level)

{
  if (backend == (log_backend *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend != ((void *)0)",
            "WEST_TOPDIR/zephyr/include/zephyr/logging/log_backend.h",223);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  backend->cb[4] = (char)((int)((int)&backend[-43999].api + 3) >> 4) + '\x01';
  backend->cb[6] = (char)level;
  *(void **)backend->cb = ctx;
  backend->cb[5] = 1;
  z_log_notify_backend_enabled();
  return;
}


