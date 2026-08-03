/*
 * Function: bt_hci_evt_le_dhkey_complete
 * Entry:    00059244
 * Prototype: void __stdcall bt_hci_evt_le_dhkey_complete(net_buf * buf)
 */


/* exclude_from_export_ai */

void bt_hci_evt_le_dhkey_complete(net_buf *buf)

{
  code *UNRECOVERED_JUMPTABLE;
  uint8_t *puVar1;
  uint8_t *puVar2;
  
  UNRECOVERED_JUMPTABLE = DAT_2000b650;
  if (DAT_2000b650 != (code *)0x0) {
    puVar2 = (buf->field6_0xc).field0.data;
    puVar1 = (uint8_t *)0x0;
    DAT_2000b650 = (code *)0x0;
    if (*puVar2 == '\0') {
      puVar1 = puVar2 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00059256. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(puVar1);
    return;
  }
  return;
}


