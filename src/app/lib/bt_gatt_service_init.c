/*
 * Function: bt_gatt_service_init
 * Entry:    0005cf60
 * Prototype: void __stdcall bt_gatt_service_init(void)
 */


/* exclude_from_export */

void bt_gatt_service_init(void)

{
  undefined **ppuVar1;
  short sVar2;
  bool bVar3;
  uint extraout_r0;
  uint extraout_r1;
  char *test;
  undefined **ppuVar4;
  char *file;
  int line;
  
  atomic_set_bit((atomic_t *)&DAT_2000b8e4,2);
  if ((extraout_r0 & extraout_r1) == 0) {
    ppuVar4 = (undefined **)&DAT_0008b808;
    bVar3 = false;
    sVar2 = DAT_2001092a;
    while( true ) {
      if (&PTR_s_LSM6DSO_0008b820 < ppuVar4) {
        if (bVar3) {
          DAT_2001092a = sVar2;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","svc <= _bt_gatt_service_static_list_end",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",1453);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)0x8b81f < ppuVar4) break;
      ppuVar1 = ppuVar4 + 1;
      ppuVar4 = ppuVar4 + 2;
      sVar2 = sVar2 + (short)*ppuVar1;
      bVar3 = true;
    }
    if (bVar3) {
      DAT_2001092a = sVar2;
    }
  }
  return;
}


