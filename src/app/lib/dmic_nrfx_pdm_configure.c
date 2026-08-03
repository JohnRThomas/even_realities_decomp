/*
 * Function: dmic_nrfx_pdm_configure
 * Entry:    00062f28
 * Prototype: int __stdcall dmic_nrfx_pdm_configure(device * dev, dmic_cfg * config)
 */


/* exclude_from_export */

int dmic_nrfx_pdm_configure(device *dev,dmic_cfg *config)

{
  uint8_t uVar1;
  ulonglong uVar2;
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  log_msg_desc desc_02;
  nrfx_err_t nVar3;
  uint extraout_r0;
  uint uVar4;
  byte bVar5;
  undefined *puVar6;
  uint32_t uVar7;
  uint uVar8;
  pcm_stream_cfg *ppVar9;
  uint uVar10;
  uint uVar11;
  uint32_t uVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  dword in_stack_ffffff70;
  uint8_t *in_stack_ffffff74;
  void *in_stack_ffffff78;
  undefined4 local_80;
  char *local_7c;
  uint8_t *local_78;
  uint local_74;
  uint8_t *in_stack_ffffff90;
  uint8_t *in_stack_ffffff94;
  undefined1 *in_stack_ffffff98;
  uint local_64;
  undefined4 local_48;
  char *local_44;
  bool local_40;
  bool bStack_3f;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  undefined4 local_30;
  char *local_2c;
  
  puVar6 = dev->data;
  puVar14 = (undefined4 *)dev->config;
  ppVar9 = config->streams;
  if (puVar6[0x51] != '\0') {
    local_2c = "Cannot configure device while it is active";
    local_30 = 2;
    desc_02.level = (dword)&local_30;
    desc_02.domain = 0x1040;
    desc_02.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
    desc_02.data_len = (dword)in_stack_ffffff90;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc_02,in_stack_ffffff94,in_stack_ffffff98);
    return -0x10;
  }
  bVar5 = (config->channel).req_num_chan;
  uVar10 = (uint)bVar5;
  uVar1 = (config->channel).req_num_streams;
  if (uVar10 == 1) {
    (config->channel).act_chan_map_lo = 0;
    (config->channel).act_chan_map_hi = 0;
    (config->channel).act_num_chan = bVar5;
    (config->channel).act_num_streams = bVar5;
    uVar7 = 0;
    if (uVar1 != '\x01') goto LAB_00062f86;
LAB_00062fc0:
    uVar12 = (config->channel).req_chan_map_lo;
    if (((uVar12 != uVar7) && (uVar12 != 1)) || ((config->channel).req_chan_map_hi != 0))
    goto LAB_00062f86;
    if ((ppVar9->pcm_rate == 0) || (ppVar9->pcm_width == '\0')) {
      if (-1 < (int)((uint)(byte)puVar6[0x50] << 0x1e)) {
        return 0;
      }
      nrfx_pdm_uninit();
      bVar5 = puVar6[0x50] & 0xfd;
LAB_00062ff4:
      puVar6[0x50] = bVar5;
      return 0;
    }
    if (ppVar9->pcm_width == '\x10') {
      uStack_3c = puVar14[2];
      uStack_38 = puVar14[3];
      local_34 = puVar14[4];
      local_30 = puVar14[5];
      uStack_3e = (undefined2)((uint)puVar14[1] >> 0x10);
      _local_40 = CONCAT11(uVar12 != uVar7,uVar10 == 1);
      local_2c = (char *)CONCAT31((int3)((uint)puVar14[6] >> 8),*(char *)(puVar14 + 8) == '\x02');
      uVar10 = 32000000;
      if (*(char *)(puVar14 + 8) == '\x02') {
        uVar10 = 0xbb8000;
      }
      in_stack_ffffff90 = (uint8_t *)(config->io).min_pdm_clk_freq;
      uVar11 = 0xffffffff;
      pbVar13 = &DAT_000f3882;
      in_stack_ffffff98 = &DAT_00000001;
      do {
        bVar5 = *pbVar13;
        uVar8 = ppVar9->pcm_rate;
        uVar4 = bVar5 * uVar8;
        __aeabi_uldivmod(uVar4 * 0x100000,uVar4 >> 0xc,uVar10 + (uVar4 >> 1),0);
        uVar2 = (ulonglong)uVar10 / (0x100000 / (ulonglong)extraout_r0);
        local_78 = (uint8_t *)uVar2;
        if ((in_stack_ffffff90 <= local_78) &&
           (local_78 <= (uint8_t *)(config->io).max_pdm_clk_freq)) {
          uVar4 = (uint)(uVar2 / (uint)bVar5);
          if (uVar4 < uVar8) {
            uVar8 = uVar8 - uVar4;
            if (uVar8 < uVar11) {
              local_30 = CONCAT13(pbVar13[1],(undefined3)local_30);
              goto LAB_000630d8;
            }
            local_78 = in_stack_ffffff94;
            if (uVar11 == 0) goto LAB_00063102;
          }
          else {
            uVar8 = uVar4 - uVar8;
            if (uVar8 < uVar11) {
              local_34 = extraout_r0 << 0xc;
              local_30 = CONCAT13(pbVar13[1],(undefined3)local_30);
              local_64 = uVar4;
              if (uVar8 == 0) goto LAB_00063102;
LAB_000630d8:
              local_34 = extraout_r0 << 0xc;
              uVar11 = uVar8;
              in_stack_ffffff94 = local_78;
              local_64 = uVar4;
            }
          }
        }
        pbVar13 = pbVar13 + 2;
        if (in_stack_ffffff98 != &DAT_00000001) goto code_r0x000630e8;
        in_stack_ffffff98 = &DAT_00000002;
      } while( true );
    }
    local_2c = "Only 16-bit samples are supported";
  }
  else {
    (config->channel).act_num_chan = '\x02';
    (config->channel).act_chan_map_hi = 0;
    uVar7 = 0x10;
    (config->channel).act_num_streams = '\x01';
    (config->channel).act_chan_map_lo = 0x10;
    if ((uVar1 == '\x01') && (uVar10 - 1 < 2)) goto LAB_00062fc0;
LAB_00062f86:
    local_2c = "Requested configuration is not supported";
  }
  puVar14 = &local_30;
  local_30 = 2;
