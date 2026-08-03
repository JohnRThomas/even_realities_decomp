/*
 * Function: z_log_init
 * Entry:    000505d4
 * Prototype: uint32_t __stdcall z_log_init(bool blocking, bool can_sleep)
 */


/* WARNING: Removing unreachable block (ram,0x000505ea) */
/* exclude_from_export */

uint32_t z_log_init(bool blocking,bool can_sleep)

{
  atomic_val_t aVar1;
  int iVar2;
  uint mask;
  char *test;
  char *file;
  int line;
  undefined **backend;
  uint uVar3;
  
  backend = &PTR_PTR_0008ba50;
  aVar1 = atomic_inc((atomic_t *)&DAT_2000aabc);
  if (aVar1 == 0) {
    mask = 0;
    uVar3 = 0;
    while( true ) {
      if (&PTR_s_bt_0008ba60 < backend) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend <= _log_backend_list_end",
                "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",294);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((log_backend *)((int)&PTR_DAT_0008ba5c + 3U) < backend) break;
      if (((log_backend *)backend)->autostart != 0) {
        if (*(code **)(((log_backend *)backend)->api + 0xc) != (code *)0x0) {
          (**(code **)(((log_backend *)backend)->api + 0xc))(backend);
        }
        if ((*(code **)(((log_backend *)backend)->api + 0x10) == (code *)0x0) ||
           (iVar2 = (**(code **)(((log_backend *)backend)->api + 0x10))(backend), iVar2 == 0)) {
          log_backend_enable((log_backend *)backend,*(void **)((log_backend *)backend)->cb,4);
        }
        else {
          mask = mask | 1 << (uVar3 & 0xff);
        }
        uVar3 = uVar3 + 1;
      }
      backend = (undefined **)((int)&((log_backend *)((int)backend + 0xd))->api + 3);
    }
    if (!blocking) {
      return mask;
    }
    while (mask != 0) {
      mask = activate_foreach_backend(mask);
      if (can_sleep) {
        z_impl_k_sleep((k_timeout_t)0x148);
      }
    }
  }
  return 0;
}


