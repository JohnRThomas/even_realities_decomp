/*
 * Function: dmic_pdm_event_handler
 * Entry:    00063250
 * Prototype: undefined __stdcall dmic_pdm_event_handler(char * param_1)
 */


/* exclude_from_export */

void dmic_pdm_event_handler(char *param_1)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  nrfx_err_t nVar1;
  undefined1 *puVar2;
  int iVar3;
  void *mem;
  char cVar4;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  undefined1 *puStack_38;
  int16_t *in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  cVar4 = *param_1;
  if (cVar4 == '\0') {
    mem = *(void **)(param_1 + 4);
    if (DAT_2000ba3a == '\0') {
LAB_0006326a:
      if (mem == (void *)0x0) {
        return;
      }
      cVar4 = '\0';
      goto LAB_0006335c;
    }
    if (mem == (void *)0x0) {
LAB_000632de:
      if (DAT_2000ba39 == '\0') {
        return;
      }
      DAT_2000ba39 = 0;
      if (-1 < (int)((uint)DAT_2000ba38 << 0x1f)) {
        DAT_2000ba39 = 0;
        return;
      }
      onoff_release(DAT_2000b9e8);
      return;
    }
LAB_00063332:
    k_mem_slab_free(DAT_2000b9fc,mem);
    if ((DAT_2000ba39 != '\0') && (DAT_2000ba39 = '\0', (int)((uint)DAT_2000ba38 << 0x1f) < 0)) {
      onoff_release(DAT_2000b9e8);
    }
  }
  else {
    puVar2 = (undefined1 *)k_mem_slab_alloc(DAT_2000b9fc,(void **)&stack0xffffffd0,(k_timeout_t)0x0)
    ;
    if ((int)puVar2 < 0) {
      local_3c = "Failed to allocate buffer: %d";
    }
    else {
      nVar1 = nrfx_pdm_buffer_set(in_stack_ffffffd0,(uint16_t)((uint)(DAT_2000ba00 << 0xf) >> 0x10))
      ;
      puVar2 = (undefined1 *)(uint)nVar1;
      if (puVar2 == &DAT_0bad0000) {
        mem = *(void **)(param_1 + 4);
        if (DAT_2000ba3a != '\0') {
          if (mem == (void *)0x0) goto LAB_000632de;
          cVar4 = '\0';
          goto LAB_00063332;
        }
        goto LAB_0006326a;
      }
      local_3c = "Failed to set buffer: 0x%08x";
    }
    local_40 = 3;
    desc.level = (dword)&local_40;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 3;
    desc.data_len = in_stack_ffffffb0;
    puStack_38 = puVar2;
    z_vrfy_z_log_msg_static_create
              (&PTR_s_dmic_nrfx_pdm_0008b950,desc,in_stack_ffffffb4,in_stack_ffffffb8);
    mem = *(void **)(param_1 + 4);
    if (DAT_2000ba3a != '\0') {
      cVar4 = DAT_2000ba3a;
      if (mem == (void *)0x0) {
        if ((DAT_2000ba39 != '\0') && (DAT_2000ba39 = '\0', (int)((uint)DAT_2000ba38 << 0x1f) < 0))
        {
          onoff_release(DAT_2000b9e8);
        }
        goto LAB_000632b4;
      }
      goto LAB_00063332;
    }
    if (mem == (void *)0x0) goto LAB_000632b4;
LAB_0006335c:
    iVar3 = z_impl_k_msgq_put((k_msgq *)&DAT_2000ba04,param_1 + 4,(k_timeout_t)0x0);
    if (iVar3 < 0) {
      local_1c = "No room in RX queue";
      local_20 = 2;
      desc_00.level = (dword)&local_20;
      desc_00.domain = 0x1040;
      desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 2;
      desc_00.data_len = (dword)in_stack_ffffffd0;
      z_vrfy_z_log_msg_static_create
                (&PTR_s_dmic_nrfx_pdm_0008b950,desc_00,in_stack_ffffffd4,in_stack_ffffffd8);
      k_mem_slab_free(DAT_2000b9fc,*(void **)(param_1 + 4));
      goto LAB_000632b4;
    }
  }
  if (cVar4 == '\0') {
    return;
  }
LAB_000632b4:
  DAT_2000ba3a = 1;
  nrfx_pdm_stop();
  return;
}


