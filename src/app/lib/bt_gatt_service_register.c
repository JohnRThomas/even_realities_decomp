/*
 * Function: bt_gatt_service_register
 * Entry:    0005dfe4
 * Prototype: int __stdcall bt_gatt_service_register(bt_gatt_service * svc)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int bt_gatt_service_register(bt_gatt_service *svc)

{
  code *pcVar1;
  ushort start_handle;
  sys_snode_t *psVar2;
  bool bVar3;
  int iVar4;
  sys_snode_t *psVar5;
  int in_r1;
  char *test;
  char *test_00;
  char *test_01;
  sys_snode_t *extraout_r1;
  sys_snode_t *bit;
  undefined1 *puVar6;
  char *file;
  char *file_00;
  char *file_01;
  bt_gatt_service *pbVar7;
  int line;
  int line_00;
  int line_01;
  bt_gatt_service *pbVar8;
  sys_snode_t *psVar9;
  sys_snode_t *psVar10;
  undefined *puVar11;
  short sVar12;
  char local_58 [4];
  char *local_54;
  uint uStack_50;
  bt_uuid local_44 [2];
  undefined2 local_42;
  undefined4 local_40;
  char local_30 [4];
  char *local_2c;
  
  if (svc == (bt_gatt_service *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","svc","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",
            0x670);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
LAB_0005e008:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (svc->attrs == (undefined *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","svc->attrs",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x671);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
    goto LAB_0005e008;
  }
  if (svc->attr_count == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","svc->attr_count",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x672);
    _ASSERT("\tinvalid parameters\n\n",test_01,file_01,line_01);
    goto LAB_0005e008;
  }
  bVar3 = atomic_test_bit((atomic_t *)&DAT_2000b8e4,in_r1);
  if ((int)((uint)bVar3 << 0x1f) < 0) {
    atomic_test_bit((atomic_t *)&DAT_20006628,(uint)bVar3 << 0x1f);
    local_2c = "Can\'t register service after init and before settings are loaded.";
    local_30[0] = '\x02';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_30);
    return -0x16;
  }
  bt_gatt_service_init();
  local_44[0].type = '\0';
  local_42 = 0x1800;
  iVar4 = bt_uuid_cmp(*(bt_uuid **)svc->attrs,local_44);
  if (iVar4 == 0) {
    return -0x78;
  }
  local_40._0_2_ = (ushort)local_40 & 0xff00;
  local_40 = CONCAT22(0x1801,(ushort)local_40);
  iVar4 = bt_uuid_cmp(*(bt_uuid **)svc->attrs,(bt_uuid *)&local_40);
  if (iVar4 == 0) {
    return -0x78;
  }
  z_sched_lock();
  puVar11 = svc->attrs;
  sVar12 = (short)svc->attr_count;
  if (DAT_2000b8e8 == (sys_snode_t *)0x0) {
    psVar9 = (sys_snode_t *)(uint)DAT_2001092a;
    bit = extraout_r1;
    if (puVar11 != (undefined *)0x0) {
      psVar10 = (sys_snode_t *)0x0;
LAB_0005e164:
      for (; sVar12 != 0; sVar12 = sVar12 + -1) {
        start_handle = *(ushort *)(puVar11 + 0x10);
        bit = (sys_snode_t *)(uint)start_handle;
        if (bit == (sys_snode_t *)0x0) {
          puVar6 = (undefined1 *)((int)&psVar9->next + 1);
          *(short *)(puVar11 + 0x10) = (short)puVar6;
          bit = (sys_snode_t *)((uint)puVar6 & 0xffff);
        }
        else if (bit <= psVar9) {
          local_40 = 0;
          bt_gatt_foreach_attr(start_handle,start_handle,&LAB_00085d72_1,&local_40);
          bit = psVar9;
          if (local_40 != 0) {
            uStack_50 = (uint)*(ushort *)(puVar11 + 0x10);
            local_54 = "Unable to register handle 0x%04x";
            local_58[0] = '\x03';
            local_58[1] = '\0';
            local_58[2] = '\0';
            local_58[3] = '\0';
            LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,local_58);
            k_sched_unlock();
            return -0x16;
          }
        }
        puVar11 = puVar11 + 0x14;
        psVar9 = bit;
      }
      goto LAB_0005e112;
    }
  }
  else {
    if (DAT_2000b8ec == (sys_snode_t *)0x0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0x5e1fc);
      (*pcVar1)();
    }
    bit = (sys_snode_t *)&BusFault;
    psVar9 = (sys_snode_t *)
             (uint)*(ushort *)
                    (((bt_gatt_service *)(DAT_2000b8ec + -2))->attrs +
                    *(uint *)(DAT_2000b8ec + -1) * 0x14 + -4);
    psVar10 = psVar9;
    if (puVar11 != (undefined *)0x0) goto LAB_0005e164;
LAB_0005e112:
    psVar9 = DAT_2000b8ec;
    if ((psVar10 != (sys_snode_t *)0x0) &&
       ((undefined1 *)(uint)*(ushort *)(svc->attrs + 0x10) <= psVar10)) {
      bit = DAT_2000b8e8;
      psVar10 = DAT_2000b8e8;
      psVar2 = DAT_2000b8ec;
      if (DAT_2000b8e8 != (sys_snode_t *)0x0) {
        pbVar7 = (bt_gatt_service *)0x0;
        psVar5 = DAT_2000b8e8;
        do {
          pbVar8 = (bt_gatt_service *)(psVar5 + -2);
          if ((undefined1 *)(uint)*(ushort *)(svc->attrs + 0x10) <
              (undefined1 *)(uint)*(ushort *)(pbVar8->attrs + 0x10)) {
            psVar10 = &svc->node;
            if (pbVar7 == (bt_gatt_service *)0x0) {
              (svc->node).next = DAT_2000b8e8;
              DAT_2000b8e8 = psVar10;
              psVar2 = DAT_2000b8ec;
              if (psVar9 == (sys_snode_t *)0x0) goto LAB_0005e1c2;
            }
            else {
              bit = (pbVar7->node).next;
              (svc->node).next = bit;
              if (bit == (sys_snode_t *)0x0) goto LAB_0005e0dc;
              (pbVar7->node).next = psVar10;
              psVar10 = DAT_2000b8e8;
              psVar2 = DAT_2000b8ec;
            }
            break;
          }
          psVar5 = psVar5->next;
          pbVar7 = pbVar8;
        } while (psVar5 != (sys_snode_t *)0x0);
      }
      goto LAB_0005e0e6;
    }
  }
  (svc->node).next = (sys_snode_t *)0x0;
LAB_0005e0dc:
  psVar10 = &svc->node;
  psVar2 = psVar10;
  if (DAT_2000b8ec != (sys_snode_t *)0x0) {
    DAT_2000b8ec->next = psVar10;
LAB_0005e1c2:
    psVar10 = DAT_2000b8e8;
    psVar2 = &svc->node;
  }
LAB_0005e0e6:
  DAT_2000b8ec = psVar2;
  DAT_2000b8e8 = psVar10;
  bVar3 = atomic_test_bit((atomic_t *)&DAT_2000b8e4,(int)bit);
  if ((int)((uint)bVar3 << 0x1f) < 0) {
    sc_indicate(*(uint16_t *)(svc->attrs + 0x10),
                *(uint16_t *)(svc->attrs + svc->attr_count * 0x14 + -4));
    db_changed();
  }
  k_sched_unlock();
  return 0;
}


