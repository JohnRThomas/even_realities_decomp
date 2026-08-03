/*
 * Function: advertise_ept
 * Entry:    0004ff80
 * Prototype: void __stdcall advertise_ept(ipc_rpmsg_instance * rpmsg_inst, ipc_rpmsg_ept * rpmsg_ept, char * name, uint32_t dest)
 */


/* exclude_from_export */

void advertise_ept(ipc_rpmsg_instance *rpmsg_inst,ipc_rpmsg_ept *rpmsg_ept,char *name,uint32_t dest)

{
  int iVar1;
  
  iVar1 = rpmsg_create_ept((rpmsg_endpoint *)rpmsg_ept,(rpmsg_device *)(rpmsg_inst + 0x38),name,
                           0xffffffff,dest,(rpmsg_ept_cb)rpmsg_inst[0x6b],&LAB_00082278_1);
  if (iVar1 == 0) {
    *(undefined1 *)(rpmsg_ept + 0x19) = 1;
    if ((code *)rpmsg_inst[0x6a] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0004ffb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)rpmsg_inst[0x6a])(rpmsg_ept);
      return;
    }
  }
  return;
}


