/*
 * Function: FUN_00037a30
 * Entry:    00037a30
 * Prototype: cJSON_bool __stdcall FUN_00037a30(cJSON * item, parse_buffer * input_buffer)
 */


cJSON_bool FUN_00037a30(cJSON *item,parse_buffer *input_buffer)

{
  undefined *puVar1;
  GlassesState *pGVar2;
  cJSON_bool cVar3;
  void *pvVar4;
  parse_buffer *input_buffer_00;
  parse_buffer *extraout_r1;
  parse_buffer *extraout_r1_00;
  int iVar5;
  int iVar6;
  ushort local_3a;
  undefined *local_38;
  undefined *puStack_34;
  undefined2 local_30;
  int local_2c;
  parse_buffer *ppStack_28;
  undefined4 local_24;
  
  local_38 = (undefined *)0x0;
  puStack_34 = (undefined *)0x0;
  local_30 = 0;
  puVar1 = FUN_0004b160(&DAT_000aac10,&local_3a);
  for (iVar5 = 0; iVar5 < (int)(uint)local_3a; iVar5 = iVar5 + 1) {
    pvVar4 = (void *)find_chinese_bitmap_by_unicode((uint)*(ushort *)(puVar1 + iVar5 * 2),0xc,0x24);
    FUN_00080bc0((int)&item->string,pvVar4,0xc,0x24,iVar5 * 0xc + 6,0);
  }
  pGVar2 = __get_dashboard_state();
  iVar5 = 0;
  local_2c = *(int *)(pGVar2->field20_0xc8 + 0x27);
  input_buffer_00 = *(parse_buffer **)(pGVar2->field20_0xc8 + 0x2b);
  local_24 = *(undefined4 *)(pGVar2->field20_0xc8 + 0x2f);
  ppStack_28 = input_buffer_00;
  do {
    cVar3 = FUN_0004d328((cJSON *)&local_38,input_buffer_00);
    iVar5 = iVar5 + 0x1e;
    input_buffer_00 = extraout_r1;
    for (iVar6 = 0; iVar6 < cVar3; iVar6 = iVar6 + 1) {
      pvVar4 = (void *)find_chinese_bitmap_by_unicode
                                 ((uint)*(byte *)((int)&((cJSON *)&local_38)->next + iVar6),0xc,0x24
                                 );
      FUN_00080bc0((int)&item->string,pvVar4,0xc,0x24,iVar6 * 0xc + 6,iVar5);
      input_buffer_00 = extraout_r1_00;
    }
  } while (iVar5 != 0x5a);
  return 0;
}


