/*
 * Function: print_string_ptr
 * Entry:    000677a0
 * Prototype: cJSON_bool __stdcall print_string_ptr(uchar * input, printbuffer * output_buffer)
 */


/* exclude_from_export */

cJSON_bool print_string_ptr(uchar *input,printbuffer *output_buffer)

{
  uchar *puVar1;
  byte *param0;
  byte *pbVar2;
  byte bVar3;
  uint param3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined3 local_2c;
  undefined1 uStack_29;
  
  _local_2c = CONCAT13((char)((uint)output_buffer >> 0x18),0x2222);
  if (output_buffer != (printbuffer *)0x0) {
    if (input == (uchar *)0x0) {
      puVar1 = ensure(output_buffer,3);
      if (puVar1 != (uchar *)0x0) {
        strcpy((char *)puVar1,(char *)&local_2c);
        return 1;
      }
    }
    else {
      iVar5 = 0;
      pbVar4 = input;
LAB_000677ca:
      while( true ) {
        pbVar2 = pbVar4 + 1;
        bVar3 = *pbVar4;
        if (bVar3 == 0) break;
        pbVar4 = pbVar2;
        if (0x22 < bVar3) goto LAB_0006784a;
        if (bVar3 < 8) {
LAB_00067854:
          iVar5 = iVar5 + 5;
        }
        else {
          if ((int)((0x4000037U >> (uint)(byte)(bVar3 - 8)) << 0x1f) < 0) goto LAB_00067844;
          if (bVar3 < 0x20) goto LAB_00067854;
        }
      }
      pbVar4 = pbVar4 + (iVar5 - (int)input);
      puVar1 = ensure(output_buffer,(size_t)(pbVar4 + 3));
      if (puVar1 != (uchar *)0x0) {
        pbVar2 = puVar1 + 1;
        *puVar1 = '\"';
        if (iVar5 == 0) {
          memcpy(pbVar2,input,(size_t)pbVar4);
          puVar1[(int)(pbVar4 + 1)] = '\"';
          puVar1[(int)(pbVar4 + 2)] = '\0';
        }
        else {
          pbVar6 = input + -1;
          while( true ) {
            pbVar6 = pbVar6 + 1;
            bVar3 = *pbVar6;
            if (bVar3 == 0) break;
            if (((bVar3 < 0x20) || (bVar3 == 0x22)) || (bVar3 == 0x5c)) {
              param0 = pbVar2 + 1;
              *pbVar2 = 0x5c;
              bVar3 = *pbVar6;
              param3 = (uint)bVar3;
              if (param3 < 0xe) {
                switch(param3) {
                case L'\b':
                  bVar3 = 'b';
                  break;
                case L'\t':
                  bVar3 = 't';
                  break;
                case L'\n':
                  bVar3 = 'n';
                  break;
                default:
switchD_000678a0_caseD_b:
                  snprintf((char *)param0,
                           *(int *)output_buffer[1].opaque -
                           ((int)param0 - *(int *)output_buffer->opaque),"u%04x",param3);
                  param0 = pbVar2 + 5;
                  goto LAB_00067882;
                case L'\f':
                  bVar3 = 0x66;
                  break;
                case L'\r':
                  bVar3 = 0x72;
                }
              }
              else if ((param3 != 0x22) && (param3 != 0x5c)) goto switchD_000678a0_caseD_b;
              pbVar2[1] = bVar3;
            }
            else {
              *pbVar2 = bVar3;
              param0 = pbVar2;
            }
LAB_00067882:
            pbVar2 = param0 + 1;
          }
          puVar1[(int)(pbVar4 + 1)] = '\"';
          puVar1[(int)(pbVar4 + 2)] = '\0';
        }
        return 1;
      }
    }
  }
  return 0;
LAB_0006784a:
  if (bVar3 == 0x5c) {
LAB_00067844:
    iVar5 = iVar5 + 1;
  }
  goto LAB_000677ca;
}


