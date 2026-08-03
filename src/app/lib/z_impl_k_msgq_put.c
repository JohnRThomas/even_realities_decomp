/*
 * Function: z_impl_k_msgq_put
 * Entry:    00075378
 * Prototype: int __stdcall z_impl_k_msgq_put(k_msgq * msgq, void * data, k_timeout_t timeout)
 */


/* exclude_from_export */

int z_impl_k_msgq_put(k_msgq *msgq,void *data,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  dword dVar1;
  bool bVar2;
  k_thread *thread;
  undefined *puVar3;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  uint uVar4;
  int line;
  int line_00;
  int line_01;
  int iVar5;
  dword *l;
  k_spinlock_key_t key;
  
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  if ((uVar4 == 0) || (timeout.ticks == 0)) {
    l = &msgq->lock;
    key = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      key = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)l);
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)l);
      dVar1 = _current.base;
      if (msgq->used_msgs < msgq->max_msgs) {
        thread = z_unpend_first_thread(&msgq->wait_q);
        if (thread != (k_thread *)0x0) {
          memcpy(thread->next_event_link,data,msgq->msg_size);
          thread[1].userspace_local_data = (undefined *)0x0;
          z_ready_thread(thread);
          z_reschedule((k_spinlock *)l,key);
          return 0;
        }
        puVar3 = msgq->write_ptr;
        if ((puVar3 < msgq->buffer_start) || (msgq->buffer_end <= puVar3)) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                  "msgq->write_ptr >= msgq->buffer_start && msgq->write_ptr < msgq->buffer_end",
                  "WEST_TOPDIR/zephyr/kernel/msg_q.c",144);
          goto LAB_000753dc;
        }
        memcpy(puVar3,data,msgq->msg_size);
        puVar3 = msgq->write_ptr;
        msgq->write_ptr = puVar3 + msgq->msg_size;
        if (puVar3 + msgq->msg_size == msgq->buffer_end) {
          msgq->write_ptr = msgq->buffer_start;
        }
        msgq->used_msgs = msgq->used_msgs + 1;
        z_handle_obj_poll_events(&msgq->poll_events,0x10);
        iVar5 = 0;
      }
      else {
        if (timeout.ticks != 0) {
          *(void **)(_current.base + 0x14) = data;
          timeout_00.ticks._4_4_ = (int)timeout.ticks;
          timeout_00.ticks._0_4_ = dVar1;
          iVar5 = z_pend_curr((k_spinlock *)l,key,&msgq->wait_q,timeout_00);
          return iVar5;
        }
        iVar5 = -0x23;
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)l);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return iVar5;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_01,line_01);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)l,file_00,line_00);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "!arch_is_in_isr() || ((timeout).ticks == (((k_timeout_t) {0})).ticks)",
            "WEST_TOPDIR/zephyr/kernel/msg_q.c",0x76);
    _ASSERT("\t\n",test,file,line);
  }
LAB_000753dc:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


