/*
 * Function: ?_deinit_ncs_memory
 * Entry:    000167d8
 * Prototype: undefined __stdcall ?_deinit_ncs_memory(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __deinit_ncs_memory(void)

{
  DAT_2007fc08 = 0;
  DAT_2007fc0c = 0;
  DAT_2007fc00 = 0;
  _DAT_2007fc04 = 0;
  DAT_2007fc5f = 0;
  _DAT_2007fc60 = 0;
  ERASE_DFU_ON_NEXT_PASS = 0;
  DAT_2007fc68 = 0;
  memset(&DAT_2007fc10,0,0x25);
  memset(&DAT_2007fc35,0,0x25);
  NCS_MEM_INIT_MAGIC = 0;
  return;
}


