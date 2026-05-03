/*
 * Function: _clean_fb_data
 * Entry:    0004ab3c
 * Prototype: int __stdcall _clean_fb_data(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
 */


int _clean_fb_data(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  
  if (0x27f < param_5) {
    param_5 = 0x280;
  }
  if (199 < param_6) {
    param_6 = 200;
  }
  if ((param_5 < param_3) || (param_6 < param_4)) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): clean frame buffer parameter error!!!\n");
      }
      else {
        ble_printk("%s(): clean frame buffer parameter error!!!\n","_clean_fb_data",param_3,
                   BLE_DEBUG);
      }
    }
    iVar2 = -1;
  }
  else {
    iVar2 = param_3 / 2;
    piVar1 = (int *)(param_1 + (param_4 + 0x3fffffff) * 4);
    while ((int *)(param_1 + param_6 * 4) != piVar1) {
      piVar1 = piVar1 + 1;
      memset((void *)(*piVar1 + iVar2),param_2,(1 - iVar2) + param_5 / 2);
    }
    iVar2 = (param_5 / 2 - iVar2) + 1;
  }
  return iVar2;
}


