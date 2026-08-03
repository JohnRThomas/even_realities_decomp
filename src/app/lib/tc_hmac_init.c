/*
 * Function: tc_hmac_init
 * Entry:    00083c72
 * Prototype: int __stdcall tc_hmac_init(TCHmacState_t ctx)
 */


/* exclude_from_export_ai */

int tc_hmac_init(TCHmacState_t ctx)

{
  if (ctx != (TCHmacState_t)0x0) {
    tc_sha256_init(ctx);
    tc_sha256_update(ctx,ctx + 0x70,0x40);
  }
  return (uint)(ctx != (TCHmacState_t)0x0);
}


