/*
 * Function: cJSON_CreateString
 * Entry:    00067f04
 * Prototype: cJSON * __stdcall cJSON_CreateString(char * string)
 */


/* exclude_from_export_ai */

cJSON * cJSON_CreateString(char *string)

{
  cJSON *item;
  uchar *puVar1;
  cjson_internal_hooks *hooks;
  
  item = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
  if (item != (cJSON *)0x0) {
    item->type = 0x10;
    puVar1 = cJSON_strdup((uchar *)string,hooks);
    item->valuestring = puVar1;
    if (puVar1 != (uchar *)0x0) {
      return item;
    }
    cJSON_Delete(item);
  }
  return (cJSON *)0x0;
}


