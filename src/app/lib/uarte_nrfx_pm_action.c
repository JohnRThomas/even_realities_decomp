/*
 * Function: uarte_nrfx_pm_action
 * Entry:    00065efc
 * Prototype: int __stdcall uarte_nrfx_pm_action(device * dev, pm_device_action action)
 */


/* exclude_from_export */

int uarte_nrfx_pm_action(device *dev,pm_device_action action)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  
  puVar4 = (undefined4 *)dev->config;
  puVar3 = (undefined4 *)*puVar4;
  puVar5 = dev->data;
  if (action == 0) {
    iVar2 = *(int *)(puVar5 + 0xc);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0xca) != '\0') {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!data->async->rx_enabled",
                "WEST_TOPDIR/zephyr/drivers/serial/uart_nrfx_uarte.c",1896);
LAB_00065f60:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if (*(int *)(iVar2 + 0xc) != 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!data->async->tx_size",
                "WEST_TOPDIR/zephyr/drivers/serial/uart_nrfx_uarte.c",1897);
        goto LAB_00065f60;
      }
    }
    if (puVar3[0x53] != 0) {
      puVar3[1] = 1;
      do {
        if (puVar3[0x51] != 0) break;
      } while (puVar3[0x49] == 0);
      puVar3[0x53] = 0;
      puVar3[0x51] = 0;
      puVar3[0x44] = 0;
    }
    iVar2 = *(int *)dev->config;
    uVar7 = *(uint *)((int)dev->config + 4) & 2;
    if (uVar7 == 0) {
      iVar6 = 1000;
      *(undefined4 *)(iVar2 + 0x308) = 0x100;
      do {
        bVar1 = is_tx_ready((device *)dev->config);
        if (bVar1) break;
        arch_busy_wait(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (*(int *)(iVar2 + 0x158) == 0) {
        *(undefined4 *)(iVar2 + 0x120) = 0;
        *(undefined4 *)(iVar2 + 0xc) = 1;
      }
    }
    iVar6 = 1000;
    do {
      if (*(int *)(iVar2 + 0x158) != 0) break;
      arch_busy_wait(1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (uVar7 == 0) {
      *(undefined4 *)(iVar2 + 0x304) = 0x100;
    }
    *(undefined4 *)(*(int *)dev->config + 0x500) = 0;
    if ((int)(puVar4[1] << 0x1f) < 0) {
      uVar7 = pinctrl_apply_state((pinctrl_dev_config *)puVar4[3],'\x01');
      return uVar7 & (int)uVar7 >> 0x1f;
    }
  }
  else {
    if (action != 1) {
      return -0x86;
    }
    if (((int)(puVar4[1] << 0x1f) < 0) &&
       (iVar2 = pinctrl_apply_state((pinctrl_dev_config *)puVar4[3],'\0'), iVar2 < 0)) {
      return iVar2;
    }
    puVar3[0x140] = 8;
    if ((*(int *)(puVar5 + 0xc) == 0) && (*(char *)(puVar4 + 2) == '\0')) {
      puVar3[0x44] = 0;
      *puVar3 = 1;
    }
  }
  return 0;
}


