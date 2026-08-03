/*
 * Function: cJSON_IsArray
 * Entry:    00088878
 * Prototype: cJSON_bool __stdcall cJSON_IsArray(cJSON * item)
 */


/* exclude_from_export_ai */

cJSON_bool cJSON_IsArray(cJSON *item)

{
  uint uVar1;
  
  uVar1 = 0;
  if (item != (cJSON *)0x0) {
    uVar1 = (uint)((char)item->type == ' ');
  }
  return uVar1;
}


