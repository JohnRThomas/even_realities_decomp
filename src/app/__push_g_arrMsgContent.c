/*
 * Function: ?_push_g_arrMsgContent
 * Entry:    00035160
 * Prototype: undefined __stdcall ?_push_g_arrMsgContent(void)
 */


void __push_g_arrMsgContent(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  pcVar1 = (char *)0xa;
  puVar2 = &DAT_20009894;
  do {
    if (BLE_DEBUG == 0) {
      printk("PUSH: g_arrMsgContent[%d].uidTail is %d push %d \n",pcVar1);
    }
    else {
      ble_printk("PUSH: g_arrMsgContent[%d].uidTail is %d push %d \n",pcVar1,puVar2[2],*puVar2);
    }
    pcVar1 = pcVar1 + 1;
    puVar2 = puVar2 + 0x6d;
  } while (pcVar1 != &BusFault);
  return;
}


