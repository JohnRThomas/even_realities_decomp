/*
 * Function: bt_rpmsg_init
 * Entry:    00063420
 * Prototype: int __stdcall bt_rpmsg_init(void)
 */


/* exclude_from_export */

int bt_rpmsg_init(void)

{
  int iVar1;
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  iVar1 = bt_hci_driver_register((bt_hci_driver *)&PTR_s_RPMsg_0008f174);
  if (iVar1 < 0) {
    local_1c = "Failed to register BT HIC driver (err %d)";
    local_20[0] = '\x03';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    iStack_18 = iVar1;
    LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1840,local_20);
  }
  return iVar1;
}


