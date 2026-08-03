/*
 * Function: do_db_hash
 * Entry:    0005df50
 * Prototype: void __stdcall do_db_hash(void)
 */


/* WARNING: Removing unreachable block (ram,0x0005df7c) */
/* exclude_from_export_ai */

void do_db_hash(void)

{
  int iVar1;
  int in_r1;
  int bit;
  int bit_00;
  int extraout_r3;
  
  atomic_test_bit((atomic_t *)&DAT_20006628,in_r1);
  db_hash_gen();
  atomic_test_bit((atomic_t *)&DAT_20006628,bit);
  atomic_test_bit((atomic_t *)&DAT_20006628,bit_00);
  if (-1 < extraout_r3 << 0x1b) {
    return;
  }
  atomic_set_bit((atomic_t *)&DAT_20006628,0x20);
  iVar1 = memcmp(&db_hash,&DAT_20006560,0x10);
  if (iVar1 == 0) {
    k_work_cancel_delayable((k_work_delayable *)&DAT_200065f8);
    atomic_test_and_clear_bit((atomic_t *)&DAT_20006628,-2);
    return;
  }
  sc_indicate(1,0xffff);
  set_all_change_unaware();
  db_hash_store();
  return;
}


