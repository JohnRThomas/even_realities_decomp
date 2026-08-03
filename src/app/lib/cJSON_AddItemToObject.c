/*
 * Function: cJSON_AddItemToObject
 * Entry:    000887f6
 * Prototype: cJSON_bool __stdcall cJSON_AddItemToObject(cJSON * object, char * string, cJSON * item)
 */


/* exclude_from_export_ai */

cJSON_bool cJSON_AddItemToObject(cJSON *object,char *string,cJSON *item)

{
  cJSON_bool cVar1;
  cJSON_bool in_stack_00000000;
  
  cVar1 = add_item_to_object(object,string,item,(cjson_internal_hooks *)0x0,in_stack_00000000);
  return cVar1;
}


