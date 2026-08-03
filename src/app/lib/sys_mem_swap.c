/*
 * Function: sys_mem_swap
 * Entry:    00086d4a
 * Prototype: void __stdcall sys_mem_swap(void * buf, size_t length)
 */


/* exclude_from_export_ai */

void sys_mem_swap(void *buf,size_t length)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)((int)buf + -1);
  puVar2 = (undefined1 *)((int)buf + 0x10);
  do {
    puVar3 = puVar3 + 1;
    uVar1 = *puVar3;
    puVar2 = puVar2 + -1;
    *puVar3 = *puVar2;
    *puVar2 = uVar1;
  } while (puVar3 != (undefined1 *)((int)buf + 7));
  return;
}


