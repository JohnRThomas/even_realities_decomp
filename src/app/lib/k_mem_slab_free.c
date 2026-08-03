/*
 * Function: k_mem_slab_free
 * Entry:    00074f9c
 * Prototype: void __stdcall k_mem_slab_free(k_mem_slab * slab, void * mem)
 */


/* exclude_from_export */

void k_mem_slab_free(k_mem_slab *slab,void *mem)

{
  bool bVar1;
  k_thread *thread;
  uint uVar2;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  undefined *puVar3;
  int line_00;
  int line_01;
  dword *l;
  k_spinlock_key_t key;
  
  l = &slab->lock;
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)l);
    puVar3 = slab->buffer;
    if (((mem < puVar3) ||
        (uVar2 = slab->block_size,
        (int)mem - (int)puVar3 != uVar2 * ((uint)((int)mem - (int)puVar3) / uVar2))) ||
       (puVar3 + uVar2 * (slab->num_blocks - 1) < mem)) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "((char *)mem >= slab->buffer) && ((((char *)mem - slab->buffer) % slab->block_size) == 0) && ((char *)mem <= (slab->buffer + (slab->block_size * (slab->num_blocks - 1))))"
              ,"WEST_TOPDIR/zephyr/kernel/mem_slab.c",0x98);
      _ASSERT("\tInvalid memory pointer provided\n",test,file_00,line_00);
    }
    else {
      if ((slab->free_list == (undefined *)0x0) &&
         (thread = z_unpend_first_thread(&slab->wait_q), thread != (k_thread *)0x0)) {
        thread[1].userspace_local_data = (undefined *)0x0;
        thread->next_event_link = mem;
        z_ready_thread(thread);
        z_reschedule((k_spinlock *)l,key);
        return;
      }
      *(undefined **)mem = slab->free_list;
      slab->free_list = mem;
      slab->num_used = slab->num_used - 1;
      bVar1 = z_spin_unlock_valid((k_spinlock *)l);
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_01,line_01);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


