/*
 * Function: dropped_notify
 * Entry:    00050748
 * Prototype: void __stdcall dropped_notify(void)
 */


/* exclude_from_export */

void dropped_notify(void)

{
  uint32_t uVar1;
  char *test;
  char *file;
  int line;
  undefined **ppuVar2;
  
  uVar1 = z_log_dropped_read_and_clear();
  ppuVar2 = &PTR_PTR_0008ba50;
  while( true ) {
    if (&PTR_s_bt_0008ba60 < ppuVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend <= _log_backend_list_end",
              "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",465);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_DAT_0008ba5c + 3U) < ppuVar2) break;
    if ((ppuVar2[1][5] != '\0') && (*(code **)(*ppuVar2 + 4) != (code *)0x0)) {
      (**(code **)(*ppuVar2 + 4))(ppuVar2,uVar1);
    }
    ppuVar2 = ppuVar2 + 4;
  }
  return;
}


