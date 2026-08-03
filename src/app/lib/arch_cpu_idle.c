/*
 * Function: arch_cpu_idle
 * Entry:    000531ac
 * Prototype: void __stdcall arch_cpu_idle(void)
 */


/* exclude_from_export */

void arch_cpu_idle(void)

{
  bool bVar1;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_arm_on_enter_cpu_idle();
  if (bVar1) {
    DataSynchronizationBarrier(0xf);
    WaitForInterrupt();
  }
  enableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  return;
}


