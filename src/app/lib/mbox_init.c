/*
 * Function: mbox_init
 * Entry:    0004ffec
 * Prototype: int __stdcall mbox_init(void)
 */


/* exclude_from_export_ai */

int mbox_init(void)

{
  int in_r0;
  int iVar1;
  ulong align;
  ulong extraout_r1;
  atomic_val_t value;
  uint uVar2;
  int extraout_r2;
  int extraout_r2_00;
  uint uVar3;
  code *pcVar4;
  ipc_rpmsg_instance *instance;
  uint *puVar5;
  atomic_t *target;
  int iVar6;
  int iVar7;
  
  instance = *(ipc_rpmsg_instance **)(in_r0 + 0x10);
  puVar5 = *(uint **)(in_r0 + 4);
  target = instance + 0xef;
  if (*target != 0) {
    return -0x78;
  }
  *target = 1;
  uVar2 = 1;
  uVar3 = puVar5[2];
  align = puVar5[10];
  while (uVar2 = vring_size(uVar2,align), uVar2 < uVar3 - 4) {
    uVar2 = extraout_r2 + 1;
    align = extraout_r1;
  }
  if (extraout_r2 + -1 == 0) {
    iVar1 = -0xc;
  }
  else {
    uVar3 = 0x80000000 >> LZCOUNT(extraout_r2 + -1);
    instance[0x98] = puVar5[1] + 7 & 0xfffffffc;
    iVar1 = vring_size(uVar3,puVar5[10]);
    instance[0x99] = iVar1;
    iVar1 = extraout_r2_00 + (uVar3 * puVar5[10] + 3 & 0xfffffffc) * 2;
    instance[0x96] = iVar1;
    instance[0x95] = iVar1 + (uVar3 * 0x12 + 9 & 0xfffffffc) + uVar3 * 8 + 8;
    uVar2 = puVar5[1];
    instance[0x97] = uVar3;
    instance[0x94] = uVar2;
    instance[0xa9] = (ipc_rpmsg_instance)puVar5;
    instance[0xaa] = 0x822cf;
    iVar1 = ipc_static_vrings_init((ipc_static_vrings *)(instance + 0x72),*puVar5);
    if (iVar1 == 0) {
      iVar7 = *(int *)(in_r0 + 4);
      iVar6 = *(int *)(in_r0 + 0x10);
      iVar1 = *(int *)(iVar7 + 0x20);
      if (*(int *)(iVar7 + 0x1c) == 1) {
        iVar1 = iVar1 + -0x10;
      }
      k_work_queue_init((k_work_q *)(iVar6 + 0x2c0));
      k_work_queue_start((k_work_q *)(iVar6 + 0x2c0),
                         (k_thread_stack_t *)(*(int *)(iVar7 + 0x24) * 0x400 + 0x2002a7e0),0x400,
                         iVar1,(k_work_queue_config *)0x0);
      k_work_init((k_work *)(iVar6 + 0x2b0),BYTE_ARRAY_000822a8 + 0xd);
      pcVar4 = *(code **)(*(int *)(*(int *)(iVar7 + 0x14) + 8) + 4);
      if (pcVar4 == (code *)0x0) {
LAB_000500e4:
        iVar1 = -0x58;
      }
      else {
        iVar1 = (*pcVar4)(*(int *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),0x822a9,iVar6);
        if (iVar1 == 0) {
          pcVar4 = *(code **)(*(int *)(*(int *)(iVar7 + 0x14) + 8) + 0x10);
          if (pcVar4 == (code *)0x0) goto LAB_000500e4;
          iVar1 = (*pcVar4)(*(int *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),1);
          if (iVar1 == 0) {
            instance[0x6a] = 0x5019d;
            instance[0x6b] = 0x8245d;
            iVar1 = ipc_rpmsg_init(instance,instance[0xee],puVar5[10],
                                   (metal_io_region *)instance[0x9a],
                                   (virtio_device *)(instance + 0x72),(void *)instance[0x82],
                                   instance[0x84],(rpmsg_ns_bind_cb)0x82317);
            if (iVar1 == 0) {
              iVar6 = rpmsg_virtio_get_buffer_size((rpmsg_device *)(instance + 0x38));
              instance[0xf0] = iVar6;
              if (-1 < iVar6) {
                value = 2;
                goto LAB_00050160;
              }
              iVar1 = -0x16;
            }
          }
        }
      }
    }
  }
  value = 0;
LAB_00050160:
  atomic_set(target,value);
  return iVar1;
}


