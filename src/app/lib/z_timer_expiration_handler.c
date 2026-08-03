/*
 * Function: z_timer_expiration_handler
 * Entry:    00066784
 * Prototype: void __stdcall z_timer_expiration_handler(_timeout * t)
 */


/* exclude_from_export_ai */

void z_timer_expiration_handler(_timeout *t)

{
  k_spinlock *lock;
  uint in_r2;
  uint uVar1;
  bool bVar2;
  
  uVar1 = in_r2 & 0xffffff;
  lock = (k_spinlock *)(in_r2 - DAT_20006890);
  bVar2 = CARRY4((uint)lock,DAT_20006890);
  DAT_20006890 = (int)&lock->thread_cpu + DAT_20006890;
  DAT_20006894 = DAT_20006894 + (uint)bVar2;
  if (uVar1 - 0x200000 < 0xc00000) {
    DAT_20006898 = DAT_2000bcc4 * 0x1000000 + uVar1;
    DAT_2000689c = (DAT_2000bcc4 >> 8) + (uint)CARRY4(DAT_2000bcc4 * 0x1000000,uVar1);
  }
  z_reschedule(lock,0x20006890);
  return;
}


