/*
 * Function: bt_gatt_foreach_attr_type
 * Entry:    0005dd30
 * Prototype: void __stdcall bt_gatt_foreach_attr_type(uint16_t start_handle, uint16_t end_handle, bt_uuid * uuid, void * attr_data, uint16_t num_matches, bt_gatt_attr_func_t func, void * user_data)
 */


/* exclude_from_export_ai */

void bt_gatt_foreach_attr_type
               (uint16_t start_handle,uint16_t end_handle,bt_uuid *uuid,void *attr_data,
               uint16_t num_matches,bt_gatt_attr_func_t func,void *user_data)

{
  ushort handle;
  uint8_t uVar1;
  undefined *puVar2;
  bt_gatt_attr *attr;
  uint uVar3;
  char *test;
  char *file;
  int line;
  undefined **ppuVar4;
  int *piVar5;
  undefined *puVar6;
  uint uVar7;
  uint16_t local_2a [3];
  
  puVar2 = (undefined *)(uint)start_handle;
  if (num_matches == 0) {
    num_matches = 0xffff;
  }
  if (puVar2 <= (undefined *)(uint)DAT_2001092a) {
    ppuVar4 = (undefined **)&DAT_0008b808;
    uVar7 = 1;
    while( true ) {
      if (&PTR_s_LSM6DSO_0008b820 < ppuVar4) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","static_svc <= _bt_gatt_service_static_list_end",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",2007);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)((int)&PTR_DAT_0008b81c + 3) < ppuVar4) break;
      if (ppuVar4[1] + uVar7 < puVar2) {
        uVar3 = (uint)(ppuVar4[1] + uVar7) & 0xffff;
      }
      else {
        puVar6 = (undefined *)0x0;
        while( true ) {
          handle = (short)uVar7 + (short)puVar6;
          uVar3 = (uint)handle;
          if (ppuVar4[1] <= puVar6) break;
          uVar1 = gatt_foreach_iter((bt_gatt_attr *)(*ppuVar4 + (int)puVar6 * 0x14),handle,
                                    start_handle,end_handle,uuid,attr_data,&num_matches,func,
                                    user_data);
          if (uVar1 == '\0') {
            return;
          }
          puVar6 = puVar6 + 1;
        }
      }
      ppuVar4 = ppuVar4 + 2;
      uVar7 = uVar3;
    }
  }
  local_2a[0] = num_matches;
  if (DAT_2000b8e8 != (int *)0x0) {
    piVar5 = DAT_2000b8e8;
    do {
      uVar7 = 0;
      if (*piVar5 == 0) {
LAB_0005ddf0:
        for (; uVar7 < (uint)piVar5[-1]; uVar7 = uVar7 + 1) {
          attr = (bt_gatt_attr *)(uVar7 * 0x14 + piVar5[-2]);
          uVar1 = gatt_foreach_iter(attr,attr->handle,start_handle,end_handle,uuid,attr_data,
                                    local_2a,func,user_data);
          if (uVar1 == '\0') {
            return;
          }
        }
      }
      else if (puVar2 < (undefined *)(uint)*(ushort *)(*(int *)(*piVar5 + -8) + 0x10)) {
        uVar7 = 0;
        goto LAB_0005ddf0;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)0x0);
  }
  return;
}


