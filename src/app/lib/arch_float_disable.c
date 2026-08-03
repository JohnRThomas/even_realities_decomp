/*
 * Function: arch_float_disable
 * Entry:    000535b0
 * Prototype: int __stdcall arch_float_disable(k_thread * thread)
 */


/* exclude_from_export */

int arch_float_disable(k_thread *thread)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((k_thread *)_current.base == thread) {
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getCurrentExceptionNumber();
      uVar3 = uVar3 & 0x1f;
    }
    if (uVar3 == 0) {
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      *(byte *)(_current.base + 0xc) = *(byte *)(_current.base + 0xc) & 0xfd;
      cVar2 = isThreadModePrivileged();
      isUsingMainStack();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setThreadModePrivileged(cVar2 == '\x01');
        bVar1 = (bool)isThreadMode();
        if (bVar1) {
          cVar2 = isUsingMainStack();
          setStackMode(cVar2 == '\x01');
        }
      }
      InstructionSynchronizationBarrier(0xf);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
  }
  return -0x16;
}


