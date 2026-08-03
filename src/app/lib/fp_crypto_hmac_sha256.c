/*
 * Function: fp_crypto_hmac_sha256
 * Entry:    00083ce8
 * Prototype: int __stdcall fp_crypto_hmac_sha256(uint8_t * out, uint8_t * in, size_t data_len, uint8_t * hmac_key, size_t hmac_key_len)
 */


/* exclude_from_export_ai */

int fp_crypto_hmac_sha256
              (uint8_t *out,uint8_t *in,size_t data_len,uint8_t *hmac_key,size_t hmac_key_len)

{
  int iVar1;
  uint8_t *tag;
  uint8_t *key;
  undefined1 auStack_2c [3];
  undefined1 local_29;
  size_t sStack_28;
  
  key = out + 0xf0;
  _auStack_2c = CONCAT13(1,(uint3)in & 0xffff);
  tag = out + 0x110;
  sStack_28 = data_len;
  tc_hmac_set_key(out,key,0x20);
  tc_hmac_init(out);
  tc_hmac_update(out,tag,0x20);
  tc_hmac_update(out,auStack_2c + 2,1);
  if ((in != (uint8_t *)0x0) && (data_len != 0)) {
    tc_hmac_update(out,in,data_len);
  }
  if ((hmac_key != (uint8_t *)0x0) && (hmac_key_len != 0)) {
    tc_hmac_update(out,hmac_key,hmac_key_len);
  }
  tc_hmac_final(key,0x20,out);
  tc_hmac_set_key(out,key,0x20);
  tc_hmac_init(out);
  tc_hmac_update(out,tag,0x20);
  iVar1 = tc_hmac_final(tag,0x20,out);
  if ((in != (uint8_t *)0x0) && (data_len != 0)) {
    tc_hmac_set_key(out,key,0x20);
    tc_hmac_init(out);
    tc_hmac_update(out,tag,0x20);
    tc_hmac_update(out,&local_29,1);
    tc_hmac_update(out,in,data_len);
    if ((hmac_key != (uint8_t *)0x0) && (hmac_key_len != 0)) {
      tc_hmac_update(out,hmac_key,hmac_key_len);
    }
    tc_hmac_final(key,0x20,out);
    tc_hmac_set_key(out,key,0x20);
    tc_hmac_init(out);
    tc_hmac_update(out,tag,0x20);
    iVar1 = tc_hmac_final(tag,0x20,out);
  }
  return iVar1;
}


