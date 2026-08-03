/*
 * Function: bt_hci_driver_register
 * Entry:    00057b3c
 * Prototype: int __stdcall bt_hci_driver_register(bt_hci_driver * drv)
 */


/* exclude_from_export */

int bt_hci_driver_register(bt_hci_driver *drv)

{
  if (DAT_20002168 != (bt_hci_driver *)0x0) {
    return -0x78;
  }
  if ((drv->open != (undefined *)0x0) && (drv->send != (undefined *)0x0)) {
    DAT_20002168 = drv;
    return 0;
  }
  return -0x16;
}


