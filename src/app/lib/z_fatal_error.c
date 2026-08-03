/*
 * Function: z_fatal_error
 * Entry:    0007492c
 * Prototype: void __stdcall z_fatal_error(uint reason, z_arch_esf_t * esf)
 */


/* exclude_from_export */

void z_fatal_error(uint reason,z_arch_esf_t *esf)

{
  uint uVar1;
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  bool bVar2;
  k_thread *thread;
  char *test;
  char *file;
  int line;
  undefined4 uVar3;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined1 *local_50;
  char *local_4c;
  k_thread *pkStack_48;
  char *local_44;
  undefined4 local_40;
  undefined2 local_3c;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
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
  thread = (k_thread *)k_current_get();
  if (reason < 5) {
    local_44 = (&PTR_s_CPU_exception_0009c1e8)[reason];
  }
  else {
    local_44 = "Unknown error";
  }
  local_3c = 0x301;
  local_4c = ">>> ZEPHYR FATAL ERROR %d: %s on CPU %d";
  local_40 = 0;
  local_50 = &DAT_01000005;
  desc.level = (dword)&local_50;
  desc.domain = 0x2c40;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffa0;
  pkStack_48 = (k_thread *)reason;
  z_impl_z_log_msg_static_create
            (&PTR_s_os_000be4b1_0x14_0008ba08,desc,in_stack_ffffffa4,in_stack_ffffffa8);
  if ((esf != (z_arch_esf_t *)0x0) && ((esf[7] & 0x1ff) != 0)) {
    local_24 = "Fault during interrupt handling\n";
    local_28 = 2;
    desc_00.level = (dword)&local_28;
    desc_00.domain = 0x1040;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffc8;
    z_impl_z_log_msg_static_create
              (&PTR_s_os_000be4b1_0x14_0008ba08,desc_00,in_stack_ffffffcc,in_stack_ffffffd0);
  }
  if (thread != (k_thread *)0x0) {
    bVar2 = arch_is_in_nested_exception((z_arch_esf_t *)thread);
    local_44 = (char *)(uint)bVar2;
    if ((local_44 != (char *)0x0) && (*local_44 != '\0')) goto LAB_000749be;
  }
  local_44 = "unknown";
LAB_000749be:
  local_4c = "Current thread: %p (%s)";
  local_40 = CONCAT22(local_40._2_2_,0x301);
  local_50 = &DAT_01000004;
  desc_01.level = (dword)&local_50;
  desc_01.domain = 0x2440;
  desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc_01.data_len = in_stack_ffffffa0;
  pkStack_48 = thread;
  z_impl_z_log_msg_static_create
            (&PTR_s_os_000be4b1_0x14_0008ba08,desc_01,in_stack_ffffffa4,in_stack_ffffffa8);
  k_sys_fatal_error_handler(reason,esf);
  if (reason != 4) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
                    /* WARNING: Subroutine does not return */
    z_thread_abort(thread);
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","reason != K_ERR_KERNEL_PANIC",
          "WEST_TOPDIR/zephyr/kernel/fatal.c",147);
  _ASSERT("\tAttempted to recover from a kernel panic condition\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


