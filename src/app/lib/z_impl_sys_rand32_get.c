/*
 * Function: z_impl_sys_rand32_get
 * Entry:    00055eec
 * Prototype: uint32_t __stdcall z_impl_sys_rand32_get(void)
 */


/* exclude_from_export */

uint32_t z_impl_sys_rand32_get(void)

{
  bool bVar1;
  int iVar2;
  undefined *in_r1;
  uint16_t length;
  char *file;
  int line;
  undefined *local_c;
  
  local_c = in_r1;
  bVar1 = z_device_is_ready((device *)&PTR_s_crypto_50844000_0008b340);
  if (!bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","device_is_ready(entropy_dev)",
            "WEST_TOPDIR/zephyr/subsys/random/rand32_entropy_device.c",21);
    _ASSERT("\tEntropy device %s not ready\n","crypto@50844000",file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  iVar2 = entropy_get_entropy((device *)&local_c,&Reset,length);
  if (iVar2 < 0) {
    local_c = (undefined *)k_cycle_get_32();
  }
  return (uint32_t)local_c;
}


