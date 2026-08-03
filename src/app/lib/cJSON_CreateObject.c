/*
 * Function: cJSON_CreateObject
 * Entry:    00067f4c
 * Prototype: cJSON * __stdcall cJSON_CreateObject(void)
 */


/* exclude_from_export_ai */

cJSON * cJSON_CreateObject(void)

{
  cJSON *pcVar1;
  
  pcVar1 = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
  if (pcVar1 != (cJSON *)0x0) {
    pcVar1->type = 0x40;
  }
  return pcVar1;
}


