/*
 * Function: z_impl_z_log_msg_static_create
 * Entry:    00050be4
 * Prototype: void __stdcall z_impl_z_log_msg_static_create(void * source, log_msg_desc desc, uint8_t * package, void * data)
 */


/* exclude_from_export */

void z_impl_z_log_msg_static_create(void *source,log_msg_desc desc,uint8_t *package,void *data)

{
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  uint uVar1;
  log_msg *msg;
  int iVar2;
  uint in_len;
  uint uVar3;
  dword in_stack_ffffff78;
  uint8_t *in_stack_ffffff7c;
  void *in_stack_ffffff80;
  undefined1 *local_68;
  char *local_64;
  undefined4 in_stack_ffffffa0;
  uint16_t *in_stack_ffffffa4;
  undefined1 *in_stack_ffffffa8;
  uint16_t auStack_3c [4];
  byte *local_34;
  uint local_30;
  undefined4 local_2c;
  
  in_len = (desc.domain & 0xfffff) >> 9;
  if (in_len == 0) {
    msg = z_log_msg_alloc(((desc.domain >> 0x14) + 0x17 & 0xfffffff8) >> 2);
    uVar3 = 0;
  }
  else {
    in_stack_ffffffa4 = auStack_3c;
    local_34 = (byte *)0x0;
    local_30 = 0;
    local_2c = 0;
    in_stack_ffffffa8 = &Reset;
    in_stack_ffffffa0 = 10;
    uVar1 = cbprintf_package_convert
                      ((void *)desc.level,in_len,(cbprintf_convert_cb)0x0,&local_34,10,
                       in_stack_ffffffa4,4);
    if (0x7ff < uVar1) {
      local_64 = "Message (\"%s\") dropped because it exceeds size limitation (%u)";
      local_68 = &DAT_01000004;
      desc_01.level = (dword)&local_68;
      desc_01.domain = 0x2480;
      desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_01.data_len = in_stack_ffffff78;
      z_impl_z_log_msg_static_create
                (&PTR_s_log_0008b990,desc_01,in_stack_ffffff7c,in_stack_ffffff80);
      return;
    }
    uVar3 = uVar1 & 0x7ff;
    msg = z_log_msg_alloc(((desc.domain >> 0x14) + 0x17 + uVar1 & 0xfffffff8) >> 2);
    desc.domain = desc.domain & 0xfff001ff;
    if (msg != (log_msg *)0x0) {
      local_34 = &msg[2].padding_Z_LOG_MSG_PADDING_;
      local_2c = 0;
      in_stack_ffffffa4 = auStack_3c;
      in_stack_ffffffa0 = 10;
      in_stack_ffffffa8 = &Reset;
      local_30 = uVar1;
      iVar2 = cbprintf_package_convert
                        ((void *)desc.level,in_len,(cbprintf_convert_cb)0x825e1,&local_34,10,
                         in_stack_ffffffa4,4);
      if (iVar2 < 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","len >= 0",
                "WEST_TOPDIR/zephyr/subsys/logging/log_msg.c",89);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
    }
  }
  desc_00.data_len = (dword)in_stack_ffffffa4;
  desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = in_stack_ffffffa0;
  desc_00.level = desc.package_len_Z_LOG_MSG_PACKAGE_BITS;
  desc_00.domain = desc.domain & 0xfff001ff | uVar3 << 9;
  z_log_msg_finalize(msg,source,desc_00,in_stack_ffffffa8);
  return;
}


