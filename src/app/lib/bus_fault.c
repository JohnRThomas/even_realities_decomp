/*
 * Function: bus_fault
 * Entry:    00053804
 * Prototype: int __stdcall bus_fault(z_arch_esf_t * esf, int from_hard_fault, bool * recoverable)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int bus_fault(z_arch_esf_t *esf,int from_hard_fault,bool *recoverable)

{
  int iVar1;
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
  
  local_1c = "***** BUS FAULT *****";
  local_20 = 2;
  PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,"***** BUS FAULT *****",
                in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8);
  if ((int)(_DAT_e000ed28 << 0x13) < 0) {
    local_20 = 2;
    local_1c = "  Stacking error";
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,"  Stacking error",
                  in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8);
    iVar1 = 0x17;
  }
  else {
    iVar1 = 0x16;
  }
  if ((int)(_DAT_e000ed28 << 0x14) < 0) {
    local_1c = "  Unstacking error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    iVar1 = 0x18;
  }
  if ((int)(_DAT_e000ed28 << 0x16) < 0) {
    local_1c = "  Precise data bus error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    if ((int)(_DAT_e000ed28 << 0x10) < 0) {
      local_3c = "  BFAR Address: 0x%x";
      uStack_38 = _DAT_e000ed38;
      local_40 = 3;
      PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1840,&local_40,3,in_stack_ffffffb0,
                    in_stack_ffffffb4,in_stack_ffffffb8);
      if (esf != (z_arch_esf_t *)0x0) {
        _DAT_e000ed28 = _DAT_e000ed28 & 0xffff7fff;
      }
    }
    iVar1 = 0x19;
  }
  if ((int)(_DAT_e000ed28 << 0x15) < 0) {
    local_1c = "  Imprecise data bus error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    iVar1 = 0x1a;
  }
  if ((int)(_DAT_e000ed28 << 0x17) < 0) {
    local_1c = "  Instruction bus error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    iVar1 = 0x1b;
  }
  else if ((int)(_DAT_e000ed28 << 0x12) < 0) {
    local_1c = "  Floating-point lazy state preservation error";
    local_20 = 2;
    PR_FAULT_INFO(&PTR_s_os_000be4b1_0x14_0008ba08,0x1040,&local_20,2,in_stack_ffffffd0,
                  in_stack_ffffffd4,in_stack_ffffffd8);
    iVar1 = 0x1c;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff00;
  *(undefined1 *)from_hard_fault = 0;
  return iVar1;
}


