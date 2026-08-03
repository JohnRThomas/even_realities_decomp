/*
 * Function: smp_dhkey_check
 * Entry:    00086916
 * Prototype: uint8_t __stdcall smp_dhkey_check(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_dhkey_check(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  uint8_t *puVar4;
  uint8_t *puVar6;
  dword *target;
  uint8_t *puVar5;
  
  if (*(char *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 3) == '\x01') {
    puVar6 = (buf->field6_0xc).field0.data;
    target = &smp->SMP_NUM_FLAGS_;
    atomic_clear_bit((atomic_t *)target,0x10);
    pbVar3 = smp[1].pcnf + 8;
    puVar4 = puVar6;
    do {
      puVar5 = puVar4 + 4;
      *(undefined4 *)pbVar3 = *(undefined4 *)puVar4;
      pbVar3 = pbVar3 + 4;
      puVar4 = puVar5;
    } while (puVar5 != puVar6 + 0x10);
    bVar1 = atomic_test_bit((atomic_t *)target,7);
    if ((!bVar1) && (bVar1 = atomic_test_bit((atomic_t *)target,10), !bVar1)) {
      iVar2 = smp_g2_test();
      return (uint8_t)iVar2;
    }
    atomic_set_bit((atomic_t *)target,9);
  }
  return '\0';
}


