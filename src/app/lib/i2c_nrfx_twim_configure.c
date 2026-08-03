/*
 * Function: i2c_nrfx_twim_configure
 * Entry:    00064b34
 * Prototype: int __stdcall i2c_nrfx_twim_configure(device * dev, uint32_t i2c_config)
 */


/* exclude_from_export */

int i2c_nrfx_twim_configure(device *dev,uint32_t i2c_config)

{
  log_msg_desc desc;
  int iVar1;
  uint uVar2;
  void *in_r2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  
  piVar3 = (int *)dev->config;
  if ((i2c_config & 1) == 0) {
    uVar2 = (i2c_config & 0xf) >> 1;
    if (uVar2 == 2) {
      iVar5 = *piVar3;
      puVar4 = &DAT_06400000;
    }
    else if (uVar2 == 3) {
      iVar5 = *piVar3;
      puVar4 = (undefined1 *)0xff00000;
    }
    else {
      if (uVar2 != 1) {
        desc.level = (dword)&stack0xfffffff0;
        desc.domain = 0x1040;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = (dword)dev;
        z_impl_z_log_msg_static_create
                  (&PTR_s_i2c_nrfx_twim_0008b980,desc,(uint8_t *)i2c_config,in_r2);
        goto LAB_00064b84;
      }
      iVar5 = *piVar3;
      puVar4 = (undefined1 *)0x1980000;
    }
    iVar1 = 0;
    *(undefined1 **)(iVar5 + 0x524) = puVar4;
  }
  else {
LAB_00064b84:
    iVar1 = -0x16;
  }
  return iVar1;
}


