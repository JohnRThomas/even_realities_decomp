/*
 * Function: FUN_00043924
 * Entry:    00043924
 * Prototype: undefined __stdcall FUN_00043924(void)
 */


void FUN_00043924(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  GlassesState *pGVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  size_t sVar10;
  int iVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 uVar12;
  undefined4 extraout_r1_03;
  undefined1 uVar13;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  undefined8 uVar17;
  longlong lVar18;
  undefined4 local_428;
  undefined1 auStack_424 [1024];
  
  local_428 = 0;
  memset(auStack_424,0,0x3fc);
  pGVar5 = __get_dashboard_state();
  switch(*(undefined1 *)(*(int *)&pGVar5->field_0x101c + 2)) {
  case 0:
    lVar18 = FUN_00080976();
    pGVar5 = __get_dashboard_state();
    lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
    uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
    if (uVar14 == 0 && (4000 < (uint)lVar18) <= uVar14) {
      return;
    }
    pGVar5 = __get_dashboard_state();
    *(char *)(*(int *)&pGVar5->field_0x101c + 3) =
         *(char *)(*(int *)&pGVar5->field_0x101c + 3) + '\x01';
    pGVar5 = __get_dashboard_state();
    if (*(byte *)(*(int *)&pGVar5->field_0x101c + 3) < 5) {
      return;
    }
    pGVar5 = __get_dashboard_state();
    uVar13 = 0;
    iVar11 = *(int *)&pGVar5->field_0x101c;
    goto LAB_000439d2;
  case 3:
    pGVar5 = __get_dashboard_state();
    pGVar6 = __get_dashboard_state();
    uVar14 = (uint)*(byte *)&pGVar5->imu_fusion_context;
    *(byte *)(*(int *)&pGVar6->field_0x101c + 3) = *(byte *)&pGVar5->imu_fusion_context;
    if (5 < DAT_2001db42) {
      return;
    }
    uVar12 = extraout_r1_00;
    if (DAT_2001db42 != 0) {
      lVar18 = FUN_00080976();
      pGVar5 = __get_dashboard_state();
      uVar14 = *(uint *)(*(int *)&pGVar5->field_0x101c + 8);
      lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
      uVar15 = (uint)((ulonglong)lVar18 >> 0x20);
      uVar12 = extraout_r1_01;
      if (uVar15 == 0 && (1000 < (uint)lVar18) <= uVar15) {
        return;
      }
    }
    iVar11 = 0x10;
    goto LAB_000439fe;
  case 4:
    iVar11 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar8 = uVar3 + 0x70;
    iVar11 = iVar11 + 0x8a;
    goto LAB_00043a64;
  case 5:
  case 0x14:
  case 0x15:
    pGVar5 = __get_dashboard_state();
    pGVar6 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar6->field_0x101c + 3) = *(undefined1 *)&pGVar5->imu_fusion_context;
    if (DAT_2001db40 == '\x01') {
      pGVar5 = __get_dashboard_state();
      if ((*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x05') && (DAT_2001db43 == '\0')) {
        lVar18 = FUN_00080976();
        pGVar5 = __get_dashboard_state();
        lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
        uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
        if (uVar14 == 0 && (499 < (uint)lVar18) <= uVar14) {
          return;
        }
      }
      bVar2 = get_current_language();
      if (bVar2 == 6) {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_dynamic_bitmap_draw(2,iVar11 + 0x42,uVar3 + 0x70);
        pcVar7 = get_string(0x13);
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar11 = iVar11 + 0x66;
      }
      else {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_dynamic_bitmap_draw(2,iVar11 + 0x82,uVar3 + 0x70);
        pcVar7 = get_string(0x13);
        iVar11 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar11 = iVar11 + 0xa6;
      }
      gui_utf_draw(0,pcVar7,0,iVar11,uVar4 + 0x6d,iVar8 + 0x240,uVar3 + 0x88,1,0,0,(undefined *)0x0,
                   0);
      return;
    }
    if (DAT_2001db40 != '\x02') {
      return;
    }
    lVar18 = FUN_00080976();
    pGVar5 = __get_dashboard_state();
    lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
    uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
    if ((uVar14 != 0 || uVar14 < (2000 < (uint)lVar18)) || (DAT_2001db43 != '\0')) {
      if (DAT_2001db44 == '\0') {
        DAT_2001db44 = '\x01';
        pcVar7 = get_string(0x14);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar9 = get_string(0x14);
        sVar10 = strlen(pcVar9);
        gui_utf_draw(0,pcVar7,3,iVar11,(uint)uVar3,iVar8 + 0x76,uVar4 + 0x1b,1,sVar10,0,
                     (undefined *)0x0,0);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,"12:47",1,iVar11,uVar3 + 0x1b,iVar8 + 0x68,uVar4 + 0x42,1,5,0,
                     (undefined *)0x0,0);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x29,iVar11 + 0xa6,uVar3 + 4,&local_428,0x55);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,"25",3,iVar11 + 0xc2,uVar3 + 3,iVar8 + 0xea,uVar4 + 0x1e,1,2,0,
                     (undefined *)0x0,0);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0,"*",3,iVar11 + 0xde,uVar3 + 3,iVar8 + 0xec,uVar4 + 0x1e,1,1,0,
                     (undefined *)0x0,0);
        pGVar5 = __get_dashboard_state();
        bVar16 = *(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x05';
        if (bVar16) {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw_ex(0x3c,iVar11 + 0xa6,uVar3 + 0x23,&local_428,0x55);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar7 = "0";
        }
        else {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3c,iVar11 + 0xa6,uVar3 + 0x23,0,0,0);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar7 = "1";
        }
        gui_utf_draw(0,pcVar7,3,iVar11 + 0xc2,uVar3 + 0x23,iVar8 + 0xd6,uVar4 + 0x3e,1,(uint)bVar16,
                     0,(undefined *)0x0,0);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x39,iVar11,uVar3 + 0x51,&local_428,0x55);
        pcVar7 = get_string(0x16);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar9 = get_string(0x16);
        sVar10 = strlen(pcVar9);
        gui_utf_draw(0,pcVar7,0,iVar11 + 0x1c,uVar3 + 0x51,iVar8 + 0xf2,uVar4 + 0x6c,1,sVar10,0,
                     (undefined *)0x0,0);
        pcVar7 = get_string(0x15);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar9 = get_string(0x15);
        sVar10 = strlen(pcVar9);
        gui_utf_draw(0,pcVar7,0,iVar11,uVar3 + 0x6d,iVar8 + 0xf2,uVar4 + 0x88,1,sVar10,0,
                     (undefined *)0x0,0);
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x14') {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw(0x3b,iVar11 + 0x108,uVar3 + 1,0,0,0);
          pcVar7 = get_string(0x17);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,pcVar7,0,iVar11 + 0x126,(uint)uVar3,iVar8 + 0x202,uVar4 + 0x1b,1,0,0,
                       (undefined *)0x0,0);
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar14 = 0;
          pcVar7 = "1/2";
        }
        else {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw_ex(0x3b,iVar11 + 0x108,uVar3 + 1,&local_428,0x55);
          pcVar7 = get_string(0x17);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar9 = get_string(0x17);
          sVar10 = strlen(pcVar9);
          gui_utf_draw(0,pcVar7,0,iVar11 + 0x126,(uint)uVar3,iVar8 + 0x202,uVar4 + 0x1b,1,sVar10,0,
                       (undefined *)0x0,0);
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
            pcVar7 = "2/2";
          }
          else {
            pcVar7 = "1/2";
          }
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          uVar14 = 3;
        }
        gui_utf_draw(0,pcVar7,3,iVar11 + 0x210,uVar4 + 1,iVar8 + 0x234,uVar3 + 0x1c,1,uVar14,0,
                     (undefined *)0x0,0);
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
          uVar14 = 0xe;
        }
        else {
          uVar14 = 0x18;
        }
        pcVar7 = get_string(uVar14);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
          uVar14 = 0xe;
        }
        else {
          uVar14 = 0x18;
        }
        pcVar9 = get_string(uVar14);
        sVar10 = strlen(pcVar9);
        gui_utf_draw(0,pcVar7,0,iVar11 + 0x108,uVar3 + 0x1b,iVar8 + 0x232,uVar4 + 0x87,4,sVar10,0,
                     (undefined *)0x0,0);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x59,iVar11 + 0xfc,(uint)uVar3,&local_428,0x55);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x5a,iVar11 + 0x23e,(uint)uVar3,&local_428,0x55);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        gui_utf_draw(0," ",0,iVar11,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,(undefined *)0x0,0
                    );
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x05') {
          bVar2 = get_current_language();
          if (bVar2 == 6) {
            pcVar7 = get_string(9);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,pcVar7,0,iVar11 + 0x5c,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,
                         (undefined *)0x0,0);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0xae;
          }
          else {
            pcVar7 = get_string(9);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            gui_utf_draw(0,pcVar7,0,iVar11 + 0x6a,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,
                         (undefined *)0x0,0);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0xca;
          }
          uVar14 = 0x85;
        }
        else {
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x14') {
            pGVar5 = __get_dashboard_state();
            if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x15') {
              bVar2 = get_current_language();
              if (bVar2 == 6) {
                pcVar7 = get_string(0xf);
                iVar11 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar8 = FUN_000809e2();
                uVar3 = FUN_00080a3a();
                iVar11 = iVar11 + 100;
              }
              else {
                pcVar7 = get_string(0xf);
                iVar11 = FUN_000809e2();
                uVar4 = FUN_00080a3a();
                iVar8 = FUN_000809e2();
                uVar3 = FUN_00080a3a();
                iVar11 = iVar11 + 0x92;
              }
              gui_utf_draw(0,pcVar7,0,iVar11,uVar4 + 0x6d,iVar8 + 0x240,uVar3 + 0x88,1,0,0,
                           (undefined *)0x0,0);
            }
            goto LAB_00044066;
          }
          pcVar7 = get_string(0xb);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          gui_utf_draw(0,pcVar7,0,iVar11 + 0x54,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,
                       (undefined *)0x0,0);
          bVar2 = get_current_language();
          if (bVar2 == 6) {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0xaa;
          }
          else {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0xb2;
          }
          uVar14 = 0x86;
        }
        gui_bmp_bitmap_draw(uVar14,iVar11,uVar3 + 0x87,0,0,0);
      }
