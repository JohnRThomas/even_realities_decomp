/*
 * Function: char_out
 * Entry:    00051204
 * Prototype: int __stdcall char_out(uint8_t * data, size_t length, void * ctx)
 */


/* exclude_from_export_ai */

int char_out(uint8_t *data,size_t length,void *ctx)

{
  uchar *puVar1;
  
  puVar1 = data + length;
  for (; data != puVar1; data = data + 1) {
    uarte_nrfx_poll_out(&uart_dev,*data);
  }
  return length;
}


