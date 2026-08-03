/*
 * Function: log_output_flush
 * Entry:    00082666
 * Prototype: void __stdcall log_output_flush(log_output * output)
 */


/* exclude_from_export */

void log_output_flush(log_output *output)

{
  buffer_write(output->func,output->buf,*(size_t *)output->control_block,
               *(void **)((int)output->control_block + 4));
  *(undefined4 *)output->control_block = 0;
  return;
}


