/*
 * Function: cJSON_AddBoolToObject
 * Entry:    000887fc
 * Prototype: cJSON * __stdcall cJSON_AddBoolToObject(cJSON * object, char * name, cJSON_bool boolean)
 */


/* exclude_from_export_ai */

cJSON * cJSON_AddBoolToObject(cJSON *object,char *name,cJSON_bool boolean)

{
  cJSON *item;
  cJSON_bool cVar1;
  cJSON_bool unaff_r4;
  
  item = cJSON_CreateBool(boolean);
  cVar1 = add_item_to_object(object,name,item,(cjson_internal_hooks *)0x0,unaff_r4);
  if (cVar1 == 0) {
    cJSON_Delete(item);
    item = (cJSON *)0x0;
  }
  return item;
}