LAB_00044066:
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x05') {
        bVar2 = get_current_language();
        if (bVar2 == 6) {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x38;
        }
        else {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x46;
        }
      }
      else {
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x14') {
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x15') goto LAB_000440a2;
          bVar2 = get_current_language();
          if (bVar2 == 6) {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = uVar3 + 0x70;
            iVar11 = iVar11 + 0x40;
          }
          else {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = uVar3 + 0x70;
            iVar11 = iVar11 + 0x6e;
          }
          goto LAB_000443e6;
        }
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = uVar3 + 0x70;
        iVar11 = iVar11 + 0x30;
      }
LAB_0004409c:
      uVar14 = 0xb;
LAB_0004409e:
      gui_bmp_dynamic_bitmap_draw(uVar14,iVar11,iVar8);
    }
LAB_000440a2:
    pGVar5 = __get_dashboard_state();
    if (*(char *)(*(int *)&pGVar5->field_0x101c + 3) == '\x01') {
      DAT_2001db43 = '\x01';
    }
    break;
  case 6:
  case 0x13:
    pGVar5 = __get_dashboard_state();
    pGVar6 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar6->field_0x101c + 3) = *(undefined1 *)&pGVar5->imu_fusion_context;
    cVar1 = DAT_2001db40;
    if (DAT_2001db40 != '\x01') {
      if (DAT_2001db40 != '\x02') {
        return;
      }
      lVar18 = FUN_00080976();
      pGVar5 = __get_dashboard_state();
      lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
      uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
      if ((uVar14 == 0 && (2000 < (uint)lVar18) <= uVar14) && (DAT_2001db43 == '\0'))
      goto LAB_000440a2;
      if (DAT_2001db44 == '\0') {
        DAT_2001db44 = '\x01';
        pGVar5 = __get_dashboard_state();
        if (-1 < (int)((uint)*(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) << 0x1d)) {
          FUN_00029774(0x15,extraout_r1_02,extraout_r2_00);
          pGVar5 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) =
               *(byte *)(*(int *)&pGVar5->field_0x101c + 0x1f) | 4;
        }
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          gui_bmp_bitmap_draw_ex(0x3c,iVar11 + 0x212,uVar3 + 4,&local_428,0x55);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          pcVar7 = "1";
          uVar14 = 1;
LAB_0004468c:
          gui_utf_draw(0,pcVar7,3,iVar11 + 0x22e,uVar3 + 3,iVar8 + 0x23e,uVar4 + 0x1e,1,uVar14,0,
                       (undefined *)0x0,0);
        }
        else {
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x13') {
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            gui_bmp_bitmap_draw(0x3c,iVar11 + 0x212,uVar3 + 4,0,0,0);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar14 = 0;
            pcVar7 = "0";
            goto LAB_0004468c;
          }
        }
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x38,iVar11,uVar3 + 4,&local_428,0x55);
        pcVar7 = get_string(0x1a);
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = FUN_000809e2();
        uVar4 = FUN_00080a3a();
        pcVar9 = get_string(0x1a);
        sVar10 = strlen(pcVar9);
        gui_utf_draw(0,pcVar7,0,iVar11 + 0x24,uVar3 + 3,iVar8 + 0x150,uVar4 + 0x1e,1,sVar10,0,
                     (undefined *)0x0,0);
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
          pcVar7 = get_string(0x1c);
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          uVar14 = 0x1c;
LAB_00044732:
          pcVar9 = get_string(uVar14);
          sVar10 = strlen(pcVar9);
          gui_utf_draw(0,pcVar7,0,iVar11,uVar3 + 0x37,iVar8 + 0x240,uVar4 + 0x6d,2,sVar10,0,
                       (undefined *)0x0,0);
        }
        else {
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x13') {
            pcVar7 = get_string(0xc);
            iVar11 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            uVar14 = 0xc;
            goto LAB_00044732;
          }
        }
        pGVar5 = __get_dashboard_state();
        if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
          bVar2 = get_current_language();
          if (bVar2 == 6) {
            pcVar7 = get_string(0x10);
            iVar11 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0x34;
          }
          else {
            pcVar7 = get_string(0x10);
            iVar11 = FUN_000809e2();
            uVar4 = FUN_00080a3a();
            iVar8 = FUN_000809e2();
            uVar3 = FUN_00080a3a();
            iVar11 = iVar11 + 0x72;
          }
          gui_utf_draw(0,pcVar7,0,iVar11,uVar4 + 0x6d,iVar8 + 0x240,uVar3 + 0x88,1,0,0,
                       (undefined *)0x0,0);
        }
        else {
          pGVar5 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x13') {
            bVar2 = get_current_language();
            if (bVar2 == 6) {
              pcVar7 = get_string(10);
              iVar11 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar8 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_utf_draw(0,pcVar7,0,iVar11 + 0x8a,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,
                           (undefined *)0x0,0);
              iVar11 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = iVar11 + 0xdc;
            }
            else {
              pcVar7 = get_string(10);
              iVar11 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar8 = FUN_000809e2();
              uVar4 = FUN_00080a3a();
              gui_utf_draw(0,pcVar7,0,iVar11 + 0x94,uVar3 + 0x6d,iVar8 + 0x240,uVar4 + 0x88,1,0,0,
                           (undefined *)0x0,0);
              iVar11 = FUN_000809e2();
              uVar3 = FUN_00080a3a();
              iVar11 = iVar11 + 0xf4;
            }
            gui_bmp_bitmap_draw(0x85,iVar11,uVar3 + 0x87,0,0,0);
          }
        }
      }
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
        bVar2 = get_current_language();
        if (bVar2 == 6) {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x10;
        }
        else {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x4e;
        }
