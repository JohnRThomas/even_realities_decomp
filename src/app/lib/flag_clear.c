/*
 * Function: flag_clear
 * Entry:    00089d04
 * Prototype: void __stdcall flag_clear(uint32_t * flagp, uint32_t bit)
 */


/* exclude_from_export */

void flag_clear(uint32_t *flagp,uint32_t bit)

{
  *flagp = *flagp & ~(1 << (bit & 0xff));
  return;
}


