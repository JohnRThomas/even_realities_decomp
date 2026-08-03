/*
 * Function: idle
 * Entry:    00075330
 * Prototype: void __stdcall idle(void * unused1, void * unused2, void * unused3)
 */


/* exclude_from_export */

void idle(void *unused1,void *unused2,void *unused3)

{
  bool bVar1;
  uint uVar2;
  
  if (-1 < *(char *)(_current.base + 0xe)) {
    do {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      arch_cpu_idle();
    } while( true );
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","_kernel.cpus[0].current->base.prio >= 0",
          "WEST_TOPDIR/zephyr/kernel/idle.c",41);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


