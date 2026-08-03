/*
 * Function: smp_pairing_complete
 * Entry:    00060d9c
 * Prototype: void __stdcall smp_pairing_complete(bt_smp * smp, uint8_t status)
 */


/* exclude_from_export_ai */

void smp_pairing_complete(bt_smp *smp,uint8_t status)

{
  bool bVar1;
  uint8_t hci_err;
  uint uVar2;
  undefined *puVar3;
  code *pcVar4;
  bt_conn *conn;
  dword *target;
  int iVar5;
  undefined4 *puVar6;
  char local_20 [4];
  char *local_1c;
  
  conn = *(bt_conn **)&smp[1].dhkey_BT_DH_KEY_LEN_;
  target = &smp->SMP_NUM_FLAGS_;
  if (conn->state == 7) {
    if (status == '\0') {
      bVar1 = atomic_test_bit((atomic_t *)target,0xd);
      if (bVar1) {
        bt_keys_store((bt_keys *)(conn->le).keys);
      }
      if (DAT_2000b700 != (int *)0x0) {
        puVar6 = (undefined4 *)*DAT_2000b700;
        if (puVar6 != (undefined4 *)0x0) {
          puVar6 = puVar6 + -3;
        }
        pcVar4 = (code *)DAT_2000b700[-3];
        if (pcVar4 == (code *)0x0) goto LAB_00060e50;
        do {
          (*pcVar4)(conn,bVar1);
LAB_00060e50:
          if (puVar6 == (undefined4 *)0x0) break;
          do {
            pcVar4 = (code *)*puVar6;
            if (puVar6[3] == 0) {
              puVar6 = (undefined4 *)0x0;
              if (pcVar4 == (code *)0x0) goto LAB_00060e66;
              break;
            }
            puVar6 = (undefined4 *)(puVar6[3] + -0xc);
          } while (pcVar4 == (code *)0x0);
        } while( true );
      }
      goto LAB_00060e66;
    }
    uVar2 = (uint)(byte)(status - 1);
    if (uVar2 < 0xf) goto LAB_00060dc6;
    uVar2 = 9;
  }
  else {
    local_1c = "Not connected!";
    local_20[0] = '\x02';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1080,local_20);
    uVar2 = 7;
LAB_00060dc6:
    uVar2 = (uint)(byte)(&DAT_000f3231)[uVar2];
  }
  puVar3 = (conn->le).keys;
  if ((puVar3 != (undefined *)0x0) &&
     ((puVar3[0xc] == '\0' || (bVar1 = atomic_test_bit((atomic_t *)target,2), bVar1)))) {
    bt_keys_clear((bt_keys *)(conn->le).keys);
    (conn->le).keys = (undefined *)0x0;
  }
  bVar1 = atomic_test_bit((atomic_t *)target,2);
  if (!bVar1) {
    if (uVar2 < 8) {
      hci_err = (&DAT_000f3220)[uVar2];
    }
    else {
      hci_err = '\x1f';
    }
    bt_conn_security_changed(conn,hci_err,(bt_security_err)uVar2);
  }
  bVar1 = atomic_test_bit((atomic_t *)target,3);
  if ((bVar1) && (DAT_2000b700 != (int *)0x0)) {
    iVar5 = *DAT_2000b700;
    if (iVar5 != 0) {
      iVar5 = iVar5 + -0xc;
    }
    pcVar4 = (code *)DAT_2000b700[-2];
    if (pcVar4 != (code *)0x0) goto LAB_00060ea4;
    while (iVar5 != 0) {
      do {
        pcVar4 = *(code **)(iVar5 + 4);
        if (*(int *)(iVar5 + 0xc) == 0) {
          iVar5 = 0;
          if (pcVar4 == (code *)0x0) goto LAB_00060e66;
          break;
        }
        iVar5 = *(int *)(iVar5 + 0xc) + -0xc;
      } while (pcVar4 == (code *)0x0);
LAB_00060ea4:
      (*pcVar4)(conn,uVar2);
    }
  }
LAB_00060e66:
  smp_reset(smp);
  if ((conn->state == 7) && (conn->sec_level != conn->required_sec_level)) {
    bt_smp_start_security(conn);
    return;
  }
  return;
}


