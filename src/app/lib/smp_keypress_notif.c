/*
 * Function: smp_keypress_notif
 * Entry:    0008685c
 * Prototype: uint8_t __stdcall smp_keypress_notif(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_keypress_notif(bt_smp *smp,net_buf *buf)

{
  atomic_set_bit((atomic_t *)smp,0xe);
  return '\0';
}