LAB_000443e6:
        uVar14 = 3;
        goto LAB_0004409e;
      }
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x13') {
        bVar2 = get_current_language();
        if (bVar2 == 6) {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x66;
        }
        else {
          iVar11 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar8 = uVar3 + 0x70;
          iVar11 = iVar11 + 0x70;
        }
        goto LAB_0004409c;
      }
      goto LAB_000440a2;
    }
    pGVar5 = __get_dashboard_state();
    if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) == '\x06') {
      lVar18 = FUN_00080976();
      pGVar5 = __get_dashboard_state();
      lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
      uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
      if (uVar14 == 0 && (2000 < (uint)lVar18) <= uVar14) {
        return;
      }
      if (DAT_2001db44 == '\0') {
        DAT_2001db44 = cVar1;
        FUN_00045444();
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        gui_bmp_bitmap_draw_ex(0x38,iVar11,uVar3 + 0x37,&local_428,0x55);
        bVar2 = get_current_language();
        if (bVar2 == 6) {
          pcVar7 = get_string(0x19);
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar11 = iVar11 + 0x34;
        }
        else {
          pcVar7 = get_string(0x19);
          iVar11 = FUN_000809e2();
          uVar4 = FUN_00080a3a();
          iVar8 = FUN_000809e2();
          uVar3 = FUN_00080a3a();
          iVar11 = iVar11 + 0x8c;
        }
        gui_utf_draw(0,pcVar7,0,iVar11,uVar4 + 0x6d,iVar8 + 0x240,uVar3 + 0x88,1,0,0,
                     (undefined *)0x0,0);
      }
      bVar2 = get_current_language();
      if (bVar2 == 6) {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = uVar3 + 0x70;
        iVar11 = iVar11 + 0x10;
      }
      else {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = uVar3 + 0x70;
        iVar11 = iVar11 + 0x68;
      }
    }
    else {
      pGVar5 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar5->field_0x101c + 2) != '\x13') {
        return;
      }
      bVar2 = get_current_language();
      if (bVar2 == 6) {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = uVar3 + 0x70;
        iVar11 = iVar11 + 0x74;
      }
      else {
        iVar11 = FUN_000809e2();
        uVar3 = FUN_00080a3a();
        iVar8 = uVar3 + 0x70;
        iVar11 = iVar11 + 0x82;
      }
    }
    uVar14 = 2;
    goto LAB_000444fc;
  case 8:
    bVar2 = get_current_language();
    if (bVar2 == 6) {
      iVar11 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = uVar3 + 0x70;
      iVar11 = iVar11 + 0x88;
    }
    else {
      iVar11 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar8 = uVar3 + 0x70;
      iVar11 = iVar11 + 0x66;
    }
