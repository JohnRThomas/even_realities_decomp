/*
 * Function: even_ai_v2_info_reflash
 * Entry:    00049a30
 * Prototype: undefined4 __stdcall even_ai_v2_info_reflash(undefined4 param_1, int param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 even_ai_v2_info_reflash(undefined4 param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  GlassesState *pGVar6;
  GlassesState *pGVar7;
  GlassesState *extraout_r0;
  GlassesState *pGVar8;
  GlassesState *extraout_r0_00;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r2;
  uint extraout_r2_00;
  int iVar12;
  undefined *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  byte bVar18;
  byte bVar19;
  uint uVar20;
  
  pGVar6 = __get_dashboard_state();
  bVar1 = get_current_language();
  pGVar7 = __get_dashboard_state();
  if (*(char *)(pGVar7 + 1) == '\x01') {
    uVar14 = (uint)(byte)pGVar6->field_0xf0;
    if (uVar14 == 2) {
      if (pGVar6->field_0xf2 != '\x01') goto LAB_00049ace;
    }
    else if ((3 < uVar14 - 3) || (uVar14 == 5)) goto LAB_00049ace;
    pGVar7 = (GlassesState *)FUN_00030458();
  }
  else {
LAB_00049ace:
    pGVar7 = __get_dashboard_state();
    if (*(char *)pGVar7 == '\x01') {
      bVar2 = FUN_00028d2c();
      pGVar7 = (GlassesState *)(uint)bVar2;
      if (pGVar7 == (GlassesState *)&DAT_00000001) {
        pGVar8 = __get_dashboard_state();
        pGVar7 = (GlassesState *)&pGVar8->field_0x1000;
        if (**(char **)&pGVar8->field_0x1014 == '\x01') {
          bVar3 = FUN_00030440();
          pGVar7 = (GlassesState *)(uint)bVar3;
          if (pGVar7 == (GlassesState *)&DAT_00000001) {
            pGVar7 = (GlassesState *)FUN_0008040c();
          }
        }
      }
    }
  }
  uVar14 = (uint)(byte)pGVar6->field_0xf0;
  if (DAT_20004de0 == uVar14) {
    if (uVar14 != 3) {
      if ((uint)DAT_20004de1 != (uint)(byte)pGVar6->field_0xf2) goto LAB_00049a82;
      goto LAB_00049aae;
    }
switchD_00049ab8_caseD_3:
    if (pGVar6->field_0xf2 == '\0') {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = uVar4 + 0x3a;
      uVar14 = 4;
      goto LAB_00049b2c;
    }
    if (param_2 != 1) {
      return 0;
    }
switchD_00049b3e_caseD_3:
    if (pGVar6->field_0xf2 != '\0') {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_area_clear(iVar9,uVar4 + 0x3a,iVar12 + 0x28,uVar5 + 0x62);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw(0,&pGVar6->field_0xff,0,iVar9 + 0x58,(uint)uVar4,iVar12 + 0x230,uVar5 + 0x88,5,0,
                   0,(undefined *)0x0,0);
      if (100 < (byte)pGVar6->field_0xf4) {
        return 0;
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_verticalLine_process_bar
                (iVar9 + 0x23c,(uint)uVar4,iVar12 + 0x23c,uVar5 + 0x88,1,pGVar6->field_0xf4);
      return 0;
    }
LAB_00049cd0:
    pcVar11 = &pGVar6->field_0xff;
    if (pGVar6->field_0xf3 == '\x01') {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      FUN_00046544(0,pcVar11,0,iVar9 + 0x58,(uint)uVar4,iVar12 + 0x230,uVar5 + 0x88,5,0);
      return 0;
    }
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar17 = (uint)uVar4;
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x88;
    iVar10 = iVar10 + 0x230;
    uVar20 = 5;
    iVar9 = iVar9 + 0x58;
    goto LAB_0004a3c6;
  }
LAB_00049a82:
  iVar9 = LOG_LEVEL;
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): even_ai_v2 action change, id:%d,status:%d, clear screen\n",
             "even_ai_v2_info_reflash");
      pGVar7 = extraout_r0_00;
      iVar9 = extraout_r1_00;
      uVar14 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): even_ai_v2 action change, id:%d,status:%d, clear screen\n",
                 "even_ai_v2_info_reflash",uVar14,(uint)(byte)pGVar6->field_0xf2);
      pGVar7 = extraout_r0;
      iVar9 = extraout_r1;
      uVar14 = extraout_r2;
    }
  }
  DAT_20004de0 = pGVar6->field_0xf0;
  DAT_20004de1 = pGVar6->field_0xf2;
  gui_screen_clear(pGVar7,iVar9,uVar14);
  FUN_00045444();
LAB_00049aae:
  switch(pGVar6->field_0xf0) {
  case 1:
switchD_00049ab8_caseD_1:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 1;
    break;
  case 2:
    if (pGVar6->field_0xf2 == '\0') goto switchD_00049ab8_caseD_1;
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 9;
    break;
  case 3:
    goto switchD_00049ab8_caseD_3;
  default:
    goto switchD_00049ab8_caseD_4;
  case 7:
    if (pGVar6->field_0xf2 == '\x02') goto switchD_00049ab8_caseD_1;
    if (param_2 != 1) {
      return 0;
    }
    goto switchD_00049b3e_caseD_7;
  }
LAB_00049b2c:
  gui_bmp_dynamic_bitmap_draw(uVar14,iVar9,iVar12);
switchD_00049ab8_caseD_4:
  if (param_2 != 1) {
    return 0;
  }
  switch(pGVar6->field_0xf0) {
  case 1:
    pcVar11 = get_string(0x56);
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,pcVar11,0,iVar9,uVar4 + 0x36,iVar12 + 0x240,uVar5 + 0x88,1,0,0,
                        (undefined *)0x0,0);
    if ((byte)pGVar6->field_0xf2 - 1 < 7) {
      uVar14 = (byte)pGVar6->field_0xf2 + 0x57 & 0xff;
    }
    else {
      uVar14 = 0x57;
    }
    pcVar11 = get_string(uVar14);
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar10 = uVar5 + 0x88;
    iVar9 = iVar9 + 0x240;
    iVar16 = uVar4 + 0x6c;
    uVar14 = 1;
    goto LAB_00049c26;
  case 2:
    if (pGVar6->field_0xf2 != '\0') {
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar12 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      gui_utf_draw_darkword_by_lines
                (0,&pGVar6->field_0xff,0,iVar9 + 0x58,(uint)uVar4,iVar12 + 0x230,uVar5 + 0x88,5,5,0,
                 (undefined *)0x0,0);
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
    if (pGVar6->field_0xf2 == '\x01') {
      if ((byte)(bVar1 - 5) < 10) {
        uVar14 = (uint)(byte)(&DAT_000db382)[(byte)(bVar1 - 5)];
      }
      else {
        uVar14 = 0x9a;
      }
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3e,iVar9 + uVar14,uVar4 + 0x36,0,0,0);
      pcVar11 = get_string(0x5f);
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar5 = FUN_00080a3a();
      uVar20 = 1;
      iVar12 = uVar5 + 0x88;
      iVar10 = iVar10 + 0x240;
      uVar17 = uVar4 + 0x36;
      iVar9 = iVar9 + uVar14 + 0x34;
      goto LAB_0004a3c6;
    }
    if (pGVar6->field_0xf2 != '\x02') {
      return 0;
    }
    pcVar11 = get_string(0x56);
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,pcVar11,0,iVar9,uVar4 + 0x36,iVar12 + 0x240,uVar5 + 0x88,1,0,0,
                        (undefined *)0x0,0);
    pcVar11 = get_string(0x45);
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar10 = uVar5 + 0x88;
    iVar9 = iVar9 + 0x240;
    iVar16 = uVar4 + 0x6c;
    uVar14 = 1;
    goto LAB_00049c26;
  }
  switch(pGVar6->field_0xf2) {
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
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x4d;
    iVar9 = iVar9 + uVar15;
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
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        puVar13 = &DAT_000db364;
LAB_00049e4e:
        uVar15 = (uint)(byte)puVar13[uVar14];
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
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        puVar13 = &DAT_000db35a;
        goto LAB_00049e4e;
      }
      uVar15 = 0xaa;
    }
LAB_00049e54:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x4b;
    iVar9 = iVar9 + uVar15;
    break;
  case 5:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x4c,iVar9 + 0x90,uVar4 + 0x3a,0,0,0);
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    gui_horizontal_percentage_bar
              (iVar9 + 0xbc,uVar4 + 0x42,iVar12 + 0x184,uVar5 + 0x46,1,0,
               (byte)((uint)((short)(ushort)(byte)pGVar7->field_0xcb * 100) / 0x2a));
    iVar9 = 0x240;
    uVar15 = 0x90;
    goto LAB_0004a208;
  case 6:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x4f,iVar9 + 0x88,uVar4 + 0x3a,0,0,0);
    iVar9 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    bVar18 = 5;
    bVar19 = 4;
    bVar3 = ((pGVar7->jdb_panel_context).field_0x355 + '\x01') * '\n';
    iVar12 = iVar12 + 0x18c;
    goto LAB_00049f56;
  case 7:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x50,iVar9 + 0x88,uVar4 + 0x3a,0,0,0);
    iVar9 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    pGVar7 = __get_dashboard_state();
    bVar3 = (byte)(((uint)(byte)(pGVar7->jdb_panel_context).field_0x354 * 100 + 100) / 9);
    bVar18 = 9;
    bVar19 = 2;
    iVar12 = iVar12 + 0x18a;
LAB_00049f56:
    gui_horizontal_percentage_bar(iVar9 + 0xb4,uVar5 + 0x42,iVar12,uVar4 + 0x46,bVar18,bVar19,bVar3)
    ;
    iVar9 = 0x240;
    uVar15 = 0x88;
    goto LAB_0004a208;
  case 8:
    if ((bVar1 == 6) || (uVar14 = (uint)(byte)(bVar1 - 5), 9 < uVar14)) {
      uVar15 = 0xc4;
    }
    else {
      puVar13 = &DAT_000db350;
LAB_00049fd6:
      uVar15 = (uint)(byte)puVar13[uVar14];
    }
    goto LAB_00049fdc;
  case 9:
    if ((bVar1 != 6) && (uVar14 = (uint)(byte)(bVar1 - 5), uVar14 < 10)) {
      puVar13 = &DAT_000db346;
      goto LAB_00049fd6;
    }
    uVar15 = 0xc2;
LAB_00049fdc:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x4e;
    iVar9 = iVar9 + uVar15;
    break;
  case 10:
    if (bVar1 == 6) {
      uVar15 = 0xaa;
    }
    else {
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        puVar13 = &DAT_000db33c;
LAB_0004a018:
        uVar15 = (uint)(byte)puVar13[uVar14];
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
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        puVar13 = &DAT_000db332;
        goto LAB_0004a018;
      }
      uVar15 = 0xc2;
    }
LAB_0004a01e:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x36;
    uVar14 = 0x3c;
    iVar9 = iVar9 + uVar15;
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
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x36;
    uVar14 = 0x3b;
    iVar9 = iVar9 + uVar15;
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
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x54;
    iVar9 = iVar9 + uVar15;
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
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x53;
    iVar9 = iVar9 + uVar15;
    break;
  case 0xf:
    if (bVar1 == 6) {
      iVar9 = 0x19a;
      uVar15 = 0x3e;
    }
    else {
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        uVar15 = (uint)(byte)(&DAT_000db30a)[uVar14];
        iVar9 = (int)*(short *)(&DAT_0009c4d8 + uVar14 * 2);
      }
      else {
        iVar9 = 0x240;
        uVar15 = 0x4e;
      }
    }
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar14 = 0x52;
    iVar12 = iVar12 + uVar15;
    goto LAB_0004a148;
  case 0x10:
    if (bVar1 == 6) {
      iVar9 = 0x240;
      uVar15 = 0x44;
    }
    else {
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        uVar15 = (uint)(char)(&DAT_000db300)[uVar14];
        puVar13 = &DAT_0009c4c4;
LAB_0004a170:
        iVar9 = (int)*(short *)(puVar13 + uVar14 * 2);
      }
      else {
        iVar9 = 0x240;
        uVar15 = 0x5c;
      }
    }
    goto LAB_0004a17c;
  case 0x11:
    if (bVar1 == 6) {
      iVar9 = 0x240;
      uVar15 = 0x46;
    }
    else {
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        uVar15 = (uint)(char)(&DAT_000db2f6)[uVar14];
        puVar13 = &DAT_0009c4b0;
        goto LAB_0004a170;
      }
      iVar9 = 0x240;
      uVar15 = 0x58;
    }
    goto LAB_0004a17c;
  case 0x12:
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    gui_utf_draw_middle(0,&pGVar6->field_0xff,0,iVar9,uVar4 + 0x36,iVar12 + 0x240,uVar5 + 0x88,3,0,0
                        ,(undefined *)0x0,0);
  default:
    iVar9 = 0x240;
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
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar12 = uVar4 + 0x3a;
    uVar14 = 0x4a;
    iVar9 = iVar9 + uVar15;
    break;
  case 0x14:
    if (bVar1 == 6) {
      iVar9 = 0x1a8;
      uVar15 = 0x36;
    }
    else {
      uVar14 = (uint)(byte)(bVar1 - 5);
      if (uVar14 < 10) {
        uVar15 = (uint)(char)(&DAT_000db2ec)[uVar14];
        puVar13 = &DAT_0009c49c;
        goto LAB_0004a170;
      }
      iVar9 = 0x240;
      uVar15 = 0x18;
    }
LAB_0004a17c:
    iVar12 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar14 = 0x51;
    iVar12 = iVar12 + uVar15;
LAB_0004a148:
    gui_bmp_bitmap_draw(uVar14,iVar12,uVar4 + 0x3a,0,0,0);
    goto LAB_0004a208;
  }
  gui_bmp_bitmap_draw(uVar14,iVar9,iVar12,0,0,0);
  iVar9 = 0x240;
LAB_0004a208:
  uVar14 = (uint)(byte)pGVar6->field_0xf2;
  if (0x14 < uVar14) {
    return 0;
  }
  if (uVar14 - 5 < 3) {
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar9 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar14 = 1;
    iVar9 = iVar9 + 0x240;
    iVar16 = uVar5 + 0x6c;
  }
  else {
    if (uVar14 == 0xf) {
      if (1 < (byte)(bVar1 - 5)) {
LAB_0004a2ea:
        iVar9 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar10 = FUN_000809e2();
        uVar5 = FUN_00080a3a();
        iVar12 = uVar5 + 0x88;
        uVar17 = uVar4 + 0x36;
        iVar10 = iVar10 + 0x240;
        uVar20 = 1;
        iVar9 = iVar9 + uVar15 + 0x2c;
        pcVar11 = &pGVar6->field_0xff;
LAB_0004a3c6:
        gui_utf_draw(0,pcVar11,0,iVar9,uVar17,iVar10,iVar12,uVar20,0,0,(undefined *)0x0,0);
        return 0;
      }
    }
    else {
      if ((uVar14 == 0x10) || (uVar14 == 0x11)) {
        bVar2 = bVar1 == 5;
      }
      else {
        if (uVar14 != 0x14) {
          if (uVar14 == 0x12) {
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
    iVar12 = FUN_000809e2();
    uVar5 = FUN_00080a3a();
    iVar10 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    uVar14 = 3;
    iVar9 = iVar10 + uVar15 + 0x2c + iVar9;
    iVar16 = uVar5 + 0x36;
    iVar12 = iVar12 + uVar15 + 0x2c;
  }
  iVar10 = uVar4 + 0x88;
  pcVar11 = &pGVar6->field_0xff;
LAB_00049c26:
  gui_utf_draw_middle(0,pcVar11,0,iVar12,iVar16,iVar9,iVar10,uVar14,0,0,(undefined *)0x0,0);
switchD_00049b3e_caseD_5:
  return 0;
}


