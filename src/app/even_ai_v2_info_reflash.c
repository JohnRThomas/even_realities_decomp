/*
 * Function: even_ai_v2_info_reflash
 * Entry:    00049a30
 * Prototype: undefined4 __stdcall even_ai_v2_info_reflash(undefined4 param_1, int param_2)
 */


undefined4 even_ai_v2_info_reflash(undefined4 param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  GlassesState *pGVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined *puVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  byte bVar18;
  byte bVar19;
  uint uVar20;
  
  pGVar6 = __get_dashboard_state();
  bVar1 = get_current_language();
  pGVar7 = __get_dashboard_state();
  if (pGVar7[1].is_master == true) {
    uVar13 = (uint)(byte)pGVar6->field20_0xc8[0x28];
    if (uVar13 == 2) {
      if (pGVar6->field20_0xc8[0x2a] != '\x01') goto LAB_00049ace;
    }
    else if ((3 < uVar13 - 3) || (uVar13 == 5)) goto LAB_00049ace;
    FUN_00030458();
  }
  else {
LAB_00049ace:
    pGVar7 = __get_dashboard_state();
    if ((((pGVar7->is_master == true) && (bVar2 = FUN_00028d2c(), bVar2)) &&
        (pGVar7 = __get_dashboard_state(), **(char **)&pGVar7->field_0x1014 == '\x01')) &&
       (cVar3 = FUN_00030440(), cVar3 == '\x01')) {
      FUN_0008040c();
    }
  }
  if (DAT_20004de0 == pGVar6->field20_0xc8[0x28]) {
    if (pGVar6->field20_0xc8[0x28] != '\x03') {
      if (DAT_20004de1 != pGVar6->field20_0xc8[0x2a]) goto LAB_00049a82;
      goto LAB_00049aae;
    }
switchD_00049ab8_caseD_3:
    if (pGVar6->field20_0xc8[0x2a] == '\0') {
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = uVar4 + 0x3a;
      uVar13 = 4;
      goto LAB_00049b2c;
    }
    if (param_2 != 1) {
      return 0;
    }
switchD_00049b3e_caseD_3:
    if (pGVar6->field20_0xc8[0x2a] != '\0') {
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_area_clear(iVar8,uVar4 + 0x3a,iVar11 + 0x28,uVar5 + 0x62);
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,pGVar6->field20_0xc8 + 0x37,0,iVar8 + 0x58,(uint)uVar4,iVar11 + 0x230,
                   uVar5 + 0x88,5,0,0,(undefined *)0x0,0);
      if (100 < (byte)pGVar6->field20_0xc8[0x2c]) {
        return 0;
      }
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_verticalLine_process_bar
                (iVar8 + 0x23c,(uint)uVar4,iVar11 + 0x23c,uVar5 + 0x88,1,pGVar6->field20_0xc8[0x2c])
      ;
      return 0;
    }
LAB_00049cd0:
    pcVar10 = pGVar6->field20_0xc8 + 0x37;
    if (pGVar6->field20_0xc8[0x2b] == '\x01') {
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      FUN_00046544(0,pcVar10,0,iVar8 + 0x58,(uint)uVar4,iVar11 + 0x230,uVar5 + 0x88,5,0);
      return 0;
    }
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar17 = (uint)uVar4;
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x88;
    iVar9 = iVar9 + 0x230;
    uVar20 = 5;
    iVar8 = iVar8 + 0x58;
    goto LAB_0004a3c6;
  }
LAB_00049a82:
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): even_ai_v2 action change, id:%d,status:%d, clear screen\n",
             "even_ai_v2_info_reflash");
    }
    else {
      ble_printk("%s(): even_ai_v2 action change, id:%d,status:%d, clear screen\n",
                 "even_ai_v2_info_reflash");
    }
  }
  DAT_20004de0 = pGVar6->field20_0xc8[0x28];
  DAT_20004de1 = pGVar6->field20_0xc8[0x2a];
  gui_screen_clear();
  FUN_00045444();
LAB_00049aae:
  switch(pGVar6->field20_0xc8[0x28]) {
  case 1:
switchD_00049ab8_caseD_1:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 1;
    break;
  case 2:
    if (pGVar6->field20_0xc8[0x2a] == '\0') goto switchD_00049ab8_caseD_1;
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 9;
    break;
  case 3:
    goto switchD_00049ab8_caseD_3;
  default:
    goto switchD_00049ab8_caseD_4;
  case 7:
    if (pGVar6->field20_0xc8[0x2a] == '\x02') goto switchD_00049ab8_caseD_1;
    if (param_2 != 1) {
      return 0;
    }
    goto switchD_00049b3e_caseD_7;
  }
