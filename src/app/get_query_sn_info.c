/*
 * Function: get_query_sn_info
 * Entry:    000332c8
 * Prototype: undefined4 __stdcall get_query_sn_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_query_sn_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  int iVar3;
  char cVar4;
  char *serial_num;
  undefined1 *puVar5;
  undefined4 auStack_b0 [5];
  undefined1 auStack_9b [135];
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_query_sn_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    serial_num = (char *)(param_1 + 4);
    puVar5 = (undefined1 *)*param_3;
    __save_serial_number(serial_num);
    printf("The string is: %s\n",serial_num);
    pGVar2 = __get_dashboard_state();
    __save_sys_settings(pGVar2);
    *puVar5 = 0x1c;
    puVar5[1] = 1;
    puVar5[2] = 3;
    puVar5[3] = 1;
    cVar4 = '\0';
    puVar5[4] = 0;
    *param_4 = 5;
    do {
      iVar3 = read_sys_settting_from_flash(auStack_b0);
      if ((iVar3 == 0) && (iVar3 = memcmp(serial_num,auStack_9b,0xe), iVar3 == 0))
      goto LAB_0003334c;
      cVar4 = cVar4 + '\x01';
      sleep(100);
    } while (cVar4 != '\x05');
    puVar5[4] = 1;
LAB_0003334c:
    uVar1 = 0;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


