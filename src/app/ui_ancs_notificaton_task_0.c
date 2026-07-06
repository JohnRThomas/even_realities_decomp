/*
 * Function: ui_ancs_notificaton_task_0
 * Entry:    0003783c
 * Prototype: undefined4 __stdcall ui_ancs_notificaton_task_0(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_ancs_notificaton_task_0(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  char *fmt;
  undefined4 extraout_r1;
  int extraout_r2;
  int iVar4;
  uint uVar5;
  undefined4 *puStack_24;
  
  puStack_24 = (undefined4 *)0x0;
  if (param_3 == 2) {
    if (BLE_DEBUG == 0) {
      printk("ui_ancs_notificaton_task exit !");
    }
    else {
      ble_printk("ui_ancs_notificaton_task exit !");
    }
    CHAR____200033f6 = -1;
    CHAR____200033f5 = -1;
    INT_200024e0 = -1;
    if (DAT_2001c4de == '\0') {
      gui_screen_clear();
    }
    else {
      __hide_icon_notification_on_gui();
      DAT_2001c4de = '\0';
    }
    DAT_20019a6d = 0;
    exit_notification_burial_point();
  }
  else if (param_3 != 0) {
    bVar1 = FUN_000359cc();
    uVar3 = FUN_00035310();
    iVar4 = extraout_r2;
    uVar5 = (uint)(byte)CHAR____200033f6;
    if ((((uint)(byte)CHAR____200033f6 == (uint)bVar1) &&
        (uVar5 = (uint)(byte)CHAR____200033f5, (byte)CHAR____200033f5 == uVar3)) &&
       (iVar4 = puStack_24[2], uVar5 = INT_200024e0, iVar4 == INT_200024e0)) {
      return 0;
    }
    bVar2 = pull_message(&puStack_24,extraout_r1,iVar4,uVar5);
    if (bVar2 < 10) {
      if ((int)((uint)*(byte *)((int)puStack_24 + 0xf) << 0x1f) < 0) {
        if (*(char *)((int)puStack_24 + 0xe) != '\0') {
          if (CHAR____200033f6 == -1) {
            __set_frame_buffer(param_1 + 0x24);
            __set_showing_notification_on_gui();
            gui_screen_clear();
            enter_notification_burial_point();
          }
          if (DAT_2001c4dd != '\0') {
            draw_particle_effects(param_1 + 0x24,uVar3,puStack_24);
            DAT_2001c4dd = '\0';
          }
          draw_message(uVar3,puStack_24);
          INT_200024e0 = puStack_24[2];
          CHAR____200033f5 = (char)uVar3;
          CHAR____200033f6 = bVar1;
          DAT_20019a6d = 0;
          return 0;
        }
        fmt = "message has not confirm!\r\n";
      }
      else {
        fmt = "message has not set to show!\r\n";
      }
      CHAR____200033f6 = -1;
      CHAR____200033f5 = -1;
      INT_200024e0 = -1;
      if (BLE_DEBUG == 0) {
        printk(fmt);
      }
      else {
        ble_printk(fmt);
      }
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("pull message error !\r\n");
      }
      else {
        ble_printk("pull message error !\r\n");
      }
      CHAR____200033f6 = -1;
      CHAR____200033f5 = -1;
      INT_200024e0 = -1;
    }
  }
  return 0;
}


