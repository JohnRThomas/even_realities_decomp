/*
 * Function: smp_pairing_failed
 * Entry:    000613dc
 * Prototype: uint8_t __stdcall smp_pairing_failed(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_pairing_failed(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  bt_conn_auth_cb *pbVar2;
  byte *pbVar3;
  undefined4 uVar4;
  char local_30 [4];
  char *local_2c;
  uint uStack_28;
  
  uVar4._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
  uVar4._1_1_ = smp[1].e[0];
  uVar4._2_1_ = smp[1].e[1];
  uVar4._3_1_ = smp[1].e[2];
  pbVar2 = latch_auth_cb(smp);
  pbVar3 = (buf->field6_0xc).field0.data;
  uStack_28 = (uint)*pbVar3;
  local_2c = "pairing failed (peer reason 0x%x)";
  local_30[0] = '\x03';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,local_30);
  bVar1 = atomic_test_and_clear_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,10);
  if ((((bVar1) || (bVar1 = atomic_test_and_clear_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0xb), bVar1))
      && (pbVar2 != (bt_conn_auth_cb *)0x0)) && ((code *)pbVar2->passkey_confirm != (code *)0x0)) {
    (*(code *)pbVar2->passkey_confirm)(uVar4);
  }
  smp_pairing_complete(smp,*pbVar3);
  return '\0';
}


