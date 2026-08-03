/*
 * Function: lc3_ltpf_disable
 * Entry:    0006e60c
 * Prototype: void __stdcall lc3_ltpf_disable(lc3_ltpf_data_t * data)
 */


/* exclude_from_export_ai */

void lc3_ltpf_disable(lc3_ltpf_data_t *data)

{
  data->opaque[0] = 0;
  return;
}


