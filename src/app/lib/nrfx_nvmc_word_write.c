/*
 * Function: nrfx_nvmc_word_write
 * Entry:    00069228
 * Prototype: void __stdcall nrfx_nvmc_word_write(uint32_t address, uint32_t value)
 */


/* exclude_from_export */

void nrfx_nvmc_word_write(uint32_t address,uint32_t value)

{
  if ((address < 0x100000) || (address - 0xff8000 < 0x1000)) {
    if ((address & 3) == 0) {
      DAT_50039584 = 1;
      DAT_50039504 = 1;
      nvmc_word_write(address,value);
      nvmc_readonly_mode_set();
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","nrfx_is_word_aligned((void const *)addr)",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_nvmc.c",406);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","is_valid_address(addr, 1)",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_nvmc.c",405);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


