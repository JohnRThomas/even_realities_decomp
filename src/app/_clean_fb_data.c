/*
 * Function: _clean_fb_data
 * Entry:    0004ab3c
 * Prototype: int __stdcall _clean_fb_data(byte * buffer, int param_2, int x_start, int y_start, int x_end, int y_end)
 */


int _clean_fb_data(byte *buffer,int param_2,int x_start,int y_start,int x_end,int y_end)

{
  byte *pbVar1;
  int iVar2;
  
  if (639 < x_end) {
    x_end = 640;
  }
  if (199 < y_end) {
    y_end = 200;
  }
  if ((x_end < x_start) || (y_end < y_start)) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): clean frame buffer parameter error!!!\n","_clean_fb_data",x_start,0,y_start);
      }
      else {
        ble_printk("%s(): clean frame buffer parameter error!!!\n");
      }
    }
    iVar2 = -1;
  }
  else {
    iVar2 = x_start / 2;
    pbVar1 = buffer + (y_start + 0x3fffffff) * 4;
    while (buffer + y_end * 4 != pbVar1) {
      pbVar1 = pbVar1 + 4;
      memset((void *)(*(int *)pbVar1 + iVar2),param_2,(1 - iVar2) + x_end / 2);
    }
    iVar2 = (x_end / 2 - iVar2) + 1;
  }
  return iVar2;
}


