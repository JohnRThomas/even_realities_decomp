/*
 * Function: sc_commit
 * Entry:    0005d61c
 * Prototype: int __stdcall sc_commit(void)
 */


/* exclude_from_export_ai */

int sc_commit(void)

{
  bool bVar1;
  int bit;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  
  atomic_set_bit((atomic_t *)&DAT_20006628,4);
  atomic_test_and_clear_bit((atomic_t *)&DAT_20006628,-3);
  bVar1 = atomic_test_bit((atomic_t *)&DAT_20006628,bit);
  timeout.ticks._0_4_ = (uint)bVar1;
  if ((int)((uint)timeout.ticks << 0x1f) < 0) {
    timeout.ticks._4_4_ = extraout_r1;
    sc_work_submit(timeout);
  }
  return 0;
}


