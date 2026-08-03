/*
 * Function: bt_gatt_attr_get_handle
 * Entry:    0005dca0
 * Prototype: uint16_t __stdcall bt_gatt_attr_get_handle(bt_gatt_attr * attr)
 */


/* exclude_from_export_ai */

uint16_t bt_gatt_attr_get_handle(bt_gatt_attr *attr)

{
  uint16_t uVar1;
  undefined **ppuVar2;
  char *test;
  char *file;
  int line;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  bt_gatt_attr *pbVar7;
  
  uVar1 = 0;
  if ((attr != (bt_gatt_attr *)0x0) && (uVar1 = attr->handle, uVar1 == 0)) {
    uVar3 = 1;
    ppuVar2 = (undefined **)&DAT_0008b808;
    while( true ) {
      if (&PTR_s_LSM6DSO_0008b820 < ppuVar2) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","static_svc <= _bt_gatt_service_static_list_end",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",1811);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)((int)&PTR_DAT_0008b81c + 3) < ppuVar2) break;
      pbVar7 = (bt_gatt_attr *)*ppuVar2;
      puVar6 = ppuVar2[1];
      if ((attr < pbVar7) || (pbVar7 + (int)(puVar6 + -1) < attr)) {
        puVar4 = puVar6 + uVar3;
      }
      else {
        puVar5 = (undefined *)0x0;
        while( true ) {
          puVar4 = puVar5 + uVar3;
          if (puVar5 == puVar6) break;
          if (attr == pbVar7 + (int)puVar5) {
            return (uint16_t)puVar4;
          }
          puVar5 = puVar5 + 1;
        }
      }
      uVar3 = (uint)puVar4 & 0xffff;
      ppuVar2 = ppuVar2 + 2;
    }
  }
  return uVar1;
}


