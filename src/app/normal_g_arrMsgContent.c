/*
 * Function: ?_normal_g_arrMsgContent
 * Entry:    00035120
 * Prototype: undefined __stdcall ?_normal_g_arrMsgContent(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void __normal_g_arrMsgContent(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_2000878c;
  do {
    if (BLE_DEBUG == 0) {
      printk("normal g_arrMsgContent[%d].uidTail is %d %d recvTime %d\n",iVar1,puVar2[2],puVar2[1],
             *puVar2,param_2,param_3);
    }
    else {
      ble_printk("normal g_arrMsgContent[%d].uidTail is %d %d recvTime %d\n");
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x6d;
  } while (iVar1 != 10);
  return;
}


