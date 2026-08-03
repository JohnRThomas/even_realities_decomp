/*
 * Function: qspi_get_zephyr_ret_code
 * Entry:    00063c34
 * Prototype: int __stdcall qspi_get_zephyr_ret_code(nrfx_err_t res)
 */


/* exclude_from_export */

int qspi_get_zephyr_ret_code(nrfx_err_t res)

{
  int iVar1;
  
  if (res + 0xf4530000 < 0xb) {
    iVar1 = (int)*(short *)(&DAT_0009cdd4 + (res + 0xf4530000) * 2);
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}


