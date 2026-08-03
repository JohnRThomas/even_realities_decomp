/*
 * Function: print_object
 * Entry:    00067968
 * Prototype: cJSON_bool __stdcall print_object(cJSON * item, printbuffer * output_buffer)
 */


/* exclude_from_export */

cJSON_bool print_object(cJSON *item,printbuffer *output_buffer)

{
  double *pdVar1;
  byte bVar2;
  double param3;
  double param3_00;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  size_t sVar7;
  uchar *puVar8;
  int *piVar9;
  char *pcVar10;
  uchar *puVar11;
  uint uVar12;
  cJSON_bool cVar13;
  cJSON *pcVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  uint local_50;
  uint uStack_4c;
  int local_44;
  char local_40 [28];
  
  if ((item == (cJSON *)0x0) || (output_buffer == (printbuffer *)0x0))
  goto switchD_0006798a_caseD_3;
  bVar2 = (byte)item->type;
  uVar12 = (uint)bVar2;
  if (uVar12 == 0x10) {
    cVar13 = print_string_ptr(item->valuestring,output_buffer);
    return cVar13;
  }
  if (0x10 < uVar12) {
    if (uVar12 == 0x40) {
      pcVar14 = (cJSON *)item->child;
      if (*(int *)output_buffer[5].opaque == 0) {
        iVar17 = 1;
      }
      else {
        iVar17 = 2;
      }
      puVar8 = ensure(output_buffer,iVar17 + 1);
      if (puVar8 != (uchar *)0x0) {
        *puVar8 = '{';
        *(int *)output_buffer[3].opaque = *(int *)output_buffer[3].opaque + 1;
        if (*(int *)output_buffer[5].opaque != 0) {
          puVar8[1] = '\n';
        }
        *(int *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + iVar17;
        for (; pcVar14 != (cJSON *)0x0; pcVar14 = (cJSON *)pcVar14->next) {
          if (*(int *)output_buffer[5].opaque != 0) {
            puVar11 = ensure(output_buffer,*(size_t *)output_buffer[3].opaque);
            puVar8 = puVar11;
            if (puVar11 == (uchar *)0x0) goto switchD_0006798a_caseD_3;
            for (; (uint)((int)puVar8 - (int)puVar11) < *(uint *)output_buffer[3].opaque;
                puVar8 = puVar8 + 1) {
              *puVar8 = '\t';
            }
            *(uint *)output_buffer[2].opaque =
                 *(int *)output_buffer[2].opaque + *(uint *)output_buffer[3].opaque;
          }
          cVar13 = print_string_ptr(*(uchar **)((int)&pcVar14->valuedouble + 4),output_buffer);
          if (cVar13 == 0) goto switchD_0006798a_caseD_3;
          update_offset(output_buffer);
          if (*(int *)output_buffer[5].opaque == 0) {
            sVar7 = 1;
          }
          else {
            sVar7 = 2;
          }
          puVar8 = ensure(output_buffer,sVar7);
          if (puVar8 == (uchar *)0x0) goto switchD_0006798a_caseD_3;
          *puVar8 = ':';
          if (*(int *)output_buffer[5].opaque != 0) {
            puVar8[1] = '\t';
          }
          *(size_t *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + sVar7;
          cVar13 = print_object(pcVar14,output_buffer);
          if (cVar13 == 0) goto switchD_0006798a_caseD_3;
          update_offset(output_buffer);
          uVar12 = (uint)(*(int *)output_buffer[5].opaque != 0);
          if (pcVar14->next != (undefined *)0x0) {
            uVar12 = uVar12 + 1;
          }
          puVar8 = ensure(output_buffer,uVar12 + 1);
          if (puVar8 == (uchar *)0x0) goto switchD_0006798a_caseD_3;
          puVar11 = puVar8;
          if (pcVar14->next != (undefined *)0x0) {
            puVar11 = puVar8 + 1;
            *puVar8 = ',';
          }
          puVar8 = puVar11;
          if (*(int *)output_buffer[5].opaque != 0) {
            puVar8 = puVar11 + 1;
            *puVar11 = '\n';
          }
          *puVar8 = '\0';
          *(uint *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + uVar12;
        }
        if (*(int *)output_buffer[5].opaque == 0) {
          sVar7 = 2;
        }
        else {
          sVar7 = *(int *)output_buffer[3].opaque + 1;
        }
        puVar8 = ensure(output_buffer,sVar7);
        if (puVar8 != (uchar *)0x0) {
          puVar11 = puVar8;
          if (*(int *)output_buffer[5].opaque != 0) {
            for (; (uint)((int)puVar11 - (int)puVar8) < *(int *)output_buffer[3].opaque - 1U;
                puVar11 = puVar11 + 1) {
              *puVar11 = '\t';
            }
          }
          *puVar11 = '}';
          puVar11[1] = '\0';
LAB_00067b78:
          *(int *)output_buffer[3].opaque = *(int *)output_buffer[3].opaque + -1;
          goto LAB_000679d0;
        }
      }
    }
    else if (uVar12 == 0x80) {
      if (item->valuestring != (char *)0x0) {
        sVar7 = strlen(item->valuestring);
        puVar8 = ensure(output_buffer,sVar7 + 1);
        if (puVar8 != (uchar *)0x0) {
          memcpy(puVar8,item->valuestring,sVar7 + 1);
          goto LAB_000679d0;
        }
      }
    }
    else if (uVar12 == 0x20) {
      pcVar14 = (cJSON *)item->child;
      puVar8 = ensure(output_buffer,1);
      if (puVar8 != (uchar *)0x0) {
        *puVar8 = '[';
        *(int *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + 1;
        *(int *)output_buffer[3].opaque = *(int *)output_buffer[3].opaque + 1;
        for (; pcVar14 != (cJSON *)0x0; pcVar14 = (cJSON *)pcVar14->next) {
          cVar13 = print_object(pcVar14,output_buffer);
          if (cVar13 == 0) goto switchD_0006798a_caseD_3;
          update_offset(output_buffer);
          if (pcVar14->next != (undefined *)0x0) {
            if (*(int *)output_buffer[5].opaque == 0) {
              iVar17 = 1;
            }
            else {
              iVar17 = 2;
            }
            puVar8 = ensure(output_buffer,iVar17 + 1);
            if (puVar8 == (uchar *)0x0) goto switchD_0006798a_caseD_3;
            *puVar8 = ',';
            if (*(int *)output_buffer[5].opaque == 0) {
              puVar11 = puVar8 + 1;
            }
            else {
              puVar11 = puVar8 + 2;
              puVar8[1] = bVar2;
            }
            *puVar11 = '\0';
            *(int *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + iVar17;
          }
        }
        puVar8 = ensure(output_buffer,2);
        if (puVar8 != (uchar *)0x0) {
          puVar8[1] = '\0';
          *puVar8 = ']';
          goto LAB_00067b78;
        }
      }
    }
    goto switchD_0006798a_caseD_3;
  }
  switch(uVar12) {
  case 1:
    local_44._0_1_ = 'f';
    local_44._1_1_ = 'a';
    local_44._2_1_ = 'l';
    local_44._3_1_ = 's';
    local_40[0] = 'e';
    local_40[1] = '\0';
    puVar8 = ensure(output_buffer,6);
    if (puVar8 != (uchar *)0x0) {
      strcpy((char *)puVar8,(char *)&local_44);
      return uVar12;
    }
  default:
switchD_0006798a_caseD_3:
    cVar13 = 0;
    break;
  case 2:
    pcVar10 = "true";
    goto LAB_000679ae;
  case 4:
    pcVar10 = "null";
LAB_000679ae:
    local_44 = *(int *)pcVar10;
    local_40[0] = (char)*(int *)((int)pcVar10 + 4);
    puVar8 = ensure(output_buffer,5);
    cVar13 = 0;
    if (puVar8 != (uchar *)0x0) {
      strcpy((char *)puVar8,(char *)&local_44);
LAB_000679d0:
      cVar13 = 1;
    }
    break;
  case 8:
    pdVar1 = (double *)((int)&item->valueint + 4);
    uVar12 = *(uint *)pdVar1;
    uVar16 = *(uint *)&item->valuedouble;
    param3_00 = *pdVar1;
    param3 = *pdVar1;
    local_44 = 0;
    memset(local_40,0,0x16);
    local_50 = 0;
    uStack_4c = 0;
    iVar17 = __unorddf2(uVar12,uVar16,uVar12,uVar16);
    if (iVar17 == 0) {
      uVar19 = uVar16 & 0x7fffffff;
      iVar17 = __unorddf2(uVar12,uVar19,-1,0x7fefffff);
      if ((iVar17 == 0) && (bVar5 = __ledf2(uVar12,uVar19,0xffffffff,0x7fefffff), !bVar5))
      goto LAB_00067a50;
      iVar17 = snprintf((char *)&local_44,0x1a,"%1.15g",param3);
      iVar6 = sscanf((FILE *)&local_44,"%lg",(va_list)&local_50);
      uVar4 = uStack_4c;
      uVar3 = local_50;
      if (iVar6 == 1) {
        uVar15 = uStack_4c & 0x7fffffff;
        bVar5 = __gedf2(uVar12,uVar19,local_50,uVar15);
        uVar18 = uVar12;
        if (bVar5) {
          uVar18 = uVar3;
          uVar19 = uVar15;
        }
        uVar20 = __subdf(uVar3,uVar4,uVar12,uVar16);
        uVar21 = __muldf3(uVar18,uVar19,0,0x3cb00000);
        bVar5 = __ledf2((uint)uVar20,(uint)(uVar20 >> 0x20) & 0x7fffffff,(uint)uVar21,
                        (uint)(uVar21 >> 0x20));
        if (!bVar5) goto LAB_00067ae8;
      }
      else {
LAB_00067ae8:
        iVar17 = snprintf((char *)&local_44,0x1a,"%1.17g",param3_00);
      }
      if (0x19 < iVar17) goto switchD_0006798a_caseD_3;
    }
    else {
LAB_00067a50:
      strcpy((char *)&local_44,"null");
      iVar17 = 4;
    }
    puVar8 = ensure(output_buffer,iVar17 + 1);
    if (puVar8 == (uchar *)0x0) goto switchD_0006798a_caseD_3;
    piVar9 = &local_44;
    for (puVar11 = puVar8; puVar8 + iVar17 != puVar11; puVar11 = puVar11 + 1) {
      *puVar11 = (uchar)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    }
    puVar8[iVar17] = '\0';
    *(int *)output_buffer[2].opaque = *(int *)output_buffer[2].opaque + iVar17;
    goto LAB_000679d0;
  }
  return cVar13;
}


