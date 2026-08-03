/*
 * Function: usage_fault
 * Entry:    00053958
 * Prototype: uint32_t __stdcall usage_fault(z_arch_esf_t * esf)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

uint32_t usage_fault(z_arch_esf_t *esf)

{
  uint32_t uVar1;
  dword in_stack_ffffffe0;
  uint8_t *in_stack_ffffffe4;
  void *in_stack_ffffffe8;
  undefined4 local_10;
  char *local_c;
  
  local_c = "***** USAGE FAULT *****";
  local_10 = 2;
  PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,"***** USAGE FAULT *****",
                in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8);
  if ((int)(_DAT_e000ed28 << 6) < 0) {
    local_10 = 2;
    local_c = "  Division by zero";
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,"  Division by zero",
                  in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x1e;
  }
  else {
    uVar1 = 0x1d;
  }
  if ((int)(_DAT_e000ed28 << 7) < 0) {
    local_c = "  Unaligned memory access";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,2,in_stack_ffffffe0,
                  in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x1f;
  }
  if ((int)(_DAT_e000ed28 << 0xb) < 0) {
    local_c = "  Stack overflow (context area not valid)";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,
                  "  Stack overflow (context area not valid)",in_stack_ffffffe0,in_stack_ffffffe4,
                  in_stack_ffffffe8);
    uVar1 = 2;
  }
  if ((int)(_DAT_e000ed28 << 0xc) < 0) {
    local_c = "  No coprocessor instructions";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,2,in_stack_ffffffe0,
                  in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x21;
  }
  if ((int)(_DAT_e000ed28 << 0xd) < 0) {
    local_c = "  Illegal load of EXC_RETURN into PC";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,2,in_stack_ffffffe0,
                  in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x22;
  }
  if ((int)(_DAT_e000ed28 << 0xe) < 0) {
    local_c = "  Illegal use of the EPSR";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,2,in_stack_ffffffe0,
                  in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x23;
  }
  if ((int)(_DAT_e000ed28 << 0xf) < 0) {
    local_c = "  Attempt to execute undefined instruction";
    local_10 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_10,2,in_stack_ffffffe0,
                  in_stack_ffffffe4,in_stack_ffffffe8);
    uVar1 = 0x24;
  }
  _DAT_e000ed28 = ~(~(_DAT_e000ed28 << 0x10) >> 0x10);
  return uVar1;
}


