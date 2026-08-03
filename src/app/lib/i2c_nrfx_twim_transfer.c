/*
 * Function: i2c_nrfx_twim_transfer
 * Entry:    00064b94
 * Prototype: int __stdcall i2c_nrfx_twim_transfer(device * dev, i2c_msg * msgs, uint8_t num_msgs, uint16_t addr)
 */


/* exclude_from_export_ai */

int i2c_nrfx_twim_transfer(device *dev,i2c_msg *msgs,uint8_t num_msgs,uint16_t addr)

{
  ushort uVar1;
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  nrfx_err_t nVar2;
  uint uVar3;
  undefined4 extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  i2c_msg *piVar8;
  k_sem *sem;
  void *pvVar9;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  dword in_stack_ffffff78;
  uint8_t *in_stack_ffffff7c;
  void *in_stack_ffffff80;
  dword in_stack_ffffff88;
  uint8_t *in_stack_ffffff8c;
  void *in_stack_ffffff90;
  uint local_68;
  char *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  int local_54;
  undefined1 *local_50;
  nrfx_twim_t *local_4c;
  uint local_48;
  k_sem *local_44;
  nrfx_twim_xfer_desc_t local_3c;
  uint local_38;
  void *local_30;
  
  local_50 = (undefined1 *)(uint)num_msgs;
  local_4c = (nrfx_twim_t *)dev->config;
  sem = (k_sem *)dev->data;
  local_48 = (uint)(ushort)local_4c[6];
  pvVar9 = sem[2].wait_q.prev;
  memset(&local_3c,0,0x14);
  local_3c.opaque[1] = (byte)addr;
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1;
  z_impl_k_sem_take(sem,timeout);
  local_44 = sem + 1;
  timeout_00.ticks._4_4_ = 0;
  timeout_00.ticks._0_4_ = extraout_r1_00;
  z_impl_k_sem_take(local_44,timeout_00);
  uVar6 = 0;
  puVar7 = (undefined1 *)0x0;
  do {
    if (local_50 <= puVar7) {
      iVar5 = 0;
LAB_00064c70:
      k_sem_give(sem);
      return iVar5;
    }
    uVar3 = (uint)*(byte *)(msgs + 2);
    if ((int)(uVar3 << 0x1c) < 0) {
      iVar5 = -0x86;
      goto LAB_00064c70;
    }
    if (((local_50 <= puVar7 + 1) || ((int)(uVar3 << 0x1e) < 0)) ||
       (((*(byte *)(msgs + 2) ^ *(byte *)(msgs + 5)) & 1) != 0 || (*(byte *)(msgs + 5) & 4) != 0)) {
      if ((uVar6 != 0) || (((uint)*msgs & 0xe0000000) != 0x20000000)) {
        iVar5 = 0;
        goto LAB_00064c2c;
      }
LAB_00064c9e:
      uVar6 = msgs[1];
      uVar3 = 0;
      local_30 = (void *)*msgs;
LAB_00064ca6:
      local_3c.opaque[0] = *(byte *)(msgs + 2) & 1;
      local_38 = uVar6;
      nVar2 = nrfx_twim_xfer(local_4c,&local_3c,(((*(byte *)(msgs + 2) ^ 2) & 3) >> 1) << 5);
      if ((undefined1 *)(uint)nVar2 == &DAT_0bad0000) {
        timeout_01.ticks._4_4_ = 0x4000;
        timeout_01.ticks._0_4_ = extraout_r1_01;
        iVar5 = z_impl_k_sem_take(local_44,timeout_01);
        if (iVar5 == 0) {
          puVar4 = sem[2].wait_q.next;
          if (puVar4 == &DAT_0bad0000) {
            if (((int)((uint)*(byte *)(msgs + 2) << 0x1f) < 0) &&
               (piVar8 = msgs, pvVar9 == local_30)) {
              while( true ) {
                uVar6 = piVar8[1];
                if (uVar3 < uVar6) break;
                uVar1 = (short)uVar3 - (short)uVar6;
                uVar3 = (uint)uVar1;
                memcpy((void *)*piVar8,(void *)((int)pvVar9 + (uint)uVar1),uVar6);
                piVar8 = piVar8 + -3;
              }
            }
            uVar6 = 0;
            goto LAB_00064d4e;
          }
          local_64 = "Error 0x%08X occurred for message %d";
          local_68 = 4;
          desc.level = (dword)&local_68;
          desc.domain = 0x2040;
          desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc.data_len = in_stack_ffffff88;
          local_60 = puVar4;
          local_5c = puVar7;
          z_impl_z_log_msg_static_create
                    (&PTR_s_i2c_nrfx_twim_0008b980,desc,in_stack_ffffff8c,in_stack_ffffff90);
        }
        else {
          local_64 = "Error on I2C line occurred for message %d";
          local_68 = 3;
          desc_00.level = (dword)&local_68;
          desc_00.domain = 0x1840;
          desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc_00.data_len = in_stack_ffffff88;
          local_60 = puVar7;
          z_impl_z_log_msg_static_create
                    (&PTR_s_i2c_nrfx_twim_0008b980,desc_00,in_stack_ffffff8c,in_stack_ffffff90);
          i2c_nrfx_twim_recover_bus(dev);
        }
      }
      else if ((undefined1 *)(uint)nVar2 == (undefined1 *)0xbad000b) {
        iVar5 = -0x10;
        goto LAB_00064c70;
      }
      iVar5 = -5;
      goto LAB_00064c70;
    }
    iVar5 = 1;
LAB_00064c2c:
    if (local_48 < uVar6 + msgs[1]) {
      local_64 = dev->name;
      local_68 = local_48;
      local_60 = (undefined1 *)CONCAT22(local_60._2_2_,0x503);
      desc_01.level = (dword)&stack0xffffff88;
      desc_01.domain = 0x3440;
      desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_01.data_len = in_stack_ffffff78;
      z_impl_z_log_msg_static_create
                (&PTR_s_i2c_nrfx_twim_0008b980,desc_01,in_stack_ffffff7c,in_stack_ffffff80);
      iVar5 = -0x1c;
      goto LAB_00064c70;
    }
    if (-1 < (int)(uVar3 << 0x1f)) {
      local_54 = iVar5;
      memcpy((void *)((int)pvVar9 + uVar6),(void *)*msgs,msgs[1]);
      iVar5 = local_54;
    }
    uVar6 = msgs[1] + uVar6 & 0xffff;
    if (iVar5 == 0) {
      uVar3 = uVar6;
      local_30 = pvVar9;
      if (uVar6 == 0) goto LAB_00064c9e;
      goto LAB_00064ca6;
    }
LAB_00064d4e:
    msgs = msgs + 3;
    puVar7 = puVar7 + 1;
  } while( true );
}


