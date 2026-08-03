/*
 * Function: nrfx_gpiote_is_init
 * Entry:    00068c60
 * Prototype: bool __stdcall nrfx_gpiote_is_init(void)
 */


/* exclude_from_export_ai */

bool nrfx_gpiote_is_init(void)

{
  return DAT_20002c58 != '\0';
}


