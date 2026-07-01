/*
 * Function: ?_normal_g_arrMsgContent
 * Entry:    00035120
 * Prototype: undefined __stdcall ?_normal_g_arrMsgContent(void)
 */


void __normal_g_arrMsgContent(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  pcVar1 = (char *)0x0;
  puVar2 = &DAT_2000878c;
  do {
    if (BLE_DEBUG == 0) {
      printk("normal g_arrMsgContent[%d].uidTail is %d %d recvTime %d\n");
    }
    else {
      ble_printk("normal g_arrMsgContent[%d].uidTail is %d %d recvTime %d\n",pcVar1,puVar2[2],
                 puVar2[1],*puVar2);
    }
    pcVar1 = pcVar1 + 1;
    puVar2 = puVar2 + 0x6d;
  } while (pcVar1 != &DAT_0000000a);
  return;
}