LAB_00049b2c:
  gui_bmp_dynamic_bitmap_draw(uVar13,iVar8,iVar11);
switchD_00049ab8_caseD_4:
  if (param_2 != 1) {
    return 0;
  }
  switch(pGVar6->field20_0xc8[0x28]) {
  case 1:
    pcVar10 = get_string(0x56);
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,pcVar10,0,iVar8,uVar4 + 0x36,iVar11 + 0x240,uVar5 + 0x88,1,0,0,
                        (undefined *)0x0,0);
    if ((byte)pGVar6->field20_0xc8[0x2a] - 1 < 7) {
      uVar13 = (byte)pGVar6->field20_0xc8[0x2a] + 0x57 & 0xff;
    }
    else {
      uVar13 = 0x57;
    }
    pcVar10 = get_string(uVar13);
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar9 = uVar5 + 0x88;
    iVar8 = iVar8 + 0x240;
    iVar16 = uVar4 + 0x6c;
    uVar13 = 1;
    goto LAB_00049c26;
  case 2:
    if (pGVar6->field20_0xc8[0x2a] != '\0') {
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar11 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw_darkword_by_lines
                (0,pGVar6->field20_0xc8 + 0x37,0,iVar8 + 0x58,(uint)uVar4,iVar11 + 0x230,
                 uVar5 + 0x88,5,5,0,(undefined *)0x0,0);
      return 0;
    }
    goto LAB_00049cd0;
  case 3:
    goto switchD_00049b3e_caseD_3;
  case 4:
    break;
  default:
    goto switchD_00049b3e_caseD_5;
  case 7:
switchD_00049b3e_caseD_7:
    if (pGVar6->field20_0xc8[0x2a] == '\x01') {
      if ((byte)(bVar1 - 5) < 10) {
        uVar13 = (uint)(byte)(&DAT_000db382)[(byte)(bVar1 - 5)];
      }
      else {
        uVar13 = 0x9a;
      }
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3e,iVar8 + uVar13,uVar4 + 0x36,0,0,0);
      pcVar10 = get_string(0x5f);
      iVar8 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      uVar20 = 1;
      iVar11 = uVar5 + 0x88;
      iVar9 = iVar9 + 0x240;
      uVar17 = uVar4 + 0x36;
      iVar8 = iVar8 + uVar13 + 0x34;
      goto LAB_0004a3c6;
    }
    if (pGVar6->field20_0xc8[0x2a] != '\x02') {
      return 0;
    }
    pcVar10 = get_string(0x56);
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,pcVar10,0,iVar8,uVar4 + 0x36,iVar11 + 0x240,uVar5 + 0x88,1,0,0,
                        (undefined *)0x0,0);
    pcVar10 = get_string(0x45);
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar9 = uVar5 + 0x88;
    iVar8 = iVar8 + 0x240;
    iVar16 = uVar4 + 0x6c;
    uVar13 = 1;
    goto LAB_00049c26;
  }
  switch(pGVar6->field20_0xc8[0x2a]) {
  case 1:
    if (bVar1 == 6) {
      uVar15 = 0x10;
    }
    else if ((byte)(bVar1 - 5) < 10) {
      uVar15 = (uint)(char)(&DAT_000db378)[(byte)(bVar1 - 5)];
    }
    else {
      uVar15 = 0x62;
    }
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x4d;
    iVar8 = iVar8 + uVar15;
    break;
  case 2:
    if (bVar1 == 6) {
      uVar15 = 0x9a;
    }
    else if ((byte)(bVar1 - 5) < 10) {
      uVar15 = (uint)(byte)(&DAT_000db36e)[(byte)(bVar1 - 5)];
    }
    else {
      uVar15 = 0xa2;
    }
    goto LAB_00049e1e;
  case 3:
    if (bVar1 == 6) {
      uVar15 = 0x8e;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        puVar12 = &DAT_000db364;
LAB_00049e4e:
        uVar15 = (uint)(byte)puVar12[uVar13];
      }
      else {
        uVar15 = 0xae;
      }
    }
    goto LAB_00049e54;
  case 4:
    if (bVar1 == 6) {
      uVar15 = 0x8a;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        puVar12 = &DAT_000db35a;
        goto LAB_00049e4e;
      }
      uVar15 = 0xaa;
    }
