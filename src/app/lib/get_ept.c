/*
 * Function: get_ept
 * Entry:    0004ffc4
 * Prototype: bool __stdcall get_ept(ipc_rpmsg_instance * rpmsg_inst, ipc_rpmsg_ept * * rpmsg_ept, char * name)
 */


/* exclude_from_export */

bool get_ept(ipc_rpmsg_instance *rpmsg_inst,ipc_rpmsg_ept **rpmsg_ept,char *name)

{
  bool bVar1;
  ipc_rpmsg_ept *piVar2;
  
  piVar2 = get_ept_slot_with_name(rpmsg_inst,name);
  bVar1 = piVar2 != (ipc_rpmsg_ept *)0x0;
  if (!bVar1) {
    piVar2 = get_ept_slot_with_name(rpmsg_inst,"");
  }
  *rpmsg_ept = piVar2;
  return bVar1;
}


