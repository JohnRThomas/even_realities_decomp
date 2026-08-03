/*
 * Function: zcbor_assert_state
 * Entry:    00089532
 * Prototype: int __stdcall zcbor_assert_state(int * state, int * input)
 */


/* exclude_from_export */

int zcbor_assert_state(int *state,int *input)

{
  bool bVar1;
  uint *extraout_r2;
  
  bVar1 = zcbor_check_error((zcbor_state_t *)state[5],(int)input);
  if (bVar1 != 0) {
    if (*extraout_r2 < extraout_r2[3]) {
      return (uint)bVar1;
    }
    zcbor_error((int)extraout_r2,8);
  }
  return 0;
}


