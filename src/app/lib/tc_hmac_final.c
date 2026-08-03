/*
 * Function: tc_hmac_final
 * Entry:    00083c98
 * Prototype: int __stdcall tc_hmac_final(uint8_t * tag, uint taglen, TCHmacState_t ctx)
 */


/* exclude_from_export_ai */

int tc_hmac_final(uint8_t *tag,uint taglen,TCHmacState_t ctx)

{
  int iVar1;
  
  if ((tag == (uint8_t *)0x0) || (taglen != 0x20)) {
    iVar1 = 0;
  }
  else if (ctx == (TCHmacState_t)0x0) {
    iVar1 = 0;
  }
  else {
    tc_sha256_final(tag,ctx);
    tc_sha256_init(ctx);
    tc_sha256_update(ctx,ctx + 0xb0,0x40);
    tc_sha256_update(ctx,tag,0x20);
    tc_sha256_final(tag,ctx);
    memset(ctx,0,0xf0);
    iVar1 = 1;
  }
  return iVar1;
}


