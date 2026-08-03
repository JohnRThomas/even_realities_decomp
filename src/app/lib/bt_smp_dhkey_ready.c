/*
 * Function: bt_smp_dhkey_ready
 * Entry:    00086c54
 * Prototype: void __stdcall bt_smp_dhkey_ready(uint8_t * dhkey)
 */


/* exclude_from_export_ai */

void bt_smp_dhkey_ready(uint8_t *dhkey)

{
  bool bVar1;
  uint8_t reason;
  bt_smp *smp;
  atomic_t *target;
  int iVar2;
  undefined4 *puVar3;
  uint8_t *puVar4;
  dword *target_00;
  uint8_t *puVar5;
  
  smp = smp_find(8);
  if (smp != (bt_smp *)0x0) {
    target_00 = &smp->SMP_NUM_FLAGS_;
    atomic_clear_bit((atomic_t *)target_00,8);
    if (dhkey == (uint8_t *)0x0) {
      iVar2 = 0xb;
LAB_00086cd6:
      reason = (uint8_t)iVar2;
      goto LAB_00086cd8;
    }
    atomic_clear_bit(target,7);
    puVar3 = (undefined4 *)((int)&smp->bondable + 3);
    puVar5 = dhkey;
    do {
      puVar4 = puVar5 + 4;
      *puVar3 = *(undefined4 *)puVar5;
      puVar3 = puVar3 + 1;
      puVar5 = puVar4;
    } while (puVar4 != dhkey + 0x20);
    bVar1 = atomic_test_bit((atomic_t *)target_00,10);
    if ((bVar1) || (bVar1 = atomic_test_bit((atomic_t *)target_00,0x10), bVar1)) {
      atomic_set_bit((atomic_t *)target_00,9);
    }
    else {
      bVar1 = atomic_test_bit((atomic_t *)target_00,9);
      if ((bVar1) && (iVar2 = smp_g2_test(), iVar2 != 0)) goto LAB_00086cd6;
    }
  }
  while ((smp = smp_find(7), smp != (bt_smp *)0x0 && (reason = generate_dhkey(smp), reason != '\0'))
        ) {
LAB_00086cd8:
    smp_error(smp,reason);
  }
  return;
}


