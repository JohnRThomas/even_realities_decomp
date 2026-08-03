/*
 * Function: k_mem_slab_init
 * Entry:    00089b98
 * Prototype: int __stdcall k_mem_slab_init(k_mem_slab * slab, void * buffer, size_t block_size, uint32_t num_blocks)
 */


/* exclude_from_export_ai */

int k_mem_slab_init(k_mem_slab *slab,void *buffer,size_t block_size,uint32_t num_blocks)

{
  int iVar1;
  
  slab->num_blocks = num_blocks;
  slab->block_size = block_size;
  slab->buffer = buffer;
  slab->num_used = 0;
  slab->lock = 0;
  iVar1 = create_free_list(slab);
  if (-1 < iVar1) {
    (slab->wait_q).head = (undefined *)slab;
    (slab->wait_q).tail = (undefined *)slab;
  }
  return iVar1;
}


