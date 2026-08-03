/*
 * Function: mpsc_pbuf_claim
 * Entry:    0004f158
 * Prototype: mpsc_pbuf_generic * __stdcall mpsc_pbuf_claim(mpsc_pbuf_buffer * buffer)
 */


/* exclude_from_export_ai */

mpsc_pbuf_generic * mpsc_pbuf_claim(mpsc_pbuf_buffer *buffer)

{
  byte bVar1;
  bool bVar2;
  mpsc_pbuf_generic *pmVar3;
  uint32_t uVar4;
  int32_t val;
  undefined *puVar5;
  char *file;
  uint uVar6;
  char *file_00;
  int line;
  dword dVar7;
  int line_00;
  uint val_00;
  dword *l;
  undefined4 uVar8;
  mpsc_pbuf_generic *pmVar9;
  mpsc_pbuf_generic *pmVar10;
  
  l = &buffer->lock;
  do {
    uVar8 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar8 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)l);
    if ((mpsc_pbuf_generic *)(uint)bVar2 == (mpsc_pbuf_generic *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
      goto LAB_0004f192;
    }
    z_spin_lock_set_owner((k_spinlock *)l);
    uVar6 = buffer->tmp_rd_idx;
    if (((buffer->flags & 8) != 0) || (dVar7 = buffer->wr_idx, dVar7 < uVar6)) {
      dVar7 = buffer->size;
    }
    if (dVar7 == uVar6) {
      pmVar3 = (mpsc_pbuf_generic *)0x0;
      pmVar10 = pmVar3;
    }
    else {
      puVar5 = buffer->buf;
      bVar1 = puVar5[uVar6];
      pmVar9 = (mpsc_pbuf_generic *)(puVar5 + uVar6 * 4);
      pmVar3 = (mpsc_pbuf_generic *)(bVar1 & 3);
      pmVar10 = pmVar3;
      if ((bVar1 & 3) != 0) {
        pmVar10 = pmVar9;
        if ((pmVar3 != (mpsc_pbuf_generic *)&DAT_00000002) ||
           (val_00 = *(uint *)(puVar5 + uVar6 * 4) >> 2, val_00 == 0)) {
          if ((int)((uint)bVar1 << 0x1f) < 0) {
            puVar5[uVar6] = bVar1 | 2;
            uVar4 = buffer->tmp_rd_idx;
            val = (*(code *)buffer->get_wlen)(pmVar9);
            uVar4 = idx_inc(buffer,uVar4,val);
            pmVar3 = (mpsc_pbuf_generic *)0x0;
            buffer->tmp_rd_idx = uVar4;
            goto LAB_0004f1f2;
          }
          val_00 = (*(code *)buffer->get_wlen)(pmVar9);
        }
        uVar4 = idx_inc(buffer,buffer->tmp_rd_idx,val_00);
        buffer->tmp_rd_idx = uVar4;
        rd_idx_inc(buffer,val_00);
        pmVar3 = (mpsc_pbuf_generic *)(uint)bVar2;
      }
    }
LAB_0004f1f2:
    bVar2 = z_spin_unlock_valid((k_spinlock *)l);
    if (!bVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
LAB_0004f192:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    if (pmVar3 == (mpsc_pbuf_generic *)0x0) {
      return pmVar10;
    }
  } while( true );
}


