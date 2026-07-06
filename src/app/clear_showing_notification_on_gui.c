/*
 * Function: ?_clear_showing_notification_on_gui
 * Entry:    00045428
 * Prototype: int __stdcall ?_clear_showing_notification_on_gui(void)
 */


int __clear_showing_notification_on_gui(void)

{
  DAT_2000aa10 = DAT_2000aa10 & 0xfffffffd;
  return 0;
}