LAB_00049e54:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x4b;
    iVar8 = iVar8 + uVar15;
    break;
  case 5:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x4c,iVar8 + 0x90,uVar4 + 0x3a,0,0,0);
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    gui_horizontal_percentage_bar
              (iVar8 + 0xbc,uVar4 + 0x42,iVar11 + 0x184,uVar5 + 0x46,1,0,
               (byte)((uint)((short)(ushort)(byte)pGVar7->field20_0xc8[3] * 100) / 0x2a));
    iVar8 = 0x240;
    uVar15 = 0x90;
    goto LAB_0004a208;
  case 6:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x4f,iVar8 + 0x88,uVar4 + 0x3a,0,0,0);
    iVar8 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    bVar18 = 5;
    bVar19 = 4;
    bVar14 = ((pGVar7->jdb_panel_context).field_0x355 + '\x01') * '\n';
    iVar11 = iVar11 + 0x18c;
    goto LAB_00049f56;
  case 7:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x50,iVar8 + 0x88,uVar4 + 0x3a,0,0,0);
    iVar8 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    bVar14 = (byte)(((uint)(byte)(pGVar7->jdb_panel_context).__raster_height_offset * 100 + 100) / 9
                   );
    bVar18 = 9;
    bVar19 = 2;
    iVar11 = iVar11 + 0x18a;
LAB_00049f56:
    gui_horizontal_percentage_bar
              (iVar8 + 0xb4,uVar5 + 0x42,iVar11,uVar4 + 0x46,bVar18,bVar19,bVar14);
    iVar8 = 0x240;
    uVar15 = 0x88;
    goto LAB_0004a208;
  case 8:
    if ((bVar1 == 6) || (uVar13 = (uint)(byte)(bVar1 - 5), 9 < uVar13)) {
      uVar15 = 0xc4;
    }
    else {
      puVar12 = &DAT_000db350;
LAB_00049fd6:
      uVar15 = (uint)(byte)puVar12[uVar13];
    }
    goto LAB_00049fdc;
  case 9:
    if ((bVar1 != 6) && (uVar13 = (uint)(byte)(bVar1 - 5), uVar13 < 10)) {
      puVar12 = &DAT_000db346;
      goto LAB_00049fd6;
    }
    uVar15 = 0xc2;
LAB_00049fdc:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x4e;
    iVar8 = iVar8 + uVar15;
    break;
  case 10:
    if (bVar1 == 6) {
      uVar15 = 0xaa;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        puVar12 = &DAT_000db33c;
LAB_0004a018:
        uVar15 = (uint)(byte)puVar12[uVar13];
      }
      else {
        uVar15 = 0xc6;
      }
    }
    goto LAB_0004a01e;
  case 0xb:
    if (bVar1 == 6) {
      uVar15 = 0xa6;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        puVar12 = &DAT_000db332;
        goto LAB_0004a018;
      }
      uVar15 = 0xc2;
    }
LAB_0004a01e:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x36;
    uVar13 = 0x3c;
    iVar8 = iVar8 + uVar15;
    break;
  case 0xc:
    if (bVar1 == 6) {
      uVar15 = 0xa0;
    }
    else if ((byte)(bVar1 - 5) < 10) {
      uVar15 = (uint)(byte)(&DAT_000db328)[(byte)(bVar1 - 5)];
    }
    else {
      uVar15 = 0xc0;
    }
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x36;
    uVar13 = 0x3b;
    iVar8 = iVar8 + uVar15;
    break;
  case 0xd:
    if (bVar1 == 6) {
      uVar15 = 0x30;
    }
    else if ((byte)(bVar1 - 5) < 10) {
      uVar15 = (uint)(char)(&DAT_000db31e)[(byte)(bVar1 - 5)];
    }
    else {
      uVar15 = 0x4a;
    }
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x54;
    iVar8 = iVar8 + uVar15;
    break;
  case 0xe:
    if (bVar1 == 6) {
      uVar15 = 0x22;
    }
    else if ((byte)(bVar1 - 5) < 10) {
      uVar15 = (uint)(char)(&DAT_000db314)[(byte)(bVar1 - 5)];
    }
    else {
      uVar15 = 0x42;
    }
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x53;
    iVar8 = iVar8 + uVar15;
    break;
  case 0xf:
    if (bVar1 == 6) {
      iVar8 = 0x19a;
      uVar15 = 0x3e;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        uVar15 = (uint)(byte)(&DAT_000db30a)[uVar13];
        iVar8 = (int)*(short *)(&DAT_0009c4d8 + uVar13 * 2);
      }
      else {
        iVar8 = 0x240;
        uVar15 = 0x4e;
      }
    }
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar13 = 0x52;
    iVar11 = iVar11 + uVar15;
    goto LAB_0004a148;
  case 0x10:
    if (bVar1 == 6) {
      iVar8 = 0x240;
      uVar15 = 0x44;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        uVar15 = (uint)(char)(&DAT_000db300)[uVar13];
        puVar12 = &DAT_0009c4c4;
LAB_0004a170:
        iVar8 = (int)*(short *)(puVar12 + uVar13 * 2);
      }
      else {
        iVar8 = 0x240;
        uVar15 = 0x5c;
      }
    }
    goto LAB_0004a17c;
  case 0x11:
    if (bVar1 == 6) {
      iVar8 = 0x240;
      uVar15 = 0x46;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        uVar15 = (uint)(char)(&DAT_000db2f6)[uVar13];
        puVar12 = &DAT_0009c4b0;
        goto LAB_0004a170;
      }
      iVar8 = 0x240;
      uVar15 = 0x58;
    }
    goto LAB_0004a17c;
  case 0x12:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,pGVar6->field20_0xc8 + 0x37,0,iVar8,uVar4 + 0x36,iVar11 + 0x240,
                        uVar5 + 0x88,3,0,0,(undefined *)0x0,0);
  default:
    iVar8 = 0x240;
    uVar15 = 0;
    goto LAB_0004a208;
  case 0x13:
    if (bVar1 == 6) {
      uVar15 = 0xc6;
    }
    else if (bVar1 == 5) {
      uVar15 = 0xcc;
    }
    else if (bVar1 == 7) {
      uVar15 = 0xd6;
    }
    else if (bVar1 == 0xe) {
      uVar15 = 0xd0;
    }
    else {
      uVar15 = 0xcc;
    }
