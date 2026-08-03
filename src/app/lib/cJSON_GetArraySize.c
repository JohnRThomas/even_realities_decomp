/*
 * Function: cJSON_GetArraySize
 * Entry:    000887d0
 * Prototype: int __stdcall cJSON_GetArraySize(cJSON * array)
 */


/* exclude_from_export_ai */

int cJSON_GetArraySize(cJSON *array)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (array != (cJSON *)0x0) {
    iVar1 = 0;
    for (puVar2 = (undefined4 *)array->child; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


