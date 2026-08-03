/*
 * Function: CC_LibFini
 * Entry:    0007c8b0
 * Prototype: int __stdcall CC_LibFini(int * param_1, void * param_2, uint param_3)
 */


/* exclude_from_export_ai */

int CC_LibFini(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    param_1 = &DAT_2000d618;
  }
  if (*param_1 != 0x5ac9bca5) {
    mbedtls_platform_zeroize(param_1,0x1c0);
    CC_HmacInit(param_1 + 1);
    CC_RndInit(param_1 + 0x47);
    iVar1 = CC_AesSelfTest((uint8_t *)(param_1 + 0x47),0x7d305,param_1 + 1,param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_1 = 0x5ac9bca5;
  }
  return 0;
}


