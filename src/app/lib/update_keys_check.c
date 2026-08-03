/*
 * Function: update_keys_check
 * Entry:    000867ba
 * Prototype: bool __stdcall update_keys_check(bt_smp * smp, bt_keys * keys)
 */


/* exclude_from_export */

bool update_keys_check(bt_smp *smp,bt_keys *keys)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  bt_keys *extraout_r2;
  bt_smp *extraout_r3;
  
  if ((keys != (bt_keys *)0x0) && (uVar1 = (ushort)keys->ltk_rand0, (uVar1 & 0x24) != 0)) {
    bVar3 = smp->prsp[4];
    if (smp->preq[4] <= smp->prsp[4]) {
      bVar3 = smp->preq[4];
    }
    if ((bVar3 < (byte)keys->keys) ||
       (((int)((uint)uVar1 << 0x1a) < 0 &&
        (bVar2 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,5), keys = extraout_r2,
        smp = extraout_r3, !bVar2)))) {
      return false;
    }
    if ((int)((uint)*(byte *)((int)&keys->keys + 1) << 0x1f) < 0) {
      return smp->method != 0;
    }
  }
  return true;
}


