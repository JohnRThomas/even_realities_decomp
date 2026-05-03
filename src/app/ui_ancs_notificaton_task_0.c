/*
 * Function: ui_ancs_notificaton_task_0
 * Entry:    0003783c
 * Prototype: undefined4 __stdcall ui_ancs_notificaton_task_0(int param_1, char * param_2, int param_3)
 */


undefined4 ui_ancs_notificaton_task_0(int param_1,char *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  uint uVar3;
  char *fmt;
  undefined4 uVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  char *extraout_r1_02;
  undefined4 extraout_r1_03;
  uint extraout_r2;
  uint uVar6;
  undefined4 extraout_r2_00;
  int iVar7;
  undefined4 extraout_r2_01;
  uint uVar8;
  undefined4 *puStack_24;
  
  puStack_24 = (undefined4 *)0x0;
  if (param_3 == 2) {
    if (BLE_DEBUG == 0) {
      printk("ui_ancs_notificaton_task exit !");
      uVar4 = extraout_r0_00;
      uVar5 = extraout_r1_00;
    }
    else {
      ble_printk("ui_ancs_notificaton_task exit !",param_2,2,BLE_DEBUG);
      uVar4 = extraout_r0;
      uVar5 = extraout_r1;
    }
    DAT_200033f6 = 0xff;
    DAT_200033f5 = 0xff;
    DAT_200024e0 = 0xffffffff;
    if (DAT_2001c4de == '\0') {
      gui_screen_clear(uVar4,uVar5,0xffffffff);
    }
    else {
      FUN_00045a0c();
      DAT_2001c4de = '\0';
    }
    DAT_20019a6d = 0;
    exit_notification_burial_point();
  }
  else if (param_3 != 0) {
    bVar1 = FUN_000359cc();
    uVar3 = FUN_00035310();
    uVar6 = extraout_r2;
    uVar8 = (uint)DAT_200033f6;
    if ((((uint)DAT_200033f6 == (uint)bVar1) && (uVar8 = (uint)DAT_200033f5, DAT_200033f5 == uVar3))
       && (uVar6 = puStack_24[2], uVar8 = DAT_200024e0, uVar6 == DAT_200024e0)) {
      return 0;
    }
    bVar2 = pull_message(&puStack_24,extraout_r1_01,uVar6,uVar8);
    if (bVar2 < 10) {
      iVar7 = (uint)*(byte *)((int)puStack_24 + 0xf) << 0x1f;
      if (iVar7 < 0) {
        if (*(char *)((int)puStack_24 + 0xe) != '\0') {
          if (DAT_200033f6 == 0xff) {
            FUN_000452f0(param_1 + 0x24);
            uVar4 = FUN_0004540c();
            gui_screen_clear(uVar4,extraout_r1_03,extraout_r2_01);
            enter_notification_burial_point();
          }
          if (DAT_2001c4dd != '\0') {
            draw_particle_effects(param_1 + 0x24,uVar3,puStack_24);
            DAT_2001c4dd = '\0';
          }
          draw_message(uVar3,puStack_24);
          DAT_200024e0 = puStack_24[2];
          DAT_200033f5 = (char)uVar3;
          DAT_200033f6 = bVar1;
          DAT_20019a6d = 0;
          return 0;
        }
        fmt = "message has not confirm!\r\n";
      }
      else {
        fmt = "message has not set to show!\r\n";
      }
      DAT_200033f6 = 0xff;
      DAT_200033f5 = 0xff;
      DAT_200024e0 = 0xffffffff;
      if (BLE_DEBUG == 0) {
        printk(fmt);
      }
      else {
        ble_printk(fmt,extraout_r1_02,iVar7,BLE_DEBUG);
      }
    }
    else {
      if (BLE_DEBUG == 0) {
        printk("pull message error !\r\n");
      }
      else {
        ble_printk("pull message error !\r\n",extraout_r1_02,extraout_r2_00,BLE_DEBUG);
      }
      DAT_200033f6 = 0xff;
      DAT_200033f5 = 0xff;
      DAT_200024e0 = 0xffffffff;
    }
  }
  return 0;
}


