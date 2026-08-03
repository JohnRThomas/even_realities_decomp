/*
 * Function: queue_insert
 * Entry:    0007591c
 * Prototype: int32_t __stdcall queue_insert(k_queue * queue, void * prev, void * data, bool alloc, bool is_append)
 */


/* exclude_from_export */

int32_t queue_insert(k_queue *queue,void *prev,void *data,bool alloc,bool is_append)

{
  bool bVar1;
  k_thread *thread;
  sys_sfnode_t *psVar2;
  uint uVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  k_spinlock *l;
  k_spinlock_key_t key;
  
  l = &queue->lock;
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid(l);
  if (!bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
LAB_0007595e:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  z_spin_lock_set_owner(l);
  if (is_append) {
    prev = (queue->data_q).tail;
  }
  thread = z_unpend_first_thread((_wait_q_t *)&queue->wait_q);
  if (thread != (k_thread *)0x0) {
    thread->next_event_link = data;
    thread[1].userspace_local_data = (undefined *)0x0;
    z_ready_thread(thread);
    goto LAB_0007598a;
  }
  if (alloc) {
    psVar2 = z_thread_aligned_alloc(0,8);
    if (psVar2 == (sys_sfnode_t *)0x0) {
      bVar1 = z_spin_unlock_valid(l);
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return -0xc;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
      goto LAB_0007595e;
    }
    psVar2[1] = (sys_sfnode_t)data;
    *psVar2 = 1;
    data = psVar2;
  }
  else {
    *(undefined4 *)data = 0;
  }
  uVar3 = *(uint *)data & 3;
  if (prev == (sys_sfnode_t *)0x0) {
    *(uint *)data = (uint)(queue->data_q).head | uVar3;
    (queue->data_q).head = data;
    if ((queue->data_q).tail == (sys_sfnode_t *)0x0) {
LAB_000759f0:
      (queue->data_q).tail = data;
    }
  }
  else if (*(uint *)prev < 4) {
    *(uint *)data = uVar3;
    psVar2 = (queue->data_q).tail;
    if (psVar2 != (sys_sfnode_t *)0x0) {
      *psVar2 = *psVar2 & 3 | (uint)data;
      goto LAB_000759f0;
    }
    (queue->data_q).head = data;
    (queue->data_q).tail = data;
  }
  else {
    *(uint *)data = *(uint *)prev & 0xfffffffc | uVar3;
    *(uint *)prev = (uint)data | *(uint *)prev & 3;
  }
  z_handle_obj_poll_events((sys_dlist_t *)&queue->poll_events,4);
LAB_0007598a:
  z_reschedule(l,key);
  return 0;
}


