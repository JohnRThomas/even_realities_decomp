/*
 * Function: cJSON_CreateArray
 * Entry:    00067f34
 * Prototype: cJSON * __stdcall cJSON_CreateArray(void)
 */


/* exclude_from_export_ai */

cJSON * cJSON_CreateArray(void)

{
  cJSON *pcVar1;
  
  pcVar1 = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
  if (pcVar1 != (cJSON *)0x0) {
    pcVar1->type = 0x20;
  }
  return pcVar1;
}


