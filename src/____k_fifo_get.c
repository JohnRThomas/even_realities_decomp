/*
 * Function: $_?_k_fifo_get
 * Entry:    00075a54
 * Prototype: net_buf * __stdcall $_?_k_fifo_get(k_fifo * fifo, k_timeout_t timeout)
 */


net_buf * ____k_fifo_get(k_fifo *fifo,k_timeout_t timeout)

{
  bool bVar1;
  net_buf *pnVar2;
  int iVar3;
  char *file;
  sys_sfnode_t *psVar4;
  char *file_00;
  uint in_r3;
  int line;
  uint uVar5;
  int line_00;
  uint uVar6;
  sys_sfnode_t *node;
  k_spinlock *l;
  k_spinlock_key_t key;
  undefined4 in_stack_00000000;
  
  l = &(fifo->_queue).lock;
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid(l);
  if (bVar1) goto LAB_00075a96;
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
  while( true ) {
    k_panic();
LAB_00075a96:
    z_spin_lock_set_owner(l);
    node = (fifo->_queue).data_q.head;
    if (node == (sys_sfnode_t *)0x0) {
      uVar6 = (uint)((ulonglong)timeout.ticks >> 0x20) | in_r3;
      pnVar2 = (net_buf *)0x0;
      if (uVar6 != 0) {
        iVar3 = z_pend_curr(l,key,(_wait_q_t *)&(fifo->_queue).wait_q,
                            (k_timeout_t)CONCAT44(in_stack_00000000,uVar6));
        if (iVar3 != 0) {
          return (net_buf *)0x0;
        }
        return *(net_buf **)(DAT_2000be38 + 0x14);
      }
    }
    else {
      uVar5 = *node;
      psVar4 = (fifo->_queue).data_q.tail;
      (fifo->_queue).data_q.head = (sys_sfnode_t *)(uVar5 & 0xfffffffc);
      if (node == psVar4) {
        (fifo->_queue).data_q.tail = (sys_sfnode_t *)(uVar5 & 0xfffffffc);
      }
      pnVar2 = z_queue_node_peek(node,true);
    }
    bVar1 = z_spin_unlock_valid(l);
    if (bVar1) break;
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(key);
  }
  InstructionSynchronizationBarrier(0xf);
  return pnVar2;
}


