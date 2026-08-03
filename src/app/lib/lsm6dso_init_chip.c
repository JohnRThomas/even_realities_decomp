/*
 * Function: lsm6dso_init_chip
 * Entry:    00065548
 * Prototype: int __stdcall lsm6dso_init_chip(device * dev)
 */


/* exclude_from_export */

int lsm6dso_init_chip(device *dev)

{
  lsm6dso_odr_xl_t val;
  int32_t iVar1;
  char *pcVar2;
  uint in_r1;
  uint uVar3;
  stmdev_ctx_t *ctx;
  undefined *puVar4;
  undefined2 uVar5;
  undefined *puVar6;
  undefined4 uStack_24;
  
  *(device **)dev->data = dev;
  ctx = (stmdev_ctx_t *)dev->config;
  puVar4 = dev->data;
  uStack_24 = in_r1;
  iVar1 = lsm6dso_mem_bank_set(ctx,0);
  if (iVar1 < 0) {
    pcVar2 = "Failed to set user bank\r\n";
  }
  else {
    iVar1 = lsm6dso_device_id_get(ctx,(uint8_t *)((int)&uStack_24 + 2));
    if (iVar1 < 0) {
      pcVar2 = "Failed reading chip id\r\n";
    }
    else {
      printk("lsm6dso_init_chip chip id 0x%x\r\n",uStack_24 >> 0x10 & 0xff);
      uVar3 = uStack_24 >> 0x10 & 0xff;
      if (uVar3 != 0x6c) {
        pcVar2 = "Invalid chip id 0x%x\r\n";
LAB_00065590:
        printk(pcVar2,uVar3);
        goto LAB_00065594;
      }
      iVar1 = lsm6dso_i3c_disable_set(ctx,0x80);
      if (iVar1 < 0) {
        pcVar2 = "Failed to disable I3C\r\n";
      }
      else {
        iVar1 = lsm6dso_sh_master_get(ctx,(uint8_t *)((int)&uStack_24 + 3));
        if (-1 < iVar1) {
          if (uStack_24._3_1_ != '\0') {
            printk("Disable shub before reset\r\n");
            lsm6dso_sh_master_set(ctx,'\0');
            arch_busy_wait(300);
          }
          iVar1 = lsm6dso_reset_set(ctx,'\x01');
          if (iVar1 < 0) goto LAB_00065594;
          arch_busy_wait(100);
          printk("accel pm is %d\r\n",(uint)*(byte *)&ctx[1].mdelay);
          uVar3 = (uint)*(byte *)&ctx[1].mdelay;
          if ((uVar3 != 1) && (uVar3 != 2)) {
            uVar3 = 0;
          }
          lsm6dso_xl_power_mode_set(ctx,uVar3);
          uVar3 = *(byte *)((int)&ctx[1].mdelay + 2) & 0x3f;
          printk("accel range is %d\r\n",uVar3);
          puVar6 = dev->data;
          iVar1 = lsm6dso_xl_full_scale_set((stmdev_ctx_t *)dev->config,uVar3);
          if (iVar1 < 0) {
            pcVar2 = "failed to set accelerometer range %d\r\n";
          }
          else {
            puVar6[0x1e] = (char)uVar3;
            if (*(char *)((int)&ctx[1].mdelay + 2) < '\0') {
              uVar3 = (uint)*(ushort *)(&DAT_0009ce06 + uVar3 * 2) * 0x3d;
            }
            else {
              uVar3 = (uint)*(ushort *)(&DAT_0009ce06 + uVar3 * 2) * 0x3d >> 1;
            }
            *(uint *)(puVar4 + 0xc) = uVar3;
            val = *(lsm6dso_odr_xl_t *)((int)&ctx[1].mdelay + 1);
            uVar3 = (uint)val;
            printk("accel odr is %d\r\n",uVar3);
            if (uVar3 < 0xb) {
              uVar5 = (&DAT_0009ce0e)[uVar3];
            }
            else {
              uVar5 = 0x1a04;
            }
            *(undefined2 *)(puVar4 + 0x1c) = uVar5;
            puVar6 = dev->data;
            iVar1 = lsm6dso_xl_data_rate_set((stmdev_ctx_t *)dev->config,val);
            if (iVar1 < 0) {
              pcVar2 = "failed to set accelerometer odr %d\r\n";
            }
            else {
              *(undefined2 *)(puVar6 + 0x1c) = uVar5;
              printk("gyro pm is %d\r\n",(uint)*(byte *)((int)&ctx[1].mdelay + 3));
              lsm6dso_gy_power_mode_set(ctx,(uint)(*(char *)((int)&ctx[1].mdelay + 3) == '\x01'));
              uVar3 = (uint)*(byte *)((int)&ctx[1].handle + 1);
              printk("gyro range is %d\r\n",uVar3);
              iVar1 = lsm6dso_gy_full_scale_set((stmdev_ctx_t *)dev->config,uVar3);
              if (iVar1 < 0) {
                pcVar2 = "failed to set gyroscope range %d\r\n";
              }
              else {
                *(uint *)(puVar4 + 0x18) = (uint)(ushort)(&DAT_0009cdea)[uVar3] * 0x1117;
                uVar3 = (uint)*(byte *)&ctx[1].handle;
                printk("gyro odr is %d\r\n",uVar3);
                if (uVar3 < 0xb) {
                  uVar5 = (&DAT_0009ce0e)[uVar3];
                }
                else {
                  uVar5 = 0x1a04;
                }
                *(undefined2 *)(puVar4 + 0x20) = uVar5;
                iVar1 = lsm6dso_gy_data_rate_set((stmdev_ctx_t *)dev->config,uVar3);
                if (-1 < iVar1) {
                  iVar1 = lsm6dso_fifo_mode_set(ctx,0);
                  if (iVar1 < 0) {
                    pcVar2 = "failed to set FIFO mode\r\n";
                  }
                  else {
                    iVar1 = lsm6dso_block_data_update_set(ctx,'\x01');
                    if (-1 < iVar1) {
                      return 0;
                    }
                    pcVar2 = "failed to set BDU mode\r\n";
                  }
                  goto LAB_00065564;
                }
                pcVar2 = "failed to set gyroscope odr %d\r\n";
              }
            }
          }
          goto LAB_00065590;
        }
        pcVar2 = "Failed to get I2C_MASTER status\r\n";
      }
    }
  }
LAB_00065564:
  printk(pcVar2);
LAB_00065594:
  printk("failed to initialize chip\r\n");
  return 0;
}


