/*
 * Function: err_restore
 * Entry:    00089574
 * Prototype: undefined __stdcall err_restore(zcbor_state_t * param_1, int param_2)
 */


/* exclude_from_export */

void err_restore(zcbor_state_t *param_1,int param_2)

{
  param_1->field0_0x0 = (zcbor_state_t_union)param_1->payload_bak;
  param_1->elem_count = param_1->elem_count + 1;
  zcbor_error((int)param_1,param_2);
  return;
}


