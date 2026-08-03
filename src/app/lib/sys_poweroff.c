/*
 * Function: sys_poweroff
 * Entry:    00081cbe
 * Prototype: void __stdcall sys_poweroff(void)
 */


/* exclude_from_export */

void sys_poweroff(void)

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
  z_sys_poweroff();
  return;
}


