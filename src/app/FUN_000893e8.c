/*
 * Function: FUN_000893e8
 * Entry:    000893e8
 * Prototype: undefined1 __stdcall FUN_000893e8(int param_1)
 */


undefined1 FUN_000893e8(int param_1)

{
  bool bVar1;
  size_t extraout_r1;
  zcbor_state_t *state;
  zcbor_state_t_union *pzVar2;
  zcbor_state_t *pzVar3;
  int *piVar4;
  uint8_t **ppuVar5;
  
  pzVar3 = *(zcbor_state_t **)(param_1 + 0x14);
  bVar1 = zcbor_check_error(pzVar3);
  if (bVar1) {
    if (pzVar3->payload_bak < (uint8_t *)pzVar3->elem_count) {
      state->payload_moved = false;
      pzVar3->payload_bak = pzVar3->payload_bak + 1;
      piVar4 = *(int **)((int)&state->constant_state + 2);
      pzVar2 = (zcbor_state_t_union *)((piVar4[1] + -1) * 0x18 + *piVar4);
      pzVar3 = state;
      do {
        ppuVar5 = &pzVar3->payload_bak;
        *pzVar2 = pzVar3->field0_0x0;
        pzVar2 = pzVar2 + 1;
        pzVar3 = (zcbor_state_t *)ppuVar5;
      } while (ppuVar5 != (uint8_t **)((int)&state[1].field0_0x0 + 2));
      state->elem_count = extraout_r1;
      return 1;
    }
    zcbor_update_state(state,&DAT_00000001,(size_t)state);
  }
  return 0;
}


