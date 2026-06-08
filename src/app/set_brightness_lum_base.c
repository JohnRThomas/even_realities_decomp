/*
 * Function: set_brightness_lum_base
 * Entry:    00032f7c
 * Prototype: undefined4 __stdcall set_brightness_lum_base(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
set_brightness_lum_base(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  GlassesState *pGVar4;
  int iVar5;
  ushort uVar6;
  ushort uVar7;
  undefined1 *puVar8;
  char cVar9;
  undefined4 auStack_b0 [29];
  ushort local_3c;
  ushort local_3a;
  ushort local_38;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_brightness_lum_base para is NULL\n");
    uVar3 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar8 = (undefined1 *)*param_3;
    *puVar8 = 0x36;
    puVar8[2] = 3;
    puVar8[1] = 1;
    puVar8[3] = 2;
    uVar7 = *(ushort *)(param_1 + 5);
    cVar2 = *(char *)(param_1 + 4);
    bVar1 = 0x3f < uVar7;
    if (bVar1) {
      uVar7 = 0x3f;
    }
    puVar8[4] = bVar1;
    if (cVar2 == '\x01') {
      pGVar4 = __get_dashboard_state();
      *(ushort *)&(pGVar4->jdb_panel_context).field_0x370 = uVar7;
    }
    else if (cVar2 == '\x02') {
      pGVar4 = __get_dashboard_state();
      *(ushort *)&(pGVar4->jdb_panel_context).field_0x372 = uVar7;
    }
    else if (cVar2 == '\0') {
      pGVar4 = __get_dashboard_state();
      *(ushort *)&(pGVar4->jdb_panel_context).field_0x36e = uVar7;
    }
    pGVar4 = __get_dashboard_state();
    *(ushort *)&(pGVar4->jdb_panel_context).field_0x36c = uVar7;
    pGVar4 = __get_dashboard_state();
    FUN_00024abc(pGVar4);
    cVar9 = '\0';
    do {
      iVar5 = read_sys_settting_from_flash(auStack_b0);
      if (((iVar5 == 0) &&
          (((uVar6 = local_3c, cVar2 == '\0' || (uVar6 = local_3a, cVar2 == '\x01')) ||
           (uVar6 = local_38, cVar2 == '\x02')))) && (uVar6 == uVar7)) goto LAB_00033016;
      cVar9 = cVar9 + '\x01';
      sleep(100);
    } while (cVar9 != '\x05');
    puVar8[4] = 2;
LAB_00033016:
    puVar8[5] = cVar2;
    uVar3 = 0;
    *param_4 = 6;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


