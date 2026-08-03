/*
 * Function: qspi_nor_erase
 * Entry:    00064078
 * Prototype: int __stdcall qspi_nor_erase(device * dev, off_t addr, size_t size)
 */


/* exclude_from_export */

int qspi_nor_erase(device *dev,off_t addr,size_t size)

{
  nrfx_err_t nVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  uint uVar6;
  char local_38 [4];
  char *local_34;
  uint uStack_30;
  uint local_2c;
  
  puVar5 = dev->config;
  if ((addr < 0) || (*(uint *)(puVar5 + 0x2c) < addr + size)) {
    iVar2 = qspi_nor_erase_error_outline(addr,size);
  }
  else if ((size == 0) || ((size & 0xfff) != 0 || (addr & 0xfffU) != 0)) {
    iVar2 = -0x16;
  }
  else {
    iVar2 = qspi_device_init(dev);
    if (iVar2 == 0) {
      qspi_trans_lock((device *)dev->data);
      iVar2 = qspi_nor_write_protection_set(dev,false);
      if (iVar2 == 0) {
        qspi_lock(dev);
        do {
          if (*(uint *)(puVar5 + 0x2c) != size) {
            if (0xffff < size) {
              if ((addr & 0xffffU) == 0) {
                nVar1 = nrfx_qspi_erase(NRF_QSPI_ERASE_LEN_64KB,addr);
                puVar4 = (undefined1 *)(uint)nVar1;
                uVar6 = 0x10000;
              }
              else {
LAB_00064142:
                if ((addr & 0xfffU) != 0) goto LAB_00064156;
                nVar1 = nrfx_qspi_erase(NRF_QSPI_ERASE_LEN_4KB,addr);
                puVar4 = (undefined1 *)(uint)nVar1;
                uVar6 = 0x1000;
              }
              goto LAB_000640e8;
            }
            if (0xfff < size) goto LAB_00064142;
LAB_00064156:
            local_34 = "unsupported at 0x%lx size %zu";
            local_38[0] = '\x04';
            local_38[1] = '\0';
            local_38[2] = '\0';
            local_38[3] = '\0';
            uStack_30 = addr;
            local_2c = size;
            LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2040,local_38);
            qspi_wait_for_completion((device *)dev->data,NRFX_ERROR_INVALID_PARAM);
            puVar4 = (undefined1 *)0xbad0004;
LAB_00064182:
            local_34 = "erase error at 0x%lx size %zu";
            local_38[0] = '\x04';
            local_38[1] = '\0';
            local_38[2] = '\0';
            local_38[3] = '\0';
            uStack_30 = addr;
            local_2c = size;
            LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2040,local_38);
            iVar2 = qspi_get_zephyr_ret_code((nrfx_err_t)puVar4);
            break;
          }
          nVar1 = nrfx_qspi_chip_erase();
          puVar4 = (undefined1 *)(uint)nVar1;
          uVar6 = size;
LAB_000640e8:
          qspi_wait_for_completion((device *)dev->data,(nrfx_err_t)puVar4);
          if (puVar4 != &DAT_0bad0000) goto LAB_00064182;
          size = size - uVar6;
          addr = addr + uVar6;
        } while (size != 0);
        qspi_unlock(dev);
        iVar3 = qspi_nor_write_protection_set(dev,true);
        if (iVar2 == 0) {
          iVar2 = iVar3;
        }
      }
      k_sem_give((k_sem *)dev->data);
    }
    qspi_device_uninit(dev);
  }
  return iVar2;
}


