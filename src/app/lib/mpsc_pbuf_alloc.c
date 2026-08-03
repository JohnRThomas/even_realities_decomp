/*
 * Function: mpsc_pbuf_alloc
 * Entry:    0004ef2c
 * Prototype: mpsc_pbuf_generic * __stdcall mpsc_pbuf_alloc(mpsc_pbuf_buffer * buffer, size_t wlen, k_timeout_t timeout)
 */


/* exclude_from_export_ai */

mpsc_pbuf_generic * mpsc_pbuf_alloc(mpsc_pbuf_buffer *buffer,size_t wlen,k_timeout_t timeout)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint32_t uVar4;
  int iVar5;
  undefined4 extraout_r1;
  char *file;
  dword dVar6;
  char *file_00;
  int line;
  undefined *puVar7;
  int line_00;
  dword *l;
  dword prev_tmp_wr_idx;
  mpsc_pbuf_generic *pmVar8;
  undefined4 uVar9;
  k_timeout_t timeout_00;
  undefined4 local_44;
  mpsc_pbuf_generic *local_34;
  uint local_30;
  uint32_t local_2c [2];
  
  prev_tmp_wr_idx = 0;
  pmVar8 = (mpsc_pbuf_generic *)0x0;
  local_34 = (mpsc_pbuf_generic *)0x0;
  local_2c[0] = 0;
  if (wlen <= buffer->size) {
    l = &buffer->lock;
    do {
      uVar9 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar9 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = z_spin_lock_valid((k_spinlock *)l);
      if (!bVar2) {
LAB_0004ef66:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
        _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
        goto LAB_0004f03c;
      }
      z_spin_lock_set_owner((k_spinlock *)l);
      if (local_2c[0] != 0) {
        post_drop_action(buffer,prev_tmp_wr_idx,local_2c[0]);
        local_2c[0] = 0;
      }
      bVar2 = free_space(buffer,&local_30);
      uVar1 = local_30;
      if (local_30 < wlen) {
        if (bVar2) {
          add_skip_item(buffer,local_30);
          bVar2 = true;
          goto LAB_0004efcc;
        }
        local_44 = (undefined4)timeout.ticks;
        if (timeout.ticks == 0) {
LAB_0004f082:
          prev_tmp_wr_idx = buffer->tmp_wr_idx;
          bVar2 = drop_item_locked(buffer,uVar1,&local_34,local_2c);
          goto LAB_0004efcc;
        }
        bVar2 = k_is_in_isr();
        if (bVar2) goto LAB_0004f082;
        bVar2 = z_spin_unlock_valid((k_spinlock *)l);
        if (bVar2) {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(uVar9);
          }
          InstructionSynchronizationBarrier(0xf);
          timeout_00.ticks._4_4_ = local_44;
          timeout_00.ticks._0_4_ = extraout_r1;
          iVar5 = z_impl_k_sem_take(&buffer->sem,timeout_00);
          uVar9 = 0;
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            uVar9 = getBasePriority();
          }
          bVar2 = (bool)isCurrentModePrivileged();
          if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
            setBasePriority(0x20);
          }
          InstructionSynchronizationBarrier(0xf);
          bVar2 = z_spin_lock_valid((k_spinlock *)l);
          if (!bVar2) goto LAB_0004ef66;
          z_spin_lock_set_owner((k_spinlock *)l);
          bVar2 = iVar5 == 0;
          goto LAB_0004efcc;
        }
LAB_0004f026:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
        _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
LAB_0004f03c:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      dVar6 = buffer->tmp_wr_idx;
      puVar7 = buffer->buf;
      pmVar8 = (mpsc_pbuf_generic *)(puVar7 + dVar6 * 4);
      puVar7[dVar6] = puVar7[dVar6] & 0xfc;
      uVar4 = idx_inc(buffer,buffer->tmp_wr_idx,wlen);
      buffer->tmp_wr_idx = uVar4;
      if (uVar4 == buffer->rd_idx) {
        buffer->flags = buffer->flags | 8;
      }
      bVar2 = false;
LAB_0004efcc:
      bVar3 = z_spin_unlock_valid((k_spinlock *)l);
      if (!bVar3) goto LAB_0004f026;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(uVar9);
      }
      InstructionSynchronizationBarrier(0xf);
      if (local_34 != (mpsc_pbuf_generic *)0x0) {
        if ((code *)buffer->notify_drop != (code *)0x0) {
          (*(code *)buffer->notify_drop)(buffer);
        }
        local_34 = (mpsc_pbuf_generic *)0x0;
      }
    } while (bVar2 != false);
  }
  return pmVar8;
}


