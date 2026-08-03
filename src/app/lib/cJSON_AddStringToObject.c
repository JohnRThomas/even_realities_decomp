/*
 * Function: cJSON_AddStringToObject
 * Entry:    0008884e
 * Prototype: cJSON * __stdcall cJSON_AddStringToObject(cJSON * object, char * name, char * string)
 */


/* exclude_from_export_ai */

cJSON * cJSON_AddStringToObject(cJSON *object,char *name,char *string)

{
  cJSON *item;
  cJSON_bool cVar1;
  cJSON_bool unaff_r4;
  
  item = cJSON_CreateString(string);
  cVar1 = add_item_to_object(object,name,item,(cjson_internal_hooks *)0x0,unaff_r4);
  if (cVar1 == 0) {
    cJSON_Delete(item);
    item = (cJSON *)0x0;
  }
  return item;
}


