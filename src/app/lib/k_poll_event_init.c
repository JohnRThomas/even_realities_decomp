/*
 * Function: k_poll_event_init
 * Entry:    0007881c
 * Prototype: void __stdcall k_poll_event_init(k_poll_event * event, uint32_t type, int mode, void * obj)
 */


/* exclude_from_export */

void k_poll_event_init(k_poll_event *event,uint32_t type,int mode,void *obj)

{
  char *test;
  char *test_00;
  char *test_01;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  int line_00;
  int line_01;
  
  if (mode == 0) {
    if (type < 0x40) {
      if (obj != (void *)0x0) {
        event->poller = (undefined *)0x0;
        event->tag = (type & 0x3f) << 8 | (uint)(byte)event->tag;
        event->type__POLL_NUM_TYPES = (dword)obj;
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","obj != ((void *)0)",
              "WEST_TOPDIR/zephyr/kernel/poll.c",48);
      _ASSERT("\tmust provide an object\n\n",test_01,file_01,line_01);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","type < ((1UL << (_POLL_NUM_TYPES)))",
              "WEST_TOPDIR/zephyr/kernel/poll.c",47);
      _ASSERT("\tinvalid type\n\n",test_00,file_00,line_00);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","mode == K_POLL_MODE_NOTIFY_ONLY",
            "WEST_TOPDIR/zephyr/kernel/poll.c",0x2d);
    _ASSERT("\tonly NOTIFY_ONLY mode is supported\n\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


