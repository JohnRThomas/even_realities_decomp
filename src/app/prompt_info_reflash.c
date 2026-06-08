/*
 * Function: prompt_info_reflash
 * Entry:    0004946c
 * Prototype: undefined4 __stdcall prompt_info_reflash(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 prompt_info_reflash(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint string_id;
  undefined4 extraout_r2;
  
  pGVar4 = __get_dashboard_state();
  bVar1 = pGVar4->field_0xf0;
  if (2 < bVar1) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): prompt_info->action_cmd over E_PROMPT_ACTION_MAX\n");
      }
      else {
        ble_printk("%s(): prompt_info->action_cmd over E_PROMPT_ACTION_MAX\n","prompt_info_reflash",
                   extraout_r2,BLE_DEBUG);
      }
    }
    return 0xffffffff;
  }
  if (bVar1 == 1) {
    string_id = 0x42;
  }
  else {
    if (bVar1 != 2) {
      return 0;
    }
    string_id = 0x43;
  }
  pcVar5 = get_string(string_id);
  iVar6 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  iVar7 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  gui_utf_draw_middle(0,pcVar5,0,iVar6,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x88,3,0,0,
                      (undefined *)0x0,0);
  return 0;
}


