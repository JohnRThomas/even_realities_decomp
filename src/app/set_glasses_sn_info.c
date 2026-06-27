/*
 * Function: set_glasses_sn_info
 * Entry:    00033160
 * Prototype: undefined4 __stdcall set_glasses_sn_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
set_glasses_sn_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  int iVar3;
  char cVar4;
  char *param1;
  undefined1 *puVar5;
  undefined4 auStack_b0 [13];
  undefined1 auStack_7b [103];
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_glasses_sn_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    param1 = (char *)(param_1 + 4);
    puVar5 = (undefined1 *)*param_3;
    FUN_00025364(param1);
    printf("The string is: %s\n",param1);
    pGVar2 = __get_dashboard_state();
    __save_sys_settings(pGVar2);
    *puVar5 = 0x29;
    puVar5[1] = 1;
    puVar5[2] = 3;
    puVar5[3] = 1;
    cVar4 = '\0';
    puVar5[4] = 0;
    *param_4 = 5;
    do {
      iVar3 = read_sys_settting_from_flash(auStack_b0);
      if ((iVar3 == 0) && (iVar3 = memcmp(param1,auStack_7b,0xb), iVar3 == 0)) goto LAB_000331e4;
      cVar4 = cVar4 + '\x01';
      sleep(100);
    } while (cVar4 != '\x05');
    puVar5[4] = 1;
LAB_000331e4:
    uVar1 = 0;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


