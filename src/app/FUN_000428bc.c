/*
 * Function: FUN_000428bc
 * Entry:    000428bc
 * Prototype: undefined __stdcall FUN_000428bc(void)
 */


void FUN_000428bc(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  GlassesState *pGVar5;
  int iVar6;
  int iVar7;
  uint string_id;
  char *pcVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined1 uVar9;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte local_30 [12];
  
  pGVar4 = __get_dashboard_state();
  if (DAT_2001db45 == '\0') {
    return;
  }
  DAT_2001db45 = 0;
  gui_screen_clear(pGVar4,extraout_r1,0);
  pGVar5 = __get_dashboard_state();
  if ((((((*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\0') &&
         (pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\n'))
        && (pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\v'))
       && ((pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x05'
           && (pGVar5 = __get_dashboard_state(),
              *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x06')))) &&
      ((pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x13' &&
       ((pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x14' &&
        (pGVar5 = __get_dashboard_state(), *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x15')))
       ))) && ((pGVar5 = __get_dashboard_state(),
               *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x0e' &&
               ((((pGVar5 = __get_dashboard_state(),
                  *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x0f' &&
                  (pGVar5 = __get_dashboard_state(),
                  *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x10')) &&
                 (pGVar5 = __get_dashboard_state(),
                 *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x11')) &&
                ((pGVar5 = __get_dashboard_state(),
                 *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x03' || (DAT_2001db40 != 2)))))))
     ) {
    pGVar5 = __get_dashboard_state();
    iVar11 = *(int *)&pGVar5->field_0x101c;
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,(char *)(iVar11 + 0x1b),3,iVar6,uVar2 + 0x37,iVar7 + 0x28,uVar3 + 0x52,4,0,0,
                 (undefined *)0x0,0);
  }
  pGVar5 = __get_dashboard_state();
  switch(*(undefined1 *)(*(int *)&pGVar5->field_0x101c + 2)) {
  case 0:
    FUN_00045428();
    DAT_2000a9d4 = 0;
    while (DAT_2000a9d4 < 8) {
      iVar6 = FUN_000809e2();
      uVar12 = 0;
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x16,iVar6,uVar2 + 0x38,0,0,0);
      pcVar8 = get_string_in_language((&DAT_20003692)[DAT_2001db40],1);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw_middle(0,pcVar8,0,iVar6 + 0x24,uVar2 + 0x37,iVar7 + 0x21c,uVar3 + 0x88,4,0,0,
                          (undefined *)0x0,0);
      do {
        iVar6 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar1 = *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6);
          if (bVar1 != 0) {
            *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6) =
                 bVar1 & (&DAT_000accab)
                         [iVar6 + (uint)local_30[DAT_2000a9d4] * 0x140 + (uVar12 % 0x1a) * 0xa00];
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x140);
        uVar12 = uVar12 + 1;
      } while (uVar12 != 199);
      DAT_2000a9d4 = DAT_2000a9d4 + 1;
      pGVar5 = __get_dashboard_state();
      iVar6 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar6,*(int *)&pGVar5->field_0xeb8,0,0,0x280,199);
    }
    goto LAB_00042a50;
  case 1:
    pcVar8 = get_string(6);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x88;
    iVar6 = iVar6 + 0x240;
    iVar10 = uVar2 + 0x37;
    iVar11 = iVar11 + 0x8c;
    break;
  case 2:
    pcVar8 = get_string(0x20);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x88;
    iVar6 = iVar6 + 0x240;
    iVar10 = uVar2 + 0x37;
    iVar11 = iVar11 + 0x80;
    break;
  case 3:
  case 5:
  case 0x14:
  case 0x15:
    if (DAT_2001db40 == 1) {
      pGVar4 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar4->field_0x101c + 2) != '\x03') {
        pGVar4 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar4->field_0x101c + 2) != '\x15') goto switchD_00042a0c_caseD_a;
        DAT_2001db42 = 0;
        pGVar4 = __get_dashboard_state();
        if ((*(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) & 3) != 1)
        goto switchD_00042a0c_caseD_a;
        FUN_00029774(0x14,extraout_r1_00,extraout_r2);
        pGVar4 = __get_dashboard_state();
        *(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) =
             *(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) | 2;
        pGVar4 = __get_dashboard_state();
        uVar9 = 0x17;
        iVar6 = *(int *)&pGVar4->field_0x101c;
LAB_00042d44:
        *(undefined1 *)(iVar6 + 2) = uVar9;
        goto switchD_00042a0c_caseD_a;
      }
      DAT_2001db42 = 0;
      pcVar8 = get_string(8);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = uVar3 + 0x88;
      uVar12 = 4;
      iVar11 = iVar11 + 0x8c;
      goto LAB_00042cee;
    }
    if (DAT_2001db40 != 2) goto switchD_00042a0c_caseD_a;
    pGVar5 = __get_dashboard_state();
    if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
      pGVar5 = __get_dashboard_state();
      iVar6 = (uint)*(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) << 0x1f;
      if (-1 < iVar6) {
        FUN_00029774(0x13,extraout_r1_01,iVar6);
        pGVar5 = __get_dashboard_state();
        *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) =
             *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) | 1;
      }
    }
    if (DAT_2001db43 != '\0') {
LAB_00042d8c:
      DAT_2001db44 = 0;
      goto switchD_00042a0c_caseD_a;
    }
    pGVar5 = __get_dashboard_state();
    if ((*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x15') || (DAT_20004db8 == '\x01')) {
      FUN_00045428();
    }
    DAT_2000a9d4 = 0;
    while (DAT_2000a9d4 < 8) {
      pcVar8 = get_string(0x14);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,3,iVar6,(uint)uVar2,iVar7 + 0x76,uVar3 + 0x1b,1,0,0,(undefined *)0x0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,"12:47",1,iVar6,uVar2 + 0x1b,iVar7 + 0x68,uVar3 + 0x42,1,0,0,(undefined *)0x0,0
                  );
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x29,iVar6 + 0xa6,uVar2 + 4,0,0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,"25",3,iVar6 + 0xc2,uVar2 + 3,iVar7 + 0xea,uVar3 + 0x1e,1,0,0,(undefined *)0x0,
                   0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,"*",3,iVar6 + 0xde,uVar2 + 3,iVar7 + 0xec,uVar3 + 0x1e,1,0,0,(undefined *)0x0,0
                  );
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3c,iVar6 + 0xa6,uVar2 + 0x23,0,0,0);
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x05') {
        pcVar8 = "1";
      }
      else {
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x03') {
          pcVar8 = "3";
        }
        else {
          pcVar8 = "0";
        }
      }
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,3,iVar6 + 0xc2,uVar2 + 0x23,iVar7 + 0xd6,uVar3 + 0x3e,1,0,0,
                   (undefined *)0x0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x39,iVar6,uVar2 + 0x51,0,0,0);
      pcVar8 = get_string(0x16);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0x1c,uVar2 + 0x51,iVar7 + 0xf2,uVar3 + 0x6c,1,0,0,
                   (undefined *)0x0,0);
      pcVar8 = get_string(0x15);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6,uVar2 + 0x6d,iVar7 + 0xf2,uVar3 + 0x88,1,0,0,(undefined *)0x0,0)
      ;
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3b,iVar6 + 0x108,uVar2 + 1,0,0,0);
      pcVar8 = get_string(0x17);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0x126,(uint)uVar2,iVar7 + 0x202,uVar3 + 0x1b,1,0,0,
                   (undefined *)0x0,0);
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
        pcVar8 = "2/2";
      }
      else {
        pcVar8 = "1/2";
      }
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,3,iVar6 + 0x210,uVar2 + 1,iVar7 + 0x234,uVar3 + 0x1c,1,0,0,
                   (undefined *)0x0,0);
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
        uVar12 = 0xe;
      }
      else {
        uVar12 = 0x18;
      }
      pcVar8 = get_string(uVar12);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0x108,uVar2 + 0x1b,iVar7 + 0x232,uVar3 + 0x87,4,0,0,
                   (undefined *)0x0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x59,iVar6 + 0xfc,(uint)uVar2,0,0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x5a,iVar6 + 0x23e,(uint)uVar2,0,0,0);
      pGVar5 = __get_dashboard_state();
      if ((*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') && (DAT_20004db8 != '\x01'))
      break;
      uVar12 = 0;
      do {
        iVar6 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar1 = *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6);
          if (bVar1 != 0) {
            *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6) =
                 bVar1 & (&DAT_000accab)
                         [iVar6 + (uint)local_30[DAT_2000a9d4] * 0x140 + (uVar12 % 0x1a) * 0xa00];
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x140);
        uVar12 = uVar12 + 1;
      } while (uVar12 != 199);
      DAT_2000a9d4 = DAT_2000a9d4 + 1;
      pGVar5 = __get_dashboard_state();
      iVar6 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar6,*(int *)&pGVar5->field_0xeb8,0,0,0x280,199);
    }
    goto LAB_00042a50;
  case 4:
    pcVar8 = get_string(7);
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,pcVar8,0,iVar6 + 0xd2,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x52,1,0,0,
                 (undefined *)0x0,0);
    pcVar8 = get_string(0x1f);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x88;
    iVar6 = iVar6 + 0x240;
    iVar10 = uVar2 + 0x6d;
    iVar11 = iVar11 + 0xae;
    goto LAB_00042c8e;
  case 6:
  case 0x13:
    if (DAT_2001db40 == 1) {
      pGVar4 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar4->field_0x101c + 2) == '\x06') {
        iVar6 = FUN_000809e2();
        uVar2 = FUN_00080a3a();
        gui_bmp_bitmap_draw(0x38,iVar6,uVar2 + 0x37,0,0,0);
        pGVar4 = __get_dashboard_state();
        if ((*(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) & 0xc) != 4)
        goto switchD_00042a0c_caseD_a;
        FUN_00029774(0x16,extraout_r1_02,extraout_r2_00);
        pGVar4 = __get_dashboard_state();
        *(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) =
             *(byte *)(*(int *)&pGVar4->field_0x101c + 0x1f) | 8;
        pGVar4 = __get_dashboard_state();
        uVar9 = 5;
        iVar6 = *(int *)&pGVar4->field_0x101c;
        goto LAB_00042d44;
      }
      pGVar4 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar4->field_0x101c + 2) != '\x13') goto switchD_00042a0c_caseD_a;
      pcVar8 = get_string(0x22);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = uVar3 + 0x88;
      iVar10 = uVar2 + 0x6d;
      iVar11 = iVar11 + 0xa6;
      uVar12 = 1;
      goto LAB_000432f0;
    }
    if (DAT_2001db40 != 2) goto switchD_00042a0c_caseD_a;
    pGVar5 = __get_dashboard_state();
    if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
      pGVar5 = __get_dashboard_state();
      if (-1 < (int)((uint)*(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) << 0x1d)) {
        FUN_00029774(0x15,extraout_r1_03,extraout_r2_01);
        pGVar5 = __get_dashboard_state();
        *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) =
             *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) | 4;
      }
    }
    else {
      pGVar5 = __get_dashboard_state();
      if ((*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x13') && (DAT_2001db43 != '\0'))
      goto LAB_00042d8c;
    }
    FUN_00045428();
    DAT_2000a9d4 = 0;
    while (DAT_2000a9d4 < 8) {
      iVar6 = FUN_000809e2();
      uVar12 = 0;
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x3c,iVar6 + 0x212,uVar2 + 4,0,0,0);
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
        pcVar8 = "1";
      }
      else {
        pcVar8 = "0";
      }
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,3,iVar6 + 0x22e,uVar2 + 3,iVar7 + 0x23e,uVar3 + 0x1e,1,0,0,
                   (undefined *)0x0,0);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x38,iVar6,uVar2 + 4,0,0,0);
      pcVar8 = get_string(0x1a);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0x24,uVar2 + 3,iVar7 + 0x150,uVar3 + 0x1e,1,0,0,
                   (undefined *)0x0,0);
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
        string_id = 0x1c;
      }
      else {
        string_id = 0xc;
      }
      pcVar8 = get_string(string_id);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x6d,2,0,0,(undefined *)0x0,0
                  );
      do {
        iVar6 = 0;
        do {
          local_30[0] = 1;
          local_30[1] = 3;
          local_30[2] = 5;
          local_30[3] = 7;
          local_30[4] = 7;
          local_30[5] = 7;
          local_30[6] = 7;
          local_30[7] = 7;
          bVar1 = *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6);
          if (bVar1 != 0) {
            *(byte *)(*(int *)(&pGVar4->field_0xb90 + uVar12 * 4) + iVar6) =
                 bVar1 & (&DAT_000accab)
                         [iVar6 + (uint)local_30[DAT_2000a9d4] * 0x140 + (uVar12 % 0x1a) * 0xa00];
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x140);
        uVar12 = uVar12 + 1;
      } while (uVar12 != 199);
      DAT_2000a9d4 = DAT_2000a9d4 + 1;
      pGVar5 = __get_dashboard_state();
      iVar6 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar6,*(int *)&pGVar5->field_0xeb8,0,0,0x280,199);
    }
