/*
 * Function: arch_cpu_atomic_idle
 * Entry:    000531e4
 * Prototype: void __stdcall arch_cpu_atomic_idle(uint key)
 */


/* exclude_from_export_ai */

void arch_cpu_atomic_idle(uint key)

{
  bool bVar1;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  bVar1 = z_arm_on_enter_cpu_idle();
  if (bVar1) {
    DataSynchronizationBarrier(0xf);
    WaitForEvent();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(key);
  }
  enableIRQinterrupts();
  return;
}


