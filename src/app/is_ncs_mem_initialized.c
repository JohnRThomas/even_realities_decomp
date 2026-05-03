/*
 * Function: is_ncs_mem_initialized
 * Entry:    00016654
 * Prototype: int __stdcall is_ncs_mem_initialized(void)
 */


int is_ncs_mem_initialized(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (NCS_MEM_INIT_MAGIC != 0x12345678) {
    iVar1 = -1;
  }
  return iVar1;
}


