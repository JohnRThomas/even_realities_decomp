/*
 * Function: add_item_to_array
 * Entry:    000886de
 * Prototype: cJSON_bool __stdcall add_item_to_array(cJSON * array, cJSON * item)
 */


/* exclude_from_export_ai */

cJSON_bool add_item_to_array(cJSON *array,cJSON *item)

{
  undefined4 *puVar1;
  
  if (((item != (cJSON *)0x0) && (array != (cJSON *)0x0)) && (item != array)) {
    if (array->child == (undefined *)0x0) {
      array->child = (undefined *)item;
      item->next = (undefined *)0x0;
      item->prev = (undefined *)item;
    }
    else {
      puVar1 = *(undefined4 **)(array->child + 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = item;
        item->prev = (undefined *)puVar1;
        *(cJSON **)(array->child + 4) = item;
      }
    }
    return 1;
  }
  return 0;
}


