/*
 * Function: push_message
 * Entry:    0003558c
 * Prototype: char __stdcall push_message(void * param_1, undefined4 param_2, undefined4 param_3)
 */


char push_message(void *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char *fmt;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar5;
  undefined4 *d;
  uint uVar6;
  int iVar7;
  
  iVar7 = LOG_LEVEL;
  pvVar3 = param_1;
  if (param_1 == (void *)0x0) {
    uVar5 = 0x35c;
    pcVar4 = "push_message";
    fmt = "[%s-%d] message is NULL \n";
  }
  else if (*(int *)((int)param_1 + 0x1b0) == 0) {
    iVar2 = FUN_0003555c(0x14,*(int *)((int)param_1 + 8));
    uVar5 = extraout_r1;
    if (iVar2 == 0) {
LAB_000355ea:
      bVar1 = APP_WHITE_LIST_BUF;
      uVar6 = (uint)APP_WHITE_LIST_BUF;
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0xfe;
      if (uVar6 < 0x14) {
        *(undefined1 *)((int)param_1 + 0xe) = 0;
        *(undefined1 *)((int)param_1 + 0xd) = 0;
        *(byte *)((int)param_1 + 0xc) = bVar1;
        memcpy(&DAT_2000878c + uVar6 * 0x6d,param_1,0x1b4);
        if (0 < iVar7) {
          if (BLE_DEBUG == 0) {
            printk("%s(): update pos to %d, uidtail %d message->startShowTime %d action %d\n",
                   "push_message",uVar6,*(undefined4 *)((int)param_1 + 8),
                   *(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 0x1b0));
          }
          else {
            ble_printk("%s(): update pos to %d, uidtail %d message->startShowTime %d action %d\n");
          }
        }
        APP_WHITE_LIST_BUF = APP_WHITE_LIST_BUF + 1;
      }
      else {
        if (0 < iVar7) {
          if (BLE_DEBUG == 0) {
            printk("%s(): update pos to %d, uidtail %d message->startShowTime %d\n","push_message",
                   0x13,uVar5,*(undefined4 *)((int)param_1 + 4));
          }
          else {
            ble_printk("%s(): update pos to %d, uidtail %d message->startShowTime %d\n",
                       "push_message",0x13);
          }
        }
        iVar7 = 10;
        d = &DAT_20009894;
        do {
          if (*(char *)((int)d + 0xd) == '\0') {
            pvVar3 = memcpy(d,d + 0x6d,0x1b4);
            *(char *)((int)pvVar3 + 0xc) = (char)iVar7;
            if (*(char *)((int)pvVar3 + 0xe) == '\0') {
              *(undefined1 *)((int)param_1 + 0xd) = 0;
            }
          }
          iVar7 = iVar7 + 1;
          d = d + 0x6d;
        } while (iVar7 != 0x13);
        memcpy(&DAT_2000a7e8,param_1,0x1b4);
        APP_WHITE_LIST_BUF = '\x14';
        DAT_2000a7f4 = 0x13;
        DAT_2000a7f6 = 0;
      }
      if (BLE_DEBUG == 0) {
        printk("[csh_debug_msg]push_message g_msg_num_push is %d \n");
        return APP_WHITE_LIST_BUF;
      }
      ble_printk("[csh_debug_msg]push_message g_msg_num_push is %d \n");
      return APP_WHITE_LIST_BUF;
    }
    if (iVar7 < 1) {
      return '\0';
    }
    pcVar4 = "push_message";
    fmt = "%s(): slave add found same message, uidtail %d\n";
  }
  else {
    iVar2 = FUN_0003555c(0x14,*(int *)((int)param_1 + 8));
    uVar5 = extraout_r1_00;
    if (iVar2 != 0) goto LAB_000355ea;
    if (iVar7 < 1) {
      return '\0';
    }
    pcVar4 = "push_message";
    fmt = "%s(): can not found same message, uidtail %d\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,pcVar4,uVar5,0,pvVar3,param_2,param_3);
  }
  else {
    ble_printk(fmt);
  }
  return '\0';
}