LAB_00049e1e:
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar11 = uVar4 + 0x3a;
    uVar13 = 0x4a;
    iVar8 = iVar8 + uVar15;
    break;
  case 0x14:
    if (bVar1 == 6) {
      iVar8 = 0x1a8;
      uVar15 = 0x36;
    }
    else {
      uVar13 = (uint)(byte)(bVar1 - 5);
      if (uVar13 < 10) {
        uVar15 = (uint)(char)(&DAT_000db2ec)[uVar13];
        puVar12 = &DAT_0009c49c;
        goto LAB_0004a170;
      }
      iVar8 = 0x240;
      uVar15 = 0x18;
    }
LAB_0004a17c:
    iVar11 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar13 = 0x51;
    iVar11 = iVar11 + uVar15;
LAB_0004a148:
    gui_bmp_bitmap_draw(uVar13,iVar11,uVar4 + 0x3a,0,0,0);
    goto LAB_0004a208;
  }
  gui_bmp_bitmap_draw(uVar13,iVar8,iVar11,0,0,0);
  iVar8 = 0x240;
LAB_0004a208:
  uVar13 = (uint)(byte)pGVar6->field20_0xc8[0x2a];
  if (0x14 < uVar13) {
    return 0;
  }
  if (uVar13 - 5 < 3) {
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar8 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar13 = 1;
    iVar8 = iVar8 + 0x240;
    iVar16 = uVar5 + 0x6c;
  }
  else {
    if (uVar13 == 0xf) {
      if (1 < (byte)(bVar1 - 5)) {
LAB_0004a2ea:
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar9 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar11 = uVar5 + 0x88;
        uVar17 = uVar4 + 0x36;
        iVar9 = iVar9 + 0x240;
        uVar20 = 1;
        iVar8 = iVar8 + uVar15 + 0x2c;
        pcVar10 = pGVar6->field20_0xc8 + 0x37;
LAB_0004a3c6:
        gui_utf_draw(0,pcVar10,0,iVar8,uVar17,iVar9,iVar11,uVar20,0,0,(undefined *)0x0,0);
        return 0;
      }
    }
    else {
      if ((uVar13 == 0x10) || (uVar13 == 0x11)) {
        bVar2 = bVar1 == 5;
      }
      else {
        if (uVar13 != 0x14) {
          if (uVar13 == 0x12) {
            return 0;
          }
          goto LAB_0004a2ea;
        }
        if ((byte)(bVar1 - 5) < 3) goto LAB_0004a2a4;
        bVar2 = bVar1 == 0xe;
      }
      if (!bVar2) goto LAB_0004a2ea;
    }
LAB_0004a2a4:
    iVar11 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar13 = 3;
    iVar8 = iVar9 + uVar15 + 0x2c + iVar8;
    iVar16 = uVar5 + 0x36;
    iVar11 = iVar11 + uVar15 + 0x2c;
  }
  iVar9 = uVar4 + 0x88;
  pcVar10 = pGVar6->field20_0xc8 + 0x37;
LAB_00049c26:
  gui_utf_draw_middle(0,pcVar10,0,iVar11,iVar16,iVar8,iVar9,uVar13,0,0,(undefined *)0x0,0);
switchD_00049b3e_caseD_5:
  return 0;
}


