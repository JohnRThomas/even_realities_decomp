/*
 * Function: tc_aes_encrypt
 * Entry:    00083810
 * Prototype: int __stdcall tc_aes_encrypt(uint8_t * out, uint8_t * in, TCAesKeySched_t s)
 */


/* exclude_from_export_ai */

int tc_aes_encrypt(uint8_t *out,uint8_t *in,TCAesKeySched_t s)

{
  uint8_t *s_00;
  int iVar1;
  int extraout_r1;
  uint *k;
  uint *k_00;
  uint8_t auStack_30 [4];
  uint8_t auStack_2c [4];
  uint8_t auStack_28 [4];
  uint8_t auStack_24 [4];
  uint8_t auStack_20 [4];
  uint8_t auStack_1c [4];
  uint8_t auStack_18 [4];
  uint8_t auStack_14 [4];
  
  iVar1 = 0;
  if (out != (uint8_t *)0x0) {
    if (in == (uint8_t *)0x0) {
      iVar1 = 0;
    }
    else if (s == (TCAesKeySched_t)0x0) {
      iVar1 = 0;
    }
    else {
      _copy(auStack_30,0x10,in,0x10);
      add_round_key(auStack_30,(uint *)s);
      k = (uint *)(s + 0x10);
      do {
        sub_bytes(auStack_30);
        shift_rows(auStack_30);
        mult_row_column(auStack_20,auStack_30);
        mult_row_column(auStack_1c,auStack_2c);
        mult_row_column(auStack_18,auStack_28);
        mult_row_column(auStack_14,auStack_24);
        _copy(auStack_30,0x10,auStack_20,0x10);
        k_00 = k + 4;
        add_round_key(auStack_30,k);
        k = k_00;
      } while (k_00 != (uint *)(extraout_r1 + 0xa0));
      sub_bytes(s_00);
      shift_rows(auStack_30);
      add_round_key(auStack_30,k_00);
      _copy(out,0x10,auStack_30,0x10);
      memset(auStack_30,0,0x10);
      iVar1 = 1;
    }
  }
  return iVar1;
}


