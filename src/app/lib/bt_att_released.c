/*
 * Function: bt_att_released
 * Entry:    0005b5d8
 * Prototype: undefined __stdcall bt_att_released(int param_1)
 */


/* exclude_from_export */

void bt_att_released(int param_1)

{
  k_mem_slab_free((k_mem_slab *)&DAT_200038f8,(void *)(param_1 + -8));
  return;
}


