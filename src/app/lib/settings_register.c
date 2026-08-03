/*
 * Function: settings_register
 * Entry:    00051734
 * Prototype: int __stdcall settings_register(settings_handler * cf)
 */


/* exclude_from_export_ai */

int settings_register(settings_handler *cf)

{
  int iVar1;
  undefined4 in_r1;
  char *test;
  undefined4 extraout_r1;
  char *file;
  int line;
  sys_snode_t *psVar2;
  undefined **ppuVar3;
  sys_snode_t *psVar4;
  k_timeout_t timeout;
  
  ppuVar3 = &PTR_s_bt_0008ba60;
  while( true ) {
    if (&PTR_img_mgmt_register_group_1_0008bad8 < ppuVar3) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","ch <= _settings_handler_static_list_end",
              "WEST_TOPDIR/zephyr/subsys/settings/src/settings.c",0x2b);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008bad4 + 3U) < ppuVar3) break;
    iVar1 = strcmp(cf->name,*ppuVar3);
    if (iVar1 == 0) {
      return -0x11;
    }
    ppuVar3 = ppuVar3 + 5;
    in_r1 = extraout_r1;
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  z_impl_k_mutex_lock((k_mutex *)&settings_lock,timeout);
  psVar4 = DAT_2000aaec;
  do {
    if (psVar4 == (sys_snode_t *)0x0) {
      (cf->node).next = (sys_snode_t *)0x0;
      psVar2 = &cf->node;
      psVar4 = psVar2;
      if (DAT_2000aaf0 != (sys_snode_t *)0x0) {
        DAT_2000aaf0->next = psVar2;
        psVar4 = DAT_2000aaec;
      }
      DAT_2000aaec = psVar4;
      iVar1 = 0;
      DAT_2000aaf0 = psVar2;
LAB_000517a2:
      z_impl_k_mutex_unlock((k_mutex *)&settings_lock);
      return iVar1;
    }
    iVar1 = strcmp(cf->name,((settings_handler *)(psVar4 + -5))->name);
    if (iVar1 == 0) {
      iVar1 = -0x11;
      goto LAB_000517a2;
    }
    psVar4 = psVar4->next;
  } while( true );
}


