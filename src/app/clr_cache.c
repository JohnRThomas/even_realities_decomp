/*
 * Function: $_clr_cache
 * Entry:    00080d76
 * Prototype: undefined __stdcall $_clr_cache(int param_1)
 */


void __clr_cache(int param_1)

{
  jbd_panel_context *pjVar1;
  byte *pBuf;
  
  pjVar1 = get_jdb_panel_context();
  pBuf = pjVar1->__panel_buffer;
  memset(pBuf,param_1,64000);
  spi_wr_buffer(0,0,pBuf,61440);
  spi_wr_buffer(0,192,pBuf,61440);
  spi_wr_buffer(0,384,pBuf,30720);
  return;
}


