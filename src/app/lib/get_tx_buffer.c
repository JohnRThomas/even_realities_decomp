/*
 * Function: get_tx_buffer
 * Entry:    000821fc
 * Prototype: int __stdcall get_tx_buffer(device * instance, void * token, void * * r_data, uint32_t * size, k_timeout_t wait)
 */


/* exclude_from_export_ai */

int get_tx_buffer(device *instance,void *token,void **r_data,uint32_t *size,k_timeout_t wait)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  if (token == (void *)0x0) {
    iVar1 = -2;
  }
  else if ((r_data == (void **)0x0) || (size == (uint32_t *)0x0)) {
    iVar1 = -0x16;
  }
  else {
    uVar3 = (uint)((ulonglong)(wait.ticks + 1) >> 0x20);
    if (uVar3 == 0 && (1 < (uint)(wait.ticks + 1)) <= uVar3) {
      if ((*size == 0) || (*size <= *(uint *)(instance->data + 0x3c0))) {
        do {
          pvVar2 = rpmsg_get_tx_payload_buffer(token,size,(uint)(wait.ticks == -1));
          if (pvVar2 != (void *)0x0) {
            *r_data = pvVar2;
            return 0;
          }
        } while (wait.ticks == -1);
        iVar1 = -0x69;
      }
      else {
        iVar1 = -0xc;
        *size = *(uint *)(instance->data + 0x3c0);
      }
    }
    else {
      iVar1 = -0x86;
    }
  }
  return iVar1;
}


