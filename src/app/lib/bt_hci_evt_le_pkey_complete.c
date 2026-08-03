/*
 * Function: bt_hci_evt_le_pkey_complete
 * Entry:    000591d0
 * Prototype: void __stdcall bt_hci_evt_le_pkey_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void bt_hci_evt_le_pkey_complete(net_buf *buf)

{
  int *piVar1;
  undefined4 *puVar2;
  uint8_t *puVar3;
  uint8_t *puVar5;
  uint8_t *puVar4;
  
  puVar5 = (buf->field6_0xc).field0.data;
  DAT_200020d4 = DAT_200020d4 & 0xffffffdf;
  piVar1 = DAT_2000b654;
  if (*puVar5 == '\0') {
    puVar2 = &DAT_2001e265;
    puVar4 = puVar5 + 1;
    do {
      puVar3 = puVar4 + 4;
      *puVar2 = *(undefined4 *)puVar4;
      puVar2 = puVar2 + 1;
      puVar4 = puVar3;
    } while (puVar3 != puVar5 + 0x41);
    DAT_200020d4 = DAT_200020d4 | 0x10;
    piVar1 = DAT_2000b654;
  }
  for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if ((code *)piVar1[-1] != (code *)0x0) {
      if (*puVar5 == '\0') {
        puVar2 = &DAT_2001e265;
      }
      else {
        puVar2 = (undefined4 *)0x0;
      }
      (*(code *)piVar1[-1])(puVar2);
    }
  }
  DAT_2000b654 = (int *)0x0;
  DAT_2000b658 = 0;
  return;
}


