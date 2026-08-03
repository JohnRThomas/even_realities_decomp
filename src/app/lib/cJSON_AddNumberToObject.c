/*
 * Function: cJSON_AddNumberToObject
 * Entry:    00088826
 * Prototype: cJSON * __stdcall cJSON_AddNumberToObject(cJSON * object, char * name, double number)
 */


/* exclude_from_export_ai */

cJSON * cJSON_AddNumberToObject(cJSON *object,char *name,double number)

{
  cJSON *item;
  cJSON_bool cVar1;
  cJSON_bool unaff_r4;
  
  item = cJSON_CreateNumber(number);
  cVar1 = add_item_to_object(object,name,item,(cjson_internal_hooks *)0x0,unaff_r4);
  if (cVar1 == 0) {
    cJSON_Delete(item);
    item = (cJSON *)0x0;
  }
  return item;
}


