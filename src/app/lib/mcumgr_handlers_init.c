/*
 * Function: mcumgr_handlers_init
 * Entry:    000545b0
 * Prototype: int __stdcall mcumgr_handlers_init(void)
 */


/* exclude_from_export */

int mcumgr_handlers_init(void)

{
  char *test;
  char *file;
  int line;
  code *pcVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  ppuVar2 = &PTR_img_mgmt_register_group_1_0008bad8;
  while( true ) {
    if (&QWORD_0008bae8 < ppuVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","handler <= _mcumgr_handler_list_end",
              "WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/mgmt/src/mgmt.c",199);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_zephyr_basic_mgmt_init_1_0008bae4 + 3U) < ppuVar2) break;
    ppuVar3 = ppuVar2 + 1;
    pcVar1 = (code *)*ppuVar2;
    ppuVar2 = ppuVar3;
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
  }
  return 0;
}


