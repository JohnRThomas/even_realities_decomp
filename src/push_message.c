/*
 * Function: push_message
 * Entry:    0003558c
 * Prototype: undefined1 __stdcall push_message(void * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined1 push_message(void *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 *d;
  uint uVar7;
  int iVar8;
  
  iVar8 = LOG_LEVEL;
  if (param_1 == (void *)0x0) {
    uVar6 = 0x35c;
    pcVar5 = "push_message";
    pcVar2 = "[%s-%d] message is NULL \n";
  }
  else if (*(int *)((int)param_1 + 0x1b0) == 0) {
    iVar3 = FUN_0003555c(0x14,*(int *)((int)param_1 + 8));
    uVar6 = extraout_r1;
    if (iVar3 == 0) {
LAB_000355ea:
      bVar1 = APP_WHITE_LIST_BUF;
      uVar7 = (uint)APP_WHITE_LIST_BUF;
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0xfe;
      if (uVar7 < 0x14) {
        *(undefined1 *)((int)param_1 + 0xe) = 0;
        *(undefined1 *)((int)param_1 + 0xd) = 0;
        *(byte *)((int)param_1 + 0xc) = bVar1;
        memcpy(&DAT_2000878c + uVar7 * 0x6d,param_1,0x1b4);
        uVar6 = extraout_r2;
        if (0 < iVar8) {
          if (BLE_DEBUG == 0) {
            printk("%s(): update pos to %d, uidtail %d message->startShowTime %d action %d\n");
            uVar6 = extraout_r2_01;
          }
          else {
            ble_printk("%s(): update pos to %d, uidtail %d message->startShowTime %d action %d\n",
                       "push_message",uVar7,*(undefined4 *)((int)param_1 + 8));
            uVar6 = extraout_r2_00;
          }
        }
        pcVar2 = (char *)(uint)(byte)(APP_WHITE_LIST_BUF + 1);
      }
      else {
        if (0 < iVar8) {
          if (BLE_DEBUG == 0) {
            printk("%s(): update pos to %d, uidtail %d message->startShowTime %d\n","push_message",
                   0x13,uVar6,*(undefined4 *)((int)param_1 + 4),param_2,param_3);
          }
          else {
            ble_printk("%s(): update pos to %d, uidtail %d message->startShowTime %d\n",
                       "push_message",0x13,uVar6);
          }
        }
        iVar8 = 10;
        d = &DAT_20009894;
        do {
          if (*(char *)((int)d + 0xd) == '\0') {
            pvVar4 = memcpy(d,d + 0x6d,0x1b4);
            *(char *)((int)pvVar4 + 0xc) = (char)iVar8;
            if (*(char *)((int)pvVar4 + 0xe) == '\0') {
              *(undefined1 *)((int)param_1 + 0xd) = 0;
            }
          }
          iVar8 = iVar8 + 1;
          d = d + 0x6d;
        } while (iVar8 != 0x13);
        memcpy(&DAT_2000a7e8,param_1,0x1b4);
        uVar6 = 0;
        pcVar2 = &BusFault;
        DAT_2000a7f4 = 0x13;
        DAT_2000a7f6 = 0;
      }
      APP_WHITE_LIST_BUF = (byte)pcVar2;
      if (BLE_DEBUG == 0) {
        printk("[csh_debug_msg]push_message g_msg_num_push is %d \n");
        return APP_WHITE_LIST_BUF;
      }
      ble_printk("[csh_debug_msg]push_message g_msg_num_push is %d \n",pcVar2,uVar6,BLE_DEBUG);
      return APP_WHITE_LIST_BUF;
    }
    if (iVar8 < 1) {
      return 0;
    }
    pcVar5 = "push_message";
    pcVar2 = "%s(): slave add found same message, uidtail %d\n";
  }
  else {
    iVar3 = FUN_0003555c(0x14,*(int *)((int)param_1 + 8));
    uVar6 = extraout_r1_00;
    if (iVar3 != 0) goto LAB_000355ea;
    if (iVar8 < 1) {
      return 0;
    }
    pcVar5 = "push_message";
    pcVar2 = "%s(): can not found same message, uidtail %d\n";
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar2);
  }
  else {
    ble_printk(pcVar2,pcVar5,uVar6,BLE_DEBUG);
  }
  return 0;
}


