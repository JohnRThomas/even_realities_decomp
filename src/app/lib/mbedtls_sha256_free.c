/*
 * Function: mbedtls_sha256_free
 * Entry:    0007d1f8
 * Prototype: int __stdcall mbedtls_sha256_free(int * param_1)
 */


/* exclude_from_export_ai */

int mbedtls_sha256_free(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_ac;
  uchar auStack_a8 [144];
  
  if (0 < param_1[0x3e]) {
    iVar3 = param_1[0x43];
    local_ac = 0;
    iVar1 = (*(code *)param_1[0x3f])(param_1[0x40],auStack_a8,0x90,&local_ac);
    if (iVar1 != 0) goto LAB_0007d240;
    if (local_ac != 0) {
      iVar2 = mbedtls_sha256_update(param_1,'\0',auStack_a8,local_ac);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[0x41] = param_1[0x41] + local_ac;
    }
    if (iVar3 == 1) goto LAB_0007d240;
  }
  iVar1 = -0x3d;
LAB_0007d240:
  mbedtls_platform_zeroize(auStack_a8,0x90);
  return iVar1;
}


