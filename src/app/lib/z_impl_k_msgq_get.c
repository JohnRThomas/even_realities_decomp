/*
 * Function: z_impl_k_msgq_get
 * Entry:    000754e8
 * Prototype: int __stdcall z_impl_k_msgq_get(k_msgq * msgq, void * data, k_timeout_t timeout)
 */


/* exclude_from_export */

int z_impl_k_msgq_get(k_msgq *msgq,void *data,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  dword dVar1;
  bool bVar2;
  k_thread *thread;
  int iVar3;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  uint uVar4;
  int line;
  int line_00;
  undefined *puVar5;
  int line_01;
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
      if (msgq->used_msgs == 0) {
        if (timeout.ticks != 0) {
          *(void **)(_current.base + 0x14) = data;
          timeout_00.ticks._4_4_ = (int)timeout.ticks;
          timeout_00.ticks._0_4_ = dVar1;
          iVar3 = z_pend_curr((k_spinlock *)l,key,&msgq->wait_q,timeout_00);
          return iVar3;
        }
        iVar3 = -0x23;
      }
      else {
        memcpy(data,msgq->read_ptr,msgq->msg_size);
        puVar5 = msgq->read_ptr;
        msgq->read_ptr = puVar5 + msgq->msg_size;
        if (puVar5 + msgq->msg_size == msgq->buffer_end) {
          msgq->read_ptr = msgq->buffer_start;
        }
        msgq->used_msgs = msgq->used_msgs - 1;
        thread = z_unpend_first_thread(&msgq->wait_q);
        iVar3 = 0;
        if (thread != (k_thread *)0x0) {
          puVar5 = msgq->write_ptr;
          if ((msgq->buffer_start <= puVar5) && (puVar5 < msgq->buffer_end)) {
            memcpy(puVar5,thread->next_event_link,msgq->msg_size);
            puVar5 = msgq->write_ptr;
            msgq->write_ptr = puVar5 + msgq->msg_size;
            if (puVar5 + msgq->msg_size == msgq->buffer_end) {
              msgq->write_ptr = msgq->buffer_start;
            }
            msgq->used_msgs = msgq->used_msgs + 1;
            thread[1].userspace_local_data = (undefined *)0x0;
            z_ready_thread(thread);
            z_reschedule((k_spinlock *)l,key);
            return 0;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                  "msgq->write_ptr >= msgq->buffer_start && msgq->write_ptr < msgq->buffer_end",
                  "WEST_TOPDIR/zephyr/kernel/msg_q.c",235);
          goto LAB_0007554c;
        }
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)l);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return iVar3;
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
            "WEST_TOPDIR/zephyr/kernel/msg_q.c",210);
    _ASSERT("\t\n",test,file,line);
  }
LAB_0007554c:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


