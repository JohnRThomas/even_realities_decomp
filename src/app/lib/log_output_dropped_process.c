/*
 * Function: log_output_dropped_process
 * Entry:    00051108
 * Prototype: void __stdcall log_output_dropped_process(log_output * output, uint32_t cnt)
 */


/* exclude_from_export */

void log_output_dropped_process(log_output *output,uint32_t cnt)

{
  size_t len;
  uint32_t uVar1;
  log_output_func_t outf;
  log_output *plStack_18;
  uint32_t uStack_14;
  
  uVar1 = 9999;
  if (cnt < 10000) {
    uVar1 = cnt;
  }
  outf = output->func;
  plStack_18 = output;
  uStack_14 = cnt;
  len = snprintk((char *)&plStack_18,5,"%d",uVar1);
  buffer_write(outf,(uint8_t *)"\x1b[1;31m--- ",0xb,*(void **)(output->control_block + 4));
  buffer_write(outf,(uint8_t *)&plStack_18,len,*(void **)(output->control_block + 4));
  buffer_write(outf,(uint8_t *)" messages dropped ---\r\n\x1b[0m",0x1b,
               *(void **)(output->control_block + 4));
  return;
}


