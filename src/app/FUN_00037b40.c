/*
 * Function: FUN_00037b40
 * Entry:    00037b40
 * Prototype: cJSON_bool __stdcall FUN_00037b40(cJSON * item, parse_buffer * input_buffer)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

cJSON_bool FUN_00037b40(cJSON *item,parse_buffer *input_buffer)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  undefined *puVar4;
  void *pvVar5;
  undefined **ppuVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort local_2a [3];
  
  ppuVar6 = &item->string;
  pGVar2 = __get_dashboard_state();
  uVar9 = *(uint *)&pGVar2->field_0xef % 0xe10;
  uVar7 = (*(uint *)&pGVar2->field_0xef / 0xe10) % 0x18;
  bVar1 = false;
  uVar8 = uVar9 % 0x3c;
  local_2a[0] = 0;
  if (uVar9 < 0x3c) {
    bVar1 = uVar7 == 0 && uVar8 == 0;
    if (uVar7 != 0 || uVar8 != 0) {
      iVar3 = 9;
    }
    else {
      iVar3 = 4;
    }
  }
  else {
    iVar3 = 9;
  }
  puVar4 = FUN_0004b2d4(iVar3,0x120);
  iVar3 = 0xc;
  FUN_00080bc0((int)ppuVar6,puVar4,0xc,0x18,0xc,0xc);
  if (bVar1) {
    puVar4 = FUN_0004b160(&DAT_000aac42,local_2a);
    for (iVar3 = 0; iVar3 < (int)(uint)local_2a[0]; iVar3 = iVar3 + 1) {
      pvVar5 = (void *)find_chinese_bitmap_by_unicode
                                 ((uint)*(ushort *)(puVar4 + iVar3 * 2),0xc,0x24);
      FUN_00080bc0((int)ppuVar6,pvVar5,0xc,0x24,iVar3 * 0xc + 0x20,8);
    }
  }
  else {
    if (uVar7 != 0) {
      pvVar5 = (void *)FUN_00080fa2(uVar7 / 10,0xf,0x24);
      FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,0x20,0xc);
      pvVar5 = (void *)FUN_00080fa2(uVar7 % 10,0xf,0x24);
      FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,0x2f,0xc);
      pvVar5 = (void *)FUN_00080fa2(10,0xf,0x24);
      FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,0x3e,0xc);
      iVar3 = 0x39;
    }
    pvVar5 = (void *)FUN_00080fa2((uVar9 / 0x3c) / 10,0xf,0x24);
    FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,iVar3 + 0x14,0xc);
    pvVar5 = (void *)FUN_00080fa2((uVar9 / 0x3c) % 10,0xf,0x24);
    FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,iVar3 + 0x23,0xc);
    pvVar5 = (void *)FUN_00080fa2(10,0xf,0x24);
    FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,iVar3 + 0x32,0xc);
    pvVar5 = (void *)FUN_00080fa2(uVar8 / 10,0xf,0x24);
    FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,iVar3 + 0x41,0xc);
    pvVar5 = (void *)FUN_00080fa2(uVar8 % 10,0xf,0x24);
    FUN_00080bc0((int)ppuVar6,pvVar5,0xf,0x24,iVar3 + 0x50,0xc);
  }
  if ((byte)pGVar2->field_0xf3 < 2) {
    FUN_00080800();
  }
  else {
    puVar4 = FUN_0004b2d4(0xc,0x120);
    FUN_00080bc0((int)ppuVar6,puVar4,0xc,0x18,0xe2,0x14);
    puVar4 = FUN_0004b160(&DAT_000aac4d,local_2a);
    for (iVar3 = 0; iVar3 < (int)(uint)local_2a[0]; iVar3 = iVar3 + 1) {
      pvVar5 = (void *)find_chinese_bitmap_by_unicode
                                 ((uint)*(ushort *)(puVar4 + iVar3 * 2),0xc,0x20);
      FUN_00080bc0((int)ppuVar6,pvVar5,0xc,0x20,iVar3 * 0xc + 0xf4,8);
    }
  }
  return 0;
}


