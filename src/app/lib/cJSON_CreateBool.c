/*
 * Function: cJSON_CreateBool
 * Entry:    00067ee4
 * Prototype: cJSON * __stdcall cJSON_CreateBool(cJSON_bool boolean)
 */


/* exclude_from_export_ai */

cJSON * cJSON_CreateBool(cJSON_bool boolean)

{
  cJSON *pcVar1;
  int iVar2;
  
  pcVar1 = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
  if (pcVar1 != (cJSON *)0x0) {
    if (boolean == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 2;
    }
    pcVar1->type = iVar2;
  }
  return pcVar1;
}


