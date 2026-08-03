/*
 * Function: cjson_print
 * Entry:    00067d30
 * Prototype: uchar * __stdcall cjson_print(cJSON * item, cJSON_bool format, cjson_internal_hooks * hooks)
 */


/* exclude_from_export */

uchar * cjson_print(cJSON *item,cJSON_bool format,cjson_internal_hooks *hooks)

{
  cJSON_bool cVar1;
  uchar *puVar2;
  uint n;
  printbuffer local_34;
  uint local_30;
  int local_2c;
  cJSON_bool local_20;
  cjson_malloc_fn *pcStack_1c;
  cjson_free_fn *pcStack_18;
  cjson_reallocate_fn *pcStack_14;
  
  memset(&local_34,0,0x24);
  local_34.opaque = (byte  [4])(*cjson_global_hooks.allocate)(0x100);
  local_30 = 0x100;
  pcStack_14 = cjson_global_hooks.reallocate;
  pcStack_18 = cjson_global_hooks.deallocate;
  pcStack_1c = cjson_global_hooks.allocate;
  local_20 = format;
  if ((local_34.opaque != (byte  [4])0x0) && (cVar1 = print_object(item,&local_34), cVar1 != 0)) {
    update_offset(&local_34);
    if (cjson_global_hooks.reallocate == (cjson_reallocate_fn *)0x0) {
      puVar2 = (*cjson_global_hooks.allocate)(local_2c + 1);
      if (puVar2 != (uchar *)0x0) {
        n = local_2c + 1U;
        if (local_30 <= local_2c + 1U) {
          n = local_30;
        }
        memcpy(puVar2,(void *)local_34.opaque,n);
        puVar2[local_2c] = '\0';
        (*cjson_global_hooks.deallocate)((void *)local_34.opaque);
        return puVar2;
      }
    }
    else {
      puVar2 = (*cjson_global_hooks.reallocate)((void *)local_34.opaque,local_2c + 1);
      if (puVar2 != (uchar *)0x0) {
        return puVar2;
      }
    }
  }
  if (local_34.opaque != (byte  [4])0x0) {
    (*cjson_global_hooks.deallocate)((void *)local_34.opaque);
  }
  return (uchar *)0x0;
}


