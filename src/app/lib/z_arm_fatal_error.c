/*
 * Function: z_arm_fatal_error
 * Entry:    00053218
 * Prototype: void __stdcall z_arm_fatal_error(uint reason, z_arch_esf_t * esf)
 */


/* exclude_from_export */

void z_arm_fatal_error(uint reason,z_arch_esf_t *esf)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  log_msg_desc desc_02;
  log_msg_desc desc_03;
  log_msg_desc desc_04;
  dword dVar1;
  dword dVar2;
  z_arch_esf_t *pzVar3;
  uint8_t *package;
  void *data;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  dword dVar4;
  uint8_t *in_stack_ffffffbc;
  undefined1 *data_00;
  z_arch_esf_t local_38;
  char *local_34;
  z_arch_esf_t local_30;
  z_arch_esf_t zStack_2c;
  
  if (esf != (z_arch_esf_t *)0x0) {
    local_38 = *esf;
    local_34 = (char *)esf[1];
    local_30 = esf[2];
    desc.level = (dword)&stack0xffffffc0;
    desc.domain = 0x2840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffb0;
    z_impl_z_log_msg_static_create
              (&PTR_s_os_000be4b1_0x14_0008ba08,desc,in_stack_ffffffb4,in_stack_ffffffb8);
    local_38 = esf[3];
    local_34 = (char *)esf[4];
    local_30 = esf[5];
    data_00 = &DAT_00000005;
    desc_00.level = (dword)&stack0xffffffc0;
    desc_00.domain = 0x2840;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffb0;
    z_impl_z_log_msg_static_create
              (&PTR_s_os_000be4b1_0x14_0008ba08,desc_00,in_stack_ffffffb4,in_stack_ffffffb8);
    local_30 = esf[7];
    local_34 = " xpsr:  0x%08x";
    local_38 = 3;
    desc_01.level = (dword)&local_38;
    desc_01.domain = 0x1840;
    desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_01.data_len = (dword)in_stack_ffffffb8;
    z_impl_z_log_msg_static_create
              (&PTR_s_os_000be4b1_0x14_0008ba08,desc_01,in_stack_ffffffbc,data_00);
    dVar1 = 0;
    pzVar3 = esf;
    do {
      package = (uint8_t *)pzVar3[8];
      local_34 = (char *)pzVar3[10];
      zStack_2c = pzVar3[0xb];
      data = (void *)(dVar1 + 1);
      local_38 = dVar1 + 2;
      local_30 = dVar1 + 3;
      dVar2 = dVar1 + 4;
      desc_02.level = (dword)&stack0xffffffb0;
      desc_02.domain = 0x5040;
      desc_02.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_02.data_len = in_stack_ffffffa0;
      dVar4 = dVar1;
      z_impl_z_log_msg_static_create
                (&PTR_s_os_000be4b1_0x14_0008ba08,desc_02,in_stack_ffffffa4,in_stack_ffffffa8);
      pzVar3 = pzVar3 + 4;
      dVar1 = dVar2;
    } while (dVar2 != 0x10);
    local_30 = esf[0x18];
    local_34 = "fpscr:  0x%08x";
    local_38 = 3;
    desc_03.level = (dword)&local_38;
    desc_03.domain = 0x1840;
    desc_03.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_03.data_len = dVar4;
    z_impl_z_log_msg_static_create(&PTR_s_os_000be4b1_0x14_0008ba08,desc_03,package,data);
    local_30 = esf[6];
    local_34 = "Faulting instruction address (r15/pc): 0x%08x";
    local_38 = 3;
    desc_04.level = (dword)&local_38;
    desc_04.domain = 0x1840;
    desc_04.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_04.data_len = dVar4;
    z_impl_z_log_msg_static_create(&PTR_s_os_000be4b1_0x14_0008ba08,desc_04,package,data);
  }
  z_fatal_error(reason,esf);
  return;
}


