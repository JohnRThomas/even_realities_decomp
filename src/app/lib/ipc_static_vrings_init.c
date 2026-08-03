/*
 * Function: ipc_static_vrings_init
 * Entry:    00050410
 * Prototype: int __stdcall ipc_static_vrings_init(ipc_static_vrings * vr, uint role)
 */


/* exclude_from_export_ai */

int ipc_static_vrings_init(ipc_static_vrings *vr,uint role)

{
  undefined2 uVar1;
  int iVar2;
  virtqueue *pvVar3;
  undefined *puVar4;
  uint uVar5;
  dword *pdVar6;
  undefined *puVar7;
  metal_device *local_24;
  metal_init_params local_20;
  
  if (vr == (ipc_static_vrings *)0x0) {
    iVar2 = -0x16;
  }
  else {
    vr[1].shm_physmap = 1;
    puVar4 = (undefined *)vr[2].rvrings_VRING_COUNT_;
    vr->notify_cb = "sram0.shm";
    vr->priv = puVar4;
    vring_init((vring *)&vr[1].shm_device,(uint)puVar4,(uint8_t *)&vr->priv,
               (ulong)vr[2].vq_VRING_COUNT_);
    local_20.log_handler = 0x6b55d;
    local_20.log_level = 6;
    iVar2 = metal_init(&local_20);
    if (((iVar2 == 0) &&
        (iVar2 = metal_register_generic_device((metal_device *)&vr->notify_cb), iVar2 == 0)) &&
       (iVar2 = metal_device_open("generic","sram0.shm",&local_24), iVar2 == 0)) {
      if (local_24->num_regions == 0) {
        pdVar6 = (dword *)0x0;
      }
      else {
        pdVar6 = &local_24->regions_METAL_MAX_DEVICE_REGIONS_;
      }
      vr[2].priv = (undefined *)pdVar6;
      pvVar3 = virtqueue_allocate((uint)vr[2].shm_io);
      vr[3].vq_VRING_COUNT_ = (undefined *)pvVar3;
      if (pvVar3 != (virtqueue *)0x0) {
        pvVar3 = virtqueue_allocate((uint)vr[2].shm_io);
        vr[3].priv = (undefined *)pvVar3;
        if (pvVar3 != (virtqueue *)0x0) {
          puVar4 = vr[2].priv;
          vr[3].vdev = (dword)vr[2].shm_addr;
          vr[3].shm_physmap = 4;
          vr[3].shm_addr = &Reset;
          vr->rvrings_VRING_COUNT_ = 2;
          uVar1 = *(undefined2 *)&vr[2].shm_io;
          puVar7 = vr[3].vq_VRING_COUNT_;
          vr[3].tx_addr = puVar4;
          vr[3].rvrings_VRING_COUNT_ = (dword)puVar4;
          uVar5 = vr[2].shm_size;
          vr->shm_size = (uint)&PTR_0008e804;
          *(undefined2 *)&vr[3].shm_device = uVar1;
          vr[2].notify_cb = puVar7;
          vr[3].vring_size = uVar5;
          *(undefined2 *)&vr[3].shm_size = uVar1;
          vr[3].rx_addr = (undefined *)pvVar3;
          vr->vring_size = role;
          vr->vq_VRING_COUNT_ = (undefined *)&vr[2].notify_cb;
          return 0;
        }
      }
      iVar2 = -0xc;
    }
  }
  return iVar2;
}


