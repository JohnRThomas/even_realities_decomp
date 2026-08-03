/*
 * Function: newline_print
 * Entry:    00050d30
 * Prototype: void __stdcall newline_print(log_output * ctx, uint32_t flags)
 */


/* exclude_from_export */

void newline_print(log_output *ctx,uint32_t flags)

{
  char *fmt;
  
  if ((int)(flags << 0x1b) < 0) {
    return;
  }
  if ((int)(flags << 0x1a) < 0) {
    fmt = "\n";
  }
  else {
    fmt = "\r\n";
  }
  print_formatted(ctx,fmt);
  return;
}


