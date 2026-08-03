/*
 * Function: z_log_dropped_read_and_clear
 * Entry:    00050730
 * Prototype: uint32_t __stdcall z_log_dropped_read_and_clear(void)
 */


/* exclude_from_export */

uint32_t z_log_dropped_read_and_clear(void)

{
  uint32_t uVar1;
  
  uVar1 = dropped_cnt;
  dropped_cnt = 0;
  return uVar1;
}


