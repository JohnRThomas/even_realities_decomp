/*
 * Function: generate_dhkey
 * Entry:    0005ff14
 * Prototype: uint8_t __stdcall generate_dhkey(bt_smp * smp)
 */


/* exclude_from_export_ai */

uint8_t generate_dhkey(bt_smp *smp)

{
  uint8_t uVar1;
  int iVar2;
  char local_18 [4];
  char *local_14;
  
  atomic_set_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,8);
  iVar2 = bt_dh_key_gen(&smp->pkey_BT_PUB_KEY_LEN_,(bt_dh_key_cb_t)0x86c55);
  uVar1 = '\0';
  if (iVar2 != 0) {
    atomic_clear_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,8);
    local_14 = "Failed to generate DHKey";
    local_18[0] = '\x02';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_18);
    uVar1 = '\b';
  }
  return uVar1;
}


