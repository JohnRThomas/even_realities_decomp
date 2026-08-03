/*
 * Function: add_item_to_object
 * Entry:    00067914
 * Prototype: cJSON_bool __stdcall add_item_to_object(cJSON * object, char * string, cJSON * item, cjson_internal_hooks * hooks, cJSON_bool constant_key)
 */


/* exclude_from_export_ai */

cJSON_bool
add_item_to_object(cJSON *object,char *string,cJSON *item,cjson_internal_hooks *hooks,
                  cJSON_bool constant_key)

{
  void *ptr;
  cJSON_bool cVar1;
  uint uVar2;
  
  if ((((object != (cJSON *)0x0) && (string != (char *)0x0)) && (item != (cJSON *)0x0)) &&
     (object != item)) {
    if (hooks == (cjson_internal_hooks *)0x0) {
      string = (char *)cJSON_strdup((uchar *)string,(cjson_internal_hooks *)string);
      if ((uchar *)string == (uchar *)0x0) {
        return 0;
      }
      uVar2 = item->type & 0xfffffdff;
    }
    else {
      uVar2 = item->type | 0x200;
    }
    if ((-1 < item->type << 0x16) &&
       (ptr = *(void **)((int)&item->valuedouble + 4), ptr != (void *)0x0)) {
      (*cjson_global_hooks.deallocate)(ptr);
    }
    *(char **)((int)&item->valuedouble + 4) = string;
    item->type = uVar2;
    cVar1 = add_item_to_array(object,item);
    return cVar1;
  }
  return 0;
}


