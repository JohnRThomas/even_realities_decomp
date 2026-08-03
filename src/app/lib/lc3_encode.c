/*
 * Function: lc3_encode
 * Entry:    0006c4e0
 * Prototype: int __stdcall lc3_encode(lc3_encoder_t encoder, lc3_pcm_format fmt, void * pcm, int stride, int nbytes, void * out)
 */


/* exclude_from_export_ai */

int lc3_encode(lc3_encoder_t encoder,lc3_pcm_format fmt,void *pcm,int stride,int nbytes,void *out)

{
  byte bVar1;
  lc3_srate sr;
  bool att;
  bool nn_flag;
  lc3_bandwidth lVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  lc3_srate lVar6;
  float *x;
  int iVar7;
  int iVar8;
  int aiStack_1e0 [6];
  undefined1 auStack_1c8 [4];
  int local_1c4;
  int local_1c0;
  int local_1bc;
  undefined1 *local_1b8;
  lc3_srate local_1b4;
  byte local_1ac;
  bool local_1ab;
  lc3_ltpf_data_t alStack_1a8 [2];
  lc3_sns_data_t alStack_1a0 [7];
  lc3_tns_data_t alStack_184 [20];
  uint auStack_134 [3];
  float afStack_128 [7];
  uint local_10c;
  uint local_108;
  
  if (encoder != 0) {
    if (nbytes - 0x14U < 0x17d) {
      iVar3 = (uint)*(byte *)(encoder + 1) * (*(byte *)encoder + 3) + *(byte *)encoder + 3;
      piVar4 = aiStack_1e0 + iVar3 * -10;
      (*(code *)(&PTR_load_s16_1_0008f818)[fmt])(encoder,pcm,stride);
      lVar6 = (lc3_srate)*(byte *)(encoder + 1);
      iVar7 = *(int *)(encoder + 0x4a0);
      iVar8 = lVar6 + LC3_SRATE_16K;
      if (lVar6 == LC3_SRATE_48K) {
        iVar8 = 6;
      }
      uVar5 = (uint)*(byte *)encoder;
      bVar1 = *(byte *)(encoder + 2);
      *piVar4 = iVar7;
      local_1b4 = (uint)bVar1;
      local_1bc = *(int *)(encoder + 0x4a8);
      x = *(float **)(encoder + 0x4a4);
      att = lc3_attdet_run(uVar5,(uint)bVar1,nbytes,(lc3_attdet_analysis_t *)(encoder + 4),
                           (int16_t *)*piVar4);
      *piVar4 = (int)alStack_1a8;
      local_1c0 = iVar8 * 5;
      local_1b8 = auStack_1c8 + iVar3 * -0x28;
      local_1c4 = iVar8 * 10;
      local_1ab = analyze(uVar5,local_1b4,(char *)(encoder + 0x10),iVar7,(char *)*piVar4);
      iVar8 = local_1b4 + LC3_SRATE_16K;
      if (local_1b4 == LC3_SRATE_48K) {
        iVar8 = 6;
      }
      memmove((void *)(iVar7 + local_1c0 * -4),
              (void *)(iVar7 + ((uVar5 + 3) * iVar8 * 0x14 - local_1c4) * 2),local_1c0 << 2);
      *piVar4 = local_1bc;
      sr = local_1b4;
      aiStack_1e0[iVar3 * -10 + 1] = (int)x;
      lc3_mdct_forward(uVar5,sr,lVar6,x,(float *)*piVar4,(float *)aiStack_1e0[iVar3 * -10 + 1]);
      nn_flag = lc3_energy_compute(uVar5,lVar6,x,afStack_128);
      if (nn_flag) {
        lc3_ltpf_disable(alStack_1a8);
      }
      lVar2 = lc3_bwdet_run(uVar5,lVar6,afStack_128);
      aiStack_1e0[iVar3 * -10 + 1] = (int)x;
      aiStack_1e0[iVar3 * -10 + 2] = (int)x;
      local_1ac = (byte)lVar2;
      *piVar4 = (int)alStack_1a0;
      lc3_sns_analyze(uVar5,lVar6,afStack_128,att,(lc3_sns_data_t *)*piVar4,
                      (float *)aiStack_1e0[iVar3 * -10 + 1],(float *)aiStack_1e0[iVar3 * -10 + 2]);
      *piVar4 = (int)alStack_184;
      aiStack_1e0[iVar3 * -10 + 1] = (int)x;
      lc3_tns_analyze(uVar5,(uint)local_1ac,nn_flag,nbytes,(lc3_tns_data_t *)*piVar4,
                      (float *)aiStack_1e0[iVar3 * -10 + 1]);
      aiStack_1e0[iVar3 * -10 + 2] = (int)x;
      aiStack_1e0[iVar3 * -10 + 3] = (int)local_1b8;
      *piVar4 = (int)alStack_184;
      aiStack_1e0[iVar3 * -10 + 4] = (int)auStack_134;
      aiStack_1e0[iVar3 * -10 + 1] = encoder + 0x498;
      lc3_spec_analyze(uVar5,lVar6,nbytes,local_1ab,(lc3_tns_data_t *)*piVar4,
                       (lc3_spec_analysis_t *)aiStack_1e0[iVar3 * -10 + 1],
                       (float *)aiStack_1e0[iVar3 * -10 + 2],
                       (uint16_t *)aiStack_1e0[iVar3 * -10 + 3],
                       (lc3_spec_side_t *)aiStack_1e0[iVar3 * -10 + 4]);
      lVar6 = (lc3_srate)*(byte *)(encoder + 1);
      uVar5 = (uint)local_1ac;
      bVar1 = *(byte *)encoder;
      iVar7 = *(int *)(encoder + 0x4a4);
      lc3_setup_bits((lc3_bits_t *)afStack_128,1,out,nbytes);
      lc3_bwdet_put_bw((lc3_bits_t *)afStack_128,lVar6,uVar5);
      spec_put_side((lc3_bits_t *)afStack_128,(uint)bVar1,lVar6,auStack_134);
      lc3_tns_put_data((lc3_bits_t *)afStack_128,alStack_184);
      if ((int)(local_108 + 1) < 0x21) {
        local_10c = local_10c | (uint)local_1ab << (local_108 & 0xff);
        local_108 = local_108 + 1;
      }
      else {
        lc3_put_bits_generic((lc3_bits_t *)afStack_128,(uint)local_1ab,1);
      }
      lc3_sns_put_data((lc3_bits_t *)afStack_128,alStack_1a0);
      if (local_1ab != false) {
        lc3_ltpf_put_data((lc3_bits_t *)afStack_128,alStack_1a8);
      }
      aiStack_1e0[iVar3 * -10 + 2] = (int)auStack_134;
      aiStack_1e0[iVar3 * -10 + 3] = iVar7;
      aiStack_1e0[iVar3 * -10 + 1] = (int)local_1b8;
      *piVar4 = nbytes;
      lc3_spec_encode((lc3_bits_t *)afStack_128,(uint)bVar1,lVar6,uVar5,*piVar4,
                      (uint16_t *)aiStack_1e0[iVar3 * -10 + 1],
                      (lc3_spec_side_t *)aiStack_1e0[iVar3 * -10 + 2],
                      (float *)aiStack_1e0[iVar3 * -10 + 3]);
      lc3_flush_bits((lc3_bits_t *)afStack_128);
      iVar3 = 0;
    }
    else {
      iVar3 = -1;
    }
    return iVar3;
  }
  return -1;
}


