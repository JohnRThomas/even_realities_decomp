/*
 * Function: block_cipher_df
 * Entry:    0007ce08
 * Prototype: int __stdcall block_cipher_df(uint8_t * param_1, void * param_2, uint param_3, uint param_4)
 */


/* exclude_from_export_ai */

int block_cipher_df(uint8_t *param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  size_t data_len;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  if (((0x180 < uVar2) || (0x180 - uVar2 < param_4)) || ((0x180 - param_4) - uVar2 < param_3)) {
    return -0x38;
  }
  uVar2 = param_4;
  memset(&DAT_2000d988,0,0x180);
  iVar1 = (**(code **)(param_1 + 0x94))
                    (*(undefined4 *)(param_1 + 0x98),&DAT_2000d988,*(undefined4 *)(param_1 + 0x18),
                     *(code **)(param_1 + 0x94),uVar2);
  if (iVar1 == 0) {
    data_len = *(size_t *)(param_1 + 0x18);
    if (param_4 != 0) {
      iVar1 = (**(code **)(param_1 + 0x94))
                        (*(undefined4 *)(param_1 + 0x98),&DAT_2000d988 + data_len,param_4);
      if (iVar1 != 0) goto LAB_0007cec2;
      data_len = data_len + param_4;
    }
    if ((param_2 == (void *)0x0) || (param_3 == 0)) {
      iVar1 = block_cipher_df(&DAT_2000d988,&DAT_2000d988,data_len);
    }
    else {
      memcpy(&DAT_2000d988 + data_len,param_2,param_3);
      iVar1 = block_cipher_df(&DAT_2000d988,&DAT_2000d988,data_len + param_3);
    }
    if ((iVar1 == 0) && (iVar1 = mbedtls_ctr_drbg_update(param_1,(uint *)&DAT_2000d988), iVar1 == 0)
       ) {
      param_1[0x10] = '\x01';
      param_1[0x11] = '\0';
      param_1[0x12] = '\0';
      param_1[0x13] = '\0';
    }
    mbedtls_platform_zeroize(&DAT_2000d988,0x180);
  }
  else {
LAB_0007cec2:
    iVar1 = -0x34;
  }
  return iVar1;
}


