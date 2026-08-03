/*
 * Function: cJSON_GetArrayItem
 * Entry:    000887e0
 * Prototype: cJSON * __stdcall cJSON_GetArrayItem(cJSON * array, int index)
 */


/* exclude_from_export_ai */

cJSON * cJSON_GetArrayItem(cJSON *array,int index)

{
  cJSON *pcVar1;
  
  if (-1 < index) {
    pcVar1 = (cJSON *)0x0;
    if (array != (cJSON *)0x0) {
      pcVar1 = (cJSON *)array->child;
      for (; (pcVar1 != (cJSON *)0x0 && (index != 0)); index = index + -1) {
        pcVar1 = (cJSON *)pcVar1->next;
      }
    }
    return pcVar1;
  }
  return (cJSON *)0x0;
}


