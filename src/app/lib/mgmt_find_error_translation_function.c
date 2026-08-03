/*
 * Function: mgmt_find_error_translation_function
 * Entry:    00054648
 * Prototype: smp_translate_error_fn __stdcall mgmt_find_error_translation_function(uint16_t group_id)
 */


/* exclude_from_export_ai */

smp_translate_error_fn mgmt_find_error_translation_function(uint16_t group_id)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_2000b32c;
  puVar2 = DAT_2000b32c;
  if (DAT_2000b32c != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*DAT_2000b32c;
  }
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (smp_translate_error_fn)0x0;
    }
    if (*(uint16_t *)((int)puVar2 + 10) == group_id) break;
    puVar2 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar1;
    }
  }
  return (smp_translate_error_fn)puVar2[3];
}


