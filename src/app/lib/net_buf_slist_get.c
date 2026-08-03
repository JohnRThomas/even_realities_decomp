/*
 * Function: net_buf_slist_get
 * Entry:    000623f4
 * Prototype: net_buf * __stdcall net_buf_slist_get(sys_slist_t * list)
 */


/* exclude_from_export */

net_buf * net_buf_slist_get(sys_slist_t *list)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  sys_snode_t *psVar3;
  int line_00;
  net_buf *pnVar4;
  undefined4 uVar5;
  
  if (list == (sys_slist_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","list","WEST_TOPDIR/zephyr/subsys/net/buf.c",442);
  }
  else {
    uVar5 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar5 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)&DAT_2000b9e4);
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)&DAT_2000b9e4);
      pnVar4 = (net_buf *)list->head;
      if (pnVar4 != (net_buf *)0x0) {
        psVar3 = (pnVar4->node).next;
        list->head = (undefined *)psVar3;
        if (pnVar4 == (net_buf *)list->tail) {
          list->tail = (undefined *)psVar3;
        }
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)&DAT_2000b9e4);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar5);
        }
        InstructionSynchronizationBarrier(0xf);
        return pnVar4;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",&DAT_2000b9e4,file_00,line_00);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",&DAT_2000b9e4,file,line);
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


