/*
 * Function: set_ncs_mem_initialized
 * Entry:    00016644
 * Prototype: undefined __stdcall set_ncs_mem_initialized(void)
 */


void set_ncs_mem_initialized(void)

{
  NCS_MEM_INIT_MAGIC = 0x12345678;
  return;
}


