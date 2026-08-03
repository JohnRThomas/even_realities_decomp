/*
 * Function: compute_scale_factors
 * Entry:    0006f01c
 * Prototype: void __stdcall compute_scale_factors(lc3_dt dt, lc3_srate sr, float * eb, bool att, float * scf)
 */


/* exclude_from_export_ai */

void compute_scale_factors(lc3_dt dt,lc3_srate sr,float *eb,bool att,float *scf)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  float *pfVar3;
  float fVar4;
  undefined *puVar5;
  float fVar6;
  float *in_stack_00000004;
  
  fVar4 = *(float *)((&DAT_00093f7c)[(uint)att * 2] + (int)scf * 4);
  ppuVar2 = (undefined **)&DAT_000909dc;
  pfVar3 = in_stack_00000004;
  do {
    *pfVar3 = 0.0;
    puVar5 = *ppuVar2;
    fVar6 = *eb;
    *pfVar3 = fVar6 * (float)puVar5;
    fVar6 = fVar6 * (float)puVar5 + eb[1] * (float)ppuVar2[1];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[2] * (float)ppuVar2[2];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[3] * (float)ppuVar2[3];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[4] * (float)ppuVar2[4];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[5] * (float)ppuVar2[5];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[6] * (float)ppuVar2[6];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[7] * (float)ppuVar2[7];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[8] * (float)ppuVar2[8];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[9] * (float)ppuVar2[9];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[10] * (float)ppuVar2[10];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[0xb] * (float)ppuVar2[0xb];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[0xc] * (float)ppuVar2[0xc];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[0xd] * (float)ppuVar2[0xd];
    *pfVar3 = fVar6;
    fVar6 = fVar6 + eb[0xe] * (float)ppuVar2[0xe];
    *pfVar3 = fVar6;
    ppuVar1 = ppuVar2 + 0xf;
    ppuVar2 = ppuVar2 + 0x10;
    *pfVar3 = fVar6 + eb[0xf] * (float)*ppuVar1;
    pfVar3 = pfVar3 + 1;
  } while (ppuVar2 != &PTR_DAT_00090ddc);
  *in_stack_00000004 = (float)(&DAT_000943e0)[dt * 8] + fVar4 * *in_stack_00000004;
  in_stack_00000004[1] = (float)(&DAT_000943e4)[dt * 8] + fVar4 * in_stack_00000004[1];
  in_stack_00000004[2] = (float)(&DAT_000943e8)[dt * 8] + fVar4 * in_stack_00000004[2];
  in_stack_00000004[3] = (float)(&DAT_000943ec)[dt * 8] + fVar4 * in_stack_00000004[3];
  in_stack_00000004[4] = (float)(&DAT_000943f0)[dt * 8] + fVar4 * in_stack_00000004[4];
  in_stack_00000004[5] = (float)(&DAT_000943f4)[dt * 8] + fVar4 * in_stack_00000004[5];
  in_stack_00000004[6] = (float)(&DAT_000943f8)[dt * 8] + fVar4 * in_stack_00000004[6];
  in_stack_00000004[7] = (float)(&DAT_000943fc)[dt * 8] + in_stack_00000004[7] * fVar4;
  in_stack_00000004[8] = (float)(&DAT_00093fe0)[sr * 8] + fVar4 * in_stack_00000004[8];
  in_stack_00000004[9] = (float)(&DAT_00093fe4)[sr * 8] + in_stack_00000004[9] * fVar4;
  in_stack_00000004[10] = (float)(&DAT_00093fe8)[sr * 8] + fVar4 * in_stack_00000004[10];
  in_stack_00000004[0xb] = (float)(&DAT_00093fec)[sr * 8] + fVar4 * in_stack_00000004[0xb];
  in_stack_00000004[0xc] = (float)(&DAT_00093ff0)[sr * 8] + fVar4 * in_stack_00000004[0xc];
  in_stack_00000004[0xd] = (float)(&DAT_00093ff4)[sr * 8] + fVar4 * in_stack_00000004[0xd];
  in_stack_00000004[0xe] = (float)(&DAT_00093ff8)[sr * 8] + fVar4 * in_stack_00000004[0xe];
  in_stack_00000004[0xf] = (float)(&DAT_00093ffc)[sr * 8] + in_stack_00000004[0xf] * fVar4;
  return;
}


