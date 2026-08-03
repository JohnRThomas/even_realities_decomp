/*
 * Function: cJSON_PrintUnformatted
 * Entry:    000887ca
 * Prototype: char * __stdcall cJSON_PrintUnformatted(cJSON * item)
 */


/* exclude_from_export_ai */

char * cJSON_PrintUnformatted(cJSON *item)

{
  uchar *puVar1;
  cjson_internal_hooks *in_r2;
  
  puVar1 = cjson_print(item,0,in_r2);
  return (char *)puVar1;
}


