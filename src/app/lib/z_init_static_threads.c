/*
 * Function: z_init_static_threads
 * Entry:    000751e0
 * Prototype: void __stdcall z_init_static_threads(void)
 */


/* exclude_from_export */

void z_init_static_threads(void)

{
  longlong lVar1;
  undefined4 extraout_r0;
  char *test;
  char *test_00;
  int iVar2;
  undefined4 extraout_r1;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined *puVar3;
  uint uVar4;
  undefined **ppuVar5;
  k_tid_t thread;
  k_timeout_t timeout;
  
  ppuVar5 = &PTR_DAT_0008b778;
  do {
    if (&PTR_DAT_0008b778 < ppuVar5) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","thread_data <= __static_thread_data_list_end",
              "WEST_TOPDIR/zephyr/kernel/thread.c",755);
      _ASSERT("\tunexpected list end location\n",test,file,line);
LAB_00075208:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_z_irq_spurious_1_0008b774 + 3U) < ppuVar5) {
      z_sched_lock();
      for (ppuVar5 = &PTR_DAT_0008b778; ppuVar5 < (undefined **)((int)&PTR_DAT_0008b778 + 1U);
          ppuVar5 = ppuVar5 + 0xb) {
        if ((undefined **)((int)&PTR_z_irq_spurious_1_0008b774 + 3U) < ppuVar5) {
          k_sched_unlock();
          return;
        }
        puVar3 = ppuVar5[9];
        if (puVar3 != (undefined *)0xffffffff) {
          uVar4 = (uint)puVar3 & ~((int)puVar3 >> 0x1f);
          lVar1 = (longlong)(int)uVar4 * 0x8000 + 999;
          iVar2 = (int)((ulonglong)lVar1 >> 0x20);
          thread = *ppuVar5;
          if (iVar2 == 0 && (uVar4 & 0x1ffff) == 0) {
            k_thread_start(thread);
          }
          else {
            __aeabi_uldivmod((int)lVar1,iVar2,1000,0);
            timeout.ticks._4_4_ = extraout_r1;
            timeout.ticks._0_4_ = extraout_r0;
            z_add_timeout((_timeout *)(thread + 0x18),(_timeout_func_t)0x89e11,timeout);
          }
        }
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","thread_data <= __static_thread_data_list_end",
              "WEST_TOPDIR/zephyr/kernel/thread.c",786);
      _ASSERT("\tunexpected list end location\n",test_00,file_00,line_00);
      goto LAB_00075208;
    }
    z_setup_new_thread((k_thread *)*ppuVar5,(k_thread_stack_t *)ppuVar5[1],(size_t)ppuVar5[2],
                       (k_thread_entry_t *)ppuVar5[3],ppuVar5[4],ppuVar5[5],ppuVar5[6],
                       (int)ppuVar5[7],(uint32_t)ppuVar5[8],ppuVar5[10]);
    *(undefined ***)(*ppuVar5 + 0x54) = ppuVar5;
    ppuVar5 = ppuVar5 + 0xb;
  } while( true );
}


