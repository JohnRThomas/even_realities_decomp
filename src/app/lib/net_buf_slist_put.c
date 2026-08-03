/*
 * Function: net_buf_slist_put
 * Entry:    00062320
 * Prototype: void __stdcall net_buf_slist_put(sys_slist_t * list, net_buf * buf)
 */


/* exclude_from_export */

void net_buf_slist_put(sys_slist_t *list,net_buf *buf)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar3;
  
  if (list == (sys_slist_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","list","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1ad);
  }
  else if (buf == (net_buf *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1ae);
  }
  else {
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)&DAT_2000b9e4);
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)&DAT_2000b9e4);
      (buf->node).next = (sys_snode_t *)0x0;
      if ((undefined4 *)list->tail == (undefined4 *)0x0) {
        list->head = (undefined *)buf;
        list->tail = (undefined *)buf;
      }
      else {
        *(net_buf **)list->tail = buf;
        list->tail = (undefined *)buf;
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)&DAT_2000b9e4);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar3);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
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


