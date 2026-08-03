/*
 * Function: metal_io_block_write
 * Entry:    00088cb8
 * Prototype: int __stdcall metal_io_block_write(metal_io_region * io, ulong offset, void * src, int len)
 */


/* exclude_from_export */

int metal_io_block_write(metal_io_region *io,ulong offset,void *src,int len)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  if (((io->virt == (undefined *)0xffffffff) || (uVar6 = io->size, uVar6 <= offset)) ||
     (puVar4 = io->virt + offset, puVar4 == (undefined *)0x0)) {
    len = -0x22;
  }
  else {
    if (uVar6 < len + offset) {
      len = uVar6 - offset;
    }
    if ((code *)io[1].size == (code *)0x0) {
      iVar5 = (int)puVar4 - (int)src;
      iVar3 = len;
      for (; (puVar1 = (undefined4 *)(iVar5 + (int)src), iVar3 != 0 &&
             ((((uint)puVar1 | (uint)src) & 3) != 0)); src = (void *)((int)src + 1)) {
        iVar3 = iVar3 + -1;
        *(undefined1 *)puVar1 = *(undefined1 *)src;
      }
      for (; 3 < iVar3; iVar3 = iVar3 + -4) {
        *puVar1 = *(undefined4 *)src;
        puVar1 = puVar1 + 1;
        src = (undefined4 *)((int)src + 4);
      }
      puVar7 = (undefined1 *)((int)src + -1);
      puVar2 = (undefined4 *)(iVar3 + (int)puVar1);
      for (; puVar1 != puVar2; puVar1 = (undefined4 *)((int)puVar1 + 1)) {
        puVar7 = puVar7 + 1;
        *(undefined1 *)puVar1 = *puVar7;
      }
      DataMemoryBarrier(0x1b);
    }
    else {
      len = (*(code *)io[1].size)();
    }
  }
  return len;
}


