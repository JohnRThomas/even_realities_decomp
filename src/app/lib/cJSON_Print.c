/*
 * Function: cJSON_Print
 * Entry:    000887c4
 * Prototype: char * __stdcall cJSON_Print(cJSON * item)
 */


/* exclude_from_export_ai */

char * cJSON_Print(cJSON *item)

{
  uchar *puVar1;
  cjson_internal_hooks *in_r2;
  
  puVar1 = cjson_print(item,1,in_r2);
  return (char *)puVar1;
}


