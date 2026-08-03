/*
 * Function: smp_central_ident
 * Entry:    0006132c
 * Prototype: uint8_t __stdcall smp_central_ident(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export */

uint8_t smp_central_ident(bt_smp *smp,net_buf *buf)

{
  byte bVar1;
  bool bVar2;
  bt_keys *pbVar3;
  char *str;
  size_t len;
  int extraout_r3;
  undefined2 *puVar4;
  bt_addr_le_t *addr;
  int iVar5;
  undefined1 *local_28;
  char *local_24;
  int iStack_20;
  undefined2 local_1c;
  
  iVar5 = *(int *)&smp[1].dhkey_BT_DH_KEY_LEN_;
  bVar2 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0xd);
  if (bVar2) {
    addr = (bt_addr_le_t *)(iVar5 + 0x90);
    puVar4 = *(undefined2 **)(extraout_r3 + 0xc);
    pbVar3 = bt_keys_get_type(BT_KEYS_REMOTE_CSRK,*(uint8_t *)(iVar5 + 8),addr);
    if (pbVar3 == (bt_keys *)0x0) {
      iStack_20 = bt_addr_le_to_str(addr,str,len);
      local_24 = "Unable to get keys for %s";
      local_1c = 0x200;
      local_28 = &DAT_01000003;
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_28);
      return '\b';
    }
    *(undefined2 *)&pbVar3->ltk_val0 = *puVar4;
    *(undefined4 *)((int)&pbVar3->ltk_rand0 + 2) = *(undefined4 *)(puVar4 + 1);
    *(undefined4 *)((int)&pbVar3->ltk_rand4 + 2) = *(undefined4 *)(puVar4 + 3);
  }
  bVar1 = smp[1].tk[10];
  smp[1].tk[10] = bVar1 & 0xfe;
  if ((int)((uint)bVar1 << 0x1e) < 0) {
    iVar5 = 8;
  }
  else {
    if (-1 < (int)((uint)bVar1 << 0x1d)) goto LAB_000613b4;
    iVar5 = 10;
  }
  atomic_set_bit((atomic_t *)smp,iVar5);
LAB_000613b4:
  if (*(short *)(smp[1].tk + 9) == 0) {
    smp_pairing_complete(smp,'\0');
  }
  return '\0';
}


