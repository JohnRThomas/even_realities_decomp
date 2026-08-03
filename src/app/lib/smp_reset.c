/*
 * Function: smp_reset
 * Entry:    000869bc
 * Prototype: void __stdcall smp_reset(bt_smp * smp)
 */


/* exclude_from_export_ai */

void smp_reset(bt_smp *smp)

{
  smp->SMP_NUM_FLAGS_ = 0;
  k_work_cancel_delayable((k_work_delayable *)(smp[3].rrnd + 9));
  smp->method = 0;
  smp->BT_SMP_NUM_CMDS_ = 0;
  atomic_set_bit((atomic_t *)smp,1);
  return;
}


