/*
 * Function: draw_message
 * Entry:    000372f8
 * Prototype: undefined __stdcall draw_message(undefined4 param_1, undefined4 * param_2)
 */


void draw_message(undefined4 param_1,undefined4 *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *param3;
  char *param3_00;
  char local_1b4 [40];
  char local_18c [72];
  char local_144 [292];
  
  local_18c[0] = '\0';
  local_18c[1] = '\0';
  local_18c[2] = '\0';
  local_18c[3] = '\0';
  memset(local_18c + 4,0,0x44);
  local_1b4[8] = '\0';
  local_1b4[9] = '\0';
  local_1b4[10] = '\0';
  local_1b4[0xb] = '\0';
  memset(local_1b4 + 0xc,0,0x1c);
  local_1b4[0] = '\0';
  local_1b4[1] = '\0';
  local_1b4[2] = '\0';
  local_1b4[3] = '\0';
  local_1b4[4] = '\0';
  local_1b4[5] = '\0';
  local_1b4[6] = '\0';
  local_1b4[7] = '\0';
  local_144[0] = '\0';
  local_144[1] = '\0';
  local_144[2] = '\0';
  local_144[3] = '\0';
  memset(local_144 + 4,0,0x11f);
  if (param_2 == (undefined4 *)0x0) {
    if (BLE_DEBUG != 0) {
      ble_printk("[%s-%d]curMsg is NULL !\n","draw_message",0x193,BLE_DEBUG);
      return;
    }
    printk("[%s-%d]curMsg is NULL !\n");
    return;
  }
  bVar1 = FUN_000359cc();
  pcVar4 = (char *)__parse_message_type((uint)bVar1);
  if (BLE_DEBUG == 0) {
    printk("show msgType is %d unReadCount %d\n");
  }
  else {
    ble_printk("show msgType is %d unReadCount %d\n",pcVar4,param_1,BLE_DEBUG);
  }
  param3_00 = (char *)(param_2 + 0x24);
  switch(pcVar4) {
  case (char *)0x0:
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    uVar6 = 0x38;
    goto LAB_0003760a;
  case (char *)0x1:
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x37,iVar7,uVar3 + 4,0,0,0);
    memset(local_18c,0,0x48);
    param3 = param3_00;
    break;
  case (char *)0x2:
    memset(local_18c,0,0x48);
    snprintf(local_18c,0x48,"%s",param3_00);
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar5 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_utf_draw_middle(0,local_18c,0,iVar7,uVar3 + 0x36,iVar5 + 0x240,uVar2 + 0x51,1,0,0,
                        (undefined *)0x0,0);
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x36,iVar7,uVar3 + 0x3a,0,0,0);
    memset(local_144,0,0x123);
    snprintf(local_144,0x123,"%s",(char *)(param_2 + 0x14));
    if (local_144[0] == '\0') {
      return;
    }
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar5 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_utf_draw_middle(0,local_144,0,iVar7,uVar3 + 0x51,iVar5 + 0x240,uVar2 + 0x51,1,0,0,
                        (undefined *)0x0,0);
    return;
  case (char *)0x3:
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x3a,iVar7,uVar3 + 4,0,0,0);
    memset(local_18c,0,0x48);
LAB_000374b8:
    snprintf(local_18c,0x48,"%s | %s",(char *)(param_2 + 0xc),(char *)(param_2 + 0x1c));
    goto LAB_000374c2;
  case (char *)0x4:
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    uVar6 = 0x39;
LAB_0003760a:
    gui_bmp_bitmap_draw(uVar6,iVar7,uVar3 + 4,0,0,0);
    memset(local_18c,0,0x48);
    param3 = (char *)(param_2 + 0xc);
    break;
  default:
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x38,iVar7,uVar3 + 4,0,0,0);
    memset(local_18c,0,0x48);
    param3 = (char *)(param_2 + 0xc);
    if (*(char *)(param_2 + 0x1c) != '\0') goto LAB_000374b8;
  }
  snprintf(local_18c,0x48,"%s",param3);
LAB_000374c2:
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw_truncate
            (0,local_18c,0,iVar7 + 0x24,(uint)uVar3,iVar5 + 0x186,uVar2 + 0x1b,1,0,0,
             (undefined *)0x0,0);
  if (BLE_DEBUG == 0) {
    printk("recvTime is %u,curMsg->message %s\n");
  }
  else {
    ble_printk("recvTime is %u,curMsg->message %s\n",(char *)*param_2,param3_00,BLE_DEBUG);
  }
  __draw_time(local_1b4 + 8,(char *)*param_2);
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  gui_bmp_bitmap_draw(0x3c,iVar7 + 0x210,(uint)uVar3,0,0,0);
  local_1b4[0] = '\0';
  local_1b4[1] = '\0';
  local_1b4[2] = '\0';
  local_1b4[3] = '\0';
  local_1b4[4] = '\0';
  local_1b4[5] = '\0';
  local_1b4[6] = '\0';
  local_1b4[7] = '\0';
  __sprintf_chk(local_1b4,0,8,"%u",param_1);
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw(0,local_1b4,0,iVar7 + 0x22c,(uint)uVar3,iVar5 + 0x244,uVar2 + 0x1b,1,0,0,
               (undefined *)0x0,0);
  memset(local_144,0,0x123);
  if (pcVar4 == &DAT_00000001) {
    snprintf(local_144,0x123,"%s",(char *)(param_2 + 0x14));
  }
  else {
    if (pcVar4 != &Reset) {
      if (*(char *)(param_2 + 0x14) == '\0') {
        snprintf(local_144,0x123,"%s",param3_00);
      }
      else {
        snprintf(local_144,0x123,"%s - %s",(char *)(param_2 + 0x14),param3_00);
      }
      if (local_144[0] == '\0') {
        return;
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar5 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      goto LAB_000375e8;
    }
    snprintf(local_144,0x123,"%s\n%s",(char *)(param_2 + 0x14),param3_00);
  }
  if (local_144[0] == '\0') {
    return;
  }
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
LAB_000375e8:
  gui_utf_Wordwrap_draw
            (0,local_144,0,iVar7,uVar3 + 0x36,iVar5 + 0x240,uVar2 + 0x87,3,0,0,(undefined *)0x0,0);
  return;
}


