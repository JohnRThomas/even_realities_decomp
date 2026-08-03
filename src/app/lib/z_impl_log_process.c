/*
 * Function: z_impl_log_process
 * Entry:    00050834
 * Prototype: void __stdcall z_impl_log_process(log_msg_generic * msg)
 */


/* exclude_from_export */

void z_impl_log_process(log_msg_generic *msg)

{
  uint uVar1;
  longlong lVar2;
  log_msg_generic *buffer;
  log_msg_generic *msg_00;
  char *test;
  log_msg_generic *extraout_r1;
  uint uVar3;
  char *file;
  int line;
  uint uVar4;
  undefined **ppuVar5;
  bool bVar6;
  ulonglong uVar7;
  
  if (DAT_2001e1bf == '\0') {
    return;
  }
  buffer = z_log_msg_local_claim();
  if (buffer != (log_msg_generic *)0x0) {
    msg_00 = buffered_cnt + -1;
    ppuVar5 = &PTR_PTR_0008ba50;
    buffered_cnt = msg_00;
    while( true ) {
      if (&PTR_s_bt_0008ba60 < ppuVar5) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend <= _log_backend_list_end",
                "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",453);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)((int)&PTR_DAT_0008ba5c + 3U) < ppuVar5) break;
      if (ppuVar5[1][5] != '\0') {
        (**(code **)*ppuVar5)(ppuVar5,buffer);
        msg_00 = extraout_r1;
      }
      ppuVar5 = ppuVar5 + 4;
    }
    msg_free((mpsc_pbuf_buffer *)buffer,msg_00);
  }
  if ((0 < dropped_cnt) &&
     (uVar7 = sys_clock_tick_get(), lVar2 = (uVar7 & 0xffffffff) * 1000,
     uVar3 = (int)(uVar7 >> 0x20) * 1000 + (int)((ulonglong)lVar2 >> 0x20),
     uVar4 = (uint)lVar2 >> 0xf | uVar3 * 0x20000, uVar3 = (uVar3 >> 0xf) - DAT_20005884,
     uVar1 = (uint)(uVar4 < DAT_20005880),
     uVar3 != uVar1 || uVar3 - uVar1 < (uint)(1000 < uVar4 - DAT_20005880))) {
    dropped_notify();
  }
  bVar6 = 0xfffffc17 < DAT_20005880;
  DAT_20005880 = DAT_20005880 + 1000;
  DAT_20005884 = DAT_20005884 + (uint)bVar6;
  return;
}


