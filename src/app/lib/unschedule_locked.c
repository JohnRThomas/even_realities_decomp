/*
 * Function: unschedule_locked
 * Entry:    00089d1a
 * Prototype: bool __stdcall unschedule_locked(k_work_delayable * dwork)
 */


/* exclude_from_export */

bool unschedule_locked(k_work_delayable *dwork)

{
  bool bVar1;
  int extraout_r0;
  int iVar2;
  
  flag_clear(&(dwork->work).flags,3);
  bVar1 = false;
  if (extraout_r0 != 0) {
    iVar2 = z_abort_timeout(&dwork->timeout);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}


