/*
 * Function: work_queue_main
 * Entry:    00075d58
 * Prototype: void __stdcall work_queue_main(void * workq_ptr, void * p2, void * p3)
 */


/* exclude_from_export */

void work_queue_main(void *workq_ptr,void *p2,void *p3)

{
  bool bVar1;
  int extraout_r0;
  int iVar2;
  undefined4 *puVar3;
  char *file;
  char *file_00;
  undefined4 uVar4;
  undefined4 *puVar5;
  int line;
  uint8_t *extraout_r3;
  undefined4 uVar6;
  int line_00;
  uint8_t *additional_input;
  uint8_t *extraout_r3_00;
  uint uVar7;
  undefined4 *puVar8;
  k_spinlock_key_t key;
  undefined4 *puVar9;
  code *pcVar10;
  undefined4 *puVar11;
  uint in_stack_ffffffc8;
  
LAB_00075d64:
  do {
    key = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      key = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (!bVar1) {
LAB_00075d7c:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file,line)
      ;
      goto LAB_00075d94;
    }
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
    puVar8 = *(undefined4 **)((int)workq_ptr + 0xd8);
    if (puVar8 == (undefined4 *)0x0) {
      flag_clear((uint32_t *)((int)workq_ptr + 0xf0),2);
      if (extraout_r0 != 0) {
        additional_input = extraout_r3;
        do {
          iVar2 = tc_hmac_prng_reseed((TCHmacPrng_t)((int)workq_ptr + 0xe8),&DAT_00000001,0,
                                      additional_input,in_stack_ffffffc8);
          additional_input = extraout_r3_00;
        } while (iVar2 != 0);
      }
      in_stack_ffffffc8 = 0xffffffff;
      z_sched_wait((k_spinlock *)((int)&_current.userspace_local_data + 2),key,
                   (_wait_q_t *)((int)workq_ptr + 0xe0),(k_timeout_t)0xffffffffffffffff,
                   (void **)0xffffffff);
      goto LAB_00075d64;
    }
    uVar6 = *puVar8;
    if (puVar8 == *(undefined4 **)((int)workq_ptr + 0xdc)) {
      *(undefined4 *)((int)workq_ptr + 0xdc) = uVar6;
    }
    *(undefined4 *)((int)workq_ptr + 0xd8) = uVar6;
    *(uint *)((int)workq_ptr + 0xf0) = *(uint *)((int)workq_ptr + 0xf0) | 2;
    pcVar10 = (code *)puVar8[1];
    puVar8[3] = puVar8[3] & 0xfffffffb | 1;
    bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (!bVar1) {
LAB_00075e04:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file_00,
              line_00);
LAB_00075d94:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(key);
    }
    InstructionSynchronizationBarrier(0xf);
    if (pcVar10 == (code *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","handler != ((void *)0)",
              "WEST_TOPDIR/zephyr/kernel/work.c",667);
      goto LAB_00075d94;
    }
    (*pcVar10)(puVar8);
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (!bVar1) goto LAB_00075d7c;
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
    puVar3 = (undefined4 *)_current._40_4_;
    uVar7 = puVar8[3];
    if ((int)(uVar7 << 0x1e) < 0) {
      puVar8[3] = uVar7 & 0xfffffffc;
      if (puVar3 != (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
        puVar11 = (undefined4 *)*puVar3;
        while (puVar3 != (undefined4 *)0x0) {
          puVar5 = puVar3;
          if (puVar8 == (undefined4 *)puVar3[1]) {
            uVar4 = *puVar3;
            if (puVar9 == (undefined4 *)0x0) {
              _current._40_4_ = uVar4;
              if ((undefined4 *)_current._44_4_ == puVar3) {
                _current._44_4_ = uVar4;
              }
            }
            else {
              *puVar9 = uVar4;
              if ((undefined4 *)_current._44_4_ == puVar3) {
                _current._44_4_ = puVar9;
              }
            }
            *puVar3 = 0;
            k_sem_give((k_sem *)(puVar3 + 2));
            puVar5 = puVar9;
          }
          puVar3 = puVar11;
          puVar9 = puVar5;
          if (puVar11 != (undefined4 *)0x0) {
            puVar11 = (undefined4 *)*puVar11;
          }
        }
      }
    }
    else {
      puVar8[3] = uVar7 & 0xfffffffe;
    }
    uVar7 = *(uint *)((int)workq_ptr + 0xf0) & 0xfffffffd;
    *(uint *)((int)workq_ptr + 0xf0) = uVar7;
    bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (!bVar1) goto LAB_00075e04;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    if (-1 < (int)(uVar7 << 0x17)) {
      z_impl_k_yield();
    }
  } while( true );
}


