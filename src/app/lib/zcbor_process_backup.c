/*
 * Function: zcbor_process_backup
 * Entry:    00089436
 * Prototype: bool __stdcall zcbor_process_backup(zcbor_state_t * state, uint32_t flags, size_t max_elem_count)
 */


/* exclude_from_export */

bool zcbor_process_backup(zcbor_state_t *state,uint32_t flags,size_t max_elem_count)

{
  bool bVar1;
  int extraout_r1;
  int iVar2;
  uint extraout_r2;
  zcbor_state_t_union *pzVar3;
  zcbor_state_t_union *pzVar4;
  zcbor_state_t_union *pzVar5;
  zcbor_state_t *pzVar6;
  zcbor_state_t_union zVar7;
  uint uVar8;
  
  pzVar6 = *(zcbor_state_t **)((int)&state->constant_state + 2);
  bVar1 = zcbor_check_error(pzVar6);
  if (bVar1) {
    zVar7 = state->field0_0x0;
    uVar8 = state->elem_count;
    if (pzVar6->payload_bak == (uint8_t *)0x0) {
      iVar2 = 2;
    }
    else {
      pzVar3 = (zcbor_state_t_union *)(extraout_r1 << 0x1f);
      if ((int)pzVar3 < 0) {
        pzVar4 = (zcbor_state_t_union *)
                 ((pzVar6->field0_0x0).payload_mut + (int)(pzVar6->payload_bak + -1) * 0x18);
        if ((-1 < extraout_r1 << 0x1d) && (*(char *)((int)pzVar4 + 0x11) != '\0')) {
          return false;
        }
        pzVar5 = pzVar4;
        pzVar6 = state;
        do {
          pzVar3 = pzVar5 + 1;
          pzVar6->field0_0x0 = *pzVar5;
          pzVar5 = pzVar3;
          pzVar6 = (zcbor_state_t *)&pzVar6->payload_bak;
        } while (pzVar3 != pzVar4 + 6);
      }
      iVar2 = extraout_r1 << 0x1e;
      bVar1 = iVar2 < 0;
      if (bVar1) {
        iVar2 = *(int *)((int)&state->constant_state + 2);
        pzVar3 = (zcbor_state_t_union *)(*(int *)(iVar2 + 4) + -1);
      }
      if (bVar1) {
        *(zcbor_state_t_union **)(iVar2 + 4) = pzVar3;
      }
      if (uVar8 <= extraout_r2) {
        if (extraout_r1 << 0x1d < 0) {
          state->field0_0x0 = zVar7;
        }
        return true;
      }
      iVar2 = 4;
    }
    zcbor_error(state,iVar2);
  }
  return false;
}


