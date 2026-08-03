/*
 * Function: k_work_submit_to_queue
 * Entry:    00089dac
 * Prototype: int __stdcall k_work_submit_to_queue(k_work_q * queue, k_work * work)
 */


/* exclude_from_export */

int k_work_submit_to_queue(k_work_q *queue,k_work *work)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint32_t key;
  
  iVar3 = z_work_submit_to_queue(queue,work);
  if (0 < iVar3) {
    key = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      key = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    z_reschedule_irqlock(key);
  }
  return iVar3;
}


