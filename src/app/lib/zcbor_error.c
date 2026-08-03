/*
 * Function: zcbor_error
 * Entry:    00089972
 * Prototype: void __stdcall zcbor_error(zcbor_state_t * state, int err)
 */


/* exclude_from_export_ai */

void zcbor_error(zcbor_state_t *state,int err)

{
  bool bVar1;
  undefined4 extraout_r1;
  int extraout_r2;
  
  bVar1 = zcbor_check_error(*(zcbor_state_t **)((int)&state->constant_state + 2));
  if ((bVar1) && (extraout_r2 != 0)) {
    *(undefined4 *)(extraout_r2 + 0xc) = extraout_r1;
  }
  return;
}


