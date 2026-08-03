/*
 * Function: smp_init
 * Entry:    0005fedc
 * Prototype: int __stdcall smp_init(bt_smp * smp)
 */


/* exclude_from_export_ai */

int smp_init(bt_smp *smp)

{
  int iVar1;
  
  memset(smp,0,0xf0);
  iVar1 = bt_rand(smp->prnd,0x10);
  if (iVar1 == 0) {
    atomic_set_bit((atomic_t *)smp,5);
    DAT_2000b928 = bt_pub_key_get();
    iVar1 = 0;
  }
  else {
    iVar1 = 8;
  }
  return iVar1;
}


