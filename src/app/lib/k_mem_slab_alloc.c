/*
 * Function: k_mem_slab_alloc
 * Entry:    00074ec8
 * Prototype: int __stdcall k_mem_slab_alloc(k_mem_slab * slab, void * * mem, k_timeout_t timeout)
 */


/* exclude_from_export */

int k_mem_slab_alloc(k_mem_slab *slab,void **mem,k_timeout_t timeout)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  undefined4 *puVar3;
  int line_00;
  int iVar4;
  dword *l;
  k_spinlock_key_t key;
  
  l = &slab->lock;
  key = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    key = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)l);
    puVar3 = (undefined4 *)slab->free_list;
    if (puVar3 == (undefined4 *)0x0) {
      if (timeout.ticks != 0) {
        iVar4 = z_pend_curr((k_spinlock *)l,key,&slab->wait_q,(k_timeout_t)(timeout.ticks << 0x20));
        if (iVar4 != 0) {
          return iVar4;
        }
        *mem = *(void **)(_current.base + 0x14);
        return 0;
      }
      iVar4 = -0xc;
      *mem = (void *)0x0;
    }
    else {
      *mem = puVar3;
      slab->free_list = (undefined *)*puVar3;
      slab->num_used = slab->num_used + 1;
      iVar4 = 0;
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)l);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(key);
      }
      InstructionSynchronizationBarrier(0xf);
      return iVar4;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


