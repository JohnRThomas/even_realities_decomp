/*
 * Function: get_ident
 * Entry:    0005a640
 * Prototype: uint8_t __stdcall get_ident(void)
 */


/* exclude_from_export */

uint8_t get_ident(void)

{
  DAT_2001e2a5 = DAT_2001e2a5 + 1;
  if (DAT_2001e2a5 == 0) {
    DAT_2001e2a5 = 1;
  }
  return DAT_2001e2a5;
}


