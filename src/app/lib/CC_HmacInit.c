/*
 * Function: CC_HmacInit
 * Entry:    0007d280
 * Prototype: undefined __stdcall CC_HmacInit(undefined4 * param_1)
 */


/* exclude_from_export_ai */

void CC_HmacInit(undefined4 *param_1)

{
  int iVar1;
  undefined4 *buf;
  
  buf = param_1 + 0x44;
  param_1[0x3e] = 0;
  memset(param_1 + 0x3f,0,0x14);
  memset(buf,0,8);
  (*DAT_20002f7c)(buf);
  *param_1 = 0;
  cc_mbedtls_sha256_init(param_1 + 1);
  iVar1 = (*DAT_20002f78)(buf);
  if (iVar1 == 0) {
    iVar1 = param_1[0x3e];
    if (iVar1 < 1) {
      param_1[iVar1 * 5 + 0x40] = 0;
      param_1[iVar1 * 5 + 0x42] = 0x20;
      param_1[iVar1 * 5 + 0x43] = 1;
      param_1[iVar1 * 5 + 0x3f] = 0x7dca5;
      param_1[0x3e] = iVar1 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0007d2f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_20002f74)(buf);
    return;
  }
  return;
}


