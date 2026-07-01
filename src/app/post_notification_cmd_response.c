/*
 * Function: post_notification_cmd_response
 * Entry:    00035700
 * Prototype: undefined4 __stdcall post_notification_cmd_response(int param_1, int param_2, int param_3, int param_4, int param_5, undefined4 * param_6)
 */


undefined4
post_notification_cmd_response
          (int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 *param_6)

{
  char *fmt;
  int iVar1;
  int extraout_r1;
  int iVar2;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r2;
  int iVar3;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  undefined1 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  if (((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || ((param_4 == 0 || (param_5 == 0))))
     || (param_6 == (undefined4 *)0x0)) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): input parm invalid !\n");
      }
      else {
        ble_printk("%s(): input parm invalid !\n","post_notification_cmd_response",param_5,BLE_DEBUG
                   ,param_1,param_2,param_3);
      }
    }
    return 0;
  }
  iVar3 = param_2;
  iVar2 = param_1;
  iVar7 = param_2;
  iVar1 = param_3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): BLE_REQ_POST_NOTIFICATION_MSG source:%d\n");
      iVar3 = extraout_r1_00;
      param_5 = extraout_r2_01;
    }
    else {
      ble_printk("%s(): BLE_REQ_POST_NOTIFICATION_MSG source:%d\n","post_notification_cmd_response",
                 (uint)*(byte *)(param_4 + 1),BLE_DEBUG,param_1,param_2,param_3);
      iVar3 = extraout_r1;
      param_5 = extraout_r2;
    }
  }
  if (*(char *)(param_4 + 1) == '\x04') {
    strcpy((char *)(*(int *)(param_1 + 0xffc) + 8),(char *)(param_2 + 0x54));
    strcpy((char *)(*(int *)(param_1 + 0xffc) + 0x19),(char *)(param_2 + 0x94));
    iVar3 = 0;
    puVar4 = *(undefined1 **)(param_1 + 0xffc);
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    if (*(char *)(param_1 + 0xd5) == '\0') {
      *(undefined1 *)(param_1 + 0xb0d) = 1;
    }
    if (2 < LOG_LEVEL) {
      piVar5 = *(int **)(param_1 + 0xffc);
      iVar2 = *piVar5;
      iVar7 = param_2 + 0x194;
      if (BLE_DEBUG == 0) {
        printk("%s(): schedule_notif#title:%s, desc:%s, ts:%d, date:%s\n");
        iVar3 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): schedule_notif#title:%s, desc:%s, ts:%d, date:%s\n",
                   "post_notification_cmd_response",piVar5 + 2,(int)piVar5 + 0x19,iVar2,iVar7);
        iVar3 = extraout_r2_00;
      }
    }
  }
  else {
    uVar6 = (uint)*(ushort *)(param_4 + 2);
    if (uVar6 != 0x1b4) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): [%s-%d] invliad  message len, data_len is %d\n\n",
                   "post_notification_cmd_response","post_notification_cmd_response",0x158,uVar6,
                   iVar7,iVar1);
        return 0;
      }
      printk("%s(): [%s-%d] invliad  message len, data_len is %d\n\n",
             "post_notification_cmd_response","post_notification_cmd_response",0x158,uVar6);
      return 0;
    }
    if ((*(uint *)(param_2 + 0x1b4) < 2) &&
       (iVar1 = is_on_whitelist_by_identifier
                          ((char *)(param_2 + 0x14),iVar3,param_5,*(uint *)(param_2 + 0x1b4)),
       iVar3 = extraout_r1_01, param_5 = extraout_r2_04, 1 < (iVar1 - 2U & 0xff))) {
      iVar3 = extraout_r2_04;
      if (iVar1 == 1) {
        com_android_phone_missed(param_2 + 4);
        iVar3 = extraout_r2_05;
      }
    }
    else {
      push_message((void *)(param_2 + 4),iVar3,param_5);
      iVar3 = extraout_r2_03;
    }
  }
  if (*(char *)(param_3 + 1) == '\x04') {
    if (LOG_LEVEL < 3) goto LAB_000357e4;
    fmt = s__s____ble_ANCS___000a9ef6;
  }
  else {
    if ((*(char *)(param_3 + 1) != '\x06') || (LOG_LEVEL < 3)) goto LAB_000357e4;
    fmt = s__s____ble_dashboard___000a9f2b;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"post_notification_cmd_response",iVar3,BLE_DEBUG,iVar2,iVar7);
  }
LAB_000357e4:
  *param_6 = 0x646f6f47;
  *(undefined1 *)(param_6 + 1) = 0;
  return 5;
}


