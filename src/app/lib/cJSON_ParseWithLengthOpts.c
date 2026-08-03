/*
 * Function: cJSON_ParseWithLengthOpts
 * Entry:    00067e0c
 * Prototype: cJSON * __stdcall cJSON_ParseWithLengthOpts(char * value, size_t buffer_length, char * * return_parse_end, cJSON_bool require_null_terminated)
 */


/* exclude_from_export_ai */

cJSON * cJSON_ParseWithLengthOpts
                  (char *value,size_t buffer_length,char **return_parse_end,
                  cJSON_bool require_null_terminated)

{
  cJSON *item;
  int iVar1;
  parse_buffer *ppVar2;
  cJSON_bool cVar3;
  parse_buffer local_3c;
  uint local_38;
  uint local_34;
  cjson_malloc_fn *pcStack_2c;
  cjson_free_fn *pcStack_28;
  cjson_reallocate_fn *pcStack_24;
  
  memset(&local_3c,0,0x1c);
  DAT_2000bcfc = (char *)0x0;
  DAT_2000bd00 = 0;
  if (value != (char *)0x0) {
    if (buffer_length != 0) {
      pcStack_24 = cjson_global_hooks.reallocate;
      pcStack_28 = cjson_global_hooks.deallocate;
      pcStack_2c = cjson_global_hooks.allocate;
      local_3c.opaque = (byte  [4])value;
      local_38 = buffer_length;
      item = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
      if (item != (cJSON *)0x0) {
        ppVar2 = (parse_buffer *)0x0;
        if (local_3c.opaque != (byte  [4])0x0) {
          if (local_34 == 0) {
            if ((4 < local_38) &&
               (iVar1 = strncmp((char *)local_3c.opaque,&DAT_000f49d3,3), iVar1 == 0)) {
              local_34 = 3;
            }
            ppVar2 = &local_3c;
          }
          else {
            ppVar2 = (parse_buffer *)0x0;
          }
        }
        ppVar2 = buffer_skip_whitespace(ppVar2);
        cVar3 = parse_value(item,ppVar2);
        if ((cVar3 != 0) &&
           ((require_null_terminated == 0 ||
            ((buffer_skip_whitespace(&local_3c), local_34 < local_38 &&
             (*(char *)((int)local_3c.opaque + local_34) == '\0')))))) {
          if (return_parse_end == (char **)0x0) {
            return item;
          }
          *return_parse_end = (char *)((int)local_3c.opaque + local_34);
          return item;
        }
        cJSON_Delete(item);
      }
    }
    if (local_38 <= local_34) {
      if (local_38 == 0) {
        local_34 = 0;
      }
      else {
        local_34 = local_38 - 1;
      }
    }
    DAT_2000bcfc = value;
    DAT_2000bd00 = local_34;
    if (return_parse_end != (char **)0x0) {
      *return_parse_end = value + local_34;
    }
  }
  return (cJSON *)0x0;
}


