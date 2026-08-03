/*
 * Function: create_free_list
 * Entry:    00089b6c
 * Prototype: int __stdcall create_free_list(k_mem_slab * slab)
 */


/* exclude_from_export */

int create_free_list(k_mem_slab *slab)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)slab->buffer;
  if (((slab->block_size | (uint)puVar1) & 3) == 0) {
    slab->free_list = (undefined *)0x0;
    for (uVar2 = 0; uVar2 < slab->num_blocks; uVar2 = uVar2 + 1) {
      *puVar1 = slab->free_list;
      slab->free_list = (undefined *)puVar1;
      puVar1 = (undefined4 *)((int)puVar1 + slab->block_size);
    }
    return 0;
  }
  return -0x16;
}


