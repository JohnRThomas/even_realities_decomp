/*
 * Function: zcbor_any_skip
 * Entry:    00089814
 * Prototype: bool __stdcall zcbor_any_skip(zcbor_state_t * state, void * unused)
 */


/* exclude_from_export */

bool zcbor_any_skip(zcbor_state_t *state,void *unused)

{
  byte bVar1;
  zcbor_state_t_union *pzVar2;
  bool bVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  zcbor_state_t_union zVar7;
  zcbor_state_t *pzVar8;
  int iVar9;
  zcbor_state_t *decoder;
  uint uVar10;
  zcbor_state_t_union *pzVar11;
  zcbor_state_t *in_stack_ffffffc0;
  void *in_stack_ffffffc4;
  uint result_len;
  zcbor_state_t_union local_30 [2];
  size_t local_28;
  size_t *local_24;
  undefined1 local_20;
  
  if (unused == (void *)0x0) {
    iVar6 = zcbor_assert_state((int *)state,(int *)0x0);
    if (iVar6 != 0) {
      result_len = 0;
      bVar1 = *(state->field0_0x0).payload_mut;
      pzVar11 = local_30;
      pzVar8 = state;
      do {
        pzVar2 = &pzVar8->field0_0x0;
        zVar7 = (zcbor_state_t_union)pzVar8->payload_bak;
        pzVar8 = (zcbor_state_t *)&pzVar8->elem_count;
        *pzVar11 = *pzVar2;
        pzVar11[1] = zVar7;
        pzVar11 = pzVar11 + 2;
      } while (pzVar8 != (zcbor_state_t *)((int)&state[1].field0_0x0 + 2));
      while( true ) {
        uVar10 = (uint)(bVar1 >> 5);
        decoder = (zcbor_state_t *)(bVar1 & 0x1f);
        if (uVar10 != 6) break;
        cVar4 = zcbor_int32_decode((int *)local_30,(size_t)&stack0xffffffc4,pzVar8,decoder);
        if (cVar4 == '\0') goto LAB_0008982c;
        if (local_24 <= local_30[0].payload_mut) goto LAB_000898be;
        bVar1 = *local_30[0].payload_mut;
        pzVar8 = (zcbor_state_t *)local_24;
      }
      if (decoder == (zcbor_state_t *)0x1f) {
        if (uVar10 - 4 < 2) {
          iVar9 = iVar6;
          if (uVar10 != 4) {
            bVar3 = true;
LAB_000898f6:
            local_20 = (undefined1)iVar9;
            if (0x7fffffff < result_len) {
              iVar6 = 5;
              goto LAB_0008981e;
            }
            local_28 = result_len * 2;
            if (!bVar3) goto LAB_0008991a;
          }
          local_20 = (undefined1)iVar9;
          bVar3 = true;
          local_30[0].payload_mut = local_30[0].payload_mut + 1;
          local_28 = 0xffffffef;
LAB_0008991a:
          do {
            bVar5 = zcbor_payload_at_end((zcbor_state_t *)local_30);
            if (bVar5) {
              if ((!bVar3) || (bVar3 = array_end_expect((zcbor_state_t *)local_30), bVar3))
              goto LAB_0008989e;
              break;
            }
            bVar5 = zcbor_any_skip((zcbor_state_t *)local_30,(void *)0x0);
          } while (bVar5);
        }
        else {
          bVar3 = value_extract((size_t)local_30,(size_t)&stack0xffffffc8,(size_t *)&NMI,uVar10 - 4,
                                in_stack_ffffffc0,in_stack_ffffffc4,result_len);
          if (bVar3) {
            if (uVar10 < 5) {
LAB_00089882:
              if (uVar10 - 2 < 2) {
                uVar10 = (int)local_24 - (int)local_30[0];
                if (-1 < (int)uVar10 && (uint)(result_len <= uVar10) <= (uint)((int)uVar10 >> 0x1f))
                {
LAB_000898be:
                  iVar6 = 8;
                  goto LAB_0008981e;
                }
                local_30[0].payload_mut = local_30[0].payload_mut + result_len;
              }
            }
LAB_0008989e:
            (state->field0_0x0).payload_mut = (uint8_t *)local_30[0];
            state->elem_count = state->elem_count - 1;
            goto LAB_0008982e;
          }
        }
      }
      else {
        bVar3 = value_extract((size_t)local_30,(size_t)&stack0xffffffc8,(size_t *)&NMI,
                              (zcbor_decoder_t)decoder,in_stack_ffffffc0,in_stack_ffffffc4,
                              result_len);
        if (bVar3) {
          if (uVar10 != 4) {
            if (uVar10 < 5) goto LAB_00089882;
            if (uVar10 != 5) goto LAB_0008989e;
            iVar9 = 0;
            bVar3 = false;
            goto LAB_000898f6;
          }
          bVar3 = false;
          local_20 = 0;
          local_28 = result_len;
          goto LAB_0008991a;
        }
      }
    }
  }
  else {
    iVar6 = 0xe;
LAB_0008981e:
    zcbor_error((int)state,iVar6);
  }
LAB_0008982c:
  iVar6 = 0;
LAB_0008982e:
  return SUB41(iVar6,0);
}


