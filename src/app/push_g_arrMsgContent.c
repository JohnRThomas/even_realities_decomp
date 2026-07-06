/*
 * Function: ?_push_g_arrMsgContent
 * Entry:    00035160
 * Prototype: undefined __stdcall ?_push_g_arrMsgContent(void)
 */


void __push_g_arrMsgContent(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 10;
  puVar2 = &DAT_20009894;
  do {
    if (BLE_DEBUG == 0) {
      printk("PUSH: g_arrMsgContent[%d].uidTail is %d push %d \n",iVar1,puVar2[2],*puVar2);
    }
    else {
      ble_printk("PUSH: g_arrMsgContent[%d].uidTail is %d push %d \n",iVar1);
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x6d;
  } while (iVar1 != 0x14);
  return;
}


