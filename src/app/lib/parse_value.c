/*
 * Function: parse_value
 * Entry:    00012868
 * Prototype: cJSON_bool __stdcall parse_value(cJSON * item, parse_buffer * input_buffer)
 */


/* exclude_from_export */

cJSON_bool parse_value(cJSON *item,parse_buffer *input_buffer)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  cJSON_bool cVar4;
  byte *pbVar5;
  cJSON *pcVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  cJSON *pcVar10;
  int iVar11;
  cJSON *item_00;
  cJSON *pcVar12;
  uint uVar13;
  byte *pbVar14;
  bool bVar15;
  uint extraout_s0;
  uint extraout_s1;
  byte abStack_60 [64];
  
  if (input_buffer == (parse_buffer *)0x0) {
    return 0;
  }
  iVar11 = *(int *)input_buffer->opaque;
  if (iVar11 == 0) {
    return 0;
  }
  uVar9 = *(uint *)input_buffer[2].opaque;
  uVar13 = *(uint *)input_buffer[1].opaque;
  if (uVar13 < uVar9 + 4) {
    if (uVar9 + 5 <= uVar13) {
LAB_000128cc:
      iVar3 = strncmp((char *)(iVar11 + uVar9),"false",5);
      if (iVar3 == 0) {
        item->type = 1;
        iVar11 = *(int *)input_buffer[2].opaque + 5;
        goto LAB_000128e0;
      }
      if (uVar9 + 4 <= uVar13) goto LAB_000128ea;
    }
LAB_000128aa:
    if (uVar13 <= uVar9) {
      return 0;
    }
    uVar7 = (uint)*(byte *)(iVar11 + uVar9);
    if (uVar7 == 0x22) {
      cVar4 = parse_string(item,input_buffer);
      return cVar4;
    }
    if ((uVar7 == 0x2d) || (uVar7 - 0x30 < 10)) {
      iVar3 = 0;
      pbVar5 = (byte *)(iVar11 + uVar9);
      pbVar14 = abStack_60;
      do {
        bVar2 = *pbVar5;
        if (bVar2 < 0x46) {
          if (bVar2 < 0x2b) goto LAB_00012952;
          if ((1 << (uint)(byte)(bVar2 - 0x2b) & (uint)&DAT_04007fe5) == 0) {
            bVar15 = bVar2 == 0x2e;
            goto LAB_00012942;
          }
        }
        else {
          bVar15 = bVar2 == 0x65;
LAB_00012942:
          if (!bVar15) goto LAB_00012952;
        }
        iVar3 = iVar3 + 1;
        *pbVar14 = bVar2;
        if ((iVar3 == 0x3f) || (pbVar5 = pbVar5 + 1, pbVar14 = pbVar14 + 1, iVar3 == uVar13 - uVar9)
           ) goto LAB_00012952;
      } while( true );
    }
    if (uVar7 == 0x5b) {
      uVar7 = *(uint *)input_buffer[3].opaque;
      if (999 < uVar7) {
        return 0;
      }
      *(uint *)input_buffer[3].opaque = uVar7 + 1;
      if (*(char *)(iVar11 + uVar9) != '[') {
        return 0;
      }
      *(uint *)input_buffer[2].opaque = uVar9 + 1;
      buffer_skip_whitespace(input_buffer);
      uVar9 = *(uint *)input_buffer[2].opaque;
      if (uVar13 <= uVar9) {
LAB_000129f2:
        *(uint *)input_buffer[2].opaque = uVar9 - 1;
        return 0;
      }
      if (*(char *)(iVar11 + uVar9) == ']') {
        item_00 = (cJSON *)0x0;
        *(uint *)input_buffer[3].opaque = uVar7;
      }
      else {
        *(uint *)input_buffer[2].opaque = uVar9 - 1;
        pcVar10 = (cJSON *)0x0;
        pcVar12 = (cJSON *)0x0;
        do {
          pcVar6 = cJSON_New_Item(*(cjson_internal_hooks **)input_buffer[4].opaque);
          item_00 = pcVar12;
          if (pcVar6 == (cJSON *)0x0) goto LAB_00012b60;
          item_00 = pcVar6;
          if (pcVar12 != (cJSON *)0x0) {
            pcVar10->next = (undefined *)pcVar6;
            pcVar6->prev = (undefined *)pcVar10;
            item_00 = pcVar12;
          }
          *(int *)input_buffer[2].opaque = *(int *)input_buffer[2].opaque + 1;
          buffer_skip_whitespace(input_buffer);
          cVar4 = parse_value(pcVar6,input_buffer);
          if (cVar4 == 0) goto LAB_00012b60;
          buffer_skip_whitespace(input_buffer);
          if (*(uint *)input_buffer[1].opaque <= *(uint *)input_buffer[2].opaque) goto LAB_00012b66;
          cVar1 = *(char *)(*(int *)input_buffer->opaque + *(uint *)input_buffer[2].opaque);
          pcVar10 = pcVar6;
          pcVar12 = item_00;
        } while (cVar1 == ',');
        if (cVar1 != ']') {
LAB_00012b66:
          cJSON_Delete(item_00);
          return 0;
        }
        *(int *)input_buffer[3].opaque = *(int *)input_buffer[3].opaque + -1;
        item_00->prev = (undefined *)pcVar6;
      }
      iVar11 = 0x20;
    }
    else {
      if (uVar7 != 0x7b) {
        return 0;
      }
      uVar7 = *(uint *)input_buffer[3].opaque;
      if (999 < uVar7) {
        return 0;
      }
      *(uint *)input_buffer[3].opaque = uVar7 + 1;
      if (*(char *)(iVar11 + uVar9) != '{') {
        return 0;
      }
      *(uint *)input_buffer[2].opaque = uVar9 + 1;
      buffer_skip_whitespace(input_buffer);
      uVar9 = *(uint *)input_buffer[2].opaque;
      if (uVar13 <= uVar9) goto LAB_000129f2;
      if (*(char *)(iVar11 + uVar9) == '}') {
        item_00 = (cJSON *)0x0;
        *(uint *)input_buffer[3].opaque = uVar7;
      }
      else {
        *(uint *)input_buffer[2].opaque = uVar9 - 1;
        pcVar10 = (cJSON *)0x0;
        pcVar12 = (cJSON *)0x0;
        do {
          pcVar6 = cJSON_New_Item(*(cjson_internal_hooks **)input_buffer[4].opaque);
          item_00 = pcVar12;
          if (pcVar6 == (cJSON *)0x0) goto LAB_00012b60;
          item_00 = pcVar6;
          if (pcVar12 != (cJSON *)0x0) {
            pcVar10->next = (undefined *)pcVar6;
            pcVar6->prev = (undefined *)pcVar10;
            item_00 = pcVar12;
          }
          *(int *)input_buffer[2].opaque = *(int *)input_buffer[2].opaque + 1;
          buffer_skip_whitespace(input_buffer);
          cVar4 = parse_string(pcVar6,input_buffer);
          if (cVar4 == 0) goto LAB_00012b60;
          buffer_skip_whitespace(input_buffer);
          puVar8 = pcVar6->valuestring;
          pcVar6->valuestring = (undefined *)0x0;
          *(undefined **)((int)&pcVar6->valuedouble + 4) = puVar8;
          uVar9 = *(uint *)input_buffer[2].opaque;
          if ((*(uint *)input_buffer[1].opaque <= uVar9) ||
             (*(char *)(*(int *)input_buffer->opaque + uVar9) != ':')) goto LAB_00012b60;
          *(uint *)input_buffer[2].opaque = uVar9 + 1;
          buffer_skip_whitespace(input_buffer);
          cVar4 = parse_value(pcVar6,input_buffer);
          if (cVar4 == 0) goto LAB_00012b60;
          buffer_skip_whitespace(input_buffer);
          if (*(uint *)input_buffer[1].opaque <= *(uint *)input_buffer[2].opaque) goto LAB_00012b66;
          cVar1 = *(char *)(*(int *)input_buffer->opaque + *(uint *)input_buffer[2].opaque);
          pcVar10 = pcVar6;
          pcVar12 = item_00;
        } while (cVar1 == ',');
        if (cVar1 != '}') goto LAB_00012b66;
        *(int *)input_buffer[3].opaque = *(int *)input_buffer[3].opaque + -1;
        item_00->prev = (undefined *)pcVar6;
      }
      iVar11 = 0x40;
    }
    item->child = (undefined *)item_00;
    item->type = iVar11;
    iVar11 = *(int *)input_buffer[2].opaque + 1;
  }
  else {
    iVar3 = strncmp((char *)(iVar11 + uVar9),"null",4);
    if (iVar3 == 0) {
      item->type = 4;
    }
    else {
      if (uVar9 + 5 <= uVar13) goto LAB_000128cc;
LAB_000128ea:
      iVar3 = strncmp((char *)(iVar11 + uVar9),"true",4);
      if (iVar3 != 0) goto LAB_000128aa;
      item->type = 2;
      *(undefined4 *)&item->valueint = 1;
    }
    iVar11 = *(int *)input_buffer[2].opaque + 4;
  }
LAB_000128e0:
  *(int *)input_buffer[2].opaque = iVar11;
  return 1;
LAB_00012952:
  abStack_60[iVar3] = 0;
  strtod();
  if (abStack_60 == (byte *)0x0) {
    return 0;
  }
  bVar15 = __aeabi_dcmpge(extraout_s0,extraout_s1,(uint)&DAT_ffc00000,(uint)&DAT_41dfffff);
  if (bVar15) {
    uVar9 = 0x7fffffff;
  }
  else {
    bVar15 = __ledf2(extraout_s0,extraout_s1,0,(uint)&DAT_c1e00000);
    if (bVar15) {
      uVar9 = 0x80000000;
    }
    else {
      uVar9 = _cast_double_to_int(extraout_s0,extraout_s1);
    }
  }
  *(uint *)((int)&item->valueint + 4) = extraout_s0;
  *(uint *)&item->valuedouble = extraout_s1;
  *(uint *)&item->valueint = uVar9;
  item->type = 8;
  iVar11 = *(int *)input_buffer[2].opaque - (int)abStack_60;
  goto LAB_000128e0;
LAB_00012b60:
  if (item_00 == (cJSON *)0x0) {
    return 0;
  }
  goto LAB_00012b66;
}


