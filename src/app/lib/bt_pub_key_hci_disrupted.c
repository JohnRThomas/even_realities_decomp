/*
 * Function: bt_pub_key_hci_disrupted
 * Entry:    000590c8
 * Prototype: void __stdcall bt_pub_key_hci_disrupted(void)
 */


/* exclude_from_export_ai */

void bt_pub_key_hci_disrupted(void)

{
  int *piVar1;
  
  DAT_200020d4 = DAT_200020d4 & 0xffffffdf;
  for (piVar1 = (int *)DAT_2000b654; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if ((code *)piVar1[-1] != (code *)0x0) {
      (*(code *)piVar1[-1])(0);
    }
  }
  DAT_2000b654 = 0;
  DAT_2000b658 = 0;
  return;
}


