/*
 * Function: svc_attr_memory_release
 * Entry:    00082b5a
 * Prototype: void __stdcall svc_attr_memory_release(bt_gatt_dm * dm)
 */


/* exclude_from_export */

void svc_attr_memory_release(bt_gatt_dm *dm)

{
  undefined4 *ptr;
  undefined4 uVar1;
  
  *(undefined4 *)((int)&dm[5].STATE_NUM_ + 3) = 0;
  while (ptr = *(undefined4 **)((int)&dm[5].cur_chunk_len + 3), ptr != (undefined4 *)0x0) {
    uVar1 = *ptr;
    *(undefined4 *)((int)&dm[5].cur_chunk_len + 3) = uVar1;
    if (ptr == *(undefined4 **)((int)&dm[5].callback + 3)) {
      *(undefined4 *)((int)&dm[5].callback + 3) = uVar1;
    }
    k_free(ptr);
  }
  *(undefined4 *)((int)&dm[6].conn + 2) = 0;
  return;
}


