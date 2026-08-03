/*
 * Function: cancel_async_locked
 * Entry:    00089d46
 * Prototype: int __stdcall cancel_async_locked(k_work * work)
 */


/* exclude_from_export */

int cancel_async_locked(k_work *work)

{
  k_work *pkVar1;
  int extraout_r0;
  uint uVar2;
  k_work *pkVar3;
  sys_snode_t *psVar4;
  uint uVar5;
  void *pvVar6;
  k_work *pkVar7;
  
  uVar5 = work->flags;
  if (-1 < (int)(uVar5 << 0x1e)) {
    pvVar6 = work->queue;
    flag_clear(&work->flags,2);
    if (extraout_r0 != 0) {
      pkVar1 = *(k_work **)((int)pvVar6 + 0xd8);
      pkVar7 = (k_work *)((uVar5 & 3) >> 1);
      while (pkVar3 = pkVar1, pkVar3 != (k_work *)0x0) {
        if (work == pkVar3) {
          psVar4 = (work->node).next;
          if (pkVar7 == (k_work *)0x0) {
            *(sys_snode_t **)((int)pvVar6 + 0xd8) = psVar4;
            if (work == *(k_work **)((int)pvVar6 + 0xdc)) {
              *(sys_snode_t **)((int)pvVar6 + 0xdc) = psVar4;
            }
          }
          else {
            (pkVar7->node).next = psVar4;
            if (work == *(k_work **)((int)pvVar6 + 0xdc)) {
              *(k_work **)((int)pvVar6 + 0xdc) = pkVar7;
            }
          }
          (work->node).next = (sys_snode_t *)0x0;
          break;
        }
        pkVar7 = pkVar3;
        pkVar1 = (k_work *)(pkVar3->node).next;
      }
    }
  }
  uVar2 = work->flags & 0xf;
  uVar5 = 0;
  if (uVar2 != 0) {
    work->flags = work->flags | 2;
    uVar5 = uVar2 | 2;
  }
  return uVar5;
}