LAB_00042a50:
    FUN_0004540c();
    goto switchD_00042a0c_caseD_a;
  case 7:
  case 9:
  case 0xc:
  case 0xd:
    pcVar8 = get_string(0x21);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x88;
    iVar6 = iVar6 + 0x240;
    iVar10 = uVar2 + 0x37;
    iVar11 = iVar11 + 0x72;
    break;
  case 8:
    bVar1 = get_current_language();
    if (bVar1 == 6) {
      pcVar8 = get_string(7);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0xc6,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      pcVar8 = get_string(0x1f);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = iVar6 + 0x240;
      iVar7 = uVar3 + 0x88;
      iVar10 = uVar2 + 0x6d;
      iVar11 = iVar11 + 0xac;
    }
    else {
      pcVar8 = get_string(7);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw(0,pcVar8,0,iVar6 + 0xd2,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x52,1,0,0,
                   (undefined *)0x0,0);
      pcVar8 = get_string(0x1f);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar6 = iVar6 + 0x240;
      iVar7 = uVar3 + 0x88;
      iVar10 = uVar2 + 0x6d;
      iVar11 = iVar11 + 0x8a;
    }
LAB_00042c8e:
    uVar12 = 1;
    goto LAB_00042ba6;
  default:
    goto switchD_00042a0c_caseD_a;
  case 0xe:
  case 0xf:
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x36,iVar6,uVar2 + 0x37,0,0,0);
    pGVar4 = __get_dashboard_state();
    if ((*(char *)(*(int *)&pGVar4->field_0x101c + 2) != '\x0f') || (DAT_2001db40 != 1)) {
      pcVar8 = get_string(0x23);
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_utf_draw_middle(0,pcVar8,0,iVar6,uVar2 + 0x37,iVar7 + 0x240,uVar3 + 0x88,4,0,0,
                          (undefined *)0x0,0);
    }
    goto switchD_00042a0c_caseD_a;
  case 0x10:
  case 0x11:
    pGVar4 = __get_dashboard_state();
    if ((*(char *)(*(int *)&pGVar4->field_0x101c + 2) == '\x11') && (DAT_2001db40 == 1)) {
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x38,iVar6,uVar2 + 0x37,0,0,0);
      goto switchD_00042a0c_caseD_a;
    }
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x3c,iVar6 + 0x212,uVar2 + 4,0,0,0);
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,"1",3,iVar6 + 0x22e,uVar2 + 3,iVar7 + 0x23e,uVar3 + 0x1e,1,1,0,(undefined *)0x0,0
                );
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x38,iVar6,uVar2 + 4,0,0,0);
    pcVar8 = get_string(0x1a);
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw(0,pcVar8,0,iVar6 + 0x24,uVar2 + 3,iVar7 + 0x150,uVar3 + 0x1e,1,0,0,(undefined *)0x0
                 ,0);
    pcVar8 = get_string(0x1c);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x6d;
    uVar12 = 2;
