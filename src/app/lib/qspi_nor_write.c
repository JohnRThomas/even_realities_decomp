/*
 * Function: qspi_nor_write
 * Entry:    000641c8
 * Prototype: int __stdcall qspi_nor_write(device * dev, off_t addr, void * src, size_t size)
 */


/* exclude_from_export */

int qspi_nor_write(device *dev,off_t addr,void *src,size_t size)

{
  nrfx_err_t nVar1;
  int iVar2;
  undefined1 *puVar3;
  uint n;
  char local_48 [4];
  char *local_44;
  off_t oStack_40;
  size_t local_3c;
  undefined1 auStack_38 [20];
  
  if ((((src == (void *)0x0) || (size == 0)) || ((4 < size && ((size & 3) != 0)))) ||
     ((addr & 3U) != 0)) {
    return -0x16;
  }
  if ((addr < 0) || (*(uint *)(dev->config + 0x2c) < addr + size)) {
    local_44 = "write error: address or size exceeds expected values.Addr: 0x%lx size %zu";
    local_48[0] = '\x04';
    local_48[1] = '\0';
    local_48[2] = '\0';
    local_48[3] = '\0';
    oStack_40 = addr;
    local_3c = size;
    LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2040,local_48);
    return -0x16;
  }
  iVar2 = qspi_device_init(dev);
  if (iVar2 != 0) goto LAB_000642fc;
  qspi_trans_lock((device *)dev->data);
  puVar3 = (undefined1 *)qspi_nor_write_protection_set(dev,false);
  qspi_lock(dev);
  if (puVar3 == (undefined1 *)0x0) {
    if (size < 4) {
      nVar1 = _nrfx_qspi_read(auStack_38,4,addr);
      puVar3 = (undefined1 *)(uint)nVar1;
      qspi_wait_for_completion((device *)dev->data,nVar1);
      if (puVar3 == &DAT_0bad0000) {
        memcpy(auStack_38,src,size);
        size = 4;
        src = auStack_38;
LAB_0006427e:
        nVar1 = nrfx_qspi_write(src,size,addr);
        puVar3 = (undefined1 *)(uint)nVar1;
        qspi_wait_for_completion((device *)dev->data,nVar1);
      }
    }
    else {
      if ((((uint)src & 0xe0000000) == 0x20000000) && (((uint)src & 3) == 0)) goto LAB_0006427e;
      do {
        n = size;
        if (0xf < size) {
          n = 0x10;
        }
        memcpy(auStack_38,src,n);
        nVar1 = nrfx_qspi_write(auStack_38,n,addr);
        puVar3 = (undefined1 *)(uint)nVar1;
        qspi_wait_for_completion((device *)dev->data,nVar1);
        if (puVar3 != &DAT_0bad0000) break;
        size = size - n;
        src = (void *)((int)src + n);
        addr = addr + n;
      } while (size != 0);
    }
  }
  qspi_unlock(dev);
  iVar2 = qspi_nor_write_protection_set(dev,true);
  nVar1 = (nrfx_err_t)iVar2;
  k_sem_give((k_sem *)dev->data);
  if (puVar3 != (undefined1 *)0x0) {
    nVar1 = (nrfx_err_t)puVar3;
  }
  iVar2 = qspi_get_zephyr_ret_code(nVar1);
LAB_000642fc:
  qspi_device_uninit(dev);
  return iVar2;
}


