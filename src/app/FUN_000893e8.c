/*
 * Function: FUN_000893e8
 * Entry:    000893e8
 * Prototype: undefined1 __stdcall FUN_000893e8(int param_1)
 */


undefined1 FUN_000893e8(int param_1)

{
  bool bVar1;
  zcbor_state_t extraout_r1;
  zcbor_state_t *state;
  zcbor_state_t *pzVar2;
  zcbor_state_t *pzVar3;
  zcbor_state_t *pzVar4;
  
  pzVar2 = *(zcbor_state_t **)(param_1 + 0x14);
  bVar1 = zcbor_check_error(pzVar2);
  if (bVar1) {
    if (pzVar2[1] < pzVar2[2]) {
      *(undefined1 *)((int)state + 0x11) = 0;
      pzVar2[1] = pzVar2[1] + 1;
      pzVar2 = (zcbor_state_t *)((((int *)state[5])[1] + -1) * 0x18 + *(int *)state[5]);
      pzVar3 = state;
      do {
        pzVar4 = pzVar3 + 1;
        *pzVar2 = *pzVar3;
        pzVar2 = pzVar2 + 1;
        pzVar3 = pzVar4;
      } while (pzVar4 != state + 6);
      state[2] = extraout_r1;
      return 1;
    }
    zcbor_update_state(state,(uint8_t *)0x1,(size_t)state);
  }
  return 0;
}


