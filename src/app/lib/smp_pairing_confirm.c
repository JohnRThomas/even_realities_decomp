/*
 * Function: smp_pairing_confirm
 * Entry:    00060544
 * Prototype: uint8_t __stdcall smp_pairing_confirm(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_pairing_confirm(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  uint8_t uVar2;
  bt_smp *smp_00;
  uint8_t *e;
  byte *pbVar3;
  uint8_t *puVar4;
  uint8_t *puVar6;
  dword *target;
  char acStack_28 [4];
  char *pcStack_24;
  uint uStack_20;
  uint8_t *puVar5;
  
  target = &smp->SMP_NUM_FLAGS_;
  puVar6 = (buf->field6_0xc).field0.data;
  atomic_clear_bit((atomic_t *)target,0xb);
  pbVar3 = smp->pcnf;
  puVar4 = puVar6;
  do {
    puVar5 = puVar4 + 4;
    *(undefined4 *)pbVar3 = *(undefined4 *)puVar4;
    pbVar3 = pbVar3 + 4;
    puVar4 = puVar5;
  } while (puVar5 != puVar6 + 0x10);
  bVar1 = atomic_test_bit((atomic_t *)target,5);
  if (bVar1) {
    uStack_20 = (uint)smp->method;
    if (uStack_20 == 1) {
      bVar1 = atomic_test_bit((atomic_t *)target,10);
      if (bVar1) {
        atomic_set_bit((atomic_t *)target,0);
        return '\0';
      }
    }
    else if (uStack_20 != 2) {
      pcStack_24 = "Unknown pairing method (%u)";
      acStack_28[0] = '\x03';
      acStack_28[1] = '\0';
      acStack_28[2] = '\0';
      acStack_28[3] = '\0';
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,acStack_28);
      return '\b';
    }
    atomic_set_bit((atomic_t *)smp,4);
    uVar2 = sc_smp_send_dhkey_check(smp_00,e);
  }
  else {
    uVar2 = smp_send_pairing_confirm(smp);
  }
  return uVar2;
}


