/*
 * Function: sc_process
 * Entry:    0005e768
 * Prototype: void __stdcall sc_process(k_work * work)
 */


/* WARNING: Removing unreachable block (ram,0x0005e782) */
/* exclude_from_export */

void sc_process(k_work *work)

{
  int iVar1;
  int in_r1;
  k_work *target;
  sys_snode_t local_1c [2];
  
  target = work + 3;
  atomic_test_bit((atomic_t *)target,in_r1);
  local_1c[0].next = work[-1].queue;
  atomic_test_and_clear_bit((atomic_t *)target,-2);
  work[-2].handler = (k_work_handler_t *)&PTR_DAT_0008ef6c;
  work[-2].queue = &LAB_0005d910_1;
  work[-1].node.next = local_1c;
  *(undefined2 *)&work[-1].queue = 0;
  *(undefined2 *)((int)&work[-1].queue + 2) = 0;
  *(undefined2 *)&work[-1].handler = 4;
  iVar1 = bt_gatt_indicate((bt_conn *)0x0,(bt_gatt_indicate_params *)(work + -2));
  if (iVar1 == 0) {
    atomic_set_bit((atomic_t *)target,2);
  }
  return;
}


