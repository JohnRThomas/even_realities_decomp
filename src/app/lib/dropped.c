/*
 * Function: dropped
 * Entry:    000511d4
 * Prototype: void __stdcall dropped(log_backend * backend, uint32_t cnt)
 */


/* exclude_from_export */

void dropped(log_backend *backend,uint32_t cnt)

{
  log_output_dropped_process((log_output *)&PTR_char_out_1_0008e898,cnt);
  return;
}


