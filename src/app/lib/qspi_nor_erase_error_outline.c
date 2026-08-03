/*
 * Function: qspi_nor_erase_error_outline
 * Entry:    00063c68
 * Prototype: undefined4 __stdcall qspi_nor_erase_error_outline(undefined4 param_1, undefined4 param_2)
 */


/* exclude_from_export */

undefined4 qspi_nor_erase_error_outline(undefined4 param_1,undefined4 param_2)

{
  char local_18 [4];
  char *local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  local_14 = "erase error: address or size exceeds expected values.Addr: 0x%lx size %zu";
  local_18[0] = '\x04';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  uStack_10 = param_1;
  local_c = param_2;
  LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2040,local_18);
  return 0xffffffea;
}


