/*
 * Function: close
 * Entry:    000823a6
 * Prototype: int __stdcall close(int file)
 */


/* exclude_from_export */

int close(int file)

{
  int iVar1;
  code *pcVar2;
  ipc_rpmsg_instance *instance;
  int iVar3;
  k_thread *thread;
  atomic_t *target;
  
  instance = *(ipc_rpmsg_instance **)(file + 0x10);
  target = instance + 0xef;
  if (*target == 2) {
    *target = 1;
    if (((char)instance[0x19] == '\0') && ((char)instance[0x35] == '\0')) {
      iVar1 = ipc_rpmsg_deinit(instance,instance[0xee]);
      if (iVar1 == 0) {
        iVar3 = *(int *)(file + 0x10);
        iVar1 = *(int *)(*(int *)(file + 4) + 0x14);
        pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
        if (pcVar2 == (code *)0x0) {
          iVar1 = -0x58;
        }
        else {
          iVar1 = (*pcVar2)(iVar1,*(undefined4 *)(*(int *)(file + 4) + 0x18),0);
          if (iVar1 == 0) {
            thread = (k_thread *)(iVar3 + 0x2c0);
            k_work_queue_drain((k_work_q *)thread,true);
                    /* WARNING: Subroutine does not return */
            z_thread_abort(thread);
          }
        }
      }
      atomic_set(target,2);
    }
    else {
      iVar1 = -0x10;
    }
  }
  else {
    iVar1 = -0x78;
  }
  return iVar1;
}


