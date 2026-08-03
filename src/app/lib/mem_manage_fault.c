/*
 * Function: mem_manage_fault
 * Entry:    00053684
 * Prototype: uint32_t __stdcall mem_manage_fault(z_arch_esf_t * esf, int from_hard_fault, bool * recoverable)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

uint32_t mem_manage_fault(z_arch_esf_t *esf,int from_hard_fault,bool *recoverable)

{
  uint32_t uVar1;
  char *test;
  char *file;
  int line;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  undefined4 uStack_38;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  local_1c = "***** MPU FAULT *****";
  local_20 = 2;
  PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,"***** MPU FAULT *****",
                in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8);
  if ((int)(_DAT_e000ed28 << 0x1b) < 0) {
    local_20 = 2;
    local_1c = "  Stacking error (context area might be not valid)";
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,
                  "  Stacking error (context area might be not valid)",in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    uVar1 = 0x11;
  }
  else {
    uVar1 = 0x10;
  }
  if ((int)(_DAT_e000ed28 << 0x1c) < 0) {
    local_1c = "  Unstacking error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    uVar1 = 0x12;
  }
  if ((int)(_DAT_e000ed28 << 0x1e) < 0) {
    local_1c = "  Data Access Violation";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    if ((int)(_DAT_e000ed28 << 0x18) < 0) {
      local_3c = "  MMFAR Address: 0x%x";
      uStack_38 = _DAT_e000ed34;
      local_40 = 3;
      PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1840,&local_40,3,in_stack_ffffffb0,
                    in_stack_ffffffb4,in_stack_ffffffb8);
      if (esf != (z_arch_esf_t *)0x0) {
        _DAT_e000ed28 = _DAT_e000ed28 & 0xffffff7f;
      }
    }
    uVar1 = 0x13;
  }
  if ((int)(_DAT_e000ed28 << 0x1f) < 0) {
    local_1c = "  Instruction Access Violation";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    uVar1 = 0x14;
  }
  if ((int)(_DAT_e000ed28 << 0x1a) < 0) {
    local_1c = "  Floating-point lazy state preservation error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    uVar1 = 0x15;
  }
  if ((((int)(_DAT_e000ed28 << 0x1b) < 0) || ((int)(_DAT_e000ed28 << 0x1e) < 0)) &&
     ((int)(_DAT_e000ed28 << 0x1b) < 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "!(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CFSR & (1UL << (0U + 4U)))",
            "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/cortex_m/fault.c",355);
    _ASSERT("\tStacking or Data Access Violation error without stack guard, user-mode or null-pointer detection\n\n"
            ,test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((int)(_DAT_e000ed28 << 0x1a) < 0) {
    _DAT_e000ed24 = _DAT_e000ed24 & 0xffffdfff;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff;
  *(undefined1 *)from_hard_fault = 0;
  return uVar1;
}