LAB_00043a64:
    uVar14 = 0xc;
LAB_000444fc:
    gui_bmp_dynamic_bitmap_draw(uVar14,iVar11,iVar8);
    break;
  case 0xf:
  case 0x11:
    pGVar5 = __get_dashboard_state();
    pGVar6 = __get_dashboard_state();
    iVar11 = *(int *)&pGVar6->field_0x101c;
    uVar13 = *(undefined1 *)&pGVar5->imu_fusion_context;
LAB_000439d2:
    *(undefined1 *)(iVar11 + 3) = uVar13;
    break;
  case 0x16:
    lVar18 = FUN_00080976();
    pGVar5 = __get_dashboard_state();
    lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
    uVar14 = (uint)((ulonglong)lVar18 >> 0x20);
    if (uVar14 != 0 || uVar14 < (4000 < (uint)lVar18)) {
      pGVar5 = __get_dashboard_state();
      *(undefined1 *)(*(int *)&pGVar5->field_0x101c + 2) = 5;
    }
    break;
  case 0x17:
    if (5 < DAT_2001db42) {
      return;
    }
    uVar12 = extraout_r1;
    uVar14 = extraout_r2;
    if (DAT_2001db42 != 0) {
      lVar18 = FUN_00080976();
      pGVar5 = __get_dashboard_state();
      uVar14 = *(uint *)(*(int *)&pGVar5->field_0x101c + 8);
      lVar18 = lVar18 - *(longlong *)(*(int *)&pGVar5->field_0x101c + 4);
      uVar15 = (uint)((ulonglong)lVar18 >> 0x20);
      uVar12 = extraout_r1_03;
      if (uVar15 == 0 && (1000 < (uint)lVar18) <= uVar15) {
        return;
      }
    }
    iVar11 = 0x14;
LAB_000439fe:
    DAT_2001db42 = DAT_2001db42 + 1;
    FUN_00029774(iVar11,uVar12,uVar14);
    uVar17 = FUN_00080976();
    pGVar5 = __get_dashboard_state();
    *(undefined8 *)(*(int *)&pGVar5->field_0x101c + 4) = uVar17;
  }
  return;
}


