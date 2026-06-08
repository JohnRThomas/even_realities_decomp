/*
 * Function: ?_bond_deleted
 * Entry:    000184d0
 * Prototype: undefined __stdcall ?_bond_deleted(undefined4 param_1, bt_addr_le_t * param_2, size_t param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void __bond_deleted(undefined4 param_1,bt_addr_le_t *param_2,size_t param_3)

{
  char acStack_28 [36];
  
  bt_addr_le_to_str(param_2,acStack_28,param_3);
  printk("bond_deleted conn: %s\n",acStack_28);
  *(undefined1 *)(GLOBAL_STATE.sem_8.limit + 0x367) = 0;
  return;
}


