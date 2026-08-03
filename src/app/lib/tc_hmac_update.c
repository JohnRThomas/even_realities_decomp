/*
 * Function: tc_hmac_update
 * Entry:    00083c8c
 * Prototype: int __stdcall tc_hmac_update(TCHmacState_t ctx, void * data, uint data_length)
 */


/* exclude_from_export_ai */

int tc_hmac_update(TCHmacState_t ctx,void *data,uint data_length)

{
  if (ctx != (TCHmacState_t)0x0) {
    tc_sha256_update(ctx,data,data_length);
  }
  return (uint)(ctx != (TCHmacState_t)0x0);
}


