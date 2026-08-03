/*
 * Function: mpsc_pbuf_free
 * Entry:    0004f268
 * Prototype: void __stdcall mpsc_pbuf_free(mpsc_pbuf_buffer * buffer, mpsc_pbuf_generic * packet)
 */


/* exclude_from_export_ai */

void mpsc_pbuf_free(mpsc_pbuf_buffer *buffer,mpsc_pbuf_generic *packet)

{
  uint uVar1;
  bool bVar2;
  int32_t val;
  uint32_t uVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  dword *l;
  undefined4 uVar4;
  
  val = (*(code *)buffer->get_wlen)(packet);
  l = &buffer->lock;
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)l);
    *(byte *)packet = *(byte *)packet & 0xfe;
    if (((int)(buffer->flags << 0x1e) < 0) &&
       (packet != (mpsc_pbuf_generic *)(buffer->buf + buffer->rd_idx * 4))) {
      packet->raw = packet->raw & 3 | val << 2;
    }
    else {
      *(byte *)packet = *(byte *)packet & 0xfd;
      if (buffer->rd_idx == buffer->tmp_rd_idx) {
        uVar3 = idx_inc(buffer,buffer->rd_idx,val);
        buffer->tmp_rd_idx = uVar3;
      }
      rd_idx_inc(buffer,val);
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)l);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      k_sem_give(&buffer->sem);
      return;
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


