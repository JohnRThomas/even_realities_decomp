/*
 * Function: draw_template_translate_screen
 * Entry:    00041d6c
 * Prototype: undefined4 __stdcall draw_template_translate_screen(int param_1)
 */


undefined4 draw_template_translate_screen(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  GlassesState *pGVar3;
  dashboard_ts_context *pdVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char local_24 [12];
  
  pGVar3 = __get_dashboard_state();
  __set_frame_buffer(param_1 + 0x24);
  uVar7 = (uint)(byte)pGVar3->field20_0xc8[0x28];
  if (((uVar7 < 9) && (uVar8 = (byte)pGVar3->field20_0xc8[0x27] - 1, (uVar8 & 0xff) < 8)) &&
     (uVar7 != 0)) {
    local_24[0] = '\0';
    local_24[1] = '\0';
    local_24[2] = '\0';
    local_24[3] = '\0';
    local_24[4] = '\0';
    local_24[5] = '\0';
    local_24[6] = '\0';
    local_24[7] = '\0';
    local_24[8] = '\0';
    local_24[9] = '\0';
    snprintf(local_24,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar7 - 1) * 4),
             *(char **)(&DAT_200024f8 + uVar8 * 4));
    iVar5 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_utf_draw(0,local_24,3,iVar5,uVar1 + 0x6e,iVar6 + 0x50,uVar2 + 0x89,1,0,0,(undefined *)0x0,0)
    ;
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
             ,"draw_template_translate_screen",uVar7,(uint)(byte)pGVar3->field20_0xc8[0x27]);
    }
    else {
      ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                 ,"draw_template_translate_screen");
    }
  }
  pdVar4 = (dashboard_ts_context *)FUN_00080732();
  iVar5 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar6 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_clock_draw(pdVar4,iVar5,uVar1 + 2,iVar6 + 0x50,uVar2 + 0x1d,3,'\x01');
  if (pGVar3->field20_0xc8[0x29] == '\x01') {
    iVar5 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    uVar7 = 0x1b;
  }
  else {
    iVar5 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    uVar7 = 0x33;
  }
  gui_bmp_bitmap_draw(uVar7,iVar5,uVar1 + 0x36,0,0,0);
  iVar5 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar6 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw(0,pGVar3->field20_0xc8 + 0x2d,0,iVar5 + 0x58,uVar1 + 1,iVar6 + 0x240,uVar2 + 0x88,5,0
               ,0,(undefined *)0x0,0);
  return 0;
}


