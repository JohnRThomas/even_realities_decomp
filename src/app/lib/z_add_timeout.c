/*
 * Function: z_add_timeout
 * Entry:    00077e9c
 * Prototype: void __stdcall z_add_timeout(_timeout * to, _timeout_func_t fn, k_timeout_t timeout)
 */


/* exclude_from_export */

void z_add_timeout(_timeout *to,_timeout_func_t fn,k_timeout_t timeout)

{
  _timeout *p_Var1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int32_t ticks;
  char *test;
  uint uVar5;
  char *file;
  char *file_00;
  undefined4 *puVar6;
  char *file_01;
  int line;
  int line_00;
  int iVar7;
  int line_01;
  _timeout *p_Var8;
  undefined4 uVar9;
  
  iVar3 = (int)((ulonglong)timeout.ticks >> 0x20);
  uVar5 = (uint)timeout.ticks;
  if (timeout.ticks == -1) {
    return;
  }
  if ((to->node).next == (void *)0x0) {
    to->fn = fn;
    uVar9 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar9 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.swap_retval + 2));
      if ((int)((iVar3 + 1) - (uint)(uVar5 != 0xffffffff)) < 0 ==
          (SBORROW4(iVar3,-1) != SBORROW4(iVar3 + 1,(uint)(uVar5 != 0xffffffff)))) {
        uVar4 = elapsed();
        iVar7 = uVar5 + 1 + uVar4;
        iVar3 = iVar3 + (uint)(0xfffffffe < uVar5) +
                ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar5 + 1,uVar4);
      }
      else {
        iVar7 = (-DAT_20006bc0 - 2) - uVar5;
        iVar3 = (((-1 - DAT_20006bc4) - (uint)(0xfffffffe < DAT_20006bc0)) - iVar3) -
                (uint)(-DAT_20006bc0 - 2 < uVar5);
        if (iVar3 < (int)(uint)(iVar7 == 0)) {
          iVar7 = 1;
          iVar3 = 0;
        }
      }
      *(int *)&to->dticks = iVar7;
      *(int *)((int)&to->dticks + 4) = iVar3;
      p_Var1 = DAT_20002d20;
      p_Var8 = (_timeout *)0x0;
      if (DAT_20002d1c != (_timeout *)&DAT_20002d1c) {
        p_Var8 = DAT_20002d1c;
      }
      for (; p_Var8 != (_timeout *)0x0; p_Var8 = (p_Var8->node).next) {
        uVar5 = (uint)p_Var8->dticks;
        iVar7 = *(int *)((int)&p_Var8->dticks + 4);
        uVar4 = (uint)to->dticks;
        iVar3 = *(int *)((int)&to->dticks + 4);
        if ((int)((iVar3 - iVar7) - (uint)(uVar4 < uVar5)) < 0 !=
            (SBORROW4(iVar3,iVar7) != SBORROW4(iVar3 - iVar7,(uint)(uVar4 < uVar5)))) {
          puVar6 = (p_Var8->node).prev;
          *(uint *)&p_Var8->dticks = uVar5 - uVar4;
          *(uint *)((int)&p_Var8->dticks + 4) = (iVar7 - iVar3) - (uint)(uVar5 < uVar4);
          (to->node).next = p_Var8;
          (to->node).prev = puVar6;
          *puVar6 = to;
          (p_Var8->node).prev = to;
          goto LAB_00077f98;
        }
        *(uint *)&to->dticks = uVar4 - uVar5;
        *(uint *)((int)&to->dticks + 4) = (iVar3 - iVar7) - (uint)(uVar4 < uVar5);
        if (p_Var8 == p_Var1) break;
      }
      (to->node).next = &DAT_20002d1c;
      (to->node).prev = p_Var1;
      (p_Var1->node).next = to;
      DAT_20002d20 = to;
LAB_00077f98:
      if ((DAT_20002d1c != (_timeout *)&DAT_20002d1c) && (to == DAT_20002d1c)) {
        ticks = next_timeout();
        sys_clock_set_timeout(ticks,false);
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file_01,line_01);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file_00,line_00);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!sys_dnode_is_linked(&to->node)",
            "WEST_TOPDIR/zephyr/kernel/timeout.c",110);
    _ASSERT("\t\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


