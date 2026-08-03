/*
 * Function: zcbor_new_backup
 * Entry:    000893e8
 * Prototype: bool __stdcall zcbor_new_backup(zcbor_state_t * state, size_t new_elem_count)
 */


/* exclude_from_export */

bool zcbor_new_backup(zcbor_state_t *state,size_t new_elem_count)

{
  bool bVar1;
  size_t extraout_r1;
  zcbor_state_t *state_00;
  zcbor_state_t_union *pzVar2;
  zcbor_state_t *pzVar3;
  int *piVar4;
  uint8_t **ppuVar5;
  
  pzVar3 = *(zcbor_state_t **)((int)&state->constant_state + 2);
  bVar1 = zcbor_check_error(pzVar3);
  if (bVar1) {
    if (pzVar3->payload_bak < (uint8_t *)pzVar3->elem_count) {
      state_00->payload_moved = false;
      pzVar3->payload_bak = pzVar3->payload_bak + 1;
      piVar4 = *(int **)((int)&state_00->constant_state + 2);
      pzVar2 = (zcbor_state_t_union *)((piVar4[1] + -1) * 0x18 + *piVar4);
      pzVar3 = state_00;
      do {
        ppuVar5 = &pzVar3->payload_bak;
        *pzVar2 = pzVar3->field0_0x0;
        pzVar2 = pzVar2 + 1;
        pzVar3 = (zcbor_state_t *)ppuVar5;
      } while (ppuVar5 != (uint8_t **)((int)&state_00[1].field0_0x0 + 2));
      state_00->elem_count = extraout_r1;
      return true;
    }
    zcbor_error(state_00,1);
  }
  return false;
}


