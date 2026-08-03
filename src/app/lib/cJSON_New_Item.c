/*
 * Function: cJSON_New_Item
 * Entry:    00088784
 * Prototype: cJSON * __stdcall cJSON_New_Item(cjson_internal_hooks * hooks)
 */


/* exclude_from_export_ai */

cJSON * cJSON_New_Item(cjson_internal_hooks *hooks)

{
  cJSON *buf;
  
  buf = (cJSON *)(*(code *)hooks)(0x28);
  if (buf != (cJSON *)0x0) {
    memset(buf,0,0x28);
  }
  return buf;
}


