/*
 * Function: submit_to_queue_locked
 * Entry:    00075f7c
 * Prototype: int __stdcall submit_to_queue_locked(k_work * work, k_work_q * * queuep)
 */


/* exclude_from_export */

int submit_to_queue_locked(k_work *work,k_work_q **queuep)

{
  bool bVar1;
  uint uVar2;
  dword dVar3;
  k_work_q *queue;
  uint uVar4;
  int iVar5;
  
  uVar2 = work->flags;
  uVar4 = (uVar2 & 3) >> 1;
  if ((int)(uVar2 << 0x1e) < 0) {
LAB_00076000:
    uVar4 = 0xfffffff0;
  }
  else {
    if ((int)(uVar2 << 0x1d) < 0) goto LAB_00075fdc;
    if (*queuep == (k_work_q *)0x0) {
      *queuep = work->queue;
    }
    if ((int)(work->flags << 0x1f) < 0) {
      if (work->queue == (k_work_q *)0x0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","work->queue != ((void *)0)",
                "WEST_TOPDIR/zephyr/kernel/work.c",334);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      iVar5 = 2;
      *queuep = work->queue;
    }
    else {
      iVar5 = 1;
    }
    queue = *queuep;
    if (queue == (k_work_q *)0x0) {
      uVar4 = 0xffffffea;
      goto LAB_00075fdc;
    }
    if ((k_work_q *)_current.base == queue) {
      bVar1 = k_is_in_isr();
      dVar3 = queue[0xc].thread;
      if (bVar1) goto LAB_00075fd0;
      if ((int)(dVar3 << 0x1f) < 0) {
        if ((-1 < (int)(dVar3 << 0x1c)) || ((int)(dVar3 << 0x1d) < 0)) goto LAB_00076012;
        goto LAB_00076000;
      }
    }
    else {
      dVar3 = queue[0xc].thread;
LAB_00075fd0:
      if ((int)(dVar3 << 0x1f) < 0) {
        if ((-1 < (int)(dVar3 << 0x1d)) && (-1 < (int)(dVar3 << 0x1c))) {
LAB_00076012:
          (work->node).next = (sys_snode_t *)0x0;
          if ((undefined4 *)queue[0xb].thread == (undefined4 *)0x0) {
            queue[10].flags = (dword)work;
            queue[0xb].thread = (dword)work;
          }
          else {
            *(undefined4 *)queue[0xb].thread = work;
            queue[0xb].thread = (dword)work;
          }
          notify_queue_locked(queue);
          work->flags = work->flags | 4;
          work->queue = *queuep;
          return iVar5;
        }
        goto LAB_00076000;
      }
    }
    uVar4 = 0xffffffed;
  }
LAB_00075fdc:
  *queuep = (k_work_q *)0x0;
  return uVar4;
}


