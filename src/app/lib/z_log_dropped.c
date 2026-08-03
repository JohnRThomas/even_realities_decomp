/*
 * Function: z_log_dropped
 * Entry:    00050708
 * Prototype: void __stdcall z_log_dropped(bool buffered)
 */


/* exclude_from_export */

void z_log_dropped(bool buffered)

{
  atomic_inc(&dropped_cnt);
  if (buffered) {
    buffered_cnt = buffered_cnt + -1;
  }
  return;
}


