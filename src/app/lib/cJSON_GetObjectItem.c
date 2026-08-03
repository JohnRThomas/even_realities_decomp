/*
 * Function: cJSON_GetObjectItem
 * Entry:    000887ec
 * Prototype: cJSON * __stdcall cJSON_GetObjectItem(cJSON * object, char * string)
 */


/* exclude_from_export_ai */

cJSON * cJSON_GetObjectItem(cJSON *object,char *string)

{
  cJSON *pcVar1;
  
  pcVar1 = get_object_item(object,string,0);
  return pcVar1;
}


