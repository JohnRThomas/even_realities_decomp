/*
 * Function: set_panel_voltage
 * Entry:    00033404
 * Prototype: undefined4 __stdcall set_panel_voltage(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_panel_voltage(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  byte bVar1;
  GlassesState *pGVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  undefined1 *puVar6;
  undefined4 auStack_b0 [5];
  byte local_9c;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 5)) {
    printk("%s para is NULL\n","set_panel_voltage");
    return 0xffffffff;
  }
  puVar6 = (undefined1 *)*param_3;
  *puVar6 = 0x3c;
  uVar4 = 3;
  puVar6[1] = 1;
  puVar6[2] = 3;
  puVar6[3] = 1;
  bVar1 = *(byte *)(param_1 + 4);
  if (bVar1 < 2) {
    pGVar2 = __get_dashboard_state();
    if ((pGVar2->jdb_panel_context).field_0x368 != bVar1) {
      pGVar2 = __get_dashboard_state();
      (pGVar2->jdb_panel_context).field_0x368 = bVar1;
      pGVar2 = __get_dashboard_state();
      __save_sys_settings(pGVar2);
      cVar5 = '\0';
      do {
        iVar3 = read_sys_settting_from_flash(auStack_b0);
        if ((iVar3 == 0) && (local_9c == bVar1)) break;
        cVar5 = cVar5 + '\x01';
        sleep(100);
      } while (cVar5 != '\x05');
      puVar6[4] = cVar5 == '\x05';
      goto LAB_0003343c;
    }
    uVar4 = 4;
  }
  puVar6[4] = uVar4;
LAB_0003343c:
  *param_4 = 5;
  return 0;
}


