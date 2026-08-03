/*
 * Function: net_buf_alloc_len
 * Entry:    00062160
 * Prototype: net_buf * __stdcall net_buf_alloc_len(net_buf_pool * pool, size_t size, k_timeout_t timeout)
 */


/* exclude_from_export */

net_buf * net_buf_alloc_len(net_buf_pool *pool,size_t size,k_timeout_t timeout)

{
  ushort uVar1;
  uint uVar2;
  net_buf_pool *pnVar3;
  uint uVar4;
  size_t sVar5;
  bool bVar6;
  net_buf *data;
  uint8_t *puVar7;
  uint extraout_r1;
  int extraout_r1_00;
  int iVar8;
  int extraout_r1_01;
  undefined4 extraout_r1_02;
  int extraout_r1_03;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  int line_00;
  int line_01;
  k_spinlock *l;
  undefined4 uVar9;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  k_timeout_t timeout_02;
  net_buf_pool *local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  size_t local_24;
  
  timeout_02.ticks._4_4_ = (undefined4)timeout.ticks;
  _uStack_28 = CONCAT44(size,timeout_02.ticks._4_4_);
  timeout_00.ticks._4_4_ = size;
  timeout_00.ticks._0_4_ = &local_30;
  local_30 = pool;
  uStack_2c = size;
  sys_timepoint_calc(timeout_00);
  uVar4 = uStack_2c;
  pnVar3 = local_30;
  if (pool == (net_buf_pool *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","pool","WEST_TOPDIR/zephyr/subsys/net/buf.c",248);
    goto LAB_000621be;
  }
  l = (k_spinlock *)((int)&pool->alloc + 1);
  uVar9 = 0;
  bVar6 = (bool)isCurrentModePrivileged();
  if (bVar6) {
    uVar9 = getBasePriority();
  }
  bVar6 = (bool)isCurrentModePrivileged();
  if ((bVar6) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar6 = z_spin_lock_valid(l);
  if (!bVar6) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
    goto LAB_000621be;
  }
  z_spin_lock_set_owner(l);
  uVar1 = *(ushort *)((int)&pool->__bufs + 3);
  if (uVar1 == 0) {
    bVar6 = z_spin_unlock_valid(l);
    if (!bVar6) goto LAB_000621ec;
    bVar6 = (bool)isCurrentModePrivileged();
    if (bVar6) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    timeout_02.ticks._0_4_ = extraout_r1_02;
    data = k_fifo_get((k_fifo *)pool,timeout_02);
    iVar8 = extraout_r1_03;
    if (data == (net_buf *)0x0) {
      return (net_buf *)0x0;
    }
  }
  else if ((uVar1 < *(ushort *)((int)&pool->__bufs + 1)) &&
          (timeout_01.ticks._4_4_ = 0, timeout_01.ticks._0_4_ = extraout_r1,
          data = k_fifo_get((k_fifo *)pool,timeout_01), data != (net_buf *)0x0)) {
    bVar6 = z_spin_unlock_valid(l);
    if (!bVar6) {
LAB_000621ec:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
      goto LAB_000621be;
    }
    bVar6 = (bool)isCurrentModePrivileged();
    if (bVar6) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar8 = extraout_r1_00;
  }
  else {
    uVar1 = *(ushort *)((int)&pool->__bufs + 3);
    *(ushort *)((int)&pool->__bufs + 3) = uVar1 - 1;
    bVar6 = z_spin_unlock_valid(l);
    if (!bVar6) goto LAB_000621ec;
    bVar6 = (bool)isCurrentModePrivileged();
    if (bVar6) {
      setBasePriority(uVar9);
    }
    InstructionSynchronizationBarrier(0xf);
    data = (net_buf *)
           (((uint)*(ushort *)((int)&pool->__bufs + 1) - (uint)uVar1) *
            (*(byte *)((int)&pool[1].free + 1) + 0x1b & 0xfffffffc) + pool[1].avail_count);
    data->pool_id = (char)((int)((int)&pool[-0xea1059].avail_count + 2) >> 2) * -0x3b;
    data->user_data_size = *(uint8_t *)((int)&pool[1].free + 1);
    iVar8 = extraout_r1_01;
  }
  sVar5 = local_24;
  if (local_24 == 0) {
    (data->field6_0xc).field0.__buf = (uint8_t *)0x0;
  }
  else {
    sys_timepoint_timeout((int *)&local_30,iVar8,(uint)pnVar3,uVar4);
    puVar7 = (uint8_t *)
             (**(code **)**(undefined4 **)(&DAT_20003c48 + (uint)data->pool_id * 0x34))
                       (data,&local_24,local_30,uStack_2c);
    (data->field6_0xc).field0.__buf = puVar7;
    if (puVar7 == (uint8_t *)0x0) {
      k_queue_prepend((k_queue *)(&DAT_20003c1c + (uint)data->pool_id * 0x34),data);
      return (net_buf *)0x0;
    }
    if (local_24 < sVar5) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","req_size <= size",
              "WEST_TOPDIR/zephyr/subsys/net/buf.c",0x14f);
      _ASSERT("\t\n",test,file_01,line_01);
LAB_000621be:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  data->frags = (net_buf *)0x0;
  data->ref = '\x01';
  data->flags = '\0';
  (data->field6_0xc).field0.len = 0;
  (data->field6_0xc).field0.size = (uint16_t)((ulonglong)_uStack_28 >> 0x20);
  (data->field6_0xc).field0.data = (data->field6_0xc).field0.__buf;
  return data;
}


