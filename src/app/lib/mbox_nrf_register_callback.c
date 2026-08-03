/*
 * Function: mbox_nrf_register_callback
 * Entry:    000874e4
 * Prototype: int __stdcall mbox_nrf_register_callback(device * dev, uint32_t channel, mbox_callback_t * cb, void * user_data)
 */


/* exclude_from_export */

int mbox_nrf_register_callback(device *dev,uint32_t channel,mbox_callback_t *cb,void *user_data)

{
  int iVar1;
  undefined *unaff_r4;
  
  if (channel < 0x10) {
    unaff_r4 = dev->data + channel * 4;
    *(mbox_callback_t **)(dev->data + channel * 4) = cb;
  }
  if (channel < 0x10) {
    *(void **)(unaff_r4 + 0x40) = user_data;
    iVar1 = 0;
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


