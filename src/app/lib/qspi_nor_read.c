/*
 * Function: qspi_nor_read
 * Entry:    00064318
 * Prototype: int __stdcall qspi_nor_read(device * dev, off_t addr, void * dest, size_t size)
 */


/* exclude_from_export */

int qspi_nor_read(device *dev,off_t addr,void *dest,size_t size)

{
  nrfx_err_t res;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint n;
  uint uVar6;
  size_t n_00;
  char local_48 [4];
  char *local_44;
  off_t oStack_40;
  size_t local_3c;
  size_t local_38;
  void *local_34;
  undefined1 auStack_30 [12];
  
  if (dest == (void *)0x0) {
    return -0x16;
  }
  if (size == 0) {
    return 0;
  }
  if ((addr < 0) || (*(uint *)(dev->config + 0x2c) < addr + size)) {
    local_44 = "read error: address or size exceeds expected values.Addr: 0x%lx size %zu";
    local_48[0] = '\x04';
    local_48[1] = '\0';
    local_48[2] = '\0';
    local_48[3] = '\0';
    oStack_40 = addr;
    local_3c = size;
    LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2040,local_48);
    return -0x16;
  }
  iVar1 = qspi_device_init(dev);
  if (iVar1 != 0) goto LAB_00064474;
  qspi_lock(dev);
  n = -addr & 3U;
  if (size <= (-addr & 3U)) {
    n = size;
  }
  uVar3 = (uint)dest & 3;
  if (-1 < -(int)dest) {
    uVar3 = -(-(int)dest & 3U);
  }
  uVar4 = -uVar3 & 3;
  if (size <= (-uVar3 & 3)) {
    uVar4 = size;
  }
  uVar2 = size - n;
  uVar5 = size - uVar4 & 0xfffffffc;
  uVar6 = uVar2 & 0xfffffffc;
  uVar3 = uVar6;
  if ((int)uVar5 < (int)uVar6) {
    uVar3 = uVar5;
  }
  n_00 = uVar2 & 3;
  if ((int)uVar5 < (int)uVar6) {
    n_00 = uVar2 - uVar5;
  }
  if (uVar3 == 0) {
LAB_000643fe:
    if (n != 0) {
      local_34 = (void *)(4 - n);
      res = _nrfx_qspi_read(auStack_30,4,addr - (int)local_34);
      qspi_wait_for_completion((device *)dev->data,res);
      if ((undefined1 *)(uint)res != &DAT_0bad0000) goto LAB_00064466;
      memcpy(dest,(undefined1 *)((int)local_34 + (int)auStack_30),n);
    }
    if (n_00 == 0) {
      res = NRFX_SUCCESS;
    }
    else {
      res = _nrfx_qspi_read(auStack_30,8,addr + n + uVar3);
      qspi_wait_for_completion((device *)dev->data,res);
      if ((undefined1 *)(uint)res == &DAT_0bad0000) {
        memcpy((void *)(uVar3 + n + (int)dest),auStack_30,n_00);
      }
    }
  }
  else {
    local_34 = (void *)((int)dest + uVar4);
    local_38 = uVar4;
    res = _nrfx_qspi_read(local_34,uVar3,addr + n);
    qspi_wait_for_completion((device *)dev->data,res);
    if ((undefined1 *)(uint)res == &DAT_0bad0000) {
      if (n != local_38) {
        memmove((void *)((int)dest + n),local_34,uVar3);
      }
      goto LAB_000643fe;
    }
  }
LAB_00064466:
  qspi_unlock(dev);
  iVar1 = qspi_get_zephyr_ret_code(res);
LAB_00064474:
  qspi_device_uninit(dev);
  return iVar1;
}


