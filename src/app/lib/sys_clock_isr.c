/*
 * Function: sys_clock_isr
 * Entry:    000535fc
 * Prototype: void __stdcall sys_clock_isr(void * arg)
 */


/* exclude_from_export_ai */

void sys_clock_isr(void *arg)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 in_r1;
  k_thread_entry_t *in_r2;
  
  cVar1 = isThreadModePrivileged();
  isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar1 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar1 = isUsingMainStack();
      setStackMode(cVar1 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  setProcStackPointerLimit(*(undefined4 *)((int)arg + 0x7c));
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(in_r1);
  }
  enableFIQinterrupts();
  enableIRQinterrupts();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  _current.base = (dword)arg;
  z_thread_entry(in_r2,(void *)0x0,(void *)0x0,(void *)0x0);
  software_bkpt(0x30);
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  iVar4 = uVar3 - 0x10;
  (*(code *)(&PTR_z_irq_spurious_1_0008b554)[iVar4 * 2])
            ((&PTR_0008b550)[iVar4 * 2],&PTR_0008b558 + iVar4 * 2);
  z_arm_int_exit();
  return;
}


