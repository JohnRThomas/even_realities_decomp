/*
 * Function: z_timeout_expires
 * Entry:    000777ec
 * Prototype: k_ticks_t __stdcall z_timeout_expires(_timeout * timeout)
 */


/* exclude_from_export_ai */

k_ticks_t z_timeout_expires(_timeout *timeout)

{
  undefined4 in_r1;
  
  _current.next_event_link = (undefined *)&_current.next_event_link;
  _current.events = 0x2000be4c;
  return CONCAT44(in_r1,timeout);
}


