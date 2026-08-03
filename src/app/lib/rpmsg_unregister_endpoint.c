/*
 * Function: rpmsg_unregister_endpoint
 * Entry:    00088ff6
 * Prototype: void __stdcall rpmsg_unregister_endpoint(rpmsg_endpoint * ept)
 */


/* exclude_from_export */

void rpmsg_unregister_endpoint(rpmsg_endpoint *ept)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  k_sem *sem;
  k_timeout_t timeout;
  
  iVar4 = *(int *)((int)&ept[1].rdev + 2);
  sem = (k_sem *)(iVar4 + 0x58);
  timeout.ticks._4_4_ = in_r2;
  timeout.ticks._0_4_ = in_r1;
  k_sem_take(sem,timeout);
  uVar2 = *(int *)((int)&ept[1].addr + 2) - 0x400;
  if (uVar2 < 0x80) {
    iVar4 = iVar4 + 0x48;
    *(uint *)(iVar4 + (uVar2 >> 5) * 4) =
         *(uint *)(iVar4 + (uVar2 >> 5) * 4) & ~(1 << (uVar2 & 0x1f));
  }
  puVar1 = *(undefined4 **)((int)&ept[1].priv + 2);
  *(undefined4 **)(*(int *)((int)&ept[1].node + 2) + 4) = puVar1;
  puVar3 = (undefined1 *)((int)&ept[1].node + 2);
  *puVar1 = *(undefined4 *)((int)&ept[1].node + 2);
  *(undefined1 **)((int)&ept[1].node + 2) = puVar3;
  *(undefined1 **)((int)&ept[1].priv + 2) = puVar3;
  *(undefined4 *)((int)&ept[1].rdev + 2) = 0;
  k_sem_give(sem);
  return;
}


