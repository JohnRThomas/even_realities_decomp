/*
 * Function: cJSON_Delete
 * Entry:    00067dc4
 * Prototype: void __stdcall cJSON_Delete(cJSON * item)
 */


/* exclude_from_export_ai */

void cJSON_Delete(cJSON *item)

{
  void *ptr;
  cJSON *pcVar1;
  
  while (item != (cJSON *)0x0) {
    pcVar1 = (cJSON *)item->next;
    if ((-1 < item->type << 0x17) &&
       ((((cJSON *)item->child == (cJSON *)0x0 ||
         (cJSON_Delete((cJSON *)item->child), -1 < item->type << 0x17)) &&
        (item->valuestring != (undefined *)0x0)))) {
      (*cjson_global_hooks.deallocate)(item->valuestring);
    }
    if ((-1 < item->type << 0x16) &&
       (ptr = *(void **)((int)&item->valuedouble + 4), ptr != (void *)0x0)) {
      (*cjson_global_hooks.deallocate)(ptr);
    }
    (*cjson_global_hooks.deallocate)(item);
    item = pcVar1;
  }
  return;
}


