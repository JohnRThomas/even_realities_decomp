/*
 * Function: get_assign_channel_info
 * Entry:    000331f8
 * Prototype: undefined4 __stdcall get_assign_channel_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_assign_channel_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  int iVar3;
  char cVar4;
  undefined1 *puVar5;
  undefined4 auStack_b0 [2];
  char local_a8;
  char local_5b;
  char local_5a;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): get_assign_channel_info para is NULL\n");
      }
      else {
        ble_printk("%s(): get_assign_channel_info para is NULL\n","get_assign_channel_info",param_3,
                   BLE_DEBUG);
      }
    }
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar5 = (undefined1 *)*param_3;
    pGVar2 = __get_dashboard_state();
    pGVar2->esb_channel = *(undefined1 *)(param_1 + 4);
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x3 = *(undefined1 *)(param_1 + 5);
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x4 = *(undefined1 *)(param_1 + 6);
    pGVar2 = __get_dashboard_state();
    __save_sys_settings(pGVar2);
    puVar5[1] = 1;
    *puVar5 = 0x1d;
    puVar5[3] = 1;
    cVar4 = '\0';
    puVar5[2] = 3;
    puVar5[4] = 0;
    do {
      iVar3 = read_sys_settting_from_flash(auStack_b0);
      if ((((iVar3 == 0) && (*(char *)(param_1 + 4) == local_a8)) &&
          (*(char *)(param_1 + 5) == local_5b)) && (*(char *)(param_1 + 6) == local_5a))
      goto LAB_000332a8;
      cVar4 = cVar4 + '\x01';
      sleep(100);
    } while (cVar4 != '\x05');
    puVar5[4] = 1;
LAB_000332a8:
    uVar1 = 0;
    *param_4 = 5;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


