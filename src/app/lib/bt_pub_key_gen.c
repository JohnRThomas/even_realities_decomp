/*
 * Function: bt_pub_key_gen
 * Entry:    000610dc
 * Prototype: int __stdcall bt_pub_key_gen(bt_pub_key_cb * cb)
 */


/* exclude_from_export_ai */

int bt_pub_key_gen(bt_pub_key_cb *cb)

{
  uint8_t reason;
  int iVar1;
  int extraout_r0;
  
  DAT_2000b928 = cb;
  if (cb == (bt_pub_key_cb *)0x0) {
    iVar1 = FUN_0005fe40();
    return iVar1;
  }
  k_sem_give((k_sem *)&DAT_20003bb0);
  iVar1 = extraout_r0;
  if (DAT_20006634 << 0x19 < 0) {
    reason = smp_public_key_periph((bt_smp *)&DAT_20006630);
    iVar1 = 0;
    if (reason != '\0') {
      iVar1 = smp_error((bt_smp *)&DAT_20006630,reason);
    }
  }
  return iVar1;
}


