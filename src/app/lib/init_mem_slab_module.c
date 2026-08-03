/*
 * Function: init_mem_slab_module
 * Entry:    00074e78
 * Prototype: int __stdcall init_mem_slab_module(void)
 */


/* exclude_from_export */

int init_mem_slab_module(void)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  k_mem_slab *slab;
  
  iVar1 = 0;
  slab = (k_mem_slab *)&DAT_200038d8;
  while( true ) {
    if ((k_mem_slab *)&DAT_20003978 < slab) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","slab <= _k_mem_slab_list_end",
              "WEST_TOPDIR/zephyr/kernel/mem_slab.c",61);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if (((undefined *)0x20003977 < slab) || (iVar1 = create_free_list(slab), iVar1 < 0)) break;
    slab = (k_mem_slab *)&slab->max_used;
  }
  return iVar1;
}


