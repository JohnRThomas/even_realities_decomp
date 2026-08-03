/*
 * Function: db_hash_commit
 * Entry:    0005dfcc
 * Prototype: int __stdcall db_hash_commit(void)
 */


/* exclude_from_export_ai */

int db_hash_commit(void)

{
  atomic_set_bit((atomic_t *)&DAT_20006628,0x10);
  do_db_hash();
  return 0;
}


