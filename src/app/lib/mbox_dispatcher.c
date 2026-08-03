/*
 * Function: mbox_dispatcher
 * Entry:    00064f3c
 * Prototype: void __stdcall mbox_dispatcher(uint8_t event_idx, void * p_context)
 */


/* exclude_from_export_ai */

void mbox_dispatcher(uint8_t event_idx,void *p_context)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  uVar1 = (uint)event_idx;
  iVar2 = *(int *)((int)p_context + 0x80);
  if ((0xf < uVar1) || (-1 < (int)((**(uint **)(iVar2 + 4) >> uVar1) << 0x1f))) {
    local_14 = "RX event on illegal channel";
    local_18 = 2;
    desc.level = (dword)&local_18;
    desc.domain = 0x1080;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd8;
    z_impl_z_log_msg_static_create
              (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc,in_stack_ffffffdc,in_stack_ffffffe0);
  }
  if ((*(uint *)((int)p_context + 0x84) >> uVar1 & 1) == 0) {
    local_14 = "RX event on disabled channel";
    local_18 = 2;
    desc_00.level = (dword)&local_18;
    desc_00.domain = 0x1080;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffd8;
    z_impl_z_log_msg_static_create
              (&PTR_s_mbox_nrfx_ipc_0008b9a8,desc_00,in_stack_ffffffdc,in_stack_ffffffe0);
  }
  UNRECOVERED_JUMPTABLE = *(code **)((int)p_context + uVar1 * 4);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00064fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar2,uVar1,*(undefined4 *)((int)p_context + uVar1 * 4 + 0x40),0);
    return;
  }
  return;
}


