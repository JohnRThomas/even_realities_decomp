/*
 * Function: nvs_flash_al_wrt
 * Entry:    00081f0e
 * Prototype: int __stdcall nvs_flash_al_wrt(nvs_fs * fs, uint32_t addr, void * data, size_t len)
 */


/* exclude_from_export_ai */

int nvs_flash_al_wrt(nvs_fs *fs,uint32_t addr,void *data,size_t len)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined1 auStack_40 [36];
  
  if (len == 0) {
LAB_00081f1c:
    iVar1 = 0;
  }
  else {
    puVar2 = fs->offset + (addr >> 0x10) * (uint)fs->sector_size + (addr & 0xffff);
    uVar3 = -**(int **)((int)&fs[1].data_wra + 3) & len;
    if (uVar3 != 0) {
      iVar1 = *(int *)((int)&fs[1].ate_wra + 3);
      iVar1 = (**(code **)(*(int *)(iVar1 + 8) + 4))(iVar1,puVar2,data,uVar3);
      if (iVar1 != 0) {
        return iVar1;
      }
      len = len - uVar3;
      if (len == 0) goto LAB_00081f1c;
      puVar2 = puVar2 + uVar3;
      data = (void *)((int)data + uVar3);
    }
    memcpy(auStack_40,data,len);
    piVar4 = *(int **)((int)&fs[1].data_wra + 3);
    memset(auStack_40 + len,(uint)*(byte *)(piVar4 + 1),*piVar4 - len);
    iVar1 = *(int *)((int)&fs[1].ate_wra + 3);
    iVar1 = (**(code **)(*(int *)(iVar1 + 8) + 4))(iVar1,puVar2,auStack_40,*piVar4);
  }
  return iVar1;
}


