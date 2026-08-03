/*
 * Function: tc_hmac_set_key
 * Entry:    00083c0a
 * Prototype: int __stdcall tc_hmac_set_key(TCHmacState_t ctx, uint8_t * key, uint key_size)
 */


/* exclude_from_export_ai */

int tc_hmac_set_key(TCHmacState_t ctx,uint8_t *key,uint key_size)

{
  int iVar1;
  uint8_t *digest;
  uint8_t auStack_148 [64];
  undefined auStack_108 [144];
  uint8_t auStack_78 [100];
  
  iVar1 = 0;
  if (ctx != (TCHmacState_t)0x0) {
    if (key == (uint8_t *)0x0) {
      iVar1 = 0;
    }
    else if (key_size == 0) {
      iVar1 = 0;
    }
    else {
      if (key_size < 0x41) {
        tc_sha256_init(auStack_108);
        tc_sha256_update(auStack_108,auStack_148,key_size);
        tc_sha256_final(auStack_78,auStack_108);
        digest = key;
      }
      else {
        tc_sha256_init(ctx);
        digest = ctx + 0x90;
        tc_sha256_update(ctx,key,key_size);
        tc_sha256_final(digest,ctx);
        key_size = 0x20;
      }
      rekey(ctx + 0x70,digest,key_size);
      iVar1 = 1;
    }
  }
  return iVar1;
}


