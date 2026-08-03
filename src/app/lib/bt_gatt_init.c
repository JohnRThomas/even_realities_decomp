/*
 * Function: bt_gatt_init
 * Entry:    0005c93c
 * Prototype: void __stdcall bt_gatt_init(void)
 */


/* exclude_from_export */

void bt_gatt_init(void)

{
  uint extraout_r0;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  int iVar1;
  uint uVar2;
  undefined *data;
  k_timeout_t delay;
  
  k_queue_init(&gatt_prep_queue._queue);
  iVar1 = 0;
  data = &DAT_2000b7b4;
  do {
    iVar1 = iVar1 + 1;
    k_queue_append(&gatt_prep_queue._queue,data);
    data = data + 0x14;
  } while (iVar1 != 10);
  atomic_set_bit((atomic_t *)&DAT_2000b8e4,1);
  uVar2 = extraout_r0 & extraout_r1;
  if (uVar2 == 0) {
    bt_gatt_service_init();
    DAT_2000b8f0 = uVar2;
    DAT_2000b8f4 = uVar2;
    k_work_init_delayable(&db_hash.work,&LAB_0008646a_1);
    delay.ticks._4_4_ = 0x148;
    delay.ticks._0_4_ = extraout_r1_00;
    k_work_schedule(&db_hash.work,delay);
    k_work_init_delayable((k_work_delayable *)&DAT_200065f8,(void *)0x5e769);
    atomic_set_bit((atomic_t *)&DAT_20006628,2);
    k_work_init_delayable(&gatt_delayed_store.work,(void *)0x8675f);
    bt_conn_auth_info_cb_register((bt_conn_auth_info_cb *)&DAT_20002a18);
    DAT_20002a14 = DAT_2000b6fc;
    DAT_2000b6fc = &DAT_200029f4;
    return;
  }
  return;
}


