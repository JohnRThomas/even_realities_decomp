/*
 * Function: _copy
 * Entry:    00083662
 * Prototype: uint __stdcall _copy(uint8_t * to, uint to_len, uint8_t * from, uint from_len)
 */


/* exclude_from_export_ai */

uint _copy(uint8_t *to,uint to_len,uint8_t *from,uint from_len)

{
  if (to_len < from_len) {
    from_len = 0;
  }
  else {
    memcpy(to,from,from_len);
  }
  return from_len;
}


