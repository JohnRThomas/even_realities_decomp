/*
 * Function: nrf_flash_init
 * Entry:    000644dc
 * Prototype: undefined4 __stdcall nrf_flash_init(void)
 */


/* exclude_from_export */

undefined4 nrf_flash_init(void)

{
  z_impl_k_sem_init((k_sem *)&DAT_2000bb3c,1,1);
  dev_layout.pages_count = flash_page_count_get();
  dev_layout.pages_size = flash_page_size_get();
  return 0;
}


