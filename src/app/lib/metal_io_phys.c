/*
 * Function: metal_io_phys
 * Entry:    00088d96
 * Prototype: metal_phys_addr_t __stdcall metal_io_phys(metal_io_region * io, ulong offset)
 */


/* exclude_from_export */

metal_phys_addr_t metal_io_phys(metal_io_region *io,ulong offset)

{
  metal_phys_addr_t mVar1;
  uint uVar2;
  
  if ((code *)io[1].mem_flags == (code *)0x0) {
    uVar2 = 0;
    if (io->page_shift < 0x20) {
      uVar2 = offset >> (io->page_shift & 0xff);
    }
    if ((io->physmap == (undefined *)0x0) || (io->size <= offset)) {
      mVar1 = 0xffffffff;
    }
    else {
      mVar1 = ((uint)io->page_mask & offset) + *(int *)(io->physmap + uVar2 * 4);
    }
    return mVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x00088dca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  mVar1 = (*(code *)io[1].mem_flags)();
  return mVar1;
}


