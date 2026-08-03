/*
 * Function: get_ept_slot_with_name
 * Entry:    0008227c
 * Prototype: ipc_rpmsg_ept * __stdcall get_ept_slot_with_name(ipc_rpmsg_instance * rpmsg_inst, char * name)
 */


/* exclude_from_export */

ipc_rpmsg_ept * get_ept_slot_with_name(ipc_rpmsg_instance *rpmsg_inst,char *name)

{
  int iVar1;
  int iVar2;
  
  iVar1 = strcmp(name,(char *)(rpmsg_inst + 0x10));
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = strcmp(name,(char *)(rpmsg_inst + 0x2c));
    if (iVar2 != 0) {
      return (ipc_rpmsg_ept *)0x0;
    }
    iVar2 = 1;
  }
  return rpmsg_inst + iVar2 * 0x1c;
}