LAB_00062f92:
  desc_01.level = (dword)puVar14;
  desc_01.domain = 0x1040;
  desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
  desc_01.data_len = (dword)in_stack_ffffff90;
  z_vrfy_z_log_msg_static_create
            (&PTR_s_dmic_nrfx_pdm_0008b950,desc_01,in_stack_ffffff94,in_stack_ffffff98);
  return -0x16;
code_r0x000630e8:
  local_78 = in_stack_ffffff94;
  if (uVar11 != 0xffffffff) {
LAB_00063102:
    local_7c = "PDM clock frequency: %u, actual PCM rate: %u";
    local_74 = local_64;
    local_80 = 4;
    desc.level = (dword)&local_80;
    desc.domain = 0x20c0;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 4;
    desc.data_len = in_stack_ffffff70;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc,in_stack_ffffff74,in_stack_ffffff78);
    if ((int)((uint)(byte)puVar6[0x50] << 0x1e) < 0) {
      nrfx_pdm_uninit();
      puVar6[0x50] = puVar6[0x50] & 0xfd;
    }
    nVar3 = nrfx_pdm_init((nrfx_pdm_config_t *)&local_40,(nrfx_pdm_event_handler_t *)*puVar14);
    local_78 = (uint8_t *)(uint)nVar3;
    if (local_78 != &DAT_0bad0000) {
      local_7c = "Failed to initialize PDM: 0x%08x";
      local_80 = 3;
      desc_00.level = (dword)&local_80;
      desc_00.domain = 0x1840;
      desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 3;
      desc_00.data_len = in_stack_ffffff70;
      z_vrfy_z_log_msg_static_create
                (&PTR_s_dmic_nrfx_pdm_0008b950,desc_00,in_stack_ffffff74,in_stack_ffffff78);
      return -5;
    }
    *(uint *)(puVar6 + 0x18) = (uint)ppVar9->block_size;
    *(k_mem_slab **)(puVar6 + 0x14) = ppVar9->mem_slab;
    bVar5 = *(char *)(puVar14 + 8) != '\0' | 2U | puVar6[0x50] & 0xfc;
    goto LAB_00062ff4;
  }
  puVar14 = &local_48;
  local_44 = "Cannot find suitable PDM clock configuration.";
  local_48 = 2;
  goto LAB_00062f92;
}


