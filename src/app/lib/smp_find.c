/*
 * Function: smp_find
 * Entry:    0005fd50
 * Prototype: bt_smp * __stdcall smp_find(int flag)
 */


/* exclude_from_export_ai */

bt_smp * smp_find(int flag)

{
  bool bVar1;
  int extraout_r3;
  bt_smp *pbVar2;
  
  bVar1 = atomic_test_bit(&DAT_20006634,flag);
  pbVar2 = (bt_smp *)(extraout_r3 + -4);
  if (!bVar1) {
    pbVar2 = (bt_smp *)0x0;
  }
  return pbVar2;
}


