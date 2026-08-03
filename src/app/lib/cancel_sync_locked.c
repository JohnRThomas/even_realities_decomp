/*
 * Function: cancel_sync_locked
 * Entry:    00075f40
 * Prototype: bool __stdcall cancel_sync_locked(k_work * work, z_work_canceller * canceller)
 */


/* exclude_from_export */

bool cancel_sync_locked(k_work *work,z_work_canceller *canceller)

{
  z_work_canceller *pzVar1;
  z_work_canceller *pzVar2;
  uint32_t uVar3;
  
  uVar3 = work->flags;
  pzVar1 = (z_work_canceller *)_current._40_4_;
  pzVar2 = (z_work_canceller *)_current._44_4_;
  if ((int)(uVar3 << 0x1e) < 0) {
    z_impl_k_sem_init(&canceller->sem,0,1);
    (canceller->node).next = (sys_snode_t *)0x0;
    canceller->work = work;
    pzVar1 = canceller;
    pzVar2 = canceller;
    if (_current._44_4_ != 0) {
      *(z_work_canceller **)_current._44_4_ = canceller;
      pzVar1 = (z_work_canceller *)_current._40_4_;
      pzVar2 = canceller;
    }
  }
  _current._44_4_ = pzVar2;
  _current._40_4_ = pzVar1;
  return SUB41((uVar3 << 0x1e) >> 0x1f,0);
}


