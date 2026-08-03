/*
 * Function: nrfx_nvmc_page_erase
 * Entry:    000691c4
 * Prototype: nrfx_err_t __stdcall nrfx_nvmc_page_erase(uint32_t address)
 */


/* exclude_from_export */

nrfx_err_t nrfx_nvmc_page_erase(uint32_t address)

{
  int iVar1;
  nrfx_err_t nVar2;
  
  if (address < 0x100000) {
    if ((address & 0xfff) == 0) {
      DAT_50039584 = 2;
      DAT_50039504 = 2;
      *(undefined4 *)address = 0xffffffff;
      do {
        iVar1 = Peripherals::KMU_S._1024_4_;
      } while (-1 < iVar1 << 0x1f);
      nvmc_readonly_mode_set();
      nVar2 = NRFX_SUCCESS;
    }
    else {
      nVar2 = NRFX_ERROR_INVALID_ADDR;
    }
    return nVar2;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","is_valid_address(addr, 0)",
          "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_nvmc.c",263);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


