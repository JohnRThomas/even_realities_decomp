/*
 * Function: zcbor_bool_decode
 * Entry:    000897b6
 * Prototype: bool __stdcall zcbor_bool_decode(zcbor_state_t * state, bool * result)
 */


/* exclude_from_export */

bool zcbor_bool_decode(zcbor_state_t *state,bool *result)

{
  bool bVar1;
  char local_11;
  
  bVar1 = zcbor_simple_decode(state,0xef);
  if (bVar1) {
    local_11 = (char)((uint)result >> 0x18);
    if ((byte)(local_11 - 0x14U) < 2) {
      *result = (bool)(local_11 - 0x14U & 1);
      return true;
    }
    err_restore(state,10);
  }
  return false;
}


