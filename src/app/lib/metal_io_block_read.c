/*
 * Function: metal_io_block_read
 * Entry:    00088c46
 * Prototype: int __stdcall metal_io_block_read(metal_io_region * io, ulong offset, void * dst, int len)
 */


/* exclude_from_export */

int metal_io_block_read(metal_io_region *io,ulong offset,void *dst,int len)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  
  if (((io->virt == (undefined *)0xffffffff) || (uVar6 = io->size, uVar6 <= offset)) ||
     (puVar4 = io->virt + offset, puVar4 == (undefined *)0x0)) {
    len = -0x22;
  }
  else {
    if (uVar6 < len + offset) {
      len = uVar6 - offset;
    }
    if ((code *)io[1].physmap == (code *)0x0) {
      DataMemoryBarrier(0x1b);
      iVar5 = (int)puVar4 - (int)dst;
      iVar3 = len;
      for (; (puVar1 = (undefined4 *)((int)dst + iVar5), iVar3 != 0 &&
             ((((uint)puVar1 | (uint)dst) & 3) != 0)); dst = (void *)((int)dst + 1)) {
        iVar3 = iVar3 + -1;
        *(undefined1 *)dst = *(undefined1 *)puVar1;
      }
      for (; 3 < iVar3; iVar3 = iVar3 + -4) {
        *(undefined4 *)dst = *puVar1;
        puVar1 = puVar1 + 1;
        dst = (undefined4 *)((int)dst + 4);
      }
      puVar2 = (undefined1 *)((int)puVar1 + -1);
      puVar1 = (undefined4 *)(iVar3 + (int)dst);
      for (; dst != puVar1; dst = (void *)((int)dst + 1)) {
        puVar2 = puVar2 + 1;
        *(undefined1 *)dst = *puVar2;
      }
    }
    else {
      len = (*(code *)io[1].physmap)();
    }
  }
  return len;
}