LAB_00042cee:
    iVar10 = uVar2 + 0x37;
LAB_000432f0:
    iVar6 = iVar6 + 0x240;
    goto LAB_00042ba6;
  case 0x16:
    pcVar8 = get_string(0x11);
    iVar11 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = uVar3 + 0x88;
    iVar6 = iVar6 + 0x240;
    iVar10 = uVar2 + 0x37;
    iVar11 = iVar11 + 0x6a;
    break;
  case 0x17:
    bVar1 = get_current_language();
    if (bVar1 == 6) {
      pcVar8 = get_string(0x12);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = uVar3 + 0x88;
      iVar6 = iVar6 + 0x240;
      iVar10 = uVar2 + 0x37;
      iVar11 = iVar11 + 0x48;
    }
    else {
      pcVar8 = get_string(0x12);
      iVar11 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = uVar3 + 0x88;
      iVar6 = iVar6 + 0x240;
      iVar10 = uVar2 + 0x37;
      iVar11 = iVar11 + 0x88;
    }
  }
  uVar12 = 4;
LAB_00042ba6:
  gui_utf_draw(0,pcVar8,0,iVar11,iVar10,iVar6,iVar7,uVar12,0,0,(undefined *)0x0,0);
switchD_00042a0c_caseD_a:
  pGVar4 = __get_dashboard_state();
  DAT_20004db8 = *(undefined1 *)&pGVar4->imu_fusion_context;
  return;
}


