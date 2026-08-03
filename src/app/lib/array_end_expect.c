/*
 * Function: array_end_expect
 * Entry:    00089582
 * Prototype: bool __stdcall array_end_expect(zcbor_state_t * state)
 */


/* exclude_from_export */

bool array_end_expect(zcbor_state_t *state)

{
  int iVar1;
  int *in_r1;
  
  iVar1 = zcbor_assert_state((int *)state,in_r1);
  if (iVar1 != 0) {
    if (*(state->field0_0x0).payload_mut == 0xff) {
      (state->field0_0x0).payload_mut = (state->field0_0x0).payload_mut + 1;
      goto LAB_0008959e;
    }
    zcbor_error((int)state,10);
  }
  iVar1 = 0;
LAB_0008959e:
  return SUB41(iVar1,0);
}


