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
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char local_24 [12];
  
  pGVar3 = __get_dashboard_state();
  FUN_000452f0(param_1 + 0x24);
  uVar6 = (uint)(byte)pGVar3->field20_0xc8[0x28];
  if (((uVar6 < 9) && (uVar7 = (byte)pGVar3->field20_0xc8[0x27] - 1, (uVar7 & 0xff) < 8)) &&
     (uVar6 != 0)) {
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
    snprintf(local_24,10,"%s>%s",*(char **)(&DAT_200024f8 + (uVar6 - 1) * 4),
             *(char **)(&DAT_200024f8 + uVar7 * 4));
    iVar4 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar5 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_utf_draw(0,local_24,3,iVar4,uVar1 + 0x6e,iVar5 + 0x50,uVar2 + 0x89,1,0,0,(undefined *)0x0,0)
    ;
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
             ,"draw_template_translate_screen");
    }
    else {
      ble_printk("%s(): translate language type error! trans_info->original_type %d trans_info->translation_type %d\n"
                 ,"draw_template_translate_screen",uVar6,(uint)(byte)pGVar3->field20_0xc8[0x27]);
    }
  }
  uVar6 = FUN_00080732();
  iVar4 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_clock_draw(uVar6,iVar4,uVar1 + 2,iVar5 + 0x50,uVar2 + 0x1d,3,'\x01');
  if (pGVar3->field20_0xc8[0x29] == '\x01') {
    iVar4 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    uVar6 = 0x1b;
  }
  else {
    iVar4 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    uVar6 = 0x33;
  }
  gui_bmp_bitmap_draw(uVar6,iVar4,uVar1 + 0x36,0,0,0);
  iVar4 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw(0,pGVar3->field20_0xc8 + 0x2d,0,iVar4 + 0x58,uVar1 + 1,iVar5 + 0x240,uVar2 + 0x88,5,0
               ,0,(undefined *)0x0,0);
  return 0;
}


