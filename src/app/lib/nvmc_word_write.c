/*
 * Function: nvmc_word_write
 * Entry:    000691ac
 * Prototype: void __stdcall nvmc_word_write(uint32_t addr, uint32_t value)
 */


/* exclude_from_export */

void nvmc_word_write(uint32_t addr,uint32_t value)

{
  int iVar1;
  
  do {
    iVar1 = Peripherals::KMU_S._1024_4_;
  } while (-1 < iVar1 << 0x1f);
  *(uint32_t *)addr = value;
  DataMemoryBarrier(0x1f);
  return;
}


