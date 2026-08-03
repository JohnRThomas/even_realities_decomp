/*
 * Function: uarte_nrfx_rx_enable
 * Entry:    00066290
 * Prototype: int __stdcall uarte_nrfx_rx_enable(device * dev, uint8_t * buf, size_t len, int32_t timeout)
 */


/* exclude_from_export */

int uarte_nrfx_rx_enable(device *dev,uint8_t *buf,size_t len,int32_t timeout)

{
  bool bVar1;
  char *test;
  undefined4 uVar2;
  char *file;
  int iVar3;
  int line;
  undefined *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)dev->config;
  puVar4 = dev->data;
  puVar6 = (undefined4 *)*puVar7;
  if (*(char *)(puVar7 + 2) != '\0') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/zephyr/drivers/serial/uart_nrfx_uarte.c",834);
    _ASSERT("\tTX only UARTE instance\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  iVar3 = *(int *)(puVar4 + 0xc);
  if ((*(char *)(iVar3 + 0xca) == '\0') && (*(char *)(iVar3 + 0xcb) == '\0')) {
    *(int32_t *)(iVar3 + 0x74) = timeout;
    if (timeout < 0x1d1) {
      iVar3 = 0x5c;
    }
    else {
      iVar3 = timeout / 5;
    }
    *(int *)(*(int *)(puVar4 + 0xc) + 0x78) = iVar3;
    *(uint8_t **)(*(int *)(puVar4 + 0xc) + 0x58) = buf;
    *(size_t *)(*(int *)(puVar4 + 0xc) + 0x5c) = len;
    *(undefined4 *)(*(int *)(puVar4 + 0xc) + 0x60) = 0;
    *(undefined4 *)(*(int *)(puVar4 + 0xc) + 100) = 0;
    *(undefined4 *)(*(int *)(puVar4 + 0xc) + 0x68) = 0;
    if ((int)(puVar7[1] << 0x1b) < 0) {
      uVar5 = (uint)*(byte *)(*(int *)(puVar4 + 0xc) + 0xc9);
      if (uVar5 != 0) {
        if (len <= uVar5) {
          uVar5 = len;
        }
        memcpy(buf,(void *)(*(int *)(puVar4 + 0xc) + 0xc4),uVar5);
        len = len - uVar5;
        buf = buf + uVar5;
        if (len == 0) {
          *(char *)(*(int *)(puVar4 + 0xc) + 0xc9) =
               *(char *)(*(int *)(puVar4 + 0xc) + 0xc9) - (char)uVar5;
          notify_uart_rx_rdy(dev,uVar5);
          rx_buf_release(dev,(uint8_t **)(*(int *)(puVar4 + 0xc) + 0x58));
          notify_rx_disable(dev);
          return 0;
        }
      }
    }
    puVar6[0x14d] = buf;
    puVar6[0x14e] = len;
    puVar6[0x44] = 0;
    puVar6[0x53] = 0;
    *(undefined1 *)(*(int *)(puVar4 + 0xc) + 0xca) = 1;
    if ((int)(puVar7[1] << 0x1b) < 0) {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      iVar3 = *(int *)(dev->data + 0xc);
      if (iVar3 != 0) {
        *(uint *)(iVar3 + 0xc0) = *(uint *)(iVar3 + 0xc0) | 2;
      }
      *(undefined4 *)(*(int *)dev->config + 0x500) = 8;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar2);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    *puVar6 = 1;
    return 0;
  }
  return -0x10;
}


