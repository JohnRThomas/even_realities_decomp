/*
 * Function: dmic_nrfx_pdm_read
 * Entry:    00062d40
 * Prototype: int __stdcall dmic_nrfx_pdm_read(int param_1, undefined4 param_2, void * param_3, undefined4 * param_4, uint param_5)
 */


/* exclude_from_export */

int dmic_nrfx_pdm_read(int param_1,undefined4 param_2,void *param_3,undefined4 *param_4,uint param_5
                      )

{
  longlong lVar1;
  log_msg_desc desc;
  log_msg_desc desc_00;
  undefined4 extraout_r0;
  undefined4 extraout_r1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  k_timeout_t timeout;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if ((int)((uint)*(byte *)(iVar5 + 0x50) << 0x1e) < 0) {
    if (param_5 == 0xffffffff) {
      uVar2 = 0xffffffff;
      uVar3 = 0xffffffff;
    }
    else {
      lVar1 = (longlong)(int)(param_5 & ~((int)param_5 >> 0x1f)) * 0x8000 + 999;
      __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000,0);
      uVar2 = extraout_r0;
      uVar3 = extraout_r1;
    }
    timeout.ticks._4_4_ = uVar3;
    timeout.ticks._0_4_ = uVar2;
    iVar4 = z_impl_k_msgq_get((k_msgq *)(iVar5 + 0x1c),param_3,timeout);
    if (iVar4 == 0) {
      *param_4 = *(undefined4 *)(iVar5 + 0x18);
    }
    else {
      local_1c = "No audio data to be read";
      local_20 = 2;
      desc.level = (dword)&local_20;
      desc.domain = 0x1040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
      desc.data_len = in_stack_ffffffd0;
      z_vrfy_z_log_msg_static_create
                (&PTR_s_dmic_nrfx_pdm_0008b950,desc,in_stack_ffffffd4,in_stack_ffffffd8);
    }
  }
  else {
    iVar4 = -5;
    local_1c = "Device is not configured";
    local_20 = 2;
    desc_00.level = (dword)&local_20;
    desc_00.domain = 0x1040;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
    desc_00.data_len = in_stack_ffffffd0;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc_00,in_stack_ffffffd4,in_stack_ffffffd8);
  }
  return iVar4;
}


