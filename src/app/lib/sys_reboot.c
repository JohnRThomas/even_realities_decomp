/*
 * Function: sys_reboot
 * Entry:    0004f348
 * Prototype: undefined __stdcall sys_reboot(int param_1)
 */


/* exclude_from_export */

void sys_reboot(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  sys_clock_disable();
  sys_arch_reboot(param_1);
  printk("Failed to reboot: spinning endlessly...\n");
  do {
    arch_cpu_idle();
  } while( true );
}


