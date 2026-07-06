/*
 * Function: spi_wr_buffer
 * Entry:    0004af6c
 * Prototype: int __stdcall spi_wr_buffer(uint16_t col, uint16_t row, uint8_t * pBuf, uint32_t len)
 */


int spi_wr_buffer(uint16_t col,uint16_t row,uint8_t *pBuf,uint32_t len)

{
  jbd_panel_context *pjVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint local_1c;
  
  local_1c = len & 0xffffff00;
  uVar4 = (uint)row;
  pjVar1 = get_jdb_panel_context();
  pbVar3 = pjVar1->current_buffer;
  iVar2 = (row & 0x1ff) << 10;
  pbVar3[-5] = 2;
  pbVar3[-3] = (byte)(((uint)col << 0x16) >> 0x1e) | (byte)((uint)iVar2 >> 8);
  pbVar3[-4] = (byte)((uint)iVar2 >> 0x10);
  pbVar3[-2] = (byte)col;
  pbVar3[-1] = 0xff;
  __lock_lcd_mutex(-1);
  (*(code *)pjVar1->spi_callbacks->rx_tx)
            (pjVar1->spi_callbacks,pbVar3 + -5,len + 6,&local_1c,1,uVar4,pBuf);
  iVar2 = __unlock_lcd_mutex();
  return iVar2;
}


